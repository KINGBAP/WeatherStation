#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <DHT.h>
#include "Sensor.h"

class TempSensor : public Sensor {
  private:
    DHT* dht;

  public:
    TempSensor(int pin, int type = DHT11);
    void begin();
    int read(float* data);
    void printTemperatureAndHumidity();
};

#endif // TEMP_SENSOR_H
