#include "MainStation.h"
#include <Arduino.h>

MainStation::MainStation() : tempSensor(D3, DHT11), airSensor(A0), screen(), airConditionner(D5),
                             date(0), temperature(0), humidity(0), airQuality(0),button(D7) {}

void MainStation::setup() {
  Serial.begin(9600);
  while (!Serial);
  airSensor.begin();
  tempSensor.begin();
  screen.begin();
  airConditionner.begin();
  button.begin();

  date = millis();

  float tempHumVal[2] = {0};
  tempSensor.read(tempHumVal);
  temperature = tempHumVal[1];
  humidity = tempHumVal[0];
  tempSensor.printTemperatureAndHumidity();   
  airQuality = airSensor.read();
}

void MainStation::loop() {
  
  airConditionnerOn = button.read();
  airConditionner.setSeuil();
  
  
  if ((millis() - date) >= 2000) {
    float tempHumVal[2] = {0};
    tempSensor.read(tempHumVal);
    temperature = tempHumVal[1];
    humidity = tempHumVal[0];
    tempSensor.printTemperatureAndHumidity();   
    airQuality = airSensor.read();
    date = millis();
  }
  
  screen.printIndoor(temperature, humidity, airQuality);
  
  if (temperature > airConditionner.getSeuil() && airConditionnerOn) {
    airConditionner.turnOn();
  }
  else {
    airConditionner.turnOff();
  }
}
