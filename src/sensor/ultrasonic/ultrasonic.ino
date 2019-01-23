
static const int TrigPin = 2; //发出超声波
static const int EchoPin = 3; //收到反射回来的超声波
static float cm; //因为测得的距离是浮点型的

void setup() {
    Serial.begin(9600); //设置波特率
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT);
}

void loop() {
    //低高低电平发一个短时间脉冲去TrigPin
    digitalWrite(TrigPin, LOW);
    // delayMicroseconds在更小的时间内延时准确
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    //通过这里控制超声波的发射
    digitalWrite(TrigPin, LOW);
    //将回波时间换算成cm
    cm = pulseIn(EchoPin, HIGH) / 58.0;
    cm = (int(cm * 100.0)) / 100.0;
    Serial.print("Distance:");
    if (cm> 240 || cm < 3) {
        Serial.print("out of detection range");
    } else {
        Serial.print(cm);
    }
    Serial.print(" cm");
    Serial.println();
    delay(60);
}
