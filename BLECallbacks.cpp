#include "BLECallbacks.h"
#include <BLEDevice.h>
#include "AppState.h"
#include "BLEStatus.h"

extern BLEStatus bles;


extern AppState app;
bool bleConnected = false;

void ServerCallbacks::onConnect(BLEServer* pServer) {
    bleConnected = true;
    bles.trigger();
}

void ServerCallbacks::onDisconnect(BLEServer* pServer) {
    bleConnected = false;
    bles.trigger();
    BLEDevice::startAdvertising();
}

void NavCallback::onWrite(BLECharacteristic* pCharacteristic) {
    std::string raw = pCharacteristic->getValue();
    String msg = String(raw.c_str());

    if (msg.length() == 0) return;

    Serial.print("BLE received: ");
    Serial.println(msg);

    int first = msg.indexOf('|');
    if (first < 0) return;

    String dir = msg.substring(0, first);

    int second = msg.indexOf('|', first + 1);
    if (second < 0) {
        app.setNavigation(dir, msg.substring(first + 1));
        return;
    }

    String dist = msg.substring(first + 1, second);
    String exitNum = msg.substring(second + 1);

    app.setNavigation(dir, dist, exitNum);
}
