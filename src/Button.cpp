#include "Arduino.h"
#include "Button.h"

inline bool Button::readPort() {
    return (int)_register & 1 << _port;
}

Button::Button(uint8_t _reg, int port, int state) {
    _register = _reg;
    _port = port;

    _state = state;
    if(_state == HIGH) {
        pinMode(_pin, INPUT); // should be INPUT_PULLDOWN in feature
    } else {
        pinMode(_pin, INPUT_PULLUP);
    }
}


Button::Button(uint8_t _reg, int port, int state, unsigned long d) {
    _register = _reg;
    _port = port;
    _state = state;
    delay = d;
    if(_state == HIGH) {
        pinMode(_pin, INPUT); // should be INPUT_PULLDOWN in feature
    } else {
        pinMode(_pin, INPUT_PULLUP);
    }
}

bool Button::down() {
    return Button::check();
}

bool Button::check() {
    raw = readPort();
    if(raw != lastState) {
        lastState = raw;
        if(raw == _state) {
            return true;
        } 
    }
    return false;
}

bool Button::debounce() {
    raw = readPort();
    if(raw != lastState) {
        lasttime = millis();
    }

    if ((millis() - lasttime) >= delay) {
        if(raw != currentState) {
            currentState = raw;
            if(raw == _state) {
                return true;
            }
        } 
    }
    lastState = raw;
    return false;
}