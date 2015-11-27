#include <RoDI.h>

RoDISonars sonars;

void setup() {
  Serial.begin(57600);
}

void loop() {
  Serial.print(sonars.read_cm(LEFT));
  Serial.print("\t|\t");
  Serial.print(sonars.read_cm(CENTER));
  Serial.print("\t|\t");
  Serial.print(sonars.read_cm(RIGHT));
  Serial.print("\t|\t");
  delay(100);
}
