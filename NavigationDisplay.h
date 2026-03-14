#ifndef NAVIGATION_DISPLAY_H
#define NAVIGATION_DISPLAY_H

#include <Adafruit_SSD1306.h>

class NavigationDisplay {
public:
    NavigationDisplay(Adafruit_SSD1306* display);

    void show(const String& direction, const String& distance, const String& exitNum = "");
    void clear();
    void update();  // optional if you want animations later

private:
    Adafruit_SSD1306* display;

    String direction;
    String distance;
    String exitNum;

    void drawLeft();
    void drawRight();
    void drawStraight();
    void drawRoundabout();

    void drawDistance();
};

#endif
