#ifndef BLE_CONTROLLER_H
#define BLE_CONTROLLER_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

class BLEController {
public:
    BLEController();
    void begin();

private:
    BLEServer* server;
    BLEService* service;
    BLECharacteristic* navChar;
};

#endif
