#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "FaceAnimator.h"
#include "NavigationDisplay.h"
#include "BLEStatus.h"
#include "BLEHandlers.h"

// OLED
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Global modules
FaceAnimator face(&display);
NavigationDisplay nav(&display);
BLEStatus bles(&display);

void setup() {
    Serial.begin(115200);
    Wire.begin(21, 22);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    randomSeed(analogRead(0));

    face.startupAnimation();

    // BLE
    BLEDevice::init("ESP32_NAV_DISPLAY");

    BLEServer *server = BLEDevice::createServer();
    server->setCallbacks(new ServerCallbacks());

    BLEService *service = server->createService("1234");

    BLECharacteristic *navChar = service->createCharacteristic(
        "ABCD",
        BLECharacteristic::PROPERTY_WRITE
    );

    navChar->setCallbacks(new NavCallback());

    service->start();

    BLEAdvertising *advertising = BLEDevice::getAdvertising();
    advertising->addServiceUUID("1234");
    BLEDevice::startAdvertising();
}

void loop() {
    display.clearDisplay();

    face.update();
    bles.draw();

    display.display();
    delay(50);
}
