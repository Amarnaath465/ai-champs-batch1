# Architecture — Industrial I/O Controller Node (Training Sample)

A small, host-buildable stand-in for a real Honeywell PA/IA/BA firmware node. No real hardware is used or required — every HAL function is a deterministic host-simulation stub, so the whole repository builds and tests with nothing but `gcc`/`make`.

## Module Layers

```
┌─────────────────────────────────────────────┐
│  Integration Layer                            │
│  fault_monitor.*  (not yet implemented —      │
│  today's Agent Mode exercise)                 │
└───────────────┬───────────────┬─────────────┘
                │               │
┌───────────────▼───┐   ┌───────▼───────────┐
│  Driver Layer       │   │  Logic Layer       │
│  can_driver.*        │   │  state_machine.*   │
│  sensor_poll.*        │   │  diag_formatter.*  │
└───────────────┬───┘   └───────────────────┘
                │
┌───────────────▼─────────────────────────────┐
│  HAL Layer (host-simulation stubs)           │
│  hal_gpio.*, hal_adc.*                        │
└───────────────────────────────────────────────┘
```

## Modules

| Module | Responsibility |
|---|---|
| `hal_gpio` / `hal_adc` | Lowest layer. Simulated digital/analog reads — the only place that would touch real registers on target hardware. |
| `can_driver` | CAN error-confinement state machine (ERROR_ACTIVE → ERROR_PASSIVE → BUS_OFF → recovery), per a simplified ISO 11898-1 model. |
| `sensor_poll` | Polls every sensor on the node in one pass and returns a snapshot with fault flags. |
| `state_machine` | Device-level state machine (INIT → CALIBRATING → RUNNING → FAULT → SAFE_SHUTDOWN) driven by discrete events. |
| `diag_formatter` | Formats diagnostic messages with module-grouped error codes (see `CODING_STANDARDS.md`). |
| `fault_monitor` | **Not yet implemented.** Integration point that watches the CAN driver and raises device-state-machine events + diagnostic messages when a fault occurs. See `include/fault_monitor.h` for the contract. |

## Layering Rules

1. **HAL is a leaf.** Nothing above the driver layer calls `hal_gpio_*`/`hal_adc_*` directly — only `can_driver` and `sensor_poll` do.
2. **Drivers don't know about the state machine.** `can_driver.c` has no dependency on `state_machine.h` — it only tracks its own error-confinement state. Translating a driver-level fault into a device-level event is the integration layer's job.
3. **The integration layer only uses public accessors.** `fault_monitor` must call `can_driver_get_state()`, never read `can_driver_t` fields directly — the struct's internals are allowed to change without breaking callers as long as the accessor contract holds.
4. **Diagnostics are cross-cutting.** Any layer may call `diag_format_message()`; it has no dependency on any other module.

## Why This Matters for Today's Lab

- The **explain** exercise uses `can_driver.c` and `state_machine.c` — both have non-obvious control flow (error-confinement thresholds, a transition table) that's exactly what Copilot Chat's repository-aware explanation is good at surfacing quickly.
- The **refactor** exercise uses `sensor_poll.c` — a single function doing five things, a realistic "written during bring-up, never revisited" pattern.
- The **debug** exercise's defect lives in `can_driver.c`'s error-confinement counter logic — a driver-layer bug, which is where the pre-programme calibration survey said engineers want the closest human review.
- The **Agent Mode** exercise is `fault_monitor` — a genuinely multi-file, repository-aware task that has to respect the layering rules above, which is exactly what a scoped Agent Mode prompt needs to get right.
