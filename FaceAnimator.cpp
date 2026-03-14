#include "FaceAnimator.h"

FaceAnimator::FaceAnimator(Adafruit_SSD1306* d) {
    display = d;

    blinkState = false;
    winkState = false;

    lastBlink = 0;
    lastWink = 0;

    blinkPause = random(6000, 9000);
    winkPause  = random(20000, 40000);
}

/* ---------- DRAWING HELPERS ---------- */

void FaceAnimator::drawEyesOpen() {
    display->fillRoundRect(32, 18, 20, 20, 6, WHITE);
    display->fillRoundRect(76, 18, 20, 20, 6, WHITE);
}

void FaceAnimator::drawEyesClosed() {
    display->fillRoundRect(32, 26, 20, 4, 2, WHITE);
    display->fillRoundRect(76, 26, 20, 4, 2, WHITE);
}

void FaceAnimator::drawWink() {
    display->fillRoundRect(32, 18, 20, 20, 6, WHITE);
    display->fillRoundRect(76, 26, 20, 4, 2, WHITE);
}

void FaceAnimator::drawMouth() {
    display->drawLine(56, 44, 72, 44, WHITE);
    display->drawPixel(55, 43, WHITE);
    display->drawPixel(73, 43, WHITE);
}

void FaceAnimator::drawFace() {
    display->clearDisplay();

    if (winkState) {
        drawWink();
    } else if (blinkState) {
        drawEyesClosed();
    } else {
        drawEyesOpen();
    }

    drawMouth();
}

/* ---------- STARTUP ANIMATION ---------- */

void FaceAnimator::startupAnimation() {
    display->clearDisplay();
    display->display();
    delay(500);

    drawEyesOpen();
    display->display();
    delay(700);

    display->clearDisplay();
    drawEyesClosed();
    display->display();
    delay(300);

    display->clearDisplay();
    drawEyesOpen();
    drawMouth();
    display->display();
    delay(400);
}

/* ---------- UPDATE ANIMATION ---------- */

void FaceAnimator::update() {
    unsigned long now = millis();

    // Blink
    if (now - lastBlink > blinkPause) {
        blinkState = true;
        drawFace();
        display->display();
        delay(120);

        blinkState = false;
        lastBlink = now;
        blinkPause = random(6000, 9000);
    }

    // Wink
    if (now - lastWink > winkPause) {
        winkState = true;
        drawFace();
        display->display();
        delay(200);

        winkState = false;
        lastWink = now;
        winkPause = random(20000, 40000);
    }

    // Normal face
    drawFace();
    display->display();
}
