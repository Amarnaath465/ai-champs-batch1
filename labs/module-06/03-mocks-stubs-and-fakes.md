# Exercise 3: Mocks, Stubs & Fakes

**Duration:** 25 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Test hardware-dependent interfaces without hardware in the loop — and close two of Exercise 1's three gaps along the way.

## Three Techniques, One Goal

| Technique | What it does |
|---|---|
| **Stub** | Returns canned data, nothing more — replace a sensor-read function with one that always returns a fixed value, enough to test the logic that consumes it |
| **Mock** | Verifies how it was called — replace a driver call with one that records whether, and how, it was invoked, then assert on that behavior |
| **Fake** | A working, simplified substitute — a lightweight in-memory implementation of something with real hardware constraints, providing real behavior without those constraints |

---

## Step 1 — Recognize What's Already In the Codebase (5 minutes)

Open `docs/ARCHITECTURE.md`. `hal_adc.c` and `hal_gpio.c` are described as "host-simulation stubs" — and they are stubs by the definition above: no real register access, deterministic behavior instead. But look closer at `src/hal_gpio.c`:

```c
bool hal_gpio_read(uint8_t pin)
{
    return (pin % 3u) == 0u;
}
```

`sensor_poll.c` reads `GPIO_PIN_DOOR` (4) and `GPIO_PIN_MOTION` (5). Compute `4 % 3` and `5 % 3` by hand. What do you get — and what does that mean for whether the door+motion fault path (`fault_flags` bit 2) can *ever* actually trigger, with this stub, no matter what a test does?

This is a real, verified finding: with the shipped HAL stub, the door+motion fault condition is **permanently unreachable** — not "hard to hit," genuinely impossible. A stub that's deterministic isn't the same as a stub that's *test-controllable*. That gap is exactly what a **fake** fixes.

## Step 2 — Build a Fake HAL (12 minutes)

Create `tests/fakes/hal_adc_fake.h` and `tests/fakes/hal_adc_fake.c`, implementing the real `hal_adc.h` interface (`hal_adc_read`, `hal_adc_raw_to_millivolts`) plus two new functions:

```c
void hal_adc_fake_reset(void);
void hal_adc_fake_set_reading(uint8_t channel, uint16_t raw_value);
```

`hal_adc_read(channel)` should simply return whatever was last set for that channel via `hal_adc_fake_set_reading` (defaulting to 0). This is deterministic *and* test-controllable — the missing property the real stub doesn't have.

Do the same for `tests/fakes/hal_gpio_fake.h`/`.c`: a `hal_gpio_fake_set_pin(pin, level)` setter and a `hal_gpio_fake_reset()`, backing a `hal_gpio_read(pin)` that returns whatever was set.

Ask Copilot to generate both, prompting with the real `hal_adc.h`/`hal_gpio.h` contracts and this exact requirement — a settable, resettable, deterministic substitute.

**Wire it into the build.** A test that links these fakes can't *also* link the real `src/hal_adc.c`/`src/hal_gpio.c` — both define `hal_adc_read`, and the linker will reject the duplicate symbol. Add this to `Makefile`:

```makefile
SRC_NO_HAL := src/can_driver.c src/sensor_poll.c src/state_machine.c src/diag_formatter.c src/event_log.c
FAKES := tests/fakes/hal_adc_fake.c tests/fakes/hal_gpio_fake.c

bin/test_device_e2e: tests/test_device_e2e.c $(SRC_NO_HAL) $(FAKES) | bin
	$(CC) $(CFLAGS) -Itests/fakes -o $@ $< $(SRC_NO_HAL) $(FAKES)
```

This explicit rule takes precedence over the Makefile's existing generic `bin/%: tests/%.c $(SRC) | bin` pattern rule for this one target name — every other `tests/test_*.c` file still builds against the real HAL exactly as before. `tests/test_device_e2e.c` doesn't need to exist yet for this rule to be valid; Exercise 5 writes it.

## Step 3 — Close the Two Unit-Level Gaps From Exercise 1 (8 minutes)

Create `tests/test_event_log_boundary.c`:

1. **The capacity-1 boundary test.** Record exactly `EVENT_LOG_CAPACITY - 1` entries. Assert `event_log_count()` reports `EVENT_LOG_CAPACITY - 1` and `event_log_dropped_count()` is still zero.
2. **The `NULL`-out negative test.** Call `event_log_get(&log, 0, NULL)` and assert it returns `false` — not that it crashes.

Run `make test` now, before fixing anything. The second test should crash the binary (a segfault) — this is Exercise 1's discovery made concrete: a real, currently-shipped gap.

**Fix it.** Open `src/event_log.c` and find `event_log_get`. Add the missing guard, matching the same defensive-NULL-check convention `diag_format_message` already uses for its `buf` parameter:

```c
bool event_log_get(const event_log_t *log, size_t index, event_log_entry_t *out)
{
    if (out == NULL || index >= log->count) {
        return false;
    }
    /* ...unchanged... */
}
```

Rebuild and rerun. Both new tests should now pass.

---

## Checkpoint

- [ ] `tests/fakes/hal_adc_fake.{h,c}` and `tests/fakes/hal_gpio_fake.{h,c}` exist, with reset + setter functions for every channel/pin you'll need
- [ ] The Makefile has a working `bin/test_device_e2e` rule that links the fakes instead of the real HAL
- [ ] `tests/test_event_log_boundary.c` exists with both new tests passing
- [ ] `src/event_log.c`'s `event_log_get` now guards against a `NULL` `out` pointer
- [ ] You personally watched the negative test crash *before* the fix, and pass *after* — not just applied the fix on faith

## Where This Goes Next

Exercise 4 runs the automated gate — static analysis, build validation, and a sanitizer build — across everything built so far, including today's new files. Exercise 5 uses the fakes you just built to close the third gap: the missing multi-module E2E test.
