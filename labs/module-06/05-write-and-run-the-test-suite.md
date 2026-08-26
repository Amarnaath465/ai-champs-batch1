# Exercise 5: Write & Run the Test Suite

**Duration:** 35 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Close the last gap from Exercise 1 — the missing software-level E2E test — using the fakes you built in Exercise 3. Then run the complete regression suite and treat a full green run as what it actually is: proof that Module 05's brownfield change didn't break anything, not an assumption.

## Regression Testing: Proving Nothing Broke

| Without regression testing | With regression testing |
|---|---|
| A brownfield change "works" by only checking the new behavior | The full existing test suite runs against every brownfield change, not just new tests |
| Existing callers of the changed interface are assumed safe, not verified | A failing existing test is the strategy working — caught before merge, not after |
| A regression surfaces in the field, weeks after the change shipped | Behavior preservation from Module 05's checklist becomes provable, not assumed |

---

## Step 1 — Write `tests/test_device_e2e.c` (20 minutes)

This test exercises three modules together in one realistic pass: `sensor_poll` (driven deterministically by the fakes from Exercise 3), `can_driver`, and `event_log`.

Prompt Copilot with the specific scenario, not a generic request:

> "Write tests/test_device_e2e.c using the minitest.h pattern. Include hal_adc_fake.h and hal_gpio_fake.h from tests/fakes/. Test 1: reset the fakes, force channel 0 (temperature) to read 4000 (above sensor_poll.c's TEMP_FAULT_HIGH of 3800), call sensor_poll_all, and assert the temperature fault bit is set. Then, in the same test, init a can_driver_t and event_log_t, attach the log, drive CAN_BUS_OFF_THRESHOLD + 1 simulated failures, assert the driver reaches CAN_STATE_BUS_OFF and the event log recorded exactly one entry, then tick through the full recovery window and assert the driver returns to CAN_STATE_ERROR_ACTIVE. Test 2: reset the fakes, set a nominal (low) temperature reading, and assert sensor_poll_all reports zero fault flags."

Read the generated test against what it's supposed to prove: does it actually use the fakes to force a specific, known reading — or does it accidentally fall back to whatever the real HAL would have produced? The whole point of Exercise 3's fakes was to make this deterministic; a test that doesn't actually call `hal_adc_fake_set_reading` before asserting on fault behavior isn't testing what it claims to.

Build just this one target and confirm it passes on its own before running the full suite:

```sh
make bin/test_device_e2e
./bin/test_device_e2e
```

## Step 2 — Run the Full Suite (10 minutes)

```sh
make clean
make test
```

Every binary in the repository should now build and pass — the original `test_can_driver.c` from Module 02, `test_sensor_poll.c` if you built it in Module 04, `test_event_log.c` and `test_can_driver_event_log.c` from Module 05, and today's `test_event_log_boundary.c` and `test_device_e2e.c`.

This full green run **is** the regression-testing proof the table above describes — not a formality, the actual evidence. Module 05's brownfield change to `can_driver.c` is proven safe specifically because `test_can_driver.c` (a file that change never touched) still passes unmodified, alongside everything new.

## Step 3 — Update the Test Strategy Table (5 minutes)

Go back to `sample-repo/specs/002-event-log-diagnostics/test-strategy.md` from Exercise 1. Move all three `Gap` rows to `Covered`, naming the test that now closes each one:

| Source | Acceptance Criterion / Guarantee | Existing Test | Status |
|---|---|---|---|
| Exercise 1 gap | Boundary: one below capacity | `test_one_below_capacity_reports_no_drop` | Covered |
| Exercise 1 gap | Negative: `NULL` out pointer | `test_get_with_null_out_returns_false_not_crash` | Covered |
| Exercise 1 gap | Multi-module E2E scenario | `test_temperature_fault_and_busoff_recorded_in_one_pass` | Covered |

If any row still can't point to a real, verified test, that's not a paperwork problem — go back and close it before Exercise 6.

---

## Checkpoint

- [ ] `tests/test_device_e2e.c` exists, genuinely uses the fakes to force deterministic sensor readings, and passes standalone
- [ ] `make test` is fully green across every binary in the repository, with zero rows left as `Gap` in `test-strategy.md`
- [ ] You can name, specifically, which existing file proves Module 05's brownfield change didn't break anything (`test_can_driver.c`, unmodified)

## Where This Goes Next

Everything so far has proven the strategy covers what's specified. Exercise 6 proves the strategy actually *works* — by breaking something on purpose and watching the suite catch it.
