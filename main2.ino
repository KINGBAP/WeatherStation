#include <Arduino.h>
#include "MainStation.h"

MainStation mainStation;

void setup() {
  mainStation.setup();
}

void loop() {
  mainStation.loop();
}
