#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>
#include <SDManager.h>
#include <Render.h>

SdFat32 SD = _initSd_();
Adafruit_ST7789 display = _initDisplay_();
Adafruit_ImageReader reader = _initReader_(SD);

void setup(){
    Serial.begin(9600);
}

void loop(){

}