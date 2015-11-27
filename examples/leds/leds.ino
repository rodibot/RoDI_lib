#include <RoDI.h>

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
