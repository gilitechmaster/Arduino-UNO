#include<Adafruit_NeoPixel.h>
#define PIN 8
#define NUM_LEDS 60 // 최대 60개까지 켜짐 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB+NEO_KHZ800);

int i = 0;

void setup() {

    Serial.begin(9600);
    strip.begin();
    strip.show();
    
}

void loop() {
    for(int i = 0; i < 7; i++) // i = 네오픽셀은 0번부터 7번까지
    {
      strip.setPixelColor(i,62,3,80);
    }
    for(int i = 7; i < 15; i++) // i = 네오픽셀은 7번부터 15번까지
    {
      strip.setPixelColor(i,62,63,20);
    }
    for(int i = 15; i < 22; i++) // i = 네오픽셀은 15번부터 22번까지
    {
      strip.setPixelColor(i,12,63,70);
    }
    for(int i = 22; i < 29; i++) // i = 네오픽셀은 22번부터 29번까지
    {
      strip.setPixelColor(i,12,43,90);
    }
    for(int i = 29; i < 36; i++) // i = 네오픽셀은 29번부터 36번까지
    {
      strip.setPixelColor(i,12,3,130);
    }
    
    for(int i = 36; i < 43; i++) // i = 네오픽셀은 36번부터 43번까지
    {
      strip.setPixelColor(i,110,10,25);
    }
    for(int i = 43; i < 50; i++) // i = 네오픽셀은 43번부터 50번까지
    {
      strip.setPixelColor(i,80,40,25);
    }
    for(int i = 50; i < 60; i++) // i = 네오픽셀은 50번부터 60번까지
    {
      strip.setPixelColor(i,80,10,55);
    }

    
    strip.show();
delay(80);
}
