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

// Array with the notes in the melody (see pitches.h for reference)
int imperial_melody[] = {440, 440, 440, 349, 523, 440, 349, 523, 440, 659, 659, 659, 698, 523, 440, 349, 523, 440};

// Array with the note durations: a quarter note has a duration of 4, half note 2 etc.
int imperial_duration[] = {500, 500, 500, 400, 125, 500, 400, 125, 1000, 500, 500, 500, 400, 125, 500, 400, 125, 1000};

RoDIBuzzer::RoDIBuzzer() {};

void RoDIBuzzer::play_tone(unsigned int frequency)
{
  tone(BUZZER, frequency);
}

void RoDIBuzzer::play_tone(unsigned int frequency, unsigned long duration)
{
  tone(BUZZER, frequency, duration);
}

void RoDIBuzzer::play_melody(int melody)
{
  int size;
  switch (melody)
  {
    case 0:
      size = sizeof(imperial_melody) / sizeof(int);
      break;
    default:
      size = sizeof(imperial_melody) / sizeof(int);
      break;
  }

  int noteDuration;
  int current_note;
  for (int thisNote = 0; thisNote < size; thisNote++) {
    switch (melody)
    {
      case 0:
        noteDuration = imperial_duration[thisNote];
        current_note = imperial_melody[thisNote];
        break;
      default:
        break;
    }
    tone(BUZZER, current_note, noteDuration);
    delay(noteDuration * 1.3);
    noTone(BUZZER);
  }
}



