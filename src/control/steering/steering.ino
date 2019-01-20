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
    //pinMode(PIN_SERVO, OUTPUT);
    myservo.attach(PIN_SERVO);
    Serial.begin(9600);
}

void loop() {
    Serial.println("running...");
    myservo.write(90);
    delay(900);
    for (int i = 90; i <= 180; i++) {
        myservo.write(i);
        delay(20);
    }
    for (int i = 180; i > 0; i--) {
        myservo.write(i);
        delay(20);
    }
    delay(1000);
    
    //analogWrite(PIN_SERVO, map(800, 0, 1023, 0, 255));
}
