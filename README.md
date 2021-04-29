# arduino-fastbutton
check if pin state changed 


example usage
```cpp
#include "Button.h"

Button button1(5, 0x09, PB5, LOW); // LOW for input pullup HIGH for INPUT
Button button2(4, 0x09, PB4, LOW, 1000); // 1000 - debaunce delay

void setup() {
    Serial.begin(9600);
}

void loop() {
    if(button1.down()) {
        Serial.println("CLICK!");
    }
    if(button2.debounce()) {
        Serial.println("debounce click");
    }
}
```