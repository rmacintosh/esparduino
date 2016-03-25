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

#include "ESP8266.h"   // library for software uart


/********************************************************************************
*   Project Defines / Constants                                                 *
********************************************************************************/

#define ESP8266_rxPin 				4
#define ESP8266_txPin 				5
#define ESP_BUFFER_SIZE				64						// Bytes
#define ESP_DEFAULT_BAUD 			115200				// Bits per second
#define ESP_CHECK_BUFFER_RATE	3000 					// micro seconds
#define ESP_RESPONSE_TIME			167						// multiplier of above (~1/2 second)

/* 
	Above rate derived from buffer size / bytes per second (baud rate). Gives the time it 
	would take to fill the ESP buffer. Buffer should be checked more frequently than this 
	calculated time. At 115200 bps the buffer fills in 4.44 ms. Check every 3 ms (3000uS)
*/

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

// Definition of ESP serial connection / UART
ESP8266 ESPcomms(ESP8266_rxPin, ESP8266_txPin);

/********************************************************************************
*   Program                                                                     *
********************************************************************************/

unsigned long previousMicros, 
							currentMicros, 
							interval, 
							responseTime;

enum ESPstatus { 
									unknown, 
									AT_cmd, 
									RST_cmd, 
									LAP_cmd, 
									JAP_cmd, 
									QAP_cmd, 
									IPSTATUS_cmd 
								};


/******************** Arduino runs this once at powerup/reset ********************/


void setup() {

  currentMicros = previousMicros = micros();	// Get initial timestamp
  interval = ESP_CHECK_BUFFER_RATE;						// Max time before checking serial buffer in uS
  responseTime = 0;														// Time to wait for ESP to respond to AT command
  ESPstatus state_of_ESP = unknown;

  ESP8266.begin(ESP_DEFAULT_BAUD);
  ESP8266.listen();														// not needed unless using other software serial instances
  Serial.begin(57600); 												// For printing status and debug
  
  delay(3000);																// Delay before kicking things off
  
} // end setup


/******************** Arduino will loop on this code forever ********************/


void loop() {

	// Grab current time
  currentMicros = micros();

  // Try to get out of unknown state by sending a reset to ESP module
  if(state_of_ESP == unknown) {
  	ESP8266.print("AT+RST\r\n");
  	state_of_ESP = RST_cmd;
  }

	// Use state machine to get ESP module ready to send or receive data  
  switch(state_of_ESP) {
  
  	case RST_cmd:				// Last command sent to ESP module was a reset
    	ESP8266.print("AT\r\n");
    	break;
    
    default:
    	break;
  }

  // check if "interval" time has passed (4 milliseconds)
  if (((unsigned long)(currentMicros - previousMicros) >= interval) || (ESP8266.overflow()) {
  
    // Check our serial buffer before it overflows!
  	if(ESP8266.available() > 0) {

  	}
    
    // save the "current" time
    previousMicros = micros();
  }

} // end loop
