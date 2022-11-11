/****************************************************************************/
//	Function: When the sensor detects a flame, the the I2C Display will show a message.
//	Hardware: Waveshare - Flame Sensor, Waveshare - I2C OLED 128x32
//	Arduino IDE: Arduino-2.0
//	Author:	    Rajveer Singh Saggu
//	Date: 	    Nov 11, 2022
//	Version:    v1.0
//      Libraries:  Adafruit GFX, Adafruit SSD1306
//	by www.rajveer2009.github.io/ <rajveersinghsaggu2009@proton.me>
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the MIT License
//  License as published by the Open Source Initiative; either
//  version 1.0 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the MIT
//  License for more details at www.rajveer2009.github.io/LICENSE .
//
/******************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define FLAME_SENSOR 3
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  pinMode(FLAME_SENSOR, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); 
}

void loop() {
  if (isFlameDetected())
    fireOn();
  else fireOff();
  delay(100);
}

/********************************/

void fireOn() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.display();
  display.println("FIRE! :)");
}

void fireOff() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.display();
  display.println("No Fire");
  display.clearDisplay(); 
  delay(1000);
}

boolean isFlameDetected() {
  if (digitalRead(FLAME_SENSOR))
    return false;
  else return true;
}
