#ifndef __AIR_SENSOR_H__
#define __AIR_SENSOR_H__

#include "Arduino.h"
#include "Air_Quality_Sensor.h"
#include "Sensor.h"


class AirSensor : public Sensor {
  public:
    AirSensor(int pin);

    void begin(void);
    int read(void);

  protected:
    AirQualitySensor airQualitySensor;
};

#endif // __AIR_SENSOR_H__
