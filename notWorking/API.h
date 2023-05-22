#ifndef API_H
#define API_H

#include <WiFi.h>

class API {
public:
    API(const char* ssid, const char* password, const char* apiKey);
    void connectWiFi();
//    void connectAPI();
//    bool isConnected();
    
private:
    const char* ssid;
    const char* password;
    const char* apiKey;
    bool isConnected;
};

#endif //API_H
