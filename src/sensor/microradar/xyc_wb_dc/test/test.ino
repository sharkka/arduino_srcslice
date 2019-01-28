
#include <Servo.h>

int signalOut = 3;
int servctrl = 5;
Servo myservo;


void setup() { 
    pinMode(signalOut, INPUT_PULLUP);
    myservo.attach(servctrl);
    Serial.begin(9600);
}

void loop() {
    int ttl = digitalRead(signalOut);
    delay(10);
    Serial.println(ttl);
    if (HIGH == ttl) {
        for (int i = 0; i < 90; i ++) {
            myservo.write(i);
            delay (50);
        }
    }
}
