#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdbool.h>

typedef enum {
    DEV_STATE_INIT = 0,
    DEV_STATE_CALIBRATING,
    DEV_STATE_RUNNING,
    DEV_STATE_FAULT,
    DEV_STATE_SAFE_SHUTDOWN,
    DEV_STATE_COUNT
} device_state_t;

typedef enum {
    DEV_EVENT_START_CAL = 0,
    DEV_EVENT_CAL_DONE,
    DEV_EVENT_CAL_FAILED,
    DEV_EVENT_FAULT_DETECTED,
    DEV_EVENT_FAULT_CLEARED,
    DEV_EVENT_SHUTDOWN_REQUESTED,
    DEV_EVENT_COUNT
} device_event_t;

typedef struct {
    device_state_t current;
} device_state_machine_t;

void device_sm_init(device_state_machine_t *sm);

/* Applies event to the state machine per the transition table in
 * state_machine.c. Returns false and leaves the state unchanged if the
 * event is not legal from the current state. */
bool device_sm_handle_event(device_state_machine_t *sm, device_event_t event);

device_state_t device_sm_get_state(const device_state_machine_t *sm);

#endif /* STATE_MACHINE_H */
