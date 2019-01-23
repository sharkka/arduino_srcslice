/**
 * @File     onwork.h
 * @Brief
 * @DateTime 2019/1/22 15:39:47
 * @Modify   2019/1/22 15:39:52
 * @Author   Anyz
 */
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

/**
 * @Brief    joytick_ctrl_t
 * @Class    joytick sensor packet
 * @DateTime 2019/1/22 17:53:59
 * @Modify   2019/1/22 17:54:04
 * @Author   Anyz
 * @Keyword
 */
typedef struct _joytick_ctrl_t {
    int rx;
    int ry;
    int rz;
    int state;
    bool brake;
} joytick_ctrl_t;

static int buildinLed  = 6;
static int jtPinRx     = A0;
static int jtPinRy     = A1;
static int buttonState = 2;

/**
 * @Method   blinkLed
 * @Brief    for debug
 * @DateTime 2019-01-22T15:40:17+0800
 * @Modify   2019-01-22T15:40:17+0800
 * @Author   Anyz
 * @param    {[type]} int n [description]
 * @return   {[type]} [description]
 */
static void blinkLed(int n) {
    digitalWrite(buildinLed, HIGH);
    delay(n % 30);
    digitalWrite(buildinLed, LOW);
    delay(n % 30);
}
/**
 * @Method   confignRF24L01
 * @Brief    configuration of nRF24L01 send
 * @DateTime 2019-01-22T15:40:45+0800
 * @Modify   2019-01-22T15:40:45+0800
 * @Author   Anyz
 * @return   {[type]} [description]
 */
static void confignRF24L01() {
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    Mirf.setRADDR((byte*)"ABCDE");
    Mirf.payload = sizeof(joytick_ctrl_t);
    Mirf.channel = 90;
    Mirf.config();
    Serial.begin(9600);
    pinMode(buildinLed, OUTPUT);
}
/**
 * @Method   send
 * @Brief    send data of joytick
 * @DateTime 2019-01-22T15:41:29+0800
 * @Modify   2019-01-22T15:41:29+0800
 * @Author   Anyz
 * @param    {[type]} joytick_ctrl_t* data [description]
 * @return   {[type]} [description]
 */
static void send(joytick_ctrl_t* data) {
    Mirf.setTADDR((byte*)"FGHIJ");
    Mirf.send((byte*)data);
    while(Mirf.isSending()) {
        delay(1);
    }
    blinkLed(buildinLed);
    delay(1);
    Serial.println("Send success, ");
    //Serial.println(ct);
}
/**
 * @Method   setup
 * @Brief
 * @DateTime 2019-01-22T15:41:51+0800
 * @Modify   2019-01-22T15:41:51+0800
 * @Author   Anyz
 * @param    {[type]} void [description]
 * @return   {[type]} [description]
 */
void setup(void) {
    Serial.begin(9600);
    pinMode(buttonState, INPUT_PULLUP);
    confignRF24L01();
}
/**
 * @Method   loop
 * @Brief
 * @DateTime 2019-01-22T15:41:58+0800
 * @Modify   2019-01-22T15:41:58+0800
 * @Author   Anyz
 * @param    {[type]} void [description]
 * @return   {[type]} [description]
 */
void loop(void) {
    joytick_ctrl_t ct;
    ct.rx = analogRead(jtPinRx);
    ct.ry = analogRead(jtPinRy);
    ct.rz = 0;
    ct.state = digitalRead(buttonState);
    send(&ct);
    char buff[64] = {0};
    sprintf(buff, "x = %d, y = %d, z = %d, state: %d", ct.rx, ct.ry, ct.rz, ct.state);
    Serial.println(buff);
    Serial.print("BUTTON state = ");
    Serial.println(ct.state);
    delay(2);
}
