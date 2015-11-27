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

#ifndef RoDI_h
#define RoDI_h

#include <Arduino.h>
#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

// Servomotors
#define LEFT_SERVO          4
#define RIGHT_SERVO         5

// Hall efect Sensors
// TODO(Gary): Implement sensors
#define LEFT_HALL           3
#define RIGHT_HALL          6

// Ultrasonic Sensors (HC-SR04)
#define LEFT_US_TRIGGER     A3
#define LEFT_US_ECHO        2
#define CENTER_US_TRIGGER   12
#define CENTER_US_ECHO      A0
#define RIGHT_US_TRIGGER    9
#define RIGHT_US_ECHO       10

// Buzzer
#define BUZZER              7

// Leds
#define USER_LED            13
#define WS2812b_LED         11

// IMU (MPU6050)
// TODO(Gary): Implement Sensor
#define IMU_SDA             A4
#define IMU_SCL             A5

// Analog Sensors
#define BATTERY_MON         A2
#define LDR                 A7

// Line Sensors
#define LEFT_LINE           A1
#define RIGHT_LINE          A6


// This class is for the 3 Sonars (HC-SR04) on the RoDI
enum SONAR {LEFT, CENTER, RIGHT};

class RoDISonars
{
  public:
    RoDISonars();
    unsigned int read(SONAR sensor);
    unsigned int read_cm(SONAR sensor);
  private:
    NewPing _left_sonar;
    NewPing _center_sonar;
    NewPing _right_sonar;
};

class RoDILeds
{
  public:
    RoDILeds();
    void begin();
    void clear();
    void toggle();
    void write(bool state);
    void write (uint32_t color);
    void write(unsigned char r, unsigned char g, unsigned char b);
    void rainbow(uint8_t wait);
  private:
    Adafruit_NeoPixel _pixel;
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
    bool _user_led_state;
    uint32_t Wheel(byte WheelPos);
};

class RoDIMotors
{
  public:
    RoDIMotors(HardwareSerial& serial);
    void drive(char speed);      // Drive in direction given by sign, at speed given
                                 // by magnitude of the parameter.
    void pivot(char speed);      // Pivot more or less in place. Turns motors in
    void rightMotor(char speed); // Drive just the right motor. speed > 0 CW, speed < 0 CCW.
    void leftMotor(char speed);  // Drive just the left motor. speed > 0 CW, speed < 0 CCW.
    void stop();
  private:
    Servo _leftServo;
    Servo _rightServo;
    bool _left_servo_attached;
    bool _right_servo_attached;
    HardwareSerial& _HardSerial;
};

class RoDILineSensor
{
  public:
    RoDILineSensor(int pin);
    int read();             // Return the current value of the pin.
    boolean check();        // In theory, this will be true if a deviation from
                            //  detectLevel is found; false otherwise.
    int setBGLevel();       // You can calibrate the sensor to detect a deviation
    int setDetectLevel();   //  from detectLevel; these functions allow for that.
    boolean calStatus();    // Have both calibrated levels been set yet?
  private:
    int _pin;
    int _BGLevel;
    int _detectLevel;
};

/*class RoDIBuzzer
{
  public:
    RoDIBuzzer();
    void play_tone(unsigned int frequency);
    void play_tone(unsigned int frequency, unsigned long duration);
    void play_melody(int melody);
};
*/

#endif
