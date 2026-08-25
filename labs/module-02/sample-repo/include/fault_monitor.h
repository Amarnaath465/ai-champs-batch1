#ifndef FAULT_MONITOR_H
#define FAULT_MONITOR_H

/* NOT YET IMPLEMENTED. There is no fault_monitor.c in this repository yet —
 * creating it, correctly, across the three modules below, is Module 02's
 * Agent Mode exercise (04-agent-mode-repository-task.md).
 *
 * Intended contract for fault_monitor_check():
 *
 *   Called once per control-loop tick, after can_driver_tick(). If the CAN
 *   driver has just transitioned into CAN_STATE_BUS_OFF since the last
 *   call to fault_monitor_check() (i.e. this is a new fault, not a fault
 *   that was already reported):
 *
 *     1. Raise DEV_EVENT_FAULT_DETECTED on the device state machine via
 *        device_sm_handle_event().
 *     2. Format a diagnostic message into diag_buf using
 *        diag_format_message() with DIAG_ERR_CAN_BUSOFF and a short,
 *        human-readable detail string (e.g. "CAN bus-off detected").
 *     3. Return true.
 *
 *   Otherwise, return false and leave diag_buf untouched.
 *
 *   Must not reach into can_driver_t's fields directly — only call the
 *   public can_driver_get_state() accessor. See docs/ARCHITECTURE.md,
 *   "Layering Rules", for why.
 */

#include <stddef.h>
#include <stdbool.h>
#include "can_driver.h"
#include "state_machine.h"

typedef struct {
    can_error_state_t last_seen_state;
} fault_monitor_t;

void fault_monitor_init(fault_monitor_t *mon, const can_driver_t *can);

bool fault_monitor_check(fault_monitor_t *mon, const can_driver_t *can,
                          device_state_machine_t *sm, char *diag_buf, size_t diag_buf_len);

#endif /* FAULT_MONITOR_H */
