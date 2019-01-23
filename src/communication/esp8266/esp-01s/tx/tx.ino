#include <SoftwareSerial.h>

int rxPin = 10;
int txPin = 11;


SoftwareSerial mySerial(rxPin, txPin); // RX, TX 配置10、11为软串口

void setup() {
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("hardware serial!");
  mySerial.begin(115200);
  mySerial.println("software serial!");
}

void loop() {
  delay(1000);
  if (mySerial.available()) {
    Serial.println(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.println(Serial.read());
  }
}
