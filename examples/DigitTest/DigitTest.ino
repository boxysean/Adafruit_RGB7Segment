#include "RGB7Segment.h"
#include "Tlc5940.h"

/* How to use:

(1) Solder up board
(2) Download TLC5940.h library
(3) Change number of TLCs in tlc_config.h to 2

*/

RGB7Segment seg;

int redValues[] = { 100, 0, 0 };
int greenValues[] = { 0, 100, 0 };
int blueValues[] = { 0, 0, 100 };

void setup() {
  seg.init(1);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    for (int x = 0; x < 10; x++) {
      seg.setDigit(x, redValues[i], greenValues[i], blueValues[i]);
      seg.update();
      Serial.println(x);
      delay(100);
    }
  }
}






