#include "API.h"
#include <ESP8266WiFi.h>

API::API(const char* ssid, const char* password, const char* apiKey)
    : ssid(ssid), password(password), apiKey(apiKey), isConnected(false) {}

void API::connectWiFi() {
    WiFi.begin(ssid, password);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    isConnected = true;
}
//void API::connectToOpenWeatherMap() {
//  if (!connectedToWifi) {
//    Serial.println("Error: not connected to WiFi.");
//    return;
//  }
//
//  HTTPClient http;
//
//  String url = "http://api.openweathermap.org/data/2.5/weather?q=Paris&appid=" + String(openWeatherMapApiKey);
//  
//  Serial.println("Connecting to OpenWeatherMap...");
//
//  http.begin(url);
//
//  int httpResponseCode = http.GET();
//
//  if (httpResponseCode == 200) {
//    Serial.println("Connected to OpenWeatherMap!");
//    connectedToOpenWeatherMap = true;
//  } else {
//    Serial.println("Error: failed to connect to OpenWeatherMap. HTTP response code: " + String(httpResponseCode));
//    connectedToOpenWeatherMap = false;
//  }
//
//  http.end();
//}
//
//bool API::isConnected() {
//  return connectedToWifi && connectedToOpenWeatherMap;
//}
