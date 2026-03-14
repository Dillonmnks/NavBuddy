#ifndef BLESTATUS_H
#define BLESTATUS_H

#include <Adafruit_SSD1306.h>

extern bool bleConnected;

class BLEStatus {
public:
    BLEStatus(Adafruit_SSD1306* display);

    void draw();

private:
    Adafruit_SSD1306* display;
};

#endif