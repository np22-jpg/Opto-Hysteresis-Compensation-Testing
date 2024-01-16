#include <Arduino.h>
#include <sweep.hpp>

void sweep_and_print(uint8_t &TCCR2B_state, uint8_t &OCR2A_value, uint32_t &delayms)
{
  uint32_t currentfreq = 0;
  uint32_t prescaler_factor = 0;

  // Set D3 to output
  TCCR2B = TCCR2B_state;
  OCR2A = OCR2A_value;
  OCR2B = OCR2A_value;


  // Map prescaler state to prescaler factor
  switch (TCCR2B_state)
  {
  case 1:
    prescaler_factor = 1;
    break;
  case 2:
    prescaler_factor = 8;
    break;
  case 3:
    prescaler_factor = 32;
    break;
  case 4:
    prescaler_factor = 64;
    break;
  case 5:
    prescaler_factor = 128;
    break;
  case 6:
    prescaler_factor = 256;
    break;
  case 7:
    prescaler_factor = 1024;
    break;
  default:
    Serial.print("Error!");
    break;
  }

  // Calculate current frequency
  currentfreq = 16000000 / (2 * (OCR2A_value + 1) * prescaler_factor);

  // Print results
  Serial.print("TCCR2B_state: ");
  Serial.println(TCCR2B_state);
  Serial.print("Prescaler factor: ");
  Serial.println(prescaler_factor);
  Serial.print("Counter limit: ");
  Serial.println(OCR2A_value);
  Serial.print("Frequency (Hz): ");
  Serial.println(currentfreq);

  delay(delayms);
}