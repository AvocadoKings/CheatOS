#ifndef RENDER_H
#define RENDER_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_ImageReader.h>
#include <SdFat.h>

#define screenWidth 240
#define screenHeight 320
#define CSpin 14
#define DCpin 27
#define MOSIpin 23
#define SCLKpin 18
#define RSTpin 33

Adafruit_ST7789 _initDisplay_(); // these are functions, not definitions dumbass -myself
Adafruit_ImageReader _initReader_(SdFat32 SD);

uint16_t rgb(int r, int g, int b);

void drawPixel(uint16_t x, uint16_t y, uint16_t c);

void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t c);

void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c, bool f=false);

void drawRRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r, uint16_t c);

void drawTri(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t c);

void drawCircle(uint16_t x, uint16_t y, uint16_t r, uint16_t c);

void drawBitmap(uint16_t x, uint16_t y, uint8_t *map, uint16_t w, uint16_t h, uint16_t c);

void clearScreen();

void fillScreen(uint16_t c);

void drawImage(const char* path, uint16_t x, uint16_t y);

#endif