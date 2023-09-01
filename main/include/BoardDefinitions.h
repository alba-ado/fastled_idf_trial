#ifndef __OCM_HARDWARE_DEFINITIONS__
#define __OCM_HARDWARE_DEFINITIONS__

//PCB Pin Configurations///////////////////////////////////////////////////////////////////////////
#define PIN_ESP_BOOT            0

#define PIN_LCD_D0              15
#define PIN_LCD_D1              16
#define PIN_LCD_D2              17
#define PIN_LCD_D3              18
#define PIN_LCD_D4              12
#define PIN_LCD_D5              11
#define PIN_LCD_D6              10
#define PIN_LCD_D7              9

#define PIN_LCD_RST             4
#define PIN_LCD_DC              5
#define PIN_LCD_WR              6
#define PIN_LCD_RD              7
#define PIN_LCD_CS              PIN_I2C_SCL     //Manually configured with jumpers CSS(CS to SCL) and CSG(CS to GND)

#define PIN_SD_DATA0            39
#define PIN_SD_DATA1            40
#define PIN_SD_DATA2            41
#define PIN_SD_DATA3            42
#define PIN_SD_CLK              47
#define PIN_SD_CMD              48

#define PIN_I2C_SDA             20
#define PIN_I2C_SCL             19

#define PIN_SPI_MOSI            35
#define PIN_SPI_MISO            37
#define PIN_SPI_SCK             36

#define PIN_RFID_RST            13
#define PIN_RFID_CS             14
#define PIN_FRAM_CS             21

#define PIN_TICKET_IN           1
#define PIN_TICKET_OUT          2
#define PIN_TICKET_CNT          46

#define PIN_COIN_TRIGGER        38
#define PIN_BUZZER_SIGNAL       45
#define PIN_RGB_DATA            3

#define PIN_VOLTAGE_SENSE       8

#define PIN_JTAG_TDI            PIN_SD_DATA2
#define PIN_JTAG_TDO            PIN_SD_DATA1
#define PIN_JTAG_TMS            PIN_SD_DATA3
#define PIN_JTAG_TCK            PIN_SD_DATA0

//Communication Settings///////////////////////////////////////////////////////////////////////////
#define SERIAL_BAUD_RATE        115200UL    //Bauds - Serial Port Speed
#define SPI_FREQUENCY           10000000UL  //Hertz - SPI Speed
#define I2C_FREQUENCY           20000UL     //Hertz - I2C Speed

//Onboard Devices//////////////////////////////////////////////////////////////////////////////////
#define EEPROM_SIZE             4096        //Bytes

#define BUZZER_LEDC_CHANNEL     3           //First free channel after the channel 2 (which doesn't work)
#define BUZZER_BEEP_FREQUENCY   2700        //Selected because it is the strongest oscillation frequency

#define RGB_FRAME_LED_COUNT     16          //LEDs
#define RGB_FRAME_CHIPSET       WS2812B     //Chip Name
#define RGB_FRAME_COLOR_ORDER   GRB         //Byte order which the colors are arranged

//Voltage Divider and ADC Parameters///////////////////////////////////////////////////////////////
#define PCB_VOLTAGE_DIVIDER_COEFFICIENT     4.63636363636364    //Volts per measured Voltage
#define PCB_INPUT_DIODE_FORWARD_VOLTAGE     0.2940              //Volts (Measured value)

#define VOLTAGE_SENSE_ADC_CHANNEL           ADC1_CHANNEL_7
#define VOLTAGE_SENSE_ADC_ATTENUATION       ADC_ATTEN_DB_11
#define VOLTAGE_SENSE_ADC_RESOLUTION        ADC_WIDTH_BIT_12
#define VOLTAGE_SENSE_ADC_SAMPLE_COUNT      100                 //Samples to measure a voltage

//Resistor Divider: R1->12K, R2->3.3K
//Voltage Division: ( ( 12 + 3.3 ) / 3.3 ) = 4.63636363636364

//Use esp_adc_cal_raw_to_voltage to get the calibrated ADC output:
//https://docs.espressif.com/projects/esp-idf/en/v4.4/esp32s3/api-reference/peripherals/adc.html
///////////////////////////////////////////////////////////////////////////////////////////////////


#endif