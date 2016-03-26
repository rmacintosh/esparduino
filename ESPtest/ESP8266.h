#ifndef ESP8266_H_
#define ESP8266_H_

#include <SoftwareSerial.h>   // This class will derive from the softwareserial class

class ESP8266 : public SoftwareSerial {
  
  public:

    // Constructors
    ESP8266(unsigned int pinESPrx, unsigned int pinESPtx);
    ESP8266(unsigned int pinESPrx, unsigned int pinESPtx, const char ssid[], const char password[]);

    // Destructor
    ~ESP8266();
  
    // Member functions
    void    setwifi_password	(const char password[]);
    void    setwifi_ssid			(const char ssid[]);
    String  getwifi_ssid			(void);
    bool    checkwifi_password(const char wifi_password[]);
  
  private:

    // Member functions
    void initESP8266(unsigned int pinESPrx, unsigned int pinESPtx, const char ssid[], const char password[]);

    // Data members
    unsigned int  pinESPrx;
    unsigned int  pinESPtx;
    String        wifi_password;
    String        wifi_ssid;

};

#endif
