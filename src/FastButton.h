#include "Arduino.h"

class FastButton {
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
    
    FastButton(int, uint8_t, int,int);
    FastButton(int, uint8_t, int,int, unsigned long);
    bool check();
    bool down();
    bool debounce();
    bool readPort();
};