#include "diag_formatter.h"
#include <stdio.h>

size_t diag_format_message(char *buf, size_t buf_len, diag_error_code_t code, const char *detail)
{
    if (buf == NULL || buf_len == 0) {
        return 0;
    }
    int written = snprintf(buf, buf_len, "[0x%04X] %s", (unsigned)code, detail);
    if (written < 0 || (size_t)written >= buf_len) {
        return 0;
    }
    return (size_t)written;
}

/* diag_format_sensor_fault intentionally left unimplemented — see the TODO
 * in diag_formatter.h. This is Module 02, Exercise 1's inline-assist task. */
