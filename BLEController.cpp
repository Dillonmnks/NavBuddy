#include "BLEController.h"
#include "BLECallbacks.h"

BLEController::BLEController() {
    server = nullptr;
    service = nullptr;
    navChar = nullptr;
}

void BLEController::begin() {
    BLEDevice::init("ESP32_NAV_DISPLAY");

    server = BLEDevice::createServer();
    server->setCallbacks(new ServerCallbacks());

    service = server->createService("1234");

    navChar = service->createCharacteristic(
        "ABCD",
        BLECharacteristic::PROPERTY_WRITE
    );

    navChar->setCallbacks(new NavCallback());

    service->start();

    BLEAdvertising* advertising = BLEDevice::getAdvertising();
    advertising->addServiceUUID("1234");
    BLEDevice::startAdvertising();
}
