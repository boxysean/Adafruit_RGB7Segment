/*
  RGB7Segment.cpp - Library for running RGB 7 Segment.
  Adafruit product: https://www.adafruit.com/products/1399
  Created by Sean McIntyre, August 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RGB7Segment.h"

int RGB7Segment::pinmap[24] = {
    20, 19, 18, // RGB pins for segment 0
    23, 22, 21, // RGB pins for segment 1
    4, 3, 5,    // RGB pins for segment 2
    6, 7, 8,    // RGB pins for segment 3
    9, 10, 11,  // RGB pins for segment 4
    14, 12, 13, // RGB pins for segment 5
    17, 16, 15  // RGB pins for segment 6
};

int RGB7Segment::bitmap[10] = {
    B0111111,
    B0000110,
    B1011011,
    B1001111,
    B1100110,
    B1101101,
    B1111101,
    B0000111,
    B1111111,
    B1100111
};


RGB7Segment::RGB7Segment() {
  this->activeUnit = 0;
}

void RGB7Segment::init(int numUnits = 1) {
  if (numUnits < 1) {
    numUnits = 1;
  }

  this->numUnits = numUnits;

  Tlc.init();
}

void RGB7Segment::selectUnit(int unitNum) {
  if (unitNum >= numUnits || unitNum < 0) {
    return;
  }

  this->activeUnit = unitNum;
}

void RGB7Segment::setSegment(int idx, int cRed, int cBlue, int cGreen) {
  int baseIdx = (this->activeUnit * RGB7SEGMENT_NUM_PINS) + (idx * 3);

  Tlc.set(pinmap[baseIdx + RGB7SEGMENT_PINMAP_RED_OFFSET], cRed);
  Tlc.set(pinmap[baseIdx + RGB7SEGMENT_PINMAP_BLUE_OFFSET], cBlue);
  Tlc.set(pinmap[baseIdx + RGB7SEGMENT_PINMAP_GREEN_OFFSET], cGreen);
}

void RGB7Segment::setDigit(int value, int cRed, int cBlue, int cGreen) {
  int data = this->bitmap[value];
  for (int index = 0; index < 8; index++) {
    int mask = (1 << index);
    int test = (mask & data);
    if (test != 0) {
      this->setSegment(index, cRed, cBlue, cGreen); 
    } else {
      this->setSegment(index, 0, 0, 0); 
    }
  }
}

void RGB7Segment::update() {
  Tlc.update();
}
