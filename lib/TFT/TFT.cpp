#include <TFT.h>

void sendCommand(uint8_t cmd){
    digitalWrite(SD_CS, HIGH);
    digitalWrite(TFT_CS, LOW);
    digitalWrite(TFT_DC, LOW);
    SPI.transfer(cmd);
    digitalWrite(TFT_CS, HIGH);
    
    return;
}

void sendData(uint8_t data){
    digitalWrite(SD_CS, HIGH);
    digitalWrite(TFT_CS, LOW);
    digitalWrite(TFT_DC, HIGH);
    SPI.transfer(data);
    digitalWrite(TFT_CS, HIGH);
    
    return;
}

void TFTInit(){
    pinMode(TFT_CS, OUTPUT);
    pinMode(TFT_RST, OUTPUT);
    pinMode(TFT_DC, OUTPUT);

    SPI.begin();
    SPI.setFrequency(SPIFreq);
    SPI.setDataMode(SPI_MODE0);

    digitalWrite(TFT_RST, LOW); // reset
    delay(50);
    digitalWrite(TFT_RST, HIGH);
    delay(50);
  
    sendCommand(0x01); // Software reset
    delay(150);
  
    sendCommand(0x11); // Sleep out
    delay(255);
  
    sendCommand(0x3A); // Pixel format
    sendData(0x55);
  
    sendCommand(0x36); // Memory data access control
    sendData(0xA0);
  
    sendCommand(0x29); // Start

    return;
}

void setAddrWindow(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1){
    digitalWrite(SD_CS, HIGH);
    sendCommand(0x2A);  // Column address set
    sendData(x0 >> 8);
    sendData(x0 & 0xFF);
    sendData(x1 >> 8);
    sendData(x1 & 0xFF);

    sendCommand(0x2B);  // Row address set
    sendData(y0 >> 8);
    sendData(y0 & 0xFF);
    sendData(y1 >> 8);
    sendData(y1 & 0xFF);

    sendCommand(0x2C);  // Memory write (begin writing pixels)

    return;
}

void drawPixel(uint16_t x, uint16_t y, uint16_t c,uint16_t *screen) {
    screen[CTN(x, y)] = c;

    return;
}

