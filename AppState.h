#ifndef APP_STATE_H
#define APP_STATE_H

#include <Arduino.h>

enum class Mode {
    FACE,
    NAVIGATION
};

class AppState {
public:
    void setNavigation(const String& dir, const String& dist, const String& exitNum = "");
    void clearNavigation();

    bool hasNavigation() const;
    Mode mode() const;

    String direction;
    String distance;
    String exitNum;

private:
    Mode currentMode = Mode::FACE;
};

#endif
