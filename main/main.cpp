//IDF Libraries////////////////////////////////////////////////////////////////////////////////////
#include <freertos/FreeRTOS.h>
#include <esp_system.h>
#include <esp_err.h>
#include <esp_event.h>
#include <nvs_flash.h>
#include <esp_adc_cal.h>
#include <esp_app_desc.h>
#include <driver/adc.h>
#include <esp_random.h>

//Arduino Libraries////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <FS.h>
#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <SD_MMC.h>

//Board Configuration//////////////////////////////////////////////////////////////////////////////
#include "BoardDefinitions.h"

//Custom Libraries/////////////////////////////////////////////////////////////////////////////////
//#include <TFT_eSPI.h>
#include <Arduino.h>

//TFT_eSPI Display = TFT_eSPI();

void hardwareInit() {
    pinMode(PIN_ESP_BOOT, INPUT);

    pinMode(PIN_LCD_D0, OUTPUT);
    pinMode(PIN_LCD_D1, OUTPUT);
    pinMode(PIN_LCD_D2, OUTPUT);
    pinMode(PIN_LCD_D3, OUTPUT);
    pinMode(PIN_LCD_D4, OUTPUT);
    pinMode(PIN_LCD_D5, OUTPUT);
    pinMode(PIN_LCD_D6, OUTPUT);
    pinMode(PIN_LCD_D7, OUTPUT);

    pinMode(PIN_LCD_RST, OUTPUT);
    pinMode(PIN_LCD_DC, OUTPUT);
    pinMode(PIN_LCD_WR, OUTPUT);
    pinMode(PIN_LCD_RD, OUTPUT);

    pinMode(PIN_RFID_RST, OUTPUT);
    pinMode(PIN_RFID_CS, OUTPUT);
    pinMode(PIN_FRAM_CS, OUTPUT);

    pinMode(PIN_TICKET_IN, INPUT);
    pinMode(PIN_TICKET_OUT, OUTPUT);
    pinMode(PIN_TICKET_CNT, OUTPUT);

    pinMode(PIN_COIN_TRIGGER, OUTPUT);
    pinMode(PIN_BUZZER_SIGNAL, OUTPUT);
    pinMode(PIN_RGB_DATA, OUTPUT);

    pinMode(PIN_VOLTAGE_SENSE, INPUT);

    initArduino();
    srand(esp_random());

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    //Start the communication devices
    Serial.begin(SERIAL_BAUD_RATE);
    SPI.begin(PIN_SPI_SCK, PIN_SPI_MISO, PIN_SPI_MOSI);
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL, I2C_FREQUENCY);
}

extern "C" void app_main() {

    hardwareInit();

    //Display.init();
	//Display.setRotation(2);
	//Display.fillScreen(TFT_BLACK);

	//Display.drawCentreString("Hello World!", 160, 220, 4);
}