void drawPixels(const uint16_t* data_in) {
    digitalWrite(SD_CS, HIGH);
    const uint16_t* data = (uint16_t*)data_in; // Treat data as 32-bit words
    sendCommand(0x2C);
    setAddrWindow(0,0,320,240);
    digitalWrite(TFT_CS, LOW);
    digitalWrite(TFT_DC, HIGH);
    for (uint32_t i = 0; i<120;i++){
        for (uint32_t j=0; j<10;j++){
            while (READ_PERI_REG(SPI_CMD_REG(3)) & SPI_USR);

            // Write 16 registers (512 bits = 64 bytes = 32 pixels)
            WRITE_PERI_REG(SPI_W0_REG(3), ((uint32_t)data[(i*160)+(j*16)+0]<<16)|data[(i*160)+(j*16)+0]);
            WRITE_PERI_REG(SPI_W1_REG(3), ((uint32_t)data[(i*160)+(j*16)+1]<<16)|data[(i*160)+(j*16)+1]);
            WRITE_PERI_REG(SPI_W2_REG(3), ((uint32_t)data[(i*160)+(j*16)+2]<<16)|data[(i*160)+(j*16)+2]);
            WRITE_PERI_REG(SPI_W3_REG(3), ((uint32_t)data[(i*160)+(j*16)+3]<<16)|data[(i*160)+(j*16)+3]);
            WRITE_PERI_REG(SPI_W4_REG(3), ((uint32_t)data[(i*160)+(j*16)+4]<<16)|data[(i*160)+(j*16)+4]);
            WRITE_PERI_REG(SPI_W5_REG(3), ((uint32_t)data[(i*160)+(j*16)+5]<<16)|data[(i*160)+(j*16)+5]);
            WRITE_PERI_REG(SPI_W6_REG(3), ((uint32_t)data[(i*160)+(j*16)+6]<<16)|data[(i*160)+(j*16)+6]);
            WRITE_PERI_REG(SPI_W7_REG(3), ((uint32_t)data[(i*160)+(j*16)+7]<<16)|data[(i*160)+(j*16)+7]);
            WRITE_PERI_REG(SPI_W8_REG(3), ((uint32_t)data[(i*160)+(j*16)+8]<<16)|data[(i*160)+(j*16)+8]);
            WRITE_PERI_REG(SPI_W9_REG(3), ((uint32_t)data[(i*160)+(j*16)+9]<<16)|data[(i*160)+(j*16)+9]);
            WRITE_PERI_REG(SPI_W10_REG(3), ((uint32_t)data[(i*160)+(j*16)+10]<<16)|data[(i*160)+(j*16)+10]);
            WRITE_PERI_REG(SPI_W11_REG(3), ((uint32_t)data[(i*160)+(j*16)+11]<<16)|data[(i*160)+(j*16)+11]);
            WRITE_PERI_REG(SPI_W12_REG(3), ((uint32_t)data[(i*160)+(j*16)+12]<<16)|data[(i*160)+(j*16)+12]);
            WRITE_PERI_REG(SPI_W13_REG(3), ((uint32_t)data[(i*160)+(j*16)+13]<<16)|data[(i*160)+(j*16)+13]);
            WRITE_PERI_REG(SPI_W14_REG(3), ((uint32_t)data[(i*160)+(j*16)+14]<<16)|data[(i*160)+(j*16)+14]);
            WRITE_PERI_REG(SPI_W15_REG(3), ((uint32_t)data[(i*160)+(j*16)+15]<<16)|data[(i*160)+(j*16)+15]);
            // Start the SPI transaction
            WRITE_PERI_REG(SPI_MOSI_DLEN_REG(3), 512 - 1);
            SET_PERI_REG_MASK(SPI_CMD_REG(3), SPI_USR);
        }
        for (uint32_t j=0; j<10;j++){
            while (READ_PERI_REG(SPI_CMD_REG(3)) & SPI_USR);

            WRITE_PERI_REG(SPI_W0_REG(3), ((uint32_t)data[(i*160)+(j*16)+0]<<16)|data[(i*160)+(j*16)+0]);
            WRITE_PERI_REG(SPI_W1_REG(3), ((uint32_t)data[(i*160)+(j*16)+1]<<16)|data[(i*160)+(j*16)+1]);
            WRITE_PERI_REG(SPI_W2_REG(3), ((uint32_t)data[(i*160)+(j*16)+2]<<16)|data[(i*160)+(j*16)+2]);
            WRITE_PERI_REG(SPI_W3_REG(3), ((uint32_t)data[(i*160)+(j*16)+3]<<16)|data[(i*160)+(j*16)+3]);
            WRITE_PERI_REG(SPI_W4_REG(3), ((uint32_t)data[(i*160)+(j*16)+4]<<16)|data[(i*160)+(j*16)+4]);
            WRITE_PERI_REG(SPI_W5_REG(3), ((uint32_t)data[(i*160)+(j*16)+5]<<16)|data[(i*160)+(j*16)+5]);
            WRITE_PERI_REG(SPI_W6_REG(3), ((uint32_t)data[(i*160)+(j*16)+6]<<16)|data[(i*160)+(j*16)+6]);
            WRITE_PERI_REG(SPI_W7_REG(3), ((uint32_t)data[(i*160)+(j*16)+7]<<16)|data[(i*160)+(j*16)+7]);
            WRITE_PERI_REG(SPI_W8_REG(3), ((uint32_t)data[(i*160)+(j*16)+8]<<16)|data[(i*160)+(j*16)+8]);
            WRITE_PERI_REG(SPI_W9_REG(3), ((uint32_t)data[(i*160)+(j*16)+9]<<16)|data[(i*160)+(j*16)+9]);
            WRITE_PERI_REG(SPI_W10_REG(3), ((uint32_t)data[(i*160)+(j*16)+10]<<16)|data[(i*160)+(j*16)+10]);
            WRITE_PERI_REG(SPI_W11_REG(3), ((uint32_t)data[(i*160)+(j*16)+11]<<16)|data[(i*160)+(j*16)+11]);
            WRITE_PERI_REG(SPI_W12_REG(3), ((uint32_t)data[(i*160)+(j*16)+12]<<16)|data[(i*160)+(j*16)+12]);
            WRITE_PERI_REG(SPI_W13_REG(3), ((uint32_t)data[(i*160)+(j*16)+13]<<16)|data[(i*160)+(j*16)+13]);
            WRITE_PERI_REG(SPI_W14_REG(3), ((uint32_t)data[(i*160)+(j*16)+14]<<16)|data[(i*160)+(j*16)+14]);
            WRITE_PERI_REG(SPI_W15_REG(3), ((uint32_t)data[(i*160)+(j*16)+15]<<16)|data[(i*160)+(j*16)+15]);

            // Start the SPI transaction
            WRITE_PERI_REG(SPI_MOSI_DLEN_REG(3), 512 - 1);
            SET_PERI_REG_MASK(SPI_CMD_REG(3), SPI_USR);
        }
    }
    while (READ_PERI_REG(SPI_CMD_REG(3)) & SPI_USR);
    digitalWrite(TFT_CS, HIGH);
    
    return;
}

void fillArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t c, uint16_t* screen){
    digitalWrite(SD_CS, HIGH);
    setAddrWindow(x0*2,y0*2,(x1*2)+1,(y1*2)+1);

    uint16_t width = x1-x0;
    uint16_t height = y1-y0;

    for(int x=0;x<width;x++){
        for(int y=0;y<height;y++){
            screen[CTN(x0+x, y0+y)] = c;
        }
    }

    return;
};

void drawImage(const char* path,int x0, int y0, int width, int height, uint16_t* screen){
    String img = SD.open(path).readString(); 
    for (int y=0;y<height; y++){
        for (int x=0;x<width;x++){
            uint16_t c = (img[((y*width)+x)*2+1] << 8 | img[((y*width)+x)*2]);
            screen[CTN(x+x0, y+y0)] = c;
        }
    }
};

void drawImage(String img,int x0, int y0, int width, int height, uint16_t* screen){
    for (int y=0;y<height; y++){
        for (int x=0;x<width;x++){
            uint16_t c = (img[((y*width)+x)*2+1] << 8 | img[((y*width)+x)*2]);
            screen[CTN(x+x0, y+y0)] = c;
        }
    }
};

TFTFrame::TFTFrame(){
    return;
}