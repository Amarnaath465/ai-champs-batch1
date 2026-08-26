# Exercise 5: Safe Evolution & Regression Protection

**Duration:** 30 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Implement exactly the extension point Exercise 4 designed, using the minimal-change strategy, then prove — with evidence, not confidence — that nothing existing broke.

## Prerequisites

Completed [Exercise 4](04-brownfield-repository-archaeology.md), with a written change-impact analysis and a specific, named extension mechanism.

---

## The Minimal-Change Strategy

Four principles that keep a brownfield enhancement safe and reviewable:

| Principle | What it means here |
|---|---|
| **Prefer extension over modification** | Add new code paths at existing extension points instead of rewriting working logic in place |
| **Preserve backward compatibility** | Existing callers, configs, and behaviors keep working unless the spec explicitly says otherwise |
| **Protect against regression** | Every existing test still passes; new tests cover exactly the new behavior, nothing more |
| **Keep changes reversible** | Small, isolated commits that could be reverted individually if something's wrong |

The tell-tale sign of a good brownfield diff: a reviewer can understand exactly what changed and why, without reading the whole file.

## Step 1 — Write the Change Plan (5 minutes)

Create `sample-repo/specs/002-event-log-diagnostics/brownfield-plan.md`:

```markdown
# Brownfield Change Plan: Wire event_log into can_driver

## Extension Point
<!-- The exact new field and/or function from Exercise 4, Investigation 5 -->

## Backward Compatibility
<!-- Which existing callers are affected, and why they aren't -->

## Regression Protection
<!-- Which existing tests must still pass unmodified, and what new test proves the new behavior -->

## Reversibility
<!-- Why this change could be reverted in one isolated commit if it's wrong -->
```

Fill in each section using your Exercise 4 answers directly — this file should take five minutes precisely because Exercise 4 already did the thinking.

## Step 2 — Implement the Extension (15 minutes)

Task by task, with Copilot, checking each diff against your change plan:

1. **Add the optional field(s)** to `can_driver_t` in `include/can_driver.h` — an `event_log_t *` pointer that defaults to unset, and (if your design needs a timestamp source) a monotonic counter field. Adding a field to a struct that's always initialized via `can_driver_init()`'s existing `memset` is backward compatible for free — every existing caller gets the new field zeroed automatically, with no changes to their own code.
2. **Add the new setter function** you named in Exercise 4 — e.g. `can_driver_set_event_log(can_driver_t *drv, event_log_t *log)`. This is purely additive: no existing function signature changes.
3. **Add exactly one guarded call** at the state transition you identified in Exercise 4 — where the driver sets `drv->state = CAN_STATE_BUS_OFF`. Guard it: only record if a log has actually been attached. Something like:

   ```c
   if (drv->event_log != NULL) {
       event_log_record(drv->event_log, DIAG_ERR_CAN_BUSOFF, /* your timestamp */);
   }
   ```

4. Check the diff against your change plan before accepting: does it touch anything beyond what `brownfield-plan.md`'s Extension Point section named? If Copilot's suggestion also "helpfully" refactors the surrounding function or renames a variable, that's not what was asked — reject and re-prompt narrower.

## Step 3 — Add a Regression Test, Without Touching the Existing One (5 minutes)

Create a **new** file, `tests/test_can_driver_event_log.c` — do not add these cases to `tests/test_can_driver.c`. Cover:

1. With a log attached via your new setter, driving the same failure sequence `test_can_driver.c` uses to reach `BUS_OFF` produces exactly one recorded event, carrying the CAN bus-off error code.
2. With **no** log attached (the default, unset state), that same failure sequence still reaches `BUS_OFF` exactly as before — proving the guard means "no log attached" is indistinguishable from "this feature doesn't exist yet," for any caller that hasn't opted in.

## Step 4 — Full Regression Run (5 minutes)

```sh
cd sample-repo
make test
```

This is your regression-protection evidence. Confirm:

- `test_can_driver` — still `6 passed, 0 failed`, and the file itself is byte-for-byte unmodified (`git diff tests/test_can_driver.c` should show nothing, if you're using git)
- `test_event_log` — still fully green from Exercise 3
- `test_can_driver_event_log` — your new file, fully green

If anything in `test_can_driver` now fails, you didn't achieve backward compatibility — go back to Step 2 and find what you changed that Investigation 2's caller list depended on.

---

## Checkpoint

- [ ] `brownfield-plan.md` exists and names a specific extension point, not a vague intention
- [ ] The diff to `can_driver.h`/`.c` is additive only — no existing function signature changed
- [ ] `tests/test_can_driver.c` is unmodified and still fully green
- [ ] `tests/test_can_driver_event_log.c` proves both the logging behavior and the "no log attached, no behavior change" guarantee
- [ ] Full `make test` is green across every test binary in the repository

## Where This Goes Next

Both halves of today's lab are now complete: a module built from nothing, and an existing module safely extended. Exercise 6 compares what "release-ready" means for each, and closes the loop into Module 06's test-strategy work.
