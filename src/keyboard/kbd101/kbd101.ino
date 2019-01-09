#include <Keypad.h>
#include "Keyboard.h"
#include <ctype.h>
#include <SPI.h>

const byte ROWS = 6;
const byte COLS = 22;


static byte kb101[6][22] = {
    { 27, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 44, 145, 19 },
    { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 220, 8, 45, 36, 33, 144, 111, 104, 109 },
    { 9, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 46, 35, 34, 103, 104, 105, 107 },
    { 20, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 222, 13, 100, 101, 102 },
    { 16, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 16, 38, 97, 98, 99, 13 },
    { 17, 18, 32, 18, 17, 37, 40, 39, 96, 110 }
};

static byte kb104[6][22] = {
    { 27, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 44, 145, 19 },
    { '`','1','2','3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 220, 8, 45, 36, 33, 144, 111, 104, 109 },
    { 9, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 46, 35, 34, 103, 104, 105, 107 },
    { ' ','a','s','d', 'f', 'g', 'h', 'j', 'k', 'l', ';', 222, 13, 100, 101, 102 },
    { 16, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 16, 38, 97, 98, 99, 13 },
    { 17, 91, 18, 32, 18, 255, 93, 17, 37, 40, 39, 96, 110 }
};

static byte rowPins[6] = { 9, 8, 7, 6, 5, 4 };
static byte colPins[22] = { 44, 43, 42, 41, 40, 39, 38, 37, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12 };

static char* keypadMap = makeKeymap(kb101);

static Keypad keypad = Keypad(keypadMap, rowPins, colPins, 6, 22);

static unsigned long startTime;
static const byte ledPin = 6;

void keyboardEvent(KeypadEvent key);
/**
 * @Method   setup
 * @Brief
 * @DateTime 2019-01-09T11:15:14+0800
 * @Modify   2019-01-09T11:15:14+0800
 * @Author   Anyz
 * @return   void
 */
void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    keypad.addEventListener(keypadEvent);
    keypad.setHoldTime(500);
    Keyboard.begin();
    configPin();
    SPI.begin();
}
/**
 * @Method   configPin
 * @Brief
 * @DateTime 2019-01-09T11:14:28+0800
 * @Modify   2019-01-09T11:14:28+0800
 * @Author   Anyz
 * @return   void
 */
static void configPin() {
    for (int i = 0; i < sizeof(rowPins); ++ i) {
        pinMode(rowPins[i], INPUT);
    }
    for (int j = 0; j < sizeof(colPins); ++ j) {
        pinMode(colPins[j], INPUT);
    }
}
/**
 * @Method   loop
 * @Brief
 * @DateTime 2019-01-09T11:14:32+0800
 * @Modify   2019-01-09T11:14:32+0800
 * @Author   Anyz
 * @return   void
 */
void loop() {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
}
/**
 * @Method   keypadEvent
 * @Brief
 * @DateTime 2019-01-09T11:14:36+0800
 * @Modify   2019-01-09T11:14:36+0800
 * @Author   Anyz
 * @param    KeypadEvent key keyboard ascii code
 * @return   void
 */
static void keypadEvent(KeypadEvent key) {
    switch (keypad.getState()){
    case PRESSED:
        Keyboard.press(key);
        break;
    case RELEASED:
        Keyboard.release(key);
        break;
    case HOLD:
        Keyboard.press(key);
        delay(33);
        Keyboard.release(key);
        break;
    }
}
