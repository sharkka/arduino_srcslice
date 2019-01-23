
int motorPwm = 10;
int minVolt = 210;
int maxVolt = 1000;

void setup() {

    pinMode(motorPwm, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for (int i = minVolt; i < maxVolt; ++i) {
        analogWrite(motorPwm, map(i, 0, 1023, 0, 255));
        delay(10);
        Serial.print("pwm puls: ");
        Serial.println(i);
    }
    for (int i = maxVolt; i < minVolt; --i) {
        analogWrite(motorPwm, map(i, 0, 1023, 0, 255));
        delay(10);
        Serial.print("pwm puls: ");
        Serial.println(i);
    }
}
