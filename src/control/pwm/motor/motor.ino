
int motorPwm = 10;

void setup() {

    pinMode(motorPwm, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for (int i = 300; i < 1000; ++i) {
        analogWrite(motorPwm, map(i, 0, 1023, 0, 255));
        delay(10);
        Serial.print("pwm puls: ");
        Serial.println(i);
    }
    for (int i = 1000; i < 300; --i) {
        analogWrite(motorPwm, map(i, 0, 1023, 0, 255));
        delay(10);
        Serial.print("pwm puls: ");
        Serial.println(i);
    }
}