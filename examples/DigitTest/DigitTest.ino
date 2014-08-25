#include "RGB7Segment.h"
#include "Tlc5940.h"

/* How to use:

(1) Solder up board. Use a 3.3K resistor and 0.1uF capacitor in the appropriate places. Use plenty of flux on the SMD bit.
(2) Download TLC5940 library (see README for link)
(3) Change number of TLCs in Tlc5940/tlc_config.h to 2
(4) Plug in board as follows:

    Basic Pin setup:
    ------------      
    ARDUINO   13|-> CL
              12|     
              11|-> IN
              10|-> BL
               9|-> XL
               8|     
               7|     
               6|     
               5|     
               4|     
               3|
               2|
               1|
               0|
    ------------ 

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





