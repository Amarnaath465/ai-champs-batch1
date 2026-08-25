# Sample Repository — Industrial I/O Controller Node

A small, host-buildable C codebase used for the Module 02 hands-on lab (GitHub Copilot Enterprise Features for Embedded Engineering). It simulates a generic Honeywell PA/IA/BA field controller node: a CAN driver, sensor polling, a device state machine, and a diagnostics formatter — all host-testable with zero external dependencies.

See [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md) for the module layering and [`docs/CODING_STANDARDS.md`](docs/CODING_STANDARDS.md) for naming/error-code conventions. See the [Module 02 lab exercises](../) for what to actually do with this repository.

## Build & Test

```sh
make test
```

This compiles every `tests/test_*.c` against the shared sources and runs each resulting binary. **On a fresh checkout, expect failures** — `tests/test_can_driver.c` currently fails because of a defect deliberately left in `src/can_driver.c` for the Module 02 debugging exercise (see `02-debug-a-defect.md`). That's expected; don't "fix" it before Exercise 2.

```sh
make clean   # remove build artifacts
```

## Layout

```
include/          public headers (one per module)
src/               implementations
tests/             host-based tests (tests/minitest.h is a ~40-line zero-dependency assert harness)
docs/              architecture and coding-standards reference
```

## Modules

| Module | Status |
|---|---|
| `can_driver` | Implemented, contains an intentional defect (Exercise 2) |
| `sensor_poll` | Implemented, intentionally monolithic (Exercise 1 refactor target) |
| `state_machine` | Implemented, fully working |
| `diag_formatter` | Partially implemented — `diag_format_sensor_fault` is a TODO (Exercise 1 inline-assist target) |
| `hal_gpio` / `hal_adc` | Implemented host-simulation stubs |
| `fault_monitor` | **Not implemented** — header contract only, this is the Exercise 4 Agent Mode deliverable |

No hardware integration is required or demonstrated anywhere in this repository — all HAL functions are deterministic host-simulation stubs, consistent with the programme's software-level-only scope.
