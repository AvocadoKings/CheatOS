#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>
#include <SDManager.h>
#include <Render.h>
#include <string>
#include <vector>
#include <firm.h>

#define rot1_1 4
#define rot2_1 15
#define rotSw_1 16
#define rot1_2 35
#define rot2_2 34
#define rotSw_2 25

int rot11 = 0;
int rot12 = 0;
int rot15 = 0;

int rot21 = 0;
int rot22 = 0;
int rot25 = 0;

int rotationX = 160;
int rotationY = 120;

int prevX = 160;
int prevY = 120;

int r=255;
int b=255;
int g=255;
uint16_t color = rgb(r,g,b);

Adafruit_ST7789 display = _initDisplay_();

void setup(){
    Serial.begin(9600);

    clearScreen();
    display.setTextSize(2);
    display.setTextColor(ST77XX_WHITE);
    
    pinMode(rot1_1, INPUT);
    pinMode(rot2_1, INPUT);
    pinMode(rotSw_1, INPUT);
    pinMode(rot1_2, INPUT);
    pinMode(rot2_2, INPUT);
    pinMode(rotSw_2, INPUT);
}

void loop(){

    bool in1 = !digitalRead(rot1_1); 
    bool in2 = !digitalRead(rot2_1); 
    bool in3 = !digitalRead(rot1_2); 
    bool in4 = !digitalRead(rot2_2); 

    if (in1){
        rot11 = 1;
        if (in1 && in2) {rot15 = 1;}
        if (rot11 && !in2 && rot15) {rotationX-=1; rot11 = 0;rot12 = 0;rot15 = 0;}
    }
    if (in2){
        rot12 = 1;   
        if (in1 && in2) {rot15 = 1;}
        if (rot12 && !in1 && rot15) {rotationX+=1; rot11 = 0;rot12 = 0;rot15 = 0;}
    }
    if (in3){
        rot21 = 1;
        if (in3 && in4) {rot25 = 1;}
        if (rot21 && !in4 && rot25) {rotationY+=1; rot21 = 0;rot22 = 0;rot25 = 0;}
    }
    if (in4){
        rot22 = 1;   
        if (in3 && in4) {rot25 = 1;}
        if (rot22 && !in3 && rot25) {rotationY-=1; rot21 = 0;rot22 = 0;rot25 = 0;}
    }

    if(!digitalRead(rotSw_1) && !digitalRead(rotSw_2)){
        clearScreen();
    }

    int deltaX = (rotationX - prevX)*5;
    int deltaY = -(rotationY - prevY)*5;
    if (!digitalRead(rotSw_1) && deltaX!=0) {

        if (r+deltaX<=255 && r+deltaX>=0){
            r += deltaX;
            Serial.println(r);
            color = rgb(r, g, b);
        }

    } else if (!digitalRead(rotSw_1) && deltaY!=0) {

        if (g+deltaY<=255 && g+deltaY>=0){
            g += deltaY;
            Serial.println(g);
            color = rgb(r, g, b);
        }
        
    } else if (!digitalRead(rotSw_2) && deltaX!=0) {

        if (b+deltaX<=255 && b+deltaX>=0){
            b += deltaX;
            Serial.println(b);
            color = rgb(r, g, b);
        }

    }else if (digitalRead(rotSw_1) && digitalRead(rotSw_2)){
        drawLine(prevX, prevY, rotationX, rotationY, color);
    }
    prevX = rotationX;
    prevY = rotationY;
    drawLine(0, 239, 319, 239, color);
}