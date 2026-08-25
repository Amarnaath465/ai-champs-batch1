#include "sensor_poll.h"
#include "hal_adc.h"
#include "hal_gpio.h"

#define ADC_CH_TEMPERATURE  0u
#define ADC_CH_PRESSURE     1u
#define ADC_CH_FLOW         2u
#define GPIO_PIN_DOOR       4u
#define GPIO_PIN_MOTION     5u
#define TEMP_FAULT_HIGH     3800u
#define PRESSURE_FAULT_HIGH 3900u

/* Polls every sensor on the node in a single pass. Written as one block
 * during bring-up and never revisited — a candidate for extraction into
 * named per-sensor helpers now that the module list has grown. */
void sensor_poll_all(sensor_snapshot_t *out)
{
    out->fault_flags = 0;

    uint16_t temp = hal_adc_read(ADC_CH_TEMPERATURE);
    out->temperature_raw = temp;
    if (temp > TEMP_FAULT_HIGH) {
        out->fault_flags |= 0x01u;
    }

    uint16_t pressure = hal_adc_read(ADC_CH_PRESSURE);
    out->pressure_raw = pressure;
    if (pressure > PRESSURE_FAULT_HIGH) {
        out->fault_flags |= 0x02u;
    }

    uint16_t flow = hal_adc_read(ADC_CH_FLOW);
    out->flow_raw = flow;

    out->door_open = hal_gpio_read(GPIO_PIN_DOOR) ? 1u : 0u;
    out->motion_detected = hal_gpio_read(GPIO_PIN_MOTION) ? 1u : 0u;

    if (out->door_open && out->motion_detected) {
        out->fault_flags |= 0x04u;
    }
}
