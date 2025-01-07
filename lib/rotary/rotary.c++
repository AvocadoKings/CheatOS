#include "rotary.h"

Encoder::Encoder(int pinA, int pinB, int pinP, int beginPos){
    pin1 = pinA;
    pin2 = pinB;
    pin3 = pinP;
    rotation = beginPos;
    prev = beginPos;

    pinMode(pin1, INPUT);
    pinMode(pin2, INPUT);
    pinMode(pin3, INPUT);
}

void Encoder::tick(){
    
    bool in1 = !digitalRead(pin1);
    bool in2 = !digitalRead(pin2);
    bool in3 = !digitalRead(pin3); 

    if (in1){
        rot1 = 1;
        if (in1 && in2) {rot5 = 1;}
        if (rot1 && !in2 && rot5) {rotation-=1*(direction == 'f') ? 1 : -1; rot1 = 0;rot2 = 0;rot5 = 0;}
    }
    if (in2){
        rot2 = 1;   
        if (in1 && in2) {rot5 = 1;}
        if (rot2 && !in1 && rot5) {rotation+=1*(direction == 'f') ? 1 : -1; rot1 = 0;rot2 = 0;rot5 = 0;}
    }

    push = in3;
    deltaRotation = rotation-prev;
    prev = rotation;
};