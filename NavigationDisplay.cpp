#include "NavigationDisplay.h"

NavigationDisplay::NavigationDisplay(Adafruit_SSD1306* d) {
    display = d;
    direction = "";
    distance = "";
    exitNum = "";
}

void NavigationDisplay::clear() {
    direction = "";
    distance = "";
    exitNum = "";
    display->clearDisplay();
    display->display();
}

void NavigationDisplay::show(const String& dir, const String& dist, const String& exit) {
    direction = dir;
    distance = dist;
    exitNum = exit;

    display->clearDisplay();

    if (direction == "LEFT") {
        drawLeft();
    }
    else if (direction == "RIGHT") {
        drawRight();
    }
    else if (direction == "STRAIGHT") {
        drawStraight();
    }
    else if (direction == "ROUNDABOUT") {
        drawRoundabout();
    }

    drawDistance();
}

void NavigationDisplay::update() {
    // Reserved for future animations (e.g., pulsing arrow)
}

/* ---------- DRAWING HELPERS ---------- */

void NavigationDisplay::drawLeft() {
    // Horizontal bar
    display->fillRect(25, 21, 35, 8, WHITE);

    // Arrow head
    display->fillTriangle(
        10, 25,   // tip
        28, 11,   // top
        28, 39,   // bottom
        WHITE
    );
}

void NavigationDisplay::drawRight() {
    display->fillRect(68, 21, 35, 8, WHITE);

    display->fillTriangle(
        118, 25,  // tip
        100, 11,  // top
        100, 39,  // bottom
        WHITE
    );
}

void NavigationDisplay::drawStraight() {
    display->fillRect(60, 15, 8, 35, WHITE);

    display->fillTriangle(
        64, 0,    // tip
        50, 18,   // left
        78, 18,   // right
        WHITE
    );
}

void NavigationDisplay::drawRoundabout() {
    display->drawCircle(64, 25, 15, WHITE);
    display->drawCircle(64, 25, 12, WHITE);

    display->setTextSize(2);
    display->setTextColor(WHITE);
    display->setCursor(90, 10);
    display->print(exitNum);
}

void NavigationDisplay::drawDistance() {
    display->setTextSize(2);
    display->setTextColor(WHITE);
    display->setCursor(0, 50);
    display->print(distance);
}
