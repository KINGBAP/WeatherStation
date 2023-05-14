#ifndef BUTTON_H
#define BUTTON_H

#include "Sensor.h"
#include "Arduino.h"

class Button : public Sensor {
  public:
    Button(int pin);
    void begin();
    bool read();
  private:
    bool airConditionnerOn = true;
};

#endif // BUTTON_H
