#include <ELECHOUSE_CC1101_SRC_DRV.h>

// Define SPI pins (ensure these match your actual connections)
#define CC1101_CS    5   // Chip Select (CS) pin
#define CC1101_SCK   18  // Serial Clock (SCK) pin
#define CC1101_MISO  19  // Master In Slave Out (MISO) pin
#define CC1101_MOSI  23  // Master Out Slave In (MOSI) pin

void setup() {
    Serial.begin(9600);
    
    // Initialize SPI communication with defined pins
    // SPI.begin(CC1101_SCK, CC1101_MISO, CC1101_MOSI, CC1101_CS);

    // Initialize the CC1101 module
    ELECHOUSE_cc1101.Init();
    ELECHOUSE_cc1101.setMHZ(433.0);   // Set frequency to 433 MHz
    ELECHOUSE_cc1101.setPA(5);        // Set transmit power level

    // Configure the module for receiving data
    ELECHOUSE_cc1101.setRX();         // Set CC1101 to receive mode
    Serial.println("CC1101 initialized and set to receive mode.");
}

void loop() {
    byte data[64];  // Buffer to store received data
    byte length = sizeof(data);

    // Check if any data is available
    if (ELECHOUSE_cc1101.ReceiveData(data, &length)) {
        Serial.print("Received message: ");
        for (byte i = 0; i < length; i++) {
            Serial.print((char)data[i]);
        }
        Serial.println();
    }

    delay(100);  // Small delay to avoid excessive Serial output
}
