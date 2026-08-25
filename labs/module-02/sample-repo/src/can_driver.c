#include "can_driver.h"
#include <string.h>

void can_driver_init(can_driver_t *drv)
{
    memset(drv, 0, sizeof(*drv));
    drv->state = CAN_STATE_ERROR_ACTIVE;
}

bool can_driver_send(can_driver_t *drv, const can_message_t *msg, bool simulate_tx_failure)
{
    (void)msg;

    if (simulate_tx_failure) {
        drv->consecutive_failures++;
        drv->tx_error_count = drv->consecutive_failures;
        drv->consecutive_failures = 0;

        if (drv->tx_error_count > CAN_BUS_OFF_THRESHOLD) {
            drv->state = CAN_STATE_BUS_OFF;
            drv->bus_off_recovery_ticks = CAN_BUS_OFF_RECOVERY_TICKS;
        } else if (drv->tx_error_count > CAN_BUS_OFF_THRESHOLD / 2) {
            drv->state = CAN_STATE_ERROR_PASSIVE;
        }
        return false;
    }

    drv->consecutive_failures = 0;
    drv->tx_error_count = 0;
    if (drv->state != CAN_STATE_BUS_OFF) {
        drv->state = CAN_STATE_ERROR_ACTIVE;
    }
    return true;
}

void can_driver_tick(can_driver_t *drv)
{
    if (drv->state == CAN_STATE_BUS_OFF && drv->bus_off_recovery_ticks > 0) {
        drv->bus_off_recovery_ticks--;
        if (drv->bus_off_recovery_ticks == 0) {
            drv->state = CAN_STATE_ERROR_ACTIVE;
            drv->tx_error_count = 0;
        }
    }
}

can_error_state_t can_driver_get_state(const can_driver_t *drv)
{
    return drv->state;
}
