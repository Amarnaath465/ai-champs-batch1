# Exercise 4: Brownfield — Repository Archaeology

**Duration:** 45 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Understand `can_driver.c` completely before changing a single line of it. This exercise produces no code — only the analysis that makes Exercise 5's change safe.

## Prerequisites

Completed [Exercise 3](03-testing-and-build-validation.md). Your `event_log` module is implemented, tested, and green.

**Also required:** the CAN driver defect from Module 02 Exercise 2 must already be fixed (see [setup.md](setup.md) if you haven't confirmed this). Today's brownfield target is the exact line of code that defect lived in — if it's still broken, `CAN_STATE_BUS_OFF` is unreachable and there's nothing safe to wire your event log into.

```sh
cd sample-repo
make test
```

Confirm `test_can_driver`: `6 passed, 0 failed` before continuing.

---

## What the Calibration Survey Told Us

19 Honeywell engineers were asked what their first move is on an existing codebase before changing it: 13 of 19 said architecture first, unprompted. 5 said spec or impact analysis first. 2 said they have no set approach at all. This exercise gives that instinct a name and a repeatable structure — useful whether you were already one of the 13, or one of the 2.

## The Brownfield Problem

> Your `event_log` module works. Now wire it into `can_driver.c` so that a real bus-off event — the transition into `CAN_STATE_BUS_OFF` — gets recorded automatically, without changing behavior for any code that doesn't explicitly ask for logging.

Six investigations, done in order, before you write any code:

## Investigation 1 — Architecture Analysis (5 minutes)

Open [`sample-repo/docs/ARCHITECTURE.md`](../module-02/sample-repo/docs/ARCHITECTURE.md). What layer is `can_driver` in? What does Layering Rule 2 say about what a driver is and isn't allowed to know about? Does your event log — per your Exercise 1 decision about which layer it belongs to — fit inside what a driver is allowed to depend on, or does it violate rule 2 the same way a dependency on `state_machine.h` would?

Write your answer down. If your Exercise 1 decision was "cross-cutting infrastructure, like `diag_formatter`," check that Layering Rule 4 actually supports a driver calling it.

## Investigation 2 — Dependency Mapping (7 minutes)

Every caller of `can_driver_init`, `can_driver_send`, `can_driver_tick`, and `can_driver_get_state` needs to keep working exactly as before. Find all of them:

```sh
grep -rn "can_driver_init\|can_driver_send\|can_driver_tick\|can_driver_get_state" --include="*.c" --include="*.h" .
```

List every file that shows up. This is the list of things your change is not allowed to break.

## Investigation 3 — Interface Contracts (5 minutes)

Open `include/can_driver.h`. Which functions are the public contract? Which struct fields does `ARCHITECTURE.md`'s Layering Rule 3 say callers must never touch directly (only through accessors like `can_driver_get_state()`)? If you add a new field to `can_driver_t`, does anything in your Investigation 2 list read the struct directly rather than through an accessor — and would a new field break it either way?

## Investigation 4 — HAL Boundaries (3 minutes)

Confirm `can_driver.c` doesn't reach into `hal_gpio_*`/`hal_adc_*` (Layering Rule 1). This particular change doesn't touch HAL at all — but checking is part of the standard six-point pass, not a step you skip because you're confident it's irrelevant this time.

## Investigation 5 — Extension Points (10 minutes)

You need a mechanism for `can_driver.c` to reach an `event_log_t` it doesn't own and wasn't given at `can_driver_init()` time (since every existing caller, including `test_can_driver.c`, calls `can_driver_init()` with no knowledge of your new module).

Two shapes are available to you:
- **Modify** an existing function's signature to accept a log parameter. This breaks every caller in your Investigation 2 list immediately — they'd all fail to compile.
- **Extend**: add a new, optional attachment mechanism that every existing caller can simply ignore.

Decide the concrete shape of the extension. A new struct field that defaults to "off"? A new setter function? Write down the exact function signature and struct change you're proposing — you'll implement exactly this in Exercise 5.

## Investigation 6 — Change Impact Analysis (10 minutes)

Combine Investigations 1–5 into one written answer: **what does this change actually touch?**

Your answer should be specific enough that a reviewer could predict the diff before seeing it — something like: "one new optional field on `can_driver_t`, one new setter function, one guarded call at the exact line where `drv->state = CAN_STATE_BUS_OFF` is set. Zero changes to any existing function's signature. Zero changes to any file in the Investigation 2 caller list, including `test_can_driver.c`."

If your answer is longer or vaguer than that, you haven't found the minimal extension point yet — go back to Investigation 5.

---

## Checkpoint

- [ ] You can state which architectural layer `can_driver` sits in and whether your event log integration respects Layering Rules 1–4
- [ ] You have a complete list of every existing caller of the four public `can_driver` functions
- [ ] You have a specific, named extension mechanism (exact new field, exact new function signature) — not "we'll add some kind of hook"
- [ ] Your written change-impact answer is specific enough that someone else could predict your diff from it alone

## Where This Goes Next

Exercise 5 turns this analysis into a short change plan, implements exactly the extension point you just designed, and proves — with a full test run — that nothing on your Investigation 2 list changed behavior.
