# Setup — Module 05 Lab

Do this before the session starts. Takes about 5 minutes if Module 02's CAN driver defect is already fixed; a bit longer otherwise.

## 1. This Module Reuses the Module 02 Sample Repository

Module 05 does not ship its own codebase — it builds directly on the same [`sample-repo/`](../module-02/sample-repo/) used in Modules 02–04. Today you'll add a brand-new module to it (greenfield) and then modify two of its existing files for the first time in this programme (brownfield).

```sh
cd labs/module-02/sample-repo
make test
```

## 2. The One Hard Dependency: the CAN Driver Defect Must Be Fixed

Today's brownfield work (Exercises 4–5) modifies `can_driver.c` at the exact point it transitions into `CAN_STATE_BUS_OFF`. If Module 02's intentional defect — `tx_error_count` resetting to 1 on every failed send instead of accumulating — is still present, **that transition is unreachable**, and there is nothing to safely wire your event log into.

Check:

```sh
cd sample-repo
make test
```

You should see `6 passed, 0 failed` from `bin/test_can_driver`. If you instead see `3 passed, 3 failed`, the defect from Module 02 Exercise 2 is still present — fix it now using [`../module-02/02-debug-a-defect.md`](../module-02/02-debug-a-defect.md) before continuing, or flag it to your facilitator.

Nothing else from Modules 02–04 is a hard dependency. `diag_format_sensor_fault()` (Module 02 Ex1) and the `sensor_poll` fault-diagnostics feature (Module 04) are not touched today — today's centerpiece feature only reuses the `diag_error_code_t` enum and `diag_format_message()`, both already implemented in the repo you were given.

## 3. Recommended, Not Required: Module 04

Exercise 2 reuses the same four-section spec template (Requirements / Constraints / Interfaces & Contracts / Acceptance Criteria) from Module 04. If you skipped Module 04, the template is repeated in full in Exercise 2 — you don't need the prior session to follow along, but the pacing assumes you've written at least one spec before.

## 4. Access Checklist

- [ ] GitHub Copilot Enterprise seat active, Chat and inline assist available
- [ ] `sample-repo/` open as your IDE workspace root
- [ ] CAN driver defect confirmed fixed — `make test` shows `test_can_driver`: 6/6 (Step 2 above)
- [ ] A terminal available for `make test` and `grep` — today's brownfield archaeology exercise greps the repository directly

## 5. Know Where the Reference Docs Are

Three files inside `sample-repo/` get referenced by name throughout today's exercises:

- [`sample-repo/docs/ARCHITECTURE.md`](../module-02/sample-repo/docs/ARCHITECTURE.md) — module layering rules; today's greenfield module joins the diagram, and today's brownfield change is tested against these rules directly
- [`sample-repo/docs/CODING_STANDARDS.md`](../module-02/sample-repo/docs/CODING_STANDARDS.md) — naming, error-code ranges, no-dynamic-allocation rule
- [`sample-repo/include/can_driver.h`](../module-02/sample-repo/include/can_driver.h) and [`src/can_driver.c`](../module-02/sample-repo/src/can_driver.c) — today's brownfield target

## 6. This Module's Own Artifacts

Like Module 04, today's work writes real, permanent changes into the shared repository. Unlike any prior module, some of today's changes land inside **existing** files rather than only adding new ones — that's the brownfield half of the lesson.

New files you'll create:

```
sample-repo/specs/002-event-log-diagnostics/
├── spec.md                (Exercise 2)
├── plan.md                (Exercise 2)
├── tasks.md                (Exercise 2)
└── brownfield-plan.md      (Exercise 5)

sample-repo/include/event_log.h          (Exercise 2)
sample-repo/src/event_log.c              (Exercise 2)
sample-repo/tests/test_event_log.c       (Exercise 3)
sample-repo/tests/test_can_driver_event_log.c   (Exercise 5)
```

Existing files you'll modify (with a minimal, additive diff — never a rewrite):

```
sample-repo/Makefile              (Exercise 2 — register the new module's source file)
sample-repo/include/can_driver.h  (Exercise 5 — one new optional field, one new function)
sample-repo/src/can_driver.c      (Exercise 5 — one guarded call at the bus-off transition)
```

`tests/test_can_driver.c`, the file Module 02 Exercise 2 already fixed, is **not** touched today. Proving that stays true — untouched, still green — is the regression-protection evidence Exercise 5 asks for.

---

Once your access checklist is complete, start with [Exercise 1](01-problem-framing-and-architecture.md).
