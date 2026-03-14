#ifndef NAVIGATION_DISPLAY_H
#define NAVIGATION_DISPLAY_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

class NavigationDisplay {
public:
    NavigationDisplay(Adafruit_SSD1306* display);

    void show(const String& direction, const String& distance, const String& exitNum = "");
    void clear();
    void update(); // reserved for future animations

private:
    Adafruit_SSD1306* display;

    // Cached values for drawing
    String direction;
    String distance;
    String exitNum;

    // Drawing helpers
    void drawLeft();
    void drawRight();
    void drawStraight();
    void drawRoundabout();
    void drawDistance();
};

#endif
