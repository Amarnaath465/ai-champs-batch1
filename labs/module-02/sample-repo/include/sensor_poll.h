#ifndef SENSOR_POLL_H
#define SENSOR_POLL_H

#include <stdint.h>

typedef struct {
    uint16_t temperature_raw;
    uint16_t pressure_raw;
    uint16_t flow_raw;
    uint8_t  door_open;
    uint8_t  motion_detected;
    uint8_t  fault_flags; /* bit0=temp high, bit1=pressure high, bit2=door+motion */
} sensor_snapshot_t;

/* Polls every sensor on the node in one pass and fills out. */
void sensor_poll_all(sensor_snapshot_t *out);

#endif /* SENSOR_POLL_H */
