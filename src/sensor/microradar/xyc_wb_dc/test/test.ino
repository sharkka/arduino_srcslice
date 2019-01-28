

int signalOut = 3;

void setup() {
    pinMode(signalOut, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    int ttl = digitalRead(signalOut);
    delay(10);
    Serial.println(ttl);
}
