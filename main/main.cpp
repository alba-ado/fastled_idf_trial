#include <Arduino.h>

extern "C" void app_main() {

    while(true) {
        Serial.println("Hello World!");
        delay(1000);
    }

}