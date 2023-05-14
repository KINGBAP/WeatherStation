#include "AirSensor.h"

AirSensor::AirSensor(int pin) : Sensor(pin),airQualitySensor(pin) {
    // do nothing
}

void AirSensor::begin() {
  bool initialized = false;
  unsigned long startTime = millis();
  
  while (!initialized && (millis() - startTime) < 10000) {  // Attendre jusqu'à 10 secondes maximum
    initialized = airQualitySensor.init();
    if (!initialized) {
      Serial.println("Air quality sensor not ready yet. Waiting...");
      delay(1000);  // Attendre 1 seconde avant la prochaine tentative
    }
  }

  if (!initialized) {
    Serial.println("Air quality sensor initialization failed.");
  }
}


int AirSensor::read(void) {
    int airQuality = airQualitySensor.slope();

    Serial.print("Sensor value: ");
    Serial.println(airQualitySensor.getValue());

    if (airQuality == AirQualitySensor::FORCE_SIGNAL) {
        Serial.println("High pollution! Force signal active.");
    } else if ( airQuality== AirQualitySensor::HIGH_POLLUTION) {
        Serial.println("High pollution!");
    } else if (airQuality == AirQualitySensor::LOW_POLLUTION) {
        Serial.println("Low pollution!");
    } else if (airQuality == AirQualitySensor::FRESH_AIR) {
        Serial.println("Fresh air.");
    }

    return airQuality;
}
