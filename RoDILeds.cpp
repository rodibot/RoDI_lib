/*
  Copyright (C) 2015 Gary Servin - garyservin@gmail.com.
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
  USA
*/

#include <Arduino.h>
#include "RoDI.h"

RoDILeds::RoDILeds():
  _r(0),
  _g(0),
  _b(0),
  _user_led_state(0){};

void RoDILeds::begin()
{
  _pixel = Adafruit_NeoPixel(1, WS2812b_LED, NEO_GRB + NEO_KHZ800);
  _pixel.begin();
  write(0,0,0);

  pinMode(USER_LED, OUTPUT);
  digitalWrite(USER_LED, LOW);
}

// Turns off both leds
void RoDILeds::clear()
{
  write(false);
  write(0,0,0);
}

// Toggles the user led (13)
void RoDILeds::toggle()
{
  _user_led_state = HIGH-digitalRead(USER_LED);
  digitalWrite(USER_LED, HIGH-digitalRead(USER_LED));
}
// Turns on or off the user led (13)
void RoDILeds::write(bool state)
{
  _user_led_state = state;
  digitalWrite(USER_LED, state);
}

// Writes the RGB color to the pixel
void RoDILeds::write (unsigned char r, unsigned char g, unsigned char b)
{
  _r = r;
  _g = g;
  _b = b;
  _pixel.setPixelColor(0, _pixel.Color(r,g,b));
  _pixel.show(); // This sends the updated pixel color to the hardware.
}

// Writes the RGB color to the pixel
void RoDILeds::write (uint32_t color)
{
  _r = (uint8_t)(color >> 16),
  _g = (uint8_t)(color >>  8),
  _b = (uint8_t)color;
  _pixel.setPixelColor(0, color);
  _pixel.show(); // This sends the updated pixel color to the hardware.
}

void RoDILeds::rainbow(uint8_t wait) {
  for(uint16_t i=0; i<256; i++) {
    _pixel.setPixelColor(0, Wheel((i) & 255));
    _pixel.show();
    delay(wait);
  }
  _pixel.setPixelColor(0, 0); // Turn pixel off after finishing the rainbow
  _pixel.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t RoDILeds::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return _pixel.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return _pixel.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return _pixel.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
