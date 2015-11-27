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

RoDIMotors::RoDIMotors(HardwareSerial& serial):
    _HardSerial(serial)
{
}

void RoDIMotors::drive(char speed)
{
  leftMotor(speed);
  rightMotor(speed);
}

void RoDIMotors::pivot(char speed)
{
  leftMotor(-speed);
  rightMotor(speed);
}

void RoDIMotors::rightMotor(char speed)
{
  if (speed == 0) {
    _rightServo.detach();
    _right_servo_attached = false;
  } else {
    if (!_right_servo_attached) {
      _rightServo.attach(RIGHT_SERVO);
      _right_servo_attached = true;
    }
    int tmp = map(speed, 100, -100, 0, 180);
    _HardSerial.print("left Servo=");
    _HardSerial.println(tmp);
    _rightServo.write(constrain(tmp, 0, 180));
  }
}

void RoDIMotors::leftMotor(char speed)
{
  if (speed == 0) {
    _leftServo.detach();
    _left_servo_attached = false;
  } else {
    if (!_left_servo_attached) {
      _leftServo.attach(LEFT_SERVO);
      _left_servo_attached = true;
    }
    int tmp = map(speed, -100, 100, 0, 180);
    _HardSerial.print("right Servo=");
    _HardSerial.println(tmp);
    _leftServo.write(constrain(tmp, 0, 180));
  }
}

void RoDIMotors::stop()
{
  _leftServo.detach();
  _left_servo_attached = false;
  _rightServo.detach();
  _right_servo_attached = false;
}
