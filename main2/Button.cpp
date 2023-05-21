#include "Button.h"

Button::Button(int Pin) : Sensor(Pin) {
  pin=Pin;
}

void Button::begin() {
  pinMode(pin, INPUT);
}

bool Button::read() {

  if (digitalRead(pin) == HIGH) {
    airConditionnerOn = !airConditionnerOn;
    Serial.println("Button changed");
    
  }
  return airConditionnerOn;
}
