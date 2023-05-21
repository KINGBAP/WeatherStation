#ifndef MAINSTATION_H
#define MAINSTATION_H

#include "TempSensor.h"
#include "AirSensor.h"
#include "Screen.h"
#include "AirConditionner.h"
#include "Button.h"

class MainStation {
public:
  MainStation();
  void setup();
  void loop();
  
private:
  TempSensor tempSensor;
  AirSensor airSensor;
  Screen screen;
  AirConditionner airConditionner;
  Button button;
  unsigned long date;
  float temperature;
  float humidity;
  int airQuality;
  bool airConditionnerOn;
  
};

#endif  // MAINSTATION_H
