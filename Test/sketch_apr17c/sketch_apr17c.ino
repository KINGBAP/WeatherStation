#include "Temperature.h"
Temperature Temp(D3,DHT11);

void setup() {
  Serial.begin(115200);
  Serial.println("Debut");
  
  

}

void loop() {

Serial.println(Temp.readTemperature(false));
delay(3000);
}
