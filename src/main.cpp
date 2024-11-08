#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define screenWidth 240
#define screenHeight 240

#define CSpin 2
#define DCpin 3
#define BLKpin 4
#define MOSIpin 19
#define SCLKpin 18
#define RSTpin -1

Adafruit_ST7789 display(CSpin, DCpin, MOSIpin, SCLKpin, RSTpin);

uint16_t rgb(int r, int g, int b){
  return ((((r+1)/8)-1) << 11) | ((((g+1)/4)-1) << 5) | (((b+1)/8)-1);
}

void setup(){
  display.init(screenWidth, screenHeight);
}

void loop(){

}