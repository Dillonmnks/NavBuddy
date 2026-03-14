#ifndef BLE_HANDLERS_H
#define BLE_HANDLERS_H

#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLEDevice.h>

extern bool bleConnected;

class ServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) override {
        bleConnected = true;
    }
    void onDisconnect(BLEServer* pServer) override {
        bleConnected = false;
        BLEDevice::startAdvertising();
    }
};

class NavCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) override;
};

#endif