# esp32 cc1101 test codes
# INFO (READ IT PLS)
- "jammerCode "WORKS" But u need to sometimes PLUG GDO0 to D2 & GDO2 to D4 !
- Then plug USB to esp32 and to PC
- Then unplug esp32 from PC and UNPLUG GDO0 & GDO2 from esp32 Pins !
- And Reconnect esp32 to pc (without connected GDO0 & GDO2 pins)
- Idk how it is possible BUT IT SOMEHOW RESET some config
- Then IT SHOULD WORKS LIKE NORMAL
## Connection
- CC1101 -> ESP32
- VCC -> 3.3V
- GND -> GND
- SCK -> GPIO18
- MISO -> GPIO19
- MOSI -> GPIO23
- CSN -> GPIO5
## Tested 06.08.2024 et mai houm (it works and sucessfuly sent message)
