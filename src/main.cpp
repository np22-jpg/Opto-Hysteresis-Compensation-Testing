#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;
}

void loop() {
  /*
    Pin 3 is OC2B, or Timer 2 B output.
    Setting WGM21 with WGM22 and WGM 20 sets
    CTC mode, where the timer is reset every
    time the counter hits a value (set later as OCR2A)
  */
  TCCR2A |= _BV(COM2B0) | _BV(WGM21);

  /*
    Set the prescaler frequency f_p
    f_p * freq = actual output frequency
    CS = clock select
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
    FOC = Force output compare.
    WGM set timer response (see above)
  */
  TCCR2B |= _BV(CS20);

  /*
    Set the frequency (via max count)
    Every time the counter (incremented each clock cycle)
    hits this value, the output is toggled.
    So 16mhz = 16,000,000/2(OCR2B+1) = output frequency
    (Keep in mind the counter starts at 0)
    */
  OCR2A = 50;
  OCR2B = OCR2A;
}