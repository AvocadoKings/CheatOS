#include "Render.h"

Adafruit_ST7789 _initDisplay_(){
    Adafruit_ST7789 display(CSpin, DCpin, MOSIpin, SCLKpin, RSTpin);
    display.init(screenWidth, screenHeight);

    return display;
};

Adafruit_ImageReader _initReader_(SdFat32 SD){
    Adafruit_ImageReader reader(SD);
    
    return reader;
};

uint16_t rgb(int r, int g, int b){
  return ((((r+1)/8)-1) << 11) | ((((g+1)/4)-1) << 5) | (((b+1)/8)-1);
};

void drawPixel(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t c) {
    display.drawPixel(x, y, c);
};

void drawLine(Adafruit_ST7789 display, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t c) {
    display.drawLine(x0, y0, x1, y1, c);
};

void drawRect(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c) {
    display.drawRect(x, y, w, h, c);
};

void drawRRect(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r, uint16_t c) {
    display.drawRoundRect(x, y, w, h, r, c);
};

void drawTri(Adafruit_ST7789 display, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t c) {
    display.drawTriangle(x0, y0, x1, y1, x2, y2, c);
};

void drawCircle(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t r, uint16_t c) {
    display.drawCircle(x, y, r, c);
};

void drawBitmap(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint8_t *map, uint16_t w, uint16_t h, uint16_t c) {
    display.drawBitmap(x, y, map, w, h, c);
};

void drawImage(Adafruit_ST7789 display, Adafruit_ImageReader reader, const char* path, uint16_t x, uint16_t y){
    reader.drawBMP(path, display, x, y, true);
};