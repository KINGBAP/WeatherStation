#ifndef __AIR_SENSOR_H__
#define __AIR_SENSOR_H__

#include "Arduino.h"
#include "Air_Quality_Sensor.h"

class AirSensor {
  public:
    AirSensor(int pin);

    bool begin(void);
    int  getAirQuality(void);

  protected:
    AirQualitySensor airQualitySensor;
};

#endif // __AIR_SENSOR_H__