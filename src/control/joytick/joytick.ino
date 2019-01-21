/**
 * Joytick
 * test
 */

int X = A0;
int Y = A1;
int BUTTON = 7;
void setup(void) {
    Serial.begin(9600);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop(void) {
    Serial.print("X = ");
    Serial.print(analogRead(X));
    Serial.print(", ");

    Serial.print("Y = ");
    Serial.print(analogRead(Y));
    Serial.print(", ");

    Serial.print("BUTTON state = ");
    Serial.println(digitalRead(BUTTON));
    delay(30);
}
