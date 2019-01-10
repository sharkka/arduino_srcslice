#include <VirtualWire.h>

static char* controller;
static int txDataPin = 12;
static int txLedPin = 13;
static int bitrate = 4000;
static int keeptime = 2000;

void setup() {
    pinMode(txLedPin, OUTPUT);
    vw_set_ptt_inverted(true);
    vw_set_tx_pin(txDataPin);
    vw_setup(bitrate);
    // speed of data transfer Kbps
} 

void loop() {
    controller = "1" ;
    vw_send((uint8_t*)controller, strlen(controller));
    vw_wait_tx();
    // Wait until the whole message is gone
    digitalWrite(txLedPin, HIGH);
    delay(keeptime);
    controller = "0" ;
    vw_send((uint8_t*)controller, strlen(controller));
    vw_wait_tx();
    // Wait until the whole message is gone
    digitalWrite(txLedPin, LOW);
    delay(keeptime);
}