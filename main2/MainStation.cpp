#include "MainStation.h"
#include <Arduino.h>

MainStation::MainStation() : tempSensor(D3, DHT11), airSensor(A0), screen(), airConditionner(D5),
                             date(0), temperature(0), humidity(0), airQuality(0),button(D7) {} // instanciation des objets Hardware qui vont interagir avec la station météo

void MainStation::setup() { //appelle de la méthode begin de chaque classe pour le fonctionnement
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

void MainStation::loop() { // boucle de notre station météo
  
  airConditionnerOn = button.read(); // récupère l'état du bouton
  airConditionner.setSeuil(); // récupère une entrée utilisateur sur le moniteur série s'il y en a une
  
  
  if ((millis() - date) >= 2000) { // permet de ne pas capturer les données des capteurs trop souvent, étant donné que ce sont des valeurs qui ne varient pas beaucoup 
    float tempHumVal[2] = {0};
    tempSensor.read(tempHumVal);
    temperature = tempHumVal[1];
    humidity = tempHumVal[0];
    tempSensor.printTemperatureAndHumidity();   
    airQuality = airSensor.read();
    date = millis();
  }
  
  screen.printIndoor(temperature, humidity, airQuality); //affich sur l'écran
  
  if (temperature > airConditionner.getSeuil() && airConditionnerOn) { // si la température dépasse le seuil fixé et que le bouton n'a pas été préssé, on allume la clim
    airConditionner.turnOn();
  }
  else {
    airConditionner.turnOff();
  }
}
