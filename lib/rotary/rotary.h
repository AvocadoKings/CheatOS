#ifndef _ROTARY_H
#define _ROTARY_H

#include <Arduino.h>

class Encoder {
public:
    Encoder(int pinA, int pinB, int pinP, int beginPos=0);
    void tick();

    int rotation;
    int deltaRotation;
    int prev;
    bool push;
    char direction = 'f';
private:
    int pin1;
    int pin2;
    int pin3;
    bool rot1 = 0;
    bool rot2 = 0;
    bool rot5 = 0;
};

#endif