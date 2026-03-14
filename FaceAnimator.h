#ifndef FACE_ANIMATOR_H
#define FACE_ANIMATOR_H

#include <Adafruit_SSD1306.h>

class FaceAnimator {
public:
    FaceAnimator(Adafruit_SSD1306* display);

    void startupAnimation();
    void update();
    void drawFace();

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

    void drawEyesOpen();
    void drawEyesClosed();
    void drawWink();
    void drawMouth();
};

#endif