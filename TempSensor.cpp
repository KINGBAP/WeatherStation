#include "TempSensor.h"

TempSensor::TempSensor(int pin, int type)  : Sensor(pin){
  dht = new DHT(pin, type);
}

void TempSensor::begin() {
  dht->begin();
}

int TempSensor::read(float *data) {
  return dht->readTempAndHumidity(data);
}

void TempSensor::printTemperatureAndHumidity() {
  float temp_hum_val[2] = {0};
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)


    if (!read(temp_hum_val)) {
        Serial.print("Humidity: ");
        Serial.print(temp_hum_val[0]);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(temp_hum_val[1]);
        Serial.println(" *C");
    } else {
        Serial.println("Failed to get temprature and humidity value.");
    }
}
