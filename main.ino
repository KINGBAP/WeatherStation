#include "TempSensor.h"
#include "AirSensor.h"
#include "Screen.h"
 #include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include "API.h"

const char* ssid = "SFR_F5AF";
const char* password = "8vxzu3p1js8tz57h1yph";

//API api("SFR_F5AF", "8vxzu3p1js8tz57h1yph", "3f881903eb950a4880a26c09beea8bef", "paris,fr");
API api("SFR_F5AF", "8vxzu3p1js8tz57h1yph","3f881903eb950a4880a26c09beea8bef");

AirSensor airSensor(A0);
Screen screen;

TempSensor TempSensor(D3, DHT11);
float temp_hum_val[2] = {0};

void setup() {
   Serial.begin(9600);
    while (!Serial);
    
    Serial.println("Waiting sensor to init...");
    airSensor.begin();
    TempSensor.begin();
    screen.begin();

    api.connectWiFi();
  
}

void loop() {

    
  

    TempSensor.readTemperatureAndHumidity(temp_hum_val);
    float temperature = temp_hum_val[1];
    float humidity = temp_hum_val[0];
    TempSensor.printTemperatureAndHumidity();   
    airSensor.getAirQuality();
    screen.printTemperatureAndHumidity(temperature,humidity);

   
     delay(5000);
}
