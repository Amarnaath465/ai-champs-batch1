#ifndef HAL_ADC_H
#define HAL_ADC_H

#include <stdint.h>

#define HAL_ADC_MAX_CHANNEL 7u
#define HAL_ADC_RAW_MAX     4095u /* 12-bit ADC */
#define HAL_ADC_VREF_MV     3300u

/* Reads a raw 12-bit sample from the given channel. */
uint16_t hal_adc_read(uint8_t channel);

/* Converts a raw 12-bit ADC reading to millivolts against HAL_ADC_VREF_MV.
 * Clamps the input to [0, HAL_ADC_RAW_MAX] before converting, so an
 * out-of-range raw value never produces an out-of-range millivolt result. */
uint16_t hal_adc_raw_to_millivolts(uint16_t raw);

#endif /* HAL_ADC_H */
