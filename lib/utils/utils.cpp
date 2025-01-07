#include <utils.h>

void _initAll_(){
    pinMode(TFT_CS, OUTPUT);
    pinMode(SD_CS, OUTPUT);

    if(!SD.begin(SD_CS, SPI,27000000)){
        Serial.println("SD failed to initialize");
        return;
    }
};

uint16_t CTN(int x, int y){
    return ((y*160)+x);
}; 