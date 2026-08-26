# Exercise 1: Spec-to-Test Traceability

**Duration:** 20 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Module 04 taught the traceability chain REQ → CON → AC → Task → Test. Today it gets its final, provable link: **Evidence**. For every acceptance criterion Module 05 wrote down, find the test that proves it — or discover that no such test exists yet. That gap list is today's actual work.

## The Test Strategy Question

> For every acceptance criterion, ask "what test proves this?" If you can't name one, the strategy has a gap — not the code.

A strategy is spec-derived when every acceptance criterion maps to at least one named test, every stated constraint has a corresponding boundary or negative test, and every test case's purpose traces back to a requirement ID — not invented after the fact to pad coverage numbers.

---

## Step 1 — Build the Test Strategy Table (12 minutes)

Open `sample-repo/specs/002-event-log-diagnostics/spec.md` and `brownfield-plan.md`. Create `sample-repo/specs/002-event-log-diagnostics/test-strategy.md`:

```markdown
# Test Strategy: Event Log Diagnostics

| Source | Acceptance Criterion / Guarantee | Existing Test | Status |
|---|---|---|---|
| spec.md | (your AC-1 wording) | test_new_log_is_empty | Covered |
| spec.md | (your AC round-trip wording) | test_record_then_get_round_trips | Covered |
| spec.md | (your full-log/overwrite wording) | test_full_log_overwrites_oldest_and_counts_drop | Covered |
| brownfield-plan.md | Regression: existing callers unaffected | test_no_log_attached_means_no_crash_and_no_logging | Covered |
```

For every row, open the named test and confirm it actually asserts what the row claims — the same discipline from Module 04 Exercise 5. Fill in your own spec's actual AC wording, not this placeholder text.

## Step 2 — Find the Gaps (8 minutes)

Now go looking for what's *not* covered. Three real gaps exist in what Module 05 shipped — find them by asking, for each, "what test proves this?":

1. **The boundary just below full.** Module 05's test suite covers "exactly at capacity" and "one past capacity." What about one entry *below* capacity — does `dropped` stay at zero there too, or could an off-by-one only show up right at the edge? Slide 8's rule applies: test at the exact edge, not comfortably inside it.

2. **A negative input to `event_log_get`.** What happens if `out` is `NULL`? Try it — copy this into a scratch `.c` file, compile it against your real `event_log.c`, and run it:

   ```c
   #include "event_log.h"
   int main(void) {
       event_log_t log;
       event_log_init(&log);
       event_log_record(&log, DIAG_ERR_CAN_BUSOFF, 1u);
       event_log_get(&log, 0, NULL);  /* NULL out pointer */
       return 0;
   }
   ```

   Run it. Check the exit code (`echo $?` after it runs). If you see a crash, you've just found a real, currently-shipped gap — not a hypothetical one.

3. **No test exercises more than two modules together.** `test_can_driver_event_log.c` is the closest thing to an integration test today, but nothing exercises `sensor_poll` alongside `can_driver` and `event_log` in one realistic pass. Is that a real gap, or is it out of scope? (It's a real gap — Exercise 5 closes it.)

Add rows for all three to `test-strategy.md`, marked `Gap`, with a one-line note on what a test would need to do.

---

## Checkpoint

- [ ] `test-strategy.md` exists with one row per acceptance criterion/guarantee from `spec.md` and `brownfield-plan.md`
- [ ] Every `Covered` row names a real, verified test
- [ ] You personally reproduced the `NULL`-out crash, not just read about it
- [ ] You have three named `Gap` rows — the boundary case, the negative case, and the missing integration/E2E coverage

## Where This Goes Next

These three gaps are not abstract — they're exactly what Exercises 3 and 5 build. Exercise 2 first classifies where in the test pyramid each gap belongs, so you know what kind of test to write before you start writing it.
