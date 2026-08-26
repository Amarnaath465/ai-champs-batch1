# Exercise 2: Greenfield — Spec to Implementation

**Duration:** 60 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Turn Exercise 1's architecture sketch into a real specification, then implement it task by task with Copilot — the same spec → plan → tasks → implement discipline from Module 04, now applied to a complete module instead of a single function.

## Prerequisites

Completed [Exercise 1](01-problem-framing-and-architecture.md), with written answers to the four architecture-decision questions.

---

## Step 1 — Write `spec.md` (10 minutes)

Create `sample-repo/specs/002-event-log-diagnostics/spec.md` using the same four-section template from Module 04:

```markdown
# Specification: Event Log Diagnostics

## Requirements
<!-- What must this module do, for whom, and why -->

## Constraints
<!-- Timing/resource limits, memory limits, platform/toolchain limits -->

## Interfaces & Contracts
<!-- Exact function signatures, structs, what existing behavior must be preserved -->

## Acceptance Criteria
<!-- Observable pass/fail conditions, including edge and negative cases -->
```

Turn your Exercise 1 answers into this spec directly:

- **Requirements**: the EVENTLOG-01 problem statement, restated as what the module must do.
- **Constraints**: no dynamic allocation; your chosen fixed capacity; the "no crash, no blocking" requirement — a log full during a fault path must never fail the caller.
- **Interfaces & Contracts**: your Step 3 draft signatures, now finalized. Name the exact struct fields, the exact function signatures, and the exact reuse of `diag_error_code_t` from `diag_formatter.h` if you chose that route.
- **Acceptance Criteria**: at minimum, cover — a fresh log reports zero entries; a recorded entry round-trips through your read function; reading past the valid range fails safely; and your chosen full-log policy (overwrite or reject) behaves exactly as specified, including whatever "how many were lost" telemetry you decided the module should expose.

Self-review against the five-point bar from Module 04 before moving on: **Testable, Bounded, Interface-Accurate, Traceable, Reviewed.**

## Step 2 — Generate `plan.md` and `tasks.md` (10 minutes)

Ask Copilot to draft a plan from your spec — approach, files touched, constraint checks, open questions — then review it yourself before breaking it into tasks. This review step is not optional: a plan that quietly drops your capacity constraint or invents a fifth function you never specified needs to be caught here, not three tasks into implementation.

An example `tasks.md` shape:

| Task | Description | Traces to | Verification |
|---|---|---|---|
| T-1 | Declare the entry struct and log struct in `include/event_log.h` | REQ-1, CON-1 | Compiles |
| T-2 | Implement `event_log_init` | REQ-1 | Manual check |
| T-3 | Implement `event_log_record`, including the full-log policy | REQ-2, CON-2 | AC-3, AC-4 |
| T-4 | Implement `event_log_count` | REQ-1 | AC-1 |
| T-5 | Implement `event_log_get` | REQ-1 | AC-2 |
| T-6 | Implement the "how many were lost" accessor | REQ-2 | AC-4 |

Adjust to your actual design — these six are a starting shape, not a requirement.

## Step 3 — Implement Task by Task (30 minutes)

For each row in `tasks.md`, in order:

1. Prompt Copilot with the specific task and the relevant spec section — not "build me an event log," but "implement T-3 from tasks.md: `event_log_record`, including the overwrite-oldest policy from AC-3/AC-4 in spec.md. Here's the struct layout: [paste]."
2. Read the diff against the acceptance criterion it claims to satisfy before accepting it.
3. Specifically watch for:
   - Any dynamic allocation slipping in (`malloc`, `calloc`) — your constraint said no.
   - Whether the full-log policy actually matches what you specified, not a plausible-looking alternative (reject-when-full and overwrite-oldest look similar in a diff if you're skimming).
   - Whether your "how many were lost" counter only increments when an entry is genuinely overwritten, not on every call.
4. Correct anything that doesn't match before moving to the next task — the same discipline from Module 04 Exercise 4: correcting a task is cheaper than reviewing a wrong diff later.

By the end of this step you should have a complete `include/event_log.h` and `src/event_log.c`.

## Step 4 — Wire the New Module Into the Build (10 minutes)

Unlike a new *test* file, which the Makefile auto-discovers, a new *source* module needs to be added to the build explicitly. Open `sample-repo/Makefile` and find the `SRC` line:

```makefile
SRC := src/can_driver.c src/sensor_poll.c src/hal_adc.c src/hal_gpio.c src/state_machine.c src/diag_formatter.c
```

Add `src/event_log.c` to this list. This is a real, deliberate Makefile edit — worth noticing precisely because it's the first one in this programme; every prior new-test-file addition needed none.

Sanity-compile your new module on its own before running the full suite:

```sh
cd sample-repo
gcc -std=c11 -Wall -Wextra -Iinclude -c src/event_log.c -o /tmp/event_log_check.o
```

Zero warnings, zero errors. Full test-writing and the full `make test` run come next in Exercise 3.

---

## Checkpoint

- [ ] `spec.md`, `plan.md`, and `tasks.md` exist in `sample-repo/specs/002-event-log-diagnostics/`
- [ ] `include/event_log.h` and `src/event_log.c` exist and implement every task in `tasks.md`
- [ ] `src/event_log.c` is registered in the Makefile's `SRC` list
- [ ] The module compiles standalone with zero warnings under `-Wall -Wextra`
- [ ] You can point to at least one moment where you corrected a Copilot diff because it didn't match your spec's full-log policy or capacity constraint

## Where This Goes Next

Exercise 3 writes the real test suite against your acceptance criteria and runs the full `make test`. Exercise 4 then turns to the existing `can_driver.c` — the module this event log will eventually be wired into.
