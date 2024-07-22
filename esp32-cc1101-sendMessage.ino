#include <ELECHOUSE_CC1101_SRC_DRV.h>

// Funkcia, ktorá inicializuje CC1101
void setup() {
    Serial.begin(9600);
    ELECHOUSE_cc1101.Init();          // Inicializuje CC1101
    ELECHOUSE_cc1101.setMHZ(433.0);   // Nastaví frekvenciu na 433 MHz

    // Nastavenie výkonu vysielača (TX power)
    // Hodnoty výkonu: -30, -20, -15, -10, 0, 5, 7, 10
    // Poznámka: Hodnoty sa môžu líšiť v závislosti od modelu CC1101 a regulácií v krajine.
    // ELECHOUSE_cc1101.setPA(10);    // Nastaví maximálny výkon vysielača
    // Ak nie je táto funkcia volaná, defaultný výkon je stredný (okolo 0-5 dBm, závisí od implementácie)
}

// Funkcia, ktorá posiela správu "Ahoj" každú sekundu
void loop() {
    const char* message = "Ahoj";    // Správa, ktorá sa bude posielať
    ELECHOUSE_cc1101.SendData((byte*)message, strlen(message)); // Posiela správu
    delay(1000);                      // Počká 1 sekundu
}
