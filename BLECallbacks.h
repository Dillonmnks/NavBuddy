#ifndef BLE_CALLBACKS_H
#define BLE_CALLBACKS_H

#include <BLEServer.h>
#include <BLECharacteristic.h>

extern bool bleConnected;

class ServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) override;
    void onDisconnect(BLEServer* pServer) override;
};

class NavCallback : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic) override;
};

#endif
