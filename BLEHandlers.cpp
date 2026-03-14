#include "BLEHandlers.h"
#include "NavigationDisplay.h"

extern NavigationDisplay nav;

void NavCallback::onWrite(BLECharacteristic *pCharacteristic) {
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
        nav.show(dir, msg.substring(first + 1));
        return;
    }

    String dist = msg.substring(first + 1, second);
    String exitNum = msg.substring(second + 1);

    nav.show(dir, dist, exitNum);
}