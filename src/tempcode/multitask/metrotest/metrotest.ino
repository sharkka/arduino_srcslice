
#include <Metro.h>
#include "utils.h"
 
const int blinkPin1 = 13; //定义 LED 引脚13
const int blinkPin2 = 12; //定义 LED 引脚12
 
boolean blink1State = false;   //定义 blink1State 为false状态
boolean blink2State = false;   //定义 blink2State 为false状态
 
Metro blink1Metro = Metro(100);   //把 blink1Metro 实例化 Metro 对象 ，并设置间隔时间
Metro blink2Metro = Metro(0);     //把 blink2Metro 实例化 Metro 对象 ，并设置间隔时间

void setup() {
    pinMode(blinkPin1 , OUTPUT);   //设置blinkPin1 为输出模式
    pinMode(blinkPin2 , OUTPUT);   //设置blinkPin2 为输出模式
}

void loop() {
    if (blink1Metro.check()) {  //检查blink1Metro间隔(我的理解是计时器每隔100毫秒就会返回true，就执行以下程序)
        blink1State = !blink1State;   //反转blink1State的逻辑真或假（false or true）
        digitalWrite(blinkPin1, blink1State); //数字引脚，设置为blink1State的状态
    }
    if (blink2Metro.check()) {
        blink2State = !blink2State;
        digitalWrite(blinkPin2, blink2State);
    }
}
