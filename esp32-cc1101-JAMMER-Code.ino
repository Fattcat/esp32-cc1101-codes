#include <ELECHOUSE_CC1101_SRC_DRV.h>

// Define the SPI pins
#define CC1101_CS    5   // Chip Select (CS) pin
#define CC1101_SCK   18  // Serial Clock (SCK) pin
#define CC1101_MISO  19  // Master In Slave Out (MISO) pin
#define CC1101_MOSI  23  // Master Out Slave In (MOSI) pin

// PRIPOJENIE :
// esp32 --> cc1101
// VCC --> VCC
// GND --> GND
// 5 --> CS
// 18 --> SCK
// 19 --> MISO
// 23 --> MOSI
// A tie GDO0 a GDO2 Piny Nechceli fungovat ked boli pripojene ! uplne sus toto

void setup() {
    Serial.begin(115200);

    // Initialize SPI settings
    //SPI.begin(CC1101_SCK, CC1101_MISO, CC1101_MOSI, CC1101_CS);
    
    // Initialize the CC1101 module
    ELECHOUSE_cc1101.Init();
    
    if (ELECHOUSE_cc1101.getCC1101()) {
        Serial.println("CC1101 initialized successfully");
    } else {
        Serial.println("CC1101 initialization failed. Please check connections.");
        while (1); // Stop here if CC1101 fails to initialize
    }

    // Set frequency to 433 MHz
    ELECHOUSE_cc1101.setMHZ(433.9);
    Serial.println("Frequency set to 433 MHz");

    // Set transmit power level
    ELECHOUSE_cc1101.setPA(10); // Maximum power

    // Set modulation (2-FSK is a common modulation scheme for basic testing)
    ELECHOUSE_cc1101.setModulation(2); // 2-FSK modulation

    // Test transmission with a simple message
    unsigned char test_message[] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA};
    ELECHOUSE_cc1101.SendData(test_message, sizeof(test_message));
    Serial.println("Test message sent.");
}

void loop() {
    // Keep the loop empty as we're focusing on the setup for testing
}
