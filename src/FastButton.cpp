#include "Arduino.h"
#include "FastButton.h"

bool FastButton::readPort() {
    return _SFR_IO8(_register) & 1 << _port;
}

FastButton::FastButton(int pin, uint8_t _reg, int port, int state) {
    _register = _reg;
    _port = port;
    _pin = pin;
    _state = state;
    if(_state == HIGH) {
        pinMode(_pin, INPUT); // should be INPUT_PULLDOWN in feature
    } else {
        pinMode(_pin, INPUT_PULLUP);
    }
}


FastButton::FastButton(int pin, uint8_t _reg, int port, int state, unsigned long d) {
    _register = _reg;
    _port = port;
    _state = state;
    _pin = pin;
    delay = d;
    if(_state == HIGH) {
        pinMode(_pin, INPUT); // should be INPUT_PULLDOWN in feature
    } else {
        pinMode(_pin, INPUT_PULLUP);
    }
}

bool FastButton::down() {
    return FastButton::check();
}

bool FastButton::check() {
    raw = FastButton::readPort();
    if(raw != lastState) {
        lastState = raw;
        if(raw == _state) {
            return true;
        } 
    }
    return false;
}

bool FastButton::debounce() {
    raw = FastButton::readPort();
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