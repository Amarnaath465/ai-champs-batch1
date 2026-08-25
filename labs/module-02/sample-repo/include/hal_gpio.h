#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>
#include <stdbool.h>

/* Reads the logic level of a digital input pin. */
bool hal_gpio_read(uint8_t pin);

#endif /* HAL_GPIO_H */
