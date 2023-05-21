#ifndef SCREEN_H
#define SCREEN_H

#include <U8g2lib.h>

class Screen {
  public:
    Screen();
    void begin();
    void printIndoor(float temperature,float humidity,int airQuality);
    
  private:
    U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2;
};

#endif
