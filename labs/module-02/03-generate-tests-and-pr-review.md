# Exercise 3: Generate Tests & Review a PR

**Duration:** 20 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Generate host-based unit tests for an untested HAL wrapper — including the boundary and negative cases that get skipped under deadline pressure — then commit your changes and run a Copilot-assisted PR/code-review pass before merging.

## Prerequisites

Completed [Exercise 2](02-debug-a-defect.md) — `make test` should show 6 passed, 0 failed before you start.

---

## Part A — Generate Tests for `hal_adc_raw_to_millivolts` (10 minutes)

**File to test:** `sample-repo/include/hal_adc.h` (no test file exists for this module yet)

1. Open `include/hal_adc.h`. Read `hal_adc_raw_to_millivolts`'s doc comment — it converts a raw 12-bit ADC value to millivolts and clamps out-of-range input.
2. Create `tests/test_hal_adc.c`. Include `hal_adc.h` and `minitest.h` (copy the `#include`/`main`/`MT_RUN` pattern from `tests/test_can_driver.c` — Copilot will pick up the pattern from context once you have the first few lines in place).
3. Ask Copilot Chat:
   > "Generate host-based unit tests for hal_adc_raw_to_millivolts using the MT_ASSERT_EQ pattern from minitest.h. Include boundary cases (0, HAL_ADC_RAW_MAX) and at least one out-of-range/negative case (a raw value above HAL_ADC_RAW_MAX) to confirm clamping."
4. Before accepting, check the generated test list against this minimum set — add any that are missing:
   - [ ] `raw = 0` → `0` mV
   - [ ] `raw = HAL_ADC_RAW_MAX` (4095) → `HAL_ADC_VREF_MV` (3300) mV
   - [ ] `raw = HAL_ADC_RAW_MAX + 500` (out-of-range) → clamps to `HAL_ADC_VREF_MV`, does not overflow or wrap
   - [ ] A mid-range value (e.g., `raw = 2048`) → roughly half of `HAL_ADC_VREF_MV`
5. Build and run:
   ```sh
   make test
   ```
   Your new `tests/test_hal_adc.c` is picked up automatically — no Makefile changes needed.

**Checkpoint:** Did Copilot's first draft include the out-of-range/negative case on its own, or only after you asked explicitly? This is the gap the calibration survey flagged — test generation is one of the most-tried capabilities, but boundary/negative cases are exactly what gets skipped under deadline, AI-generated or not.

---

## Part B — Commit and Request a Review Pass (10 minutes)

1. From `sample-repo/`, create a branch and commit your Exercise 2 fix and Exercise 3 test file together:
   ```sh
   git checkout -b module02/can-fix-and-adc-tests
   git add src/can_driver.c tests/test_hal_adc.c
   git commit -m "Fix CAN bus-off threshold accumulation; add hal_adc boundary tests"
   ```
2. **If you have push access to a shared lab repository:** push the branch and open a pull request. Use Copilot's PR-description assistance to draft the description, then ask Copilot to review the diff for coding-standards compliance (`docs/CODING_STANDARDS.md`) before requesting a human reviewer.
3. **If you're working offline / without a shared remote:** simulate the review locally —
   ```sh
   git diff main...module02/can-fix-and-adc-tests
   ```
   Paste or reference this diff in Copilot Chat and ask:
   > "Review this diff against docs/CODING_STANDARDS.md. Flag anything that violates naming, error-code ranges, the no-dynamic-allocation rule, or the layering rules in docs/ARCHITECTURE.md."
4. Read the review output critically. Specifically check whether Copilot flags (or misses) that your `can_driver.c` fix didn't introduce any new magic numbers, and that your new test file follows the existing `MT_ASSERT_EQ` / `MT_RUN` conventions rather than inventing a new pattern.

**Checkpoint:** Did the AI review catch anything a human reviewer would plausibly catch — and did it miss anything a human would plausibly catch? Note one example of each if you can find them; it's useful evidence for Module 09's PR-quality-gate design.

---

## Where This Goes Next

- Keep this branch — [Exercise 4](04-agent-mode-repository-task.md) builds `fault_monitor` on top of it.
- Your review notes (what AI caught vs. missed) are a direct input to Module 09 (PR Process Automation, Quality Gates, LLM-as-Judge).
