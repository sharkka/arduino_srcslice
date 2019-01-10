#include <VirtualWire.h>

static int rxDataPin = 12;
static int rxLedPin = 5;
static int bitrate = 4000;

void setup() {
    vw_set_ptt_inverted(true);
    // Required for DR3100
    vw_set_rx_pin(rxDataPin);
    vw_setup(bitrate);
    // Bits per sec
    pinMode(rxLedPin, OUTPUT);
    vw_rx_start();
    // Start the receiver PLL running
} 

void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) {
        ('1' == buf[0]) ?
          digitalWrite(rxLedPin, HIGH) :
          digitalWrite(rxLedPin, LOW);
    }
}
