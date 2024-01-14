#ifndef SWEEP_HEADER_FILE
#define SWEEP_HEADER_FILE
/**
 * @brief Performs a sweep operation and prints the results.
 *
 * This function takes in the state of TCCR2B and the value of OCR2A as parameters.
 * It performs a sweep operation and prints the results.
 *
 * @param TCCR2B_state The state of TCCR2B.
 * @param OCR2A_value The value of OCR2A.
 */
void sweep_and_print(uint8_t &TCCR2B_state, uint8_t &OCR2A_value, uint8_t &delayms);

#endif