#ifndef DIAG_FORMATTER_H
#define DIAG_FORMATTER_H

#include <stddef.h>

typedef enum {
    DIAG_ERR_NONE           = 0x0000,
    DIAG_ERR_SENSOR_OOR     = 0x1001, /* sensor reading out of range */
    DIAG_ERR_CAN_BUSOFF     = 0x2001, /* CAN controller entered bus-off */
    DIAG_ERR_STATE_INVALID  = 0x3001  /* illegal state transition attempted */
} diag_error_code_t;

/* Formats a diagnostic message as "[0xCCCC] <detail>" into buf.
 * Returns the number of characters written (excluding the null
 * terminator), or 0 if buf was too small or NULL. */
size_t diag_format_message(char *buf, size_t buf_len, diag_error_code_t code, const char *detail);

/* TODO (Module 02, Exercise 1 — inline-assist): diag_format_sensor_fault
 *
 * Same formatting style as diag_format_message above, but takes a sensor
 * channel id and a raw reading, and produces:
 *   "[0x1001] sensor <channel> out of range (raw=<value>)"
 *
 * Follow the DIAG_ERR_* naming already used above and the snprintf-based
 * pattern in diag_formatter.c. Add the declaration here and the
 * implementation in diag_formatter.c.
 */

#endif /* DIAG_FORMATTER_H */
