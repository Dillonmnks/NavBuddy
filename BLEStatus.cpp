#include "BLEStatus.h"

bool bleConnected = false;

BLEStatus::BLEStatus(Adafruit_SSD1306* d) {
    display = d;
    showUntil = 0;
}

void BLEStatus::trigger() {
    // Show icon for 3 seconds
    showUntil = millis() + 3000;
}

void BLEStatus::draw() {
    if (millis() > showUntil) {
        return; // do not draw anything
    }

    if (bleConnected) {
        display->fillCircle(122, 4, 3, WHITE);
    } else {
        display->drawCircle(122, 4, 3, WHITE);
    }
}
