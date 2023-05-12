#include "TempSensor.h"
#include "AirSensor.h"
#include "Screen.h"
 #include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
//#include "API.h"
#include "AirConditionner.h"

const char* ssid = "SFR_F5AF";
const char* password = "8vxzu3p1js8tz57h1yph";


//API api("Alfredo", "cestmoiwesh","3f881903eb950a4880a26c09beea8bef");

AirSensor airSensor(A0);
Screen screen;
AirConditionner airConditionner(D5);

TempSensor TempSensor(D3, DHT11);
float temp_hum_val[2] = {0};
unsigned long date;
float temperature;
float humidity;
int airQuality;
const int buttonPin = D7;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
bool airConditionnerOn = true;


void setup() {
    pinMode(buttonPin, INPUT);
   Serial.begin(9600);
    while (!Serial);

    Serial.println("Waiting sensor to init...");
    airSensor.begin();
    TempSensor.begin();
    screen.begin();
    airConditionner.begin();

    //api.connectWiFi();
    date = millis();

    TempSensor.readTemperatureAndHumidity(temp_hum_val);
    temperature = temp_hum_val[1];
    humidity = temp_hum_val[0];
    TempSensor.printTemperatureAndHumidity();   
    airQuality = airSensor.getAirQuality();
}

void loop() {

     buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed.
    // if it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
        // turn LED on:
        airConditionnerOn = !airConditionnerOn;
        Serial.println("Button changed");
    }
  
    if ((millis() - date) >= 2000) {
    TempSensor.readTemperatureAndHumidity(temp_hum_val);
    temperature = temp_hum_val[1];
    humidity = temp_hum_val[0];
    TempSensor.printTemperatureAndHumidity();   
    airQuality = airSensor.getAirQuality();
    date = millis();
    }
    screen.printTemperatureAndHumidity(temperature,humidity,airQuality);
    if(temperature > 24 and airConditionnerOn) {
        airConditionner.turnOn();
    }
    else {
      airConditionner.turnOff();
    }

   
    // delay(5000);
}
