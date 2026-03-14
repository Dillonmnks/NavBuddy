#ifndef FACE_ANIMATOR_H
#define FACE_ANIMATOR_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

class FaceAnimator {
public:
    FaceAnimator(Adafruit_SSD1306* display);

    void startupAnimation();
    void update();

private:
    Adafruit_SSD1306* display;

    // Animation states
    bool blinkState;
    bool winkState;

    // Timers
    unsigned long lastBlink;
    unsigned long lastWink;

    // Randomized delays
    unsigned long blinkPause;
    unsigned long winkPause;

    // Internal drawing helpers
    void drawFace();
    void drawEyesOpen();
    void drawEyesClosed();
    void drawWink();
    void drawMouth();
};

#endif
