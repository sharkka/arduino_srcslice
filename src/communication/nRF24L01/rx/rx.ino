/**
 *  Mirf github: https://github.com/E-elektronic/Mirf.git
 */

#include <SPI.h>
#include "Mirf.h"
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

int buildinLed = 17;

void blinkLed(int k) {
    if (k%2)
        digitalWrite(buildinLed, HIGH);
    else
        digitalWrite(buildinLed, LOW);
}

void setup() {
    Serial.begin(9600);
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    Mirf.setRADDR((byte*)"FGHIJ"); //设置自己的地址（接收端地址），使用5个字符
    Mirf.payload = sizeof(joytick_ctrl_t);   
    Mirf.channel = 90;   //设置使用的信道
    Mirf.config(); 
    Serial.println("Listening...");  //开始监听接收到的数据
}

void loop() {
    if (Mirf.dataReady()) {  //当接收到程序，便从串口输出接收到的数据
        Mirf.getData((byte*)&ct);
        Serial.print("Got data: -- ");
        char buff[64] = {0};
        sprintf(buff, "Joy Tick rx: %d, ry: %d, rz: %d\nbrake: %s",ct.rx, ct.ry, ct.rz, (ct.state ? "NO" : "YES"));
        Serial.println(buff);
        blinkLed(ct.rx);
    }
}
