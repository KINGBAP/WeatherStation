#ifndef SCREEN_H
#define SCREEN_H

#include <U8g2lib.h>

class Screen {
  public:
    Screen();
    void begin();
    void printTemperatureAndHumidity(float temperature,float humidity);
    void printAirQuality(int airQuality);

  private:
    U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2;
};

#endif
