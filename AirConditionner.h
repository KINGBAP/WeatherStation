#ifndef AIR_CONDITIONNER_H
#define AIR_CONDITIONNER_H


#include <Servo.h>
#include "Hardware.h"

class AirConditionner : public Hardware {
  private:
    Servo monServo;
    int seuil=21;

  public:
    AirConditionner(int pin);
    void begin();
    void turnOn();
    void turnOff();
    int getSeuil();
    void setSeuil();
};

#endif // AIR_CONDITIONNER_H
