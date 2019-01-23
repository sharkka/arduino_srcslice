
int motorPwmP = 10;
int motorPwmN = 6;
int positive = 8;
int negative = 7;
int minVolt = 20;
int maxVolt = 300;

bool forward = true;

void setup() {
    pinMode(motorPwmP, OUTPUT);
    pinMode(motorPwmN, OUTPUT);
    pinMode(positive, OUTPUT);
    pinMode(negative, OUTPUT);
    Serial.begin(9600);

    digitalWrite(positive, HIGH);
    digitalWrite(negative, HIGH);
}

void loop() {
    for (int i = minVolt; i < maxVolt; ++i) {
        if (forward)
            analogWrite(motorPwmN, map(i, 0, 1023, 0, 255));
        else
            analogWrite(motorPwmP, map(i, 0, 1023, 0, 255));
        
        delay(10);
        Serial.print("pwm puls: ");
        Serial.println(i);
    }
    for (int i = maxVolt; i < minVolt; --i) {
        if (forward)
            analogWrite(motorPwmN, map(i, 0, 1023, 0, 255));
        else
            analogWrite(motorPwmP, map(i, 0, 1023, 0, 255));
        
        delay(10);
        Serial.print("pwm puls: ");
        Serial.println(i);
    }
}
