# Exercise 3: Testing & Build Validation

**Duration:** 30 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Prove the greenfield module you just wrote actually satisfies its acceptance criteria — run continuously as you write tests, not saved for the very end — then validate the full build the same way a reviewer or CI pipeline would.

## Prerequisites

Completed [Exercise 2](02-greenfield-spec-to-implementation.md). `include/event_log.h` and `src/event_log.c` exist, are registered in the Makefile, and compile standalone with zero warnings.

---

## Step 1 — Write `tests/test_event_log.c` (15 minutes)

Seed Copilot with your actual acceptance criteria, not a generic request:

> "Write tests/test_event_log.c using the minitest.h pattern already used in test_can_driver.c. Cover: (1) a freshly-initialized log reports zero entries, (2) recording one entry and reading it back returns the exact code and tick recorded, (3) reading an index at or beyond the current count fails safely, (4) filling the log to capacity and recording one more entry [either rejects the new entry, or overwrites the oldest and increments the drop counter — whichever your spec.md specifies]."

Read the generated test against your spec's acceptance criteria line by line before running anything — a test that compiles and passes but doesn't actually assert what your AC claims is worse than no test, because it looks like coverage that isn't there.

For the full-log case specifically: record exactly your chosen capacity's worth of entries first (confirm count reports full, drops reports zero), then record one more (confirm count stays capped, drops increments by exactly one, and — if you chose overwrite — that the previously-oldest entry is now gone and the next-oldest has taken its place).

## Step 2 — Run the Full Suite (10 minutes)

```sh
cd sample-repo
make test
```

`test_event_log.c` is picked up automatically — the Makefile's test-discovery pattern needs no changes for a new *test* file, only for a new *source* module (which you already handled in Exercise 2, Step 4). You should see your new test binary listed alongside `test_can_driver`, `test_sensor_poll` (if built in Module 04), and any others already in the repo, all passing.

If anything fails, resist patching the test to match whatever the code happens to do — go back to `spec.md` and decide whether the code or the acceptance criterion was wrong, then fix that side deliberately.

## Step 3 — Build & Static Validation (5 minutes)

The Makefile already compiles with `-Wall -Wextra`. Confirm your new files produce zero warnings — a warning that's easy to ignore today is exactly the kind of thing Module 06's static-analysis stage is built to catch systematically, and a reviewer six weeks from now won't have your context for why it's "probably fine."

If `cppcheck` (or another static analyzer) is available in your environment, run it against `src/event_log.c` as a preview of what Module 06 formalizes:

```sh
cppcheck --enable=warning,style -Iinclude src/event_log.c
```

Not required if unavailable — the compiler warning check above is the floor, not the ceiling.

---

## Checkpoint

- [ ] `tests/test_event_log.c` exists, with one test per acceptance criterion in your spec
- [ ] `make test` is fully green, including every pre-existing test binary in the repo
- [ ] Zero new compiler warnings from `src/event_log.c` or `tests/test_event_log.c`
- [ ] You manually traced at least the full-log test case against your spec's exact wording before trusting it

## Where This Goes Next

The greenfield half of today's lab is complete: a specified, implemented, tested, build-validated module that didn't exist three hours ago. Exercise 4 turns to the harder half — `can_driver.c` already exists, already works, and already has callers. Before you touch it, you'll do the repository archaeology that makes changing it safely possible.
