/**
 * @File     steering.ino
 * @Brief
 * @DateTime 2019/1/17 13:09:23
 * @Modify   2019/1/17 13:09:29
 * @Author   Anyz
 */
#include <Servo.h>

#define PIN_SERVO 10
Servo myservo;

void setup() {
    myservo.attach(PIN_SERVO);
}

void loop() {
    myservo.write(0);
    delay(300);
    myservo.write(80);
    delay(300);
    myservo.write(160);
    delay(300);
    myservo.write(80);
    delay(300);
    myservo.write(0);
    delay(300);
}
