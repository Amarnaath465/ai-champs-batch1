# Exercise 2: Debug a Real Defect

**Duration:** 20 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Hunt and fix the intentional defect in the CAN driver's error-confinement logic using Copilot Chat + inline assist — root-causing from a failing test rather than from a stack trace, since this is a host-based lab.

## Prerequisites

Completed [Exercise 0](00-capability-map-walkthrough.md). If you haven't run `make test` yet in `sample-repo/`, do that first — you should see 3 failing assertions, all in `tests/test_can_driver.c`.

---

## Step 1 — Reproduce and Read the Failure (3 minutes)

```sh
cd sample-repo
make test
```

You should see output like:

```
FAIL tests/test_can_driver.c:15: driver should enter BUS_OFF after exceeding the consecutive failure threshold (got 0, expected 2)
FAIL tests/test_can_driver.c:28: precondition failed: driver never reached BUS_OFF (got 0, expected 2)
FAIL tests/test_can_driver.c:48: driver should be ERROR_PASSIVE after moderate consecutive failures (got 0, expected 1)
```

Read `tests/test_can_driver.c` lines 1–20 (`test_bus_off_after_consecutive_failures`). It sends 9 consecutive failed messages and expects the driver to end up in `CAN_STATE_BUS_OFF` (value 2). It's getting `CAN_STATE_ERROR_ACTIVE` (value 0) instead — the driver never escalates no matter how many failures happen.

## Step 2 — Ask Copilot for a Root-Cause Hypothesis (7 minutes)

1. Open `src/can_driver.c` alongside the failing test.
2. Select the body of `can_driver_send()`.
3. Ask Copilot Chat, feeding it the failing assertion as context:
   > "This test expects the driver to reach CAN_STATE_BUS_OFF after 9 consecutive simulated failures, but tx_error_count never seems to exceed 1. Walk through what tx_error_count and consecutive_failures do on each call to can_driver_send and tell me where the accumulation breaks."
4. Read the explanation Copilot gives you. **Do not apply a fix yet.** Trace the logic yourself, by hand, for 3 consecutive calls with `simulate_tx_failure = true`:

   | Call # | `consecutive_failures` before | after `++` | `tx_error_count` after copy | `consecutive_failures` after reset |
   |---|---|---|---|---|
   | 1 | 0 | 1 | 1 | ? |
   | 2 | ? | ? | ? | ? |
   | 3 | ? | ? | ? | ? |

5. Fill in the table. Where does the accumulation actually break?

**Checkpoint:** Can you point to the exact line where the bug lives, in your own words, without re-reading Copilot's explanation? If not, ask a narrower follow-up question rather than moving on — the goal is root-cause understanding, not a pasted fix.

## Step 3 — Fix It (7 minutes)

1. With the root cause identified, either:
   - Ask Copilot Chat: "Given that root cause, propose a minimal fix that doesn't change any other behavior in this function," **or**
   - Fix it yourself now that you understand the bug (often faster once you've traced it by hand).
2. Apply the fix to `src/can_driver.c`.
3. Rebuild and rerun:
   ```sh
   make test
   ```
4. All three previously-failing assertions should now pass (6 passed, 0 failed).

**If tests still fail:** don't keep applying suggested patches blindly — go back to Step 2's trace table and check whether your fix actually addresses where the table showed the break, or just moved the symptom.

## Step 4 — Sanity-Check the Fix Against the Coding Standards (3 minutes)

Open `docs/CODING_STANDARDS.md`. Does your fix:
- Avoid dynamic allocation? (trivially yes here, but check the habit)
- Keep the function's return-`bool`-for-success convention intact?
- Not introduce a new magic number where `CAN_BUS_OFF_THRESHOLD` should be reused?

---

## Discussion Note

This defect is a **driver-layer logic bug** — exactly the category the pre-programme calibration survey flagged as needing the closest human review (timing behaviour, memory safety, and error handling ranked #1–3 for "where human review is non-negotiable"). Notice that Copilot could describe *what* the code does accurately, but *whether that behavior is correct* required your own trace against the test's expectations. That division of labor — AI explains, human verifies against intent — is the pattern the rest of this programme is built on.

## Where This Goes Next

- A clean `make test` run (6/6 passing) is required before Exercise 3, where you'll add a new test file alongside this one.
- Note how long Steps 1–3 took you — it's one of the data points for [Exercise 5](05-manual-vs-ai-comparison.md).
