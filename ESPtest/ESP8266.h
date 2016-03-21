#ifndef ESP8266_H_
#define ESP8266_H_

class ESP8266 : public SoftwareSerial {
  
  public:

    // Constructors
    ESP8266(unsigned int pinESPrx, unsigned int pinESPtx);

    // Member functions
    void    setwifi_password(const char password[]);
    void    setwifi_ssid(const char ssid[]);
    String  getwifi_ssid(void);
    bool    checkwifi_password(const char wifi_password[]);
  
  private:

    // Data members
    unsigned int  pinESPrx;
    unsigned int  pinESPtx;
    String        wifi_password;
    String        wifi_ssid;

};

#endif
