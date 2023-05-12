#include "AirConditionner.h"

AirConditionner::AirConditionner(int Pin) {
  pin=Pin;
}

void AirConditionner::begin() {
  monServo.attach(pin);
}

void AirConditionner::turnOn() {
    monServo.write(180);  // le bras du servomoteur prend la position de la variable position
    delay(150);  // on attend 15 millisecondes
    monServo.write(0); 
    delay(150);
}

void AirConditionner::turnOff() {
    monServo.write(0);
    
    
}
