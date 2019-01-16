#include <Servo.h>
#define PIN_SERVO 10  //舵机信号控制引脚

#define STOP      0
#define FORWARD   1
#define BACKWARD  2
#define TURNLEFT  3
#define TURNRIGHT 4
// 电机
int xyouIN1 = 4; // 下L298
int xyouIN2 = 18;
int xzuoIN3 = 12;
int xzuoIN4 = 13;
int xyoupwmENA = 3;
int xzuopwmENB = 5;

int syouIN1 = 14; // 上L298
int syouIN2 = 15;
int szuoIN3 = 16;
int szuoIN4 = 17;
int syoupwmENA = 6;
int szuopwmENB = 11;

// 超声波
const int TrigPin = 7;
const int EchoPin = 8;
float cm;
// 舵机
Servo myservo;

void setup() {
    // 电机
    pinMode(xyouIN1, OUTPUT);
    pinMode(xyouIN2, OUTPUT);
    pinMode(xzuoIN3, OUTPUT);
    pinMode(xzuoIN4, OUTPUT);
    pinMode(xyoupwmENA, OUTPUT);
    pinMode(xzuopwmENB, OUTPUT);

    pinMode(syouIN1, OUTPUT);
    pinMode(syouIN2, OUTPUT);
    pinMode(szuoIN3, OUTPUT);
    pinMode(szuoIN4, OUTPUT);
    pinMode(syoupwmENA, OUTPUT);
    pinMode(szuopwmENB, OUTPUT);
    /****************舵机******************/
    myservo.attach(PIN_SERVO);  //舵机初始化

    /*************************************/
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    Serial.begin(9600);
    //myservo.write(82);//舵机向前
}

void motorRun(int cmd,int value) {
    analogWrite(xyoupwmENA, value);  //设置PWM输出，即设置速度
    analogWrite(xzuopwmENB, value);
    analogWrite(syoupwmENA, value);  //设置PWM输出，即设置速度
    analogWrite(szuopwmENB, value);
    switch(cmd) {
    case FORWARD: //前进
        digitalWrite(xyouIN1, HIGH);
        digitalWrite(xzuoIN3, HIGH);
        digitalWrite(syouIN1, HIGH);
        digitalWrite(szuoIN3, HIGH);
        digitalWrite(xyouIN2, LOW);
        digitalWrite(xzuoIN4, LOW);
        digitalWrite(syouIN2, LOW);
        digitalWrite(szuoIN4, LOW);
        break;
    case BACKWARD: //后退
        digitalWrite(xyouIN2, HIGH);
        digitalWrite(xzuoIN4, HIGH);
        digitalWrite(syouIN2, HIGH);
        digitalWrite(szuoIN4, HIGH);
        digitalWrite(xyouIN1, LOW);
        digitalWrite(xzuoIN3, LOW);
        digitalWrite(syouIN1, LOW);
        digitalWrite(szuoIN3, LOW);
       break;
    case TURNLEFT: //左转
        digitalWrite(xyouIN1, LOW);
        digitalWrite(xzuoIN3, LOW);
        digitalWrite(syouIN1, LOW);
        digitalWrite(szuoIN3, LOW);
        digitalWrite(xyouIN2, LOW);
        digitalWrite(xzuoIN4, HIGH);
        digitalWrite(syouIN2, LOW);
        digitalWrite(szuoIN4, HIGH);
        break;
    case TURNRIGHT: //右转
        digitalWrite(xyouIN1, LOW);
        digitalWrite(xzuoIN3, LOW);
        digitalWrite(syouIN1, LOW);
        digitalWrite(szuoIN3, LOW);
        digitalWrite(xyouIN2, HIGH);
        digitalWrite(xzuoIN4, LOW);
        digitalWrite(syouIN2, HIGH);
        digitalWrite(szuoIN4, LOW);
        break;
    default: //停止
        digitalWrite(xyouIN1, LOW);
        digitalWrite(xzuoIN3, LOW);
        digitalWrite(syouIN1, LOW);
        digitalWrite(szuoIN3, LOW);
        digitalWrite(xyouIN2, LOW);
        digitalWrite(xzuoIN4, LOW);
        digitalWrite(syouIN2, LOW);
        digitalWrite(szuoIN4, LOW);
    }
}

void loop() {
    ceju();
    int pos;
    int dis[3]; //距离
    motorRun(FORWARD, 150);
    myservo.write(82); //舵机向中间
    dis[1] = ceju();
    Serial.println(dis[1]);

    if (dis[1] < 30) {
        motorRun(STOP, 0);
        for (pos = 82; pos <= 127; pos += 1) {
            myservo.write(pos);
            delay(15);
        }
        dis[2] = ceju(); //左边
        for (pos = 127; pos >= 37; pos -= 1) {
            myservo.write(pos);
            delay(15);
            if (pos == 82)
                dis[1] = ceju(); //中间
            }
        dis[0] = ceju(); //右边
        for (pos = 37; pos <= 82; pos += 1) {
            myservo.write(pos);
            delay(15);
        }
        //右边距离障碍的距离比左边近
        if (dis[0] < dis[2]) {
            motorRun(TURNLEFT, 200);
            delay(500);
        } else {
            motorRun(TURNRIGHT, 200);
            delay(500);
        }
    }
}

/*************超声波代码*******************/
int ceju() {
    digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);

    cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm
    cm = (int(cm * 100.0)) / 100.0; //保留两位小数
    if (cm >= 50) {
        //如果距离小于50厘米返回数据
        return 50;
    } else {
        //如果距离小于50厘米小灯熄灭
        return cm;
    }
}
