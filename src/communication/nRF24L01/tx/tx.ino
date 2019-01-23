/**
 *  Mirf github: https://github.com/E-elektronic/Mirf.git
 */

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

typedef struct _joytick_ctrl_t {
    int rx;
    int ry;
    int rz;
    int state;
    bool brake;
} joytick_ctrl_t;

joytick_ctrl_t ct;

int buildinLed = 6;

void blinkLed(int n) {
    digitalWrite(buildinLed, HIGH);
    delay(n % 30);
    digitalWrite(buildinLed, LOW);
    delay(n % 30);
}

void setup() {
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    Mirf.setRADDR((byte*)"ABCDE"); //设置自己的地址（发送端地址），使用5个字符

    ct.rx = 2;
    ct.ry = 50;
    ct.brake = false;
    Mirf.payload = sizeof(joytick_ctrl_t);
    Mirf.channel = 90;              //设置所用信道
    Mirf.config();
    Serial.begin(9600);
    pinMode(buildinLed, OUTPUT);
}

int rx = 0;
int ry = 0;
int rz = 0;
int ot = 0;

void loop() {
    Mirf.setTADDR((byte*)"FGHIJ");           //设置接收端地址
    //value = random(255);                      //0-255的随机数
    ct.rx = 50.0 * cos(rx++ / 20.0) * sin(ry) + 0.05 * rx;
    ct.ry = 200.0 * sin(ry++ / 18.0);
    ct.rz = 100 * sin(sin(rz++/20.0));
    
    Mirf.send((byte*)&ct);                //发送指令，发送随机数value
    while(Mirf.isSending()) {
        delay(1);         //直到发送成功，退出循环
    }
    blinkLed(rx);
    delay(10);
    Serial.print(ct.rx);
    Serial.print("  , ");
    Serial.print(ct.ry);
    Serial.print("  , ");
    Serial.print(ct.rz);
    Serial.print("  , ");
    Serial.print(ct.state);
    Serial.print("  , ");
    Serial.println("Send success, ");
    //Serial.println(ct);
}
