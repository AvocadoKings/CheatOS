#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>
#include <SDManager.h>
#include <Render.h>
#include <dap.h>
#include <string>


void setup(){
    Serial.begin(115200);
    string testcoding = "\n              \nx = 10\n ";
    createInstructionList(testcoding);
}

void loop(){

}