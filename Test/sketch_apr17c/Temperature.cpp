#include "Temperature.h"

Temperature::Temperature(uint8_t pin, uint8_t type) : DHT(pin,type) {
    this->pin = pin;
    this->type = type;
    
}

