/*

AT+CIPSTART=0,"TCP","api.thingspeak.com",80
AT+CIPSEND=0,96
GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=TR78MOF25ZJY6691 HTTP/1.0
AT+CIPSEND=0,86
GET https://api.thingspeak.com/update?api_key=YB733YRL09Q71ZZX&field1=395 HTTP/1.0

esptool.py write_flash 0x00000 at/noboot/eagle.flash.bin 0x3e000 at/blank.bin 0x040000 at/noboot/eagle.irom0text.bin 0x7c000 at/esp_init_data_default.bin 0x7e000 at/blank.bin

*/

/********************************************************************************
*   Project Includes                                                            *
********************************************************************************/

#include <SoftwareSerial.h>   // library for software uart


/********************************************************************************
*   Project Defines                                                             *
********************************************************************************/

#define ESP8266_rxPin 4
#define ESP8266_txPin 5

// WiFi SSID and Password definition
const char SSID_ESP[] = "YOUR SSID";
const char SSID_KEY[] = "YOUR PASSWORD";

// HTTP GET request URLs
const char HTTPGET_receive[] = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=TR78MOF25ZJY6691 HTTP/1.0\r\n\r\n";
const char HTTPGET_send[] = "GET https://api.thingspeak.com/update?api_key=YB733YRL09Q71ZZX&field1=395 HTTP/1.0\r\n\r\n";

// WiFi MODES
const char CWMODE_STATION = '1';
const char CWMODE_AP      = '2';
const char CWMODE_BOTH    = '3';

const char CIPMUX_SINGLE  = '0';
const char CIPMUX_MULTI   = '1';

SoftwareSerial ESP8266comms(ESP8266_rxPin, ESP8266_txPin);

/********************************************************************************
*   Project Defines                                                             *
********************************************************************************/

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
