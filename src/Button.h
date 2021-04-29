#include "Arduino.h"

class Button {
    private:
        uint8_t _register;
        int _port;
        int _pin;
        int type;
        int raw;
        int _state;
        int lastState;
        int currentState;
        unsigned long lasttime;
        unsigned long delay = 50;
    public:
    Button(uint8_t, int,int);
    Button(uint8_t, int,int, unsigned long);
    bool check();
    bool down();
    bool debounce();
    inline bool readPort();
};