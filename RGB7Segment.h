/*
  RGB7Segment.h - Library for running RGB 7 Segment.
  Adafruit product: https://www.adafruit.com/products/1399
  Created by Sean McIntyre, August 2014.
  Released into the public domain.
*/
#ifndef RGB7SEGMENT_H
#define RGB7SEGMENT_H

#include "Arduino.h"
#include "Tlc5940.h"

#define RGB7SEGMENT_NUM_PINS 24
#define RGB7SEGMENT_PINMAP_RED_OFFSET 0
#define RGB7SEGMENT_PINMAP_GREEN_OFFSET 1
#define RGB7SEGMENT_PINMAP_BLUE_OFFSET 2

class RGB7Segment {
  public:
    RGB7Segment();
    void init(int numUnits);
    void selectUnit(int unitNum);
    void setSegment(int idx, int cRed, int cBlue, int cGreen);
    void setDigit(int value, int cRed, int cBlue, int cGreen);
    void update();

  private:
    int numUnits;
    int activeUnit;

	static int pinmap[24];
	static int bitmap[10];
};

#endif