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

#define MAX_DISTANCE_US   200

RoDISonars::RoDISonars():
    _left_sonar(LEFT_US_TRIGGER, LEFT_US_ECHO, MAX_DISTANCE_US),
    _center_sonar(CENTER_US_TRIGGER, CENTER_US_ECHO, MAX_DISTANCE_US),
    _right_sonar(RIGHT_US_TRIGGER, RIGHT_US_ECHO, MAX_DISTANCE_US)
{
}

// Returns the echo time in microseconds
unsigned int RoDISonars::read(SONAR sensor)
{
  if(sensor == LEFT){
    return _left_sonar.ping();
  }else if(sensor == CENTER){
    return _center_sonar.ping();
  }else if(sensor == RIGHT){
    return _right_sonar.ping();
  }
}

// Returns the distance in cm
unsigned int RoDISonars::read_cm(SONAR sensor)
{
  if(sensor == LEFT){
    return _left_sonar.ping_cm();
  }else if(sensor == CENTER){
    return _center_sonar.ping_cm();
  }else if(sensor == RIGHT){
    return _right_sonar.ping_cm();
  }
}
