#ifndef TEMPERATURE_H 
#define TEMPERATURE_H

#include "DHT.h"

class Temperature : public DHT {
    private:
    uint8_t pin, type;

    public:
    
    Temperature(uint8_t pin, uint8_t type);
    float convertCtoK(float c);


};

#endif