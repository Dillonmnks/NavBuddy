#include "BLEStatus.h"

bool bleConnected = false;
BLEStatus::BLEStatus(Adafruit_SSD1306* d)
{
  display = d;
}

void BLEStatus::draw() {
  if (bleConnected) {
        display->fillCircle(122, 4, 3, WHITE);   // solid dot
    } else {
        display->drawCircle(122, 4, 3, WHITE);   // hollow circle
  }
}