#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

/* CAN controller error-confinement states, simplified from ISO 11898-1. */
typedef enum {
    CAN_STATE_ERROR_ACTIVE = 0,
    CAN_STATE_ERROR_PASSIVE,
    CAN_STATE_BUS_OFF
} can_error_state_t;

typedef struct {
    uint32_t id;
    uint8_t  dlc;
    uint8_t  data[8];
} can_message_t;

typedef struct {
    can_error_state_t state;
    uint8_t  tx_error_count;
    uint8_t  consecutive_failures;
    uint32_t bus_off_recovery_ticks;
} can_driver_t;

#define CAN_BUS_OFF_THRESHOLD      8u
#define CAN_BUS_OFF_RECOVERY_TICKS 128u

void can_driver_init(can_driver_t *drv);

/* Sends msg on the bus. simulate_tx_failure lets host-based tests force a
 * transmit error without real hardware, to exercise the retry / bus-off
 * error-confinement path. Returns true on a successful send. */
bool can_driver_send(can_driver_t *drv, const can_message_t *msg, bool simulate_tx_failure);

/* Advances bus-off recovery timing by one tick. Call once per control-loop
 * iteration regardless of driver state. */
void can_driver_tick(can_driver_t *drv);

can_error_state_t can_driver_get_state(const can_driver_t *drv);

#endif /* CAN_DRIVER_H */
