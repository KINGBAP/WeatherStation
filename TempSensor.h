#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <DHT.h>

class TempSensor {
  private:
    int pin;
    DHT* dht;

  public:
    TempSensor(int pin, int type = DHT11);
    void begin();
    float readTemperature();
    float readHumidity();
    int readTemperatureAndHumidity(float* data);
    void printTemperatureAndHumidity();
};

#endif // TEMP_SENSOR_H
