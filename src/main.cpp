#include <Arduino.h>
#include <sweep.hpp>

void setup()
{
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  // pinMode(11, OUTPUT);
  pinMode(A0, INPUT);

  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  Serial.begin(9600);
}

void loop()
{
  /*
    Pin 3 is OC2B, or Timer 2 B output.
    Setting WGM21 with WGM22 and WGM 20 sets
    CTC mode, where the timer is reset every
    time the counter hits a value (set later as OCR2A)
  */
  TCCR2A |= _BV(COM2B0) | _BV(WGM21);

  /*
    Set the prescaler factor f_p
    f_p * freq = actual output frequency
    CS = clock select
    Table of values:
    Binary # | f_p value  | Decimal value
    0b001    | 1          | 1
    0b010    | 8          | 2
    0b011    | 32         | 3
    0b100    | 64         | 4
    0b101    | 128        | 5
    0b110    | 256        | 6
    0b111    | 1024       | 7

    The first 5 bits in the register are as follows:
    FOC2A, FOC2B, -, -, WGM22
    FOC = Force output compare.
    WGM set timer response (see above)

    Digital pins 3 and 11 were chosen because they follow
    timer 2, which has more granuality for choosing prescale
    factors.
  */

  // For example:
  TCCR2B |= _BV(CS21);
  // Sets a prescaler value of 8.

  uint8_t prescaler_state = 1;
  uint8_t counter_max = 0;
  uint8_t hold_time = 2000;

  sweep_and_print(prescaler_state, counter_max, hold_time);
}