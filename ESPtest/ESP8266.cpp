#include <SoftwareSerial.h>   // This class will derive from the softwareserial class
#include "ESP8266.h"

ESP8266::ESP8266(unsigned int pinESPrx, unsigned int pinESPtx) 
: SoftwareSerial(pinESPrx,pinESPtx) 
{
  initESP8266(pinESPrx, pinESPtx, "", "");
}

ESP8266::ESP8266(unsigned int pinESPrx, unsigned int pinESPtx, const char ssid[], const char password[]) 
: SoftwareSerial(pinESPrx,pinESPtx) 
{
  initESP8266(pinESPrx, pinESPtx, ssid, password);
}

void ESP8266::initESP8266(unsigned int pinESPrx, unsigned int pinESPtx, const char ssid[], const char password[]) {
  this->pinESPrx = pinESPrx;
  this->pinESPtx = pinESPtx;
  this->wifi_password = String(password);
  this->wifi_ssid = String(ssid);  
}

void ESP8266::setwifi_password(const char password[]) { 
  this->wifi_password = String(password);
}

void ESP8266::setwifi_ssid(const char ssid[]) { 
  this->wifi_ssid = String(ssid); 
}

String ESP8266::getwifi_ssid(void) { 
  return this->wifi_ssid; 
}

bool ESP8266::checkwifi_password(const char wifi_password[]) { 
  String test(wifi_password);
  if(this->wifi_password.equals(wifi_password) == 0)
    return true;
  else
    return false; 
}
