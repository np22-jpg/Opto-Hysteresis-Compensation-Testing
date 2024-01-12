#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  TCCR2A = 0b10100011;

  /*
    Set the prescaler frequency f_p
    f_p * freq = actual output frequency
    Table of values:
    Binary # | f_p value
    0b001    | 1
    0b010    | 8
    0b011    | 32
    0b100    | 64
    0b101    | 128
    0b110    | 256
    0b111    | 1024

    The first 5 bits in the register are as follows:
    FOC2A, FOC2B, -, -, WGM22
    FOC2x are both unused, and WGM22 is set to 0 in conjunction with TCCR2A to set fast PWM.
  */
  TCCR2B = 0b001;

  /*
    Set the duty cycle:
    (OCR2B + 1)/256 = ~50% duty cycle
    On the scope, this turns out to be more like 43% on and 57% off.
  */
  OCR2B = 127;
  OCR2A = 7;   // toggle after counting to 8
}