#include <Arduino.h>
#include <string>
#include <TFT.h>
#include <rotary.h>
#include <utils.h>

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15  // Chip select control pin
#define TFT_DC   2  // Data Command control pin
#define TFT_RST  4 

Encoder rotary1 = Encoder(33, 32, 26, 10);
Encoder rotary2 = Encoder(35, 34, 225, 10);

TaskHandle_t rotaryTask;

uint16_t *screen = (uint16_t*)malloc(160*120*2);

void updateRot(void * parameter){
    while(true){
        rotary1.tick();
        rotary2.tick();
        delay(1);
    }
}

void setup(){
    Serial.begin(9600);
    TFTInit();
    _initAll_();
    Serial.println(xPortGetCoreID());
    xTaskCreatePinnedToCore(updateRot, "Rotary", 10000, NULL, 0, &rotaryTask, 0);

    String logo = SD.open("/dvd.cif").readString();
    
    bool xdir = false;
    bool ydir = false;

    int xPos = 1;
    int yPos = 1;

    while(xPos!=0 || yPos!=0){
        memset(screen, 0, 160*120*2);
        if(xPos==160-32||xPos==0){xdir=!xdir;}
        if(yPos==120-14||yPos==0){ydir=!ydir;}
        xPos +=(xdir)?-1:1;
        yPos +=(ydir)?-1:1;
        drawImage(logo, xPos, yPos, 32,14,screen);
        drawPixel(rotary1.prev, rotary2.prev, 0xFFFF, screen);
        drawPixels(screen);
    }

}

void loop(){

}