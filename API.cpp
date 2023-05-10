#include "API.h"
#include <WiFi.h>

API::API(const char* ssid, const char* password, const char* apiKey)
    : m_ssid(ssid), m_password(password), m_apiKey(apiKey), m_isConnected(false) {}

void API::connectWiFi() {
    WiFi.begin(m_ssid, m_password);
    Serial.print("Connecting to ");
    Serial.println(m_ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    m_isConnected = true;
}
void API::connectToOpenWeatherMap() {
  if (!m_connectedToWifi) {
    Serial.println("Error: not connected to WiFi.");
    return;
  }

  HTTPClient http;

  String url = "http://api.openweathermap.org/data/2.5/weather?q=Paris&appid=" + String(m_openWeatherMapApiKey);
  
  Serial.println("Connecting to OpenWeatherMap...");

  http.begin(url);

  int httpResponseCode = http.GET();

  if (httpResponseCode == 200) {
    Serial.println("Connected to OpenWeatherMap!");
    m_connectedToOpenWeatherMap = true;
  } else {
    Serial.println("Error: failed to connect to OpenWeatherMap. HTTP response code: " + String(httpResponseCode));
    m_connectedToOpenWeatherMap = false;
  }

  http.end();
}

bool API::isConnected() {
  return m_connectedToWifi && m_connectedToOpenWeatherMap;
}

