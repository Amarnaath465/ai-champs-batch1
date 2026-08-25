#include "hal_adc.h"

/* Host-simulation stub: real register access is replaced with a
 * deterministic pattern so the same sequence of calls always produces the
 * same readings during training. */
uint16_t hal_adc_read(uint8_t channel)
{
    static uint16_t seed = 100;
    seed = (uint16_t)(seed + channel * 17u + 3u);
    return (uint16_t)(seed % (HAL_ADC_RAW_MAX + 1u));
}

uint16_t hal_adc_raw_to_millivolts(uint16_t raw)
{
    if (raw > HAL_ADC_RAW_MAX) {
        raw = HAL_ADC_RAW_MAX;
    }
    return (uint16_t)(((uint32_t)raw * HAL_ADC_VREF_MV) / HAL_ADC_RAW_MAX);
}
