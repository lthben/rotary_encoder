/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 * 
 * 1600 values per revolution
 */
 
// This optional setting causes Encoder to use more optimized code,
// It must be defined before Encoder.h is included.
#define ENCODER_OPTIMIZE_INTERRUPTS 
#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability

Encoder myEnc(2, 3); //white (pin 2), green (pin 3) 
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
//  Serial.println("Basic Encoder Test:");
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    if (newPosition%40 == 0) {
        Serial.println(newPosition); //throttle below 9600bytes/s
    }
  }
}
