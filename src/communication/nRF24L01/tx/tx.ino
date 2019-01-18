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
    bool brake;
} joytick_ctrl_t;

joytick_ctrl_t ct;

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
}

void loop() {
    Mirf.setTADDR((byte*)"FGHIJ");           //设置接收端地址
    //value = random(255);                      //0-255的随机数
    Mirf.send((byte*)&ct);                //发送指令，发送随机数value
    while(Mirf.isSending()) {
        delay(1);         //直到发送成功，退出循环
    }
    delay(200);
    Serial.println("Send success, ");
    //Serial.println(ct);
}
