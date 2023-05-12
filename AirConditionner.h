#ifndef AIR_CONDITIONNER_H
#define AIR_CONDITIONNER_H


#include <Servo.h>

class AirConditionner {
  private:
    int pin;
    Servo monServo;
   // boolean isOn;

  public:
    AirConditionner(int pin);
    void begin();
    void turnOn();
    void turnOff();
    //boolean getIsOn();
};

#endif // AIR_CONDITIONNER_H