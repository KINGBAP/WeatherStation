#ifndef API_H
#define API_H

#include <WiFi.h>

class API {
public:
    API(const char* ssid, const char* password, const char* apiKey);
    void connectWiFi();
    void connectAPI();
    bool isConnected();
    
private:
    const char* m_ssid;
    const char* m_password;
    const char* m_apiKey;
    bool m_isConnected;
};

#endif //API_H
