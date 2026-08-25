# Coding Standards — Industrial I/O Controller Node (Training Sample)

A deliberately short standards doc — enough for Copilot (and you) to infer "the house style" from, matching what a real embedded team's repo-level conventions typically look like.

## Naming

- `snake_case` for functions, variables, and types.
- Every public symbol is prefixed with its owning module: `can_*` (CAN driver), `hal_*` (hardware abstraction), `diag_*` (diagnostics), `sensor_*` (sensor polling), `device_sm_*` (state machine), `fault_monitor_*` (fault integration).
- Types end in `_t`.
- Constants and macros are `UPPER_SNAKE_CASE`.

## Error Codes

Diagnostic error codes are 4-hex-digit values, grouped by owning module:

| Range | Module |
|---|---|
| `0x1xxx` | Sensor faults |
| `0x2xxx` | CAN driver faults |
| `0x3xxx` | State machine faults |

Add new codes to the matching range in `diag_formatter.h` — never reuse a code across modules.

## Headers

- Every header has an `#ifndef`/`#define`/`#endif` guard named after the file (`CAN_DRIVER_H`, not `_CAN_DRIVER_H_`).
- Public function declarations get a one-to-three-line comment above them describing behavior, not restating the name.
- Headers include only what they need (`<stdint.h>`, `<stdbool.h>`, `<stddef.h>` as appropriate) — no transitive reliance on another header having already included something.

## Functions

- No dynamic allocation (`malloc`/`free`) anywhere in this codebase — fixed-size buffers and caller-owned memory only.
- Return `bool` for success/failure where the caller needs to branch on it; return `size_t` for "how much did you write" style functions.
- Functions that mutate a "driver" or "state machine" struct take a pointer to it as the first argument.

## Layering

See `ARCHITECTURE.md` for the module layering rules — in short: HAL is the only layer allowed to be a leaf; nothing above it reaches around a driver to touch HAL directly.

## Comments

- Comment the *why*, not the *what* — if a comment just restates the code, delete it.
- Known technical debt or an intentionally-unimplemented function gets a `TODO` comment naming what's missing, not a vague `// fix later`.
