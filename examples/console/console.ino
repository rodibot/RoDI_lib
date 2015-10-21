#include <RoDI.h>
#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

RoDILeds leds;
RoDIMotors motors;
RoDISonars sonars;
RoDIBuzzer buzzer;
RoDILineSensor left_sensor(LEFT_LINE);
RoDILineSensor right_sensor(RIGHT_LINE);

void setup() {
  Serial.begin(57600);
  leds.begin();
}

void loop() {
  if (Serial.available()) {

    int cmd = Serial.read();

    switch (cmd) {
      case 'm':
        print_menu();
        break;
      case 'S':
        clear_terminal();
        Serial.println("Sonars");
        Serial.print("[");
        Serial.print(sonars.read_cm(LEFT));
        Serial.print(",");
        Serial.print(sonars.read_cm(CENTER));
        Serial.print(",");
        Serial.print(sonars.read_cm(RIGHT));
        Serial.println("]");
        break;
      case 'L':
        leds.toggle();
        print_menu();
        break;
      case 'R':
        leds.rainbow(20);
        print_menu();
        break;
      case 'f':
        clear_terminal();
        Serial.println("Robot forward");
        motors.drive(50);
        break;
      case 'b':
        clear_terminal();
        Serial.println("Robot backward");
        motors.drive(-50);
        break;
      case 'l':
        clear_terminal();
        Serial.println("Robot pivot left");
        motors.pivot(50);
        break;
      case 'r':
        clear_terminal();
        Serial.println("Robot pivot right");
        motors.pivot(-50);
        break;
      case 's':
        clear_terminal();
        Serial.println("Stop Robot");
        motors.stop();
        break;
      case 'F':
        clear_terminal();
        Serial.println("Line Sensors");
        Serial.print("[");
        Serial.print(left_sensor.read());
        Serial.print(",");
        Serial.print(right_sensor.read());
        Serial.println("]");
        break;
      case 'p':
        buzzer.play_melody(0);
        print_menu();
        break;
      case 'x':
        clear_terminal();
        Serial.println("LDR sensor");
        Serial.print("[");
        Serial.print(analogRead(LDR));
        Serial.println("]");
        break;
      case 'B':
        clear_terminal();
        Serial.println("Battery Momitor");
        Serial.print("[");
        Serial.print(analogRead(BATTERY_MON));
        Serial.println("]");
        break;
      case 'I':
        clear_terminal();
        Serial.println("IMU data");
        Serial.println("###### Not implemented #####");
        break;
      case 'C':
        clear_terminal();
        break;
      default:
        break;
    }
  }
}

void print_menu() {
  clear_terminal();
  Serial.println("S -> Read Sonars");
  Serial.println("L -> Toggle User LED");
  Serial.println("R -> Show rainbow example using the pixel");
  Serial.println("f -> Move the robot forward");
  Serial.println("b -> Move the robot backwards");
  Serial.println("l -> Pivot the robot left");
  Serial.println("r -> Pivot the robot right");
  Serial.println("s -> Stop the robot");
  Serial.println("F -> Read the line sensors");
  Serial.println("p -> Play a melody");
  Serial.println("x -> Read LDR sensor");
  Serial.println("B -> Read Battery Monitor");
  Serial.println("I -> Read IMU data");
  Serial.println("C -> Clear terminal");
}

void clear_terminal() {
  // First clear terminal
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}
