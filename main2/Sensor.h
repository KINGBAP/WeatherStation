#ifndef SENSOR_H
#define SENSOR_H

#include "Hardware.h"

class Sensor : public Hardware {
public:
  Sensor(int pin);
  //virtual int read(float *data)=0;


};

#endif
