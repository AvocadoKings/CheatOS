#include "Render.h"

Adafruit_ST7789 _initDisplay_(){
    Adafruit_ST7789 display(CSpin, DCpin, RSTpin);
    display.init(screenWidth, screenHeight);
    display.invertDisplay(0);
    display.setRotation(1);
    return display;
};

Adafruit_ImageReader _initReader_(SdFat32 SD){
    Adafruit_ImageReader reader(SD);
    
    return reader;
};

uint16_t rgb(int r, int g, int b){
    if (r < 0 || 255 < r || g < 0 || 255 < g || b < 0 || b > 255)
        return 0x0000;

    unsigned char red = r >> 3;
    unsigned char green = g >> 2;
    unsigned char blue = b >> 3;

    uint16_t result = (red << (5 + 6)) | (green << 5) | blue;
    return result;

};

void drawPixel(uint16_t x, uint16_t y, uint16_t c) {
    extern Adafruit_ST7789 display;
    display.drawPixel(x, y, c);
};

void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t c) {
    extern Adafruit_ST7789 display;
    display.drawLine(x0, y0, x1, y1, c);
};

void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c, bool f) {
    extern Adafruit_ST7789 display;
    if (f){
        display.fillRect(x, y, w, h, c);
    } else {
        display.drawRect(x, y, w, h, c);
    }
};

void drawRRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r, uint16_t c) {
    extern Adafruit_ST7789 display;
    display.drawRoundRect(x, y, w, h, r, c);
};

void drawTri(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t c) {
    extern Adafruit_ST7789 display;
    display.drawTriangle(x0, y0, x1, y1, x2, y2, c);
};

void drawCircle(uint16_t x, uint16_t y, uint16_t r, uint16_t c) {
    extern Adafruit_ST7789 display;
    display.drawCircle(x, y, r, c);
};

void drawBitmap(uint16_t x, uint16_t y, uint8_t *map, uint16_t w, uint16_t h, uint16_t c) {
    extern Adafruit_ST7789 display;
    display.drawBitmap(x, y, map, w, h, c);
};

void clearScreen(){
    extern Adafruit_ST7789 display;
    display.fillScreen(ST77XX_BLACK);
};

void fillScreen(uint16_t c){
    extern Adafruit_ST7789 display;
    display.fillScreen(c);
};

void drawImage(const char* path, uint16_t x, uint16_t y){
    extern Adafruit_ST7789 display;
    extern Adafruit_ImageReader reader;
    reader.drawBMP(path, display, x, y, true);
};