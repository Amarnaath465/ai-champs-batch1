#include "hal_gpio.h"

/* Host-simulation stub: no real hardware register access is available in
 * this training lab, so pin state follows a deterministic pattern instead. */
bool hal_gpio_read(uint8_t pin)
{
    return (pin % 3u) == 0u;
}
