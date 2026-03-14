#include "AppState.h"

void AppState::setNavigation(const String& dir, const String& dist, const String& exit) {
    direction = dir;
    distance = dist;
    exitNum = exit;
    currentMode = Mode::NAVIGATION;
}

void AppState::clearNavigation() {
    direction = "";
    distance = "";
    exitNum = "";
    currentMode = Mode::FACE;
}

bool AppState::hasNavigation() const {
    return currentMode == Mode::NAVIGATION;
}

Mode AppState::mode() const {
    return currentMode;
}
