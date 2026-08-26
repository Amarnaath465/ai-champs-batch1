# Exercise 6: Inject a Defect, Prove the Strategy

**Duration:** 30 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Derive, build, and run a test strategy is not the same as proving it works. Break the implementation on purpose — something a real review might miss — and confirm the suite catches it. If it doesn't, that's not a failed lab; per the deck, it's the most valuable finding of the session, because it means the strategy needs work before the code does.

## Prerequisites

Completed [Exercise 5](05-write-and-run-the-test-suite.md). `make test` is fully green.

---

## Step 1 — Pick a Defect (2 minutes)

Two candidates, both real gaps a rushed reviewer could plausibly miss:

**Defect A — remove the event-log guard in `can_driver_send`.** In `src/can_driver.c`, find:
```c
if (drv->event_log != NULL) {
    event_log_record(drv->event_log, DIAG_ERR_CAN_BUSOFF, drv->tick_count);
}
```
Change the condition so it always executes (e.g., replace it with `if (1) {`).

**Defect B — remove the `NULL`-out guard in `event_log_get`.** In `src/event_log.c`, find:
```c
if (out == NULL || index >= log->count) {
```
Remove the `out == NULL ||` part, back to `if (index >= log->count) {`.

If you have time, do both — one at a time, each fully reverted before starting the next. If you're short on time, pick one.

## Step 2 — Break It, Then Run Everything (10 minutes)

Apply your chosen change. Then:

```sh
make clean
make test
```

**If you picked Defect A:** watch for which binaries fail. Every caller of `can_driver_send` that never attaches an event log — including the **original** `test_can_driver.c` from Module 02, a file today's work never touched — should crash. This is regression testing catching a brownfield defect in code nobody was actively reviewing at that moment.

**If you picked Defect B:** only `tests/test_event_log_boundary.c` (today's new negative test) should fail. Every other binary — including the original `test_event_log.c` — stays green, because nothing else ever calls `event_log_get` with a `NULL` `out`. This is the opposite lesson: a narrow, targeted test catching a narrow, targeted defect that broader tests structurally can't see.

Either way: if nothing fails, that's the real finding. Go back to `test-strategy.md` and figure out which row's test isn't actually testing what it claims — then fix the test, not the defect, first.

## Step 3 — Revert (3 minutes)

```sh
git diff src/can_driver.c src/event_log.c
git checkout -- src/can_driver.c src/event_log.c   # or manually undo your specific edit
make test
```

Confirm you're back to fully green before continuing.

## Step 4 — Assemble the Test Evidence Package (10 minutes)

"Tested" is not "trust me, it works" — it's evidence a reviewer can check in under a minute. Create `sample-repo/specs/002-event-log-diagnostics/test-evidence.md`:

```markdown
# Test Evidence: Event Log Diagnostics

## Traceability Table
(paste your completed test-strategy.md table — every row Covered)

## Build & Static Analysis Log
(paste your Exercise 4 output — zero warnings, sanitizer clean, cppcheck output if run)

## Test Run Output
(paste the full `make test` pass/fail summary — every binary, not a screenshot of only the ones that passed)

## Regression Confirmation
(one sentence: which pre-existing test file proves the brownfield change didn't break anything, and that you ran it — not assumed it)

## Defect Injection Proof
(which defect you injected, which test(s) caught it, and confirmation it's been reverted)
```

## Step 5 — Anti-Pattern Self-Audit (5 minutes)

Five habits that quietly turn "we have tests" into false confidence. Check your own work against all five, honestly:

- [ ] Did you derive tests from acceptance criteria before implementation finished — or write some after the fact to match whatever the code already did?
- [ ] Did you run the *full* regression suite on the brownfield change, or only the new tests?
- [ ] Did you mock the hardware-dependent interface to test logic in isolation, or skip a test because "we can't test that here"?
- [ ] Did you treat a caught defect as proof the strategy works — and would you have treated an uncaught one as a reason to skip testing next time, instead of a reason to strengthen the strategy?
- [ ] Is your test evidence something a reviewer could actually check, or does it boil down to "it's tested," unverifiable?

If any box is unchecked, that's real signal — not a failed exercise. Note it.

---

## Checkpoint

- [ ] You injected at least one real defect and confirmed which test(s) caught it, or discovered a genuine gap and closed it
- [ ] Everything is reverted and `make test` is fully green again
- [ ] `test-evidence.md` exists with all five sections filled in with real content, not placeholders
- [ ] You completed the anti-pattern self-audit honestly

## Module 06 Outcomes

- [ ] Can derive a test strategy directly from a specification's acceptance criteria
- [ ] Know the three test-pyramid layers and when each one is enough
- [ ] Can write mocks, stubs, and fakes for hardware-dependent interfaces
- [ ] Practiced boundary and negative testing on real embedded scenarios
- [ ] Understand static analysis, build validation, and sanitizers as a pre-review gate
- [ ] Ran the full regression suite against a brownfield change
- [ ] Injected a real defect and proved the test strategy caught it
- [ ] Know what test evidence looks like — and why Module 09 checks for it

**Module 06 complete.** Next: **Module 07 — MCP-Enabled Agentic Embedded Engineering and Reusable Skills** (2 hours). Connect agents to approved repositories, build/test tools, and CI services — then package today's work as a reusable, versioned skill.
