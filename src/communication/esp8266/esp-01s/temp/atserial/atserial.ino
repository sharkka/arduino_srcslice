
#include <SoftwareSerial.h>

SoftwareSerial WIFISerial(8, 9); // RX, TX
int buildinLed = 13;

void setup() {
    Serial.begin(9600);
    pinMode(buildinLed, OUTPUT);
    WIFISerial.begin(9600);
    delay(2000);
    WIFISerial.println("AT+RST");
    delay(2000);
    WIFISerial.println("AT+CWMODE=3");
    delay(2000);
    WIFISerial.println("AT+CWJAP=\"jeapedu\",\"python\"");
    delay(3000);
    WIFISerial.println("AT+CIFSR");
    delay(1000);
    WIFISerial.println("AT+CIPMUX=1");
    delay(1000);
    WIFISerial.println("AT+CIPMODE=1");
    delay(1000);
    WIFISerial.println("AT+CIPSTART=\"TCP\",\"192.168.1.6\",6060");
    delay(1000);
    WIFISerial.println("AT+CIPSEND");
    WIFISerial.println("history!");
}
 
void loop() {
    int i = 0;
    //Serial.println("serial output");
    if (WIFISerial.available()) {
        Serial.write(WIFISerial.read());
        //Serial.println("ifwifi serial output");
    }
    //Serial.println("only serial output");
    if (Serial.available()) {
        WIFISerial.write(Serial.read());
        // Serial.println("if serial output");
    }
    for (i = 1; i < 100; i++) {
        WIFISerial.println(i);
        Serial.print("debug, ");
        Serial.println(i);
        //digitalWrite(buildinLed, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);              // wait for a second
        digitalWrite(buildinLed, LOW);    // turn the LED off by making the voltage LOW
        delay(100);              // wait for a second
    }
}
