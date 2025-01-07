#ifndef _UTILS_H
#define _UTILS_H

#include <Arduino.h>
#include <SPI.h>
#include <FS.h>
#include <SD.h>
#include <string.h>

#define TFT_CS 15
#define TFT_RST 4
#define TFT_DC 2
#define TFT_MOSI 23
#define TFT_SCK 18
#define TFT_LED 15
#define TFT_MISO 19

#define SD_CS 5
#define SD_MOSI 23
#define SD_SCK 18
#define SD_MISO 19

void _initAll_();

uint16_t CTN(int x, int y); 

#endif