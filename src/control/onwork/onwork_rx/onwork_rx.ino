/**
 * @File     onwork_rx.h
 * @Brief    receive joytick data
 * @DateTime 2019/1/22 15:39:47
 * @Modify   2019/1/22 15:39:52
 * @Author   Anyz
 */
#include <SPI.h>
#include "Mirf.h"
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <Servo.h>

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

static int buildinLed   = 17;
static int steeringPin  = 10;
static int motorRPinPwm = 11;
static int motorLPinPwm = 12;
static int motorREnable = 13;
static int motorLEnable = 14;
static int alarmRis     = 15;
static int alarmLis     = 16;
static Servo steeringServo;

/**
 * @Method   controlSteeringEngine
 * @Brief
 * @DateTime 2019-01-22T16:15:27+0800
 * @Modify   2019-01-22T16:15:27+0800
 * @Author   Anyz
 * @param    {[type]} int x [description]
 * @return   {[type]} [description]
 */
static void controlSteeringEngine(int x) {
    int angle = (x - 512) / 511.0 * 60;
    if (angle >= 0) {
        steeringServo.write(90 + angle);
    } else {
        steeringServo.write(90 - angle);
    }
}
/**
 * @Method   controlMotionEngine
 * @Brief
 * @DateTime 2019-01-22T16:15:29+0800
 * @Modify   2019-01-22T16:15:29+0800
 * @Author   Anyz
 * @param    {[type]} int y [description]
 * @return   {[type]} [description]
 */
static void controlMotionEngine(int y) {
    if (y > 513) {
        digitalWrite(motorREnable, HIGH);
        digitalWrite(motorLEnable, LOW);
        analogWrite(motorRPinPwm, map(y, 512, 1023, 0, 255));
    } else if (y < 510) {
        digitalWrite(motorREnable, LOW);
        digitalWrite(motorLEnable, HIGH);
        analogWrite(motorLPinPwm, 255 - map(y, 0, 512, 0, 255));
    }
    // 510,511,512 will ignore
}
/**
 * @Method   controlBrakeSystem
 * @Brief
 * @DateTime 2019-01-22T16:15:32+0800
 * @Modify   2019-01-22T16:15:32+0800
 * @Author   Anyz
 * @param    {[type]} int state [description]
 * @return   {[type]} [description]
 */
static void controlBrakeSystem(int state) {
    if (0 == state) {
        digitalWrite(motorREnable, HIGH);
        digitalWrite(motorLEnable, LOW);
        analogWrite(motorRPinPwm, map(0, 0, 1023, 0, 255));
    }
}
/**
 * @Method   setup
 * @Brief
 * @DateTime 2019-01-22T16:15:36+0800
 * @Modify   2019-01-22T16:15:36+0800
 * @Author   Anyz
 * @return   {[type]} [description]
 */
void setup() {
    Serial.begin(9600);
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    Mirf.setRADDR((byte*)"FGHIJ");
    Mirf.payload = sizeof(joytick_ctrl_t);   
    Mirf.channel = 90;
    Mirf.config(); 
    Serial.println("Listening...");
    steeringServo.attach(steeringPin);
    pinMode(motorRPinPwm, OUTPUT);
    pinMode(motorLPinPwm, OUTPUT);
    pinMode(motorREnable, OUTPUT);
    pinMode(motorLEnable, OUTPUT);
}
/**
 * @Method   loop
 * @Brief
 * @DateTime 2019-01-22T16:15:39+0800
 * @Modify   2019-01-22T16:15:39+0800
 * @Author   Anyz
 * @return   {[type]} [description]
 */
void loop() {
    joytick_ctrl_t ct;
    if (Mirf.dataReady()) {
        Mirf.getData((byte*)&ct);
        Serial.print("Got data: -- ");
        char buff[64] = {0};
        sprintf(buff, "Joy Tick rx: %d, ry: %d, rz: %d\nbrake: %s",ct.rx, ct.ry, ct.rz, (ct.brake ? "YES" : "NO"));
        Serial.println(buff);
        controlSteeringEngine(ct.rx);
        controlSteeringEngine(ct.ry);
        controlBrakeSystem(ct.state);
    }
}
