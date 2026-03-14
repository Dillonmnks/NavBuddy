#ifndef BLE_STATUS_H
#define BLE_STATUS_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

extern bool bleConnected;

class BLEStatus {
public:
    BLEStatus(Adafruit_SSD1306* display);

    void trigger();   // call when BLE connects/disconnects
    void draw();      // draws only if timer active

private:
    Adafruit_SSD1306* display;
    unsigned long showUntil;   // timestamp until icon is visible
};

#endif
