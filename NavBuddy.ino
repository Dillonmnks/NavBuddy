#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "AppState.h"
#include "bBLEController.h"
#include "FaceAnimator.h"
#include "NavigationDisplay.h"
#include "BLEStatus.h"

// -------------------- OLED SETUP --------------------

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// -------------------- GLOBAL MODULES --------------------

AppState app;
BLEController ble;

FaceAnimator face(&display);
NavigationDisplay nav(&display);
BLEStatus bles(&display);

// -------------------- SETUP --------------------

void setup() {
    Serial.begin(115200);

    Wire.begin(21, 22);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 init failed");
        while (true);
    }

    randomSeed(analogRead(0));

    face.startupAnimation();

    // Initialize BLE
    ble.begin();

    Serial.println("System ready.");
}

// -------------------- LOOP --------------------

void loop() {
    display.clearDisplay();

    // Decide what to draw based on app state
    if (app.mode() == Mode::FACE) {
        face.update();
    } else {
        nav.show(app.direction, app.distance, app.exitNum);
    }

    // Draw BLE connection indicator
    bles.draw();

    display.display();
    delay(50);
}
