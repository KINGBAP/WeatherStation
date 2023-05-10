#include "Screen.h"

Screen::Screen() : u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE) {}

void Screen::begin() {
  u8g2.begin();
}

void Screen::printTemperatureAndHumidity(float temperature,float humidity) {
u8g2.firstPage();
  do {
u8g2.setFont(u8g2_font_ncenB10_tr);
u8g2.drawStr(0,24,"Temperature:");
u8g2.setCursor(0, 40); // aller à la ligne suivante
u8g2.print(temperature);
    u8g2.print(" °C");
      //u8g2.setCursor(0, 56); // aller à la ligne suivante
u8g2.drawStr(0,56,"Humidity:");
u8g2.setCursor(0,72);
u8g2.print(humidity);

  } while (u8g2.nextPage() );
}

void Screen::printAirQuality(int airQuality) {
u8g2.firstPage();
  do {
u8g2.setFont(u8g2_font_ncenB10_tr);
u8g2.drawStr(0, 72, "Air Quality:");
u8g2.setCursor(80, 72);
u8g2.print(airQuality);
u8g2.drawStr(104, 72, "ppm");
  } while (u8g2.nextPage());
}
