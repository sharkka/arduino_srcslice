/**
 * test board
 * anyz
 */

int testled = 13;
int timespan = 500;

void setup() {
    pinMode(testled, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    delay(timespan);
    digitalWrite(testled, HIGH);
    delay(timespan);
    digitalWrite(testled, LOW);
    Serial.println("buildin led test...");
}
