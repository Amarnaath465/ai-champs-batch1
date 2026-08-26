# Exercise 4: Implement Against the Spec

**Duration:** 25 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Execute `tasks.md` with Copilot, one task at a time, checking each diff against `spec.md` as it lands — instead of handing the whole feature to Agent Mode in one prompt and hoping the result matches intent.

## Prerequisites

Completed [Exercise 3](03-generate-plan-and-tasks.md). `spec.md`, `plan.md`, and `tasks.md` all exist in `sample-repo/specs/001-sensor-fault-diagnostics/`.

---

## Why Task-by-Task, Not One Big Prompt

Module 02's Agent Mode exercise handed Copilot one carefully-scoped prompt for an entire module (`fault_monitor`) and reviewed the whole diff at the end. That worked because the contract was already fully specified in a header comment.

Today's task list breaks the same kind of work into rows that each touch one acceptance criterion. The difference matters when things go wrong: if task T-6 (priority ordering) produces a subtly wrong diff, you find that out immediately, against a small diff — not after a 40-line function has already merged three different pieces of logic together. This is the practical version of Exercise 3's rule: **correcting a plan/task is cheaper than reviewing a wrong diff.**

## Step 1 — Add the Declaration (3 minutes)

Start with your `tasks.md` row for the header declaration (T-1 in the example template). In `include/sensor_poll.h`, add your function's declaration with a contract comment above it — name the priority rule and the empty/overflow behavior directly in the comment, matching this codebase's convention (see `diag_formatter.h`'s comment above `diag_format_message` for the style).

You can write this one by hand or ask Copilot inline — it's a single declaration, low-risk either way.

## Step 2 — Implement Task by Task (15 minutes)

For each remaining row in `tasks.md`, in order:

1. Open Copilot Chat and reference the specific task: *"Implement T-3 from tasks.md: the temperature-fault branch, reusing diag_format_sensor_fault. Here's the relevant part of spec.md: [paste AC-2]."*
2. **Read the diff before accepting it.** Check it against the acceptance criterion it claims to satisfy — not against "does this look like reasonable C."
3. Specifically watch for:
   - Does it call `diag_format_sensor_fault()` / `diag_format_message()`, or does it duplicate `snprintf` formatting inline? (Your `plan.md` Constraint Checks should have already flagged this — hold the diff to it.)
   - Does it reach into `hal_adc_*`/`hal_gpio_*` at all? It shouldn't — the function only reads an already-filled `sensor_snapshot_t`.
   - Does the priority-check logic (once you reach that task) match the exact order your spec named — not just "some" order?
   - Does the buffer-too-small / no-fault-active case return exactly what your spec's AC says, not an assumed default?
4. Accept, edit, or reject each suggestion individually. If a diff doesn't match its acceptance criterion, that's the moment to correct it — go back to Copilot with what specifically was wrong, the same iterate-don't-silently-patch discipline from Module 02.

Move to the next task only once the current one's diff matches its acceptance criterion.

## Step 3 — Write `tests/test_sensor_poll.c` (7 minutes)

Your last task row should be the test file. Ask Copilot to generate it, but **seed it with your actual acceptance criteria**, not a generic request:

> "Write tests/test_sensor_poll.c using the minitest.h pattern already used in test_can_driver.c. Cover: (1) no fault active returns 0 and leaves buf untouched, (2) single temperature fault produces the same message diag_format_sensor_fault would for that channel/value, (3) single pressure fault, (4) door+motion fault uses diag_format_message with [your chosen error code], (5) multiple simultaneous faults resolve to the [your priority order] fault, (6) a buffer too small to hold the message returns 0."

A clean trick for case (2)/(3): have the test call `diag_format_sensor_fault()` itself to build the *expected* string, rather than hardcoding the literal `"[0x1001] sensor 0 out of range (raw=4000)"` text — that way the test doesn't duplicate a magic number that could drift from the real channel constant.

Build and run:

```sh
cd sample-repo
make test
```

All tests — the original CAN driver suite, `hal_adc`, `fault_monitor` (if you built it in Module 02), and your new `sensor_poll` tests — should pass. `test_sensor_poll.c` is picked up automatically; no Makefile changes needed.

---

## Checkpoint

- [ ] `include/sensor_poll.h` declares the function with a contract comment
- [ ] `src/sensor_poll.c` implements every branch named in `tasks.md`
- [ ] `tests/test_sensor_poll.c` exists, with one test per acceptance criterion in your spec
- [ ] `make test` is fully green
- [ ] You can point to at least one moment where you corrected a Copilot suggestion because it didn't match a specific acceptance criterion — or explain why none was needed

## Where This Goes Next

Exercise 5 closes the loop: proving every acceptance criterion in `spec.md` actually maps to implemented, tested behavior — the traceability chain from Exercise 1, applied to real code you just wrote.
