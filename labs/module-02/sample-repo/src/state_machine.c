#include "state_machine.h"
#include <stddef.h>

/* Transition table: [current_state][event] -> next_state, or
 * DEV_STATE_COUNT if the transition is not legal from that state.
 *
 * Columns follow device_event_t order:
 *   START_CAL, CAL_DONE, CAL_FAILED, FAULT_DETECTED, FAULT_CLEARED, SHUTDOWN_REQUESTED
 */
static const device_state_t transition_table[DEV_STATE_COUNT][DEV_EVENT_COUNT] = {
    /* INIT */
    { DEV_STATE_CALIBRATING, DEV_STATE_COUNT,     DEV_STATE_COUNT, DEV_STATE_COUNT, DEV_STATE_COUNT, DEV_STATE_SAFE_SHUTDOWN },
    /* CALIBRATING */
    { DEV_STATE_COUNT,       DEV_STATE_RUNNING,   DEV_STATE_FAULT, DEV_STATE_FAULT, DEV_STATE_COUNT, DEV_STATE_SAFE_SHUTDOWN },
    /* RUNNING */
    { DEV_STATE_COUNT,       DEV_STATE_COUNT,     DEV_STATE_COUNT, DEV_STATE_FAULT, DEV_STATE_COUNT, DEV_STATE_SAFE_SHUTDOWN },
    /* FAULT */
    { DEV_STATE_COUNT,       DEV_STATE_COUNT,     DEV_STATE_COUNT, DEV_STATE_COUNT, DEV_STATE_RUNNING, DEV_STATE_SAFE_SHUTDOWN },
    /* SAFE_SHUTDOWN (terminal) */
    { DEV_STATE_COUNT,       DEV_STATE_COUNT,     DEV_STATE_COUNT, DEV_STATE_COUNT, DEV_STATE_COUNT, DEV_STATE_COUNT }
};

void device_sm_init(device_state_machine_t *sm)
{
    sm->current = DEV_STATE_INIT;
}

bool device_sm_handle_event(device_state_machine_t *sm, device_event_t event)
{
    device_state_t next = transition_table[sm->current][event];
    if (next == DEV_STATE_COUNT) {
        return false;
    }
    sm->current = next;
    return true;
}

device_state_t device_sm_get_state(const device_state_machine_t *sm)
{
    return sm->current;
}
