#include <RoDI.h>
#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

RoDILeds leds;

void setup() {
  leds.begin();
}

void loop() {
  // Toggle user led
  for(int i = 0; i < 10; i++){
    leds.toggle();
    delay(200);
  }

  // Show rainbow on the pixel
  leds.rainbow(20);
}
