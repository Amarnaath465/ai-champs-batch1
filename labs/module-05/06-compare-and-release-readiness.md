# Exercise 6: Compare & Release Readiness

**Duration:** 15 minutes | **Format:** Individual + group debrief

## Objective

Walk both artifacts you built today against their release-readiness bar, then compare what actually differed between building from nothing and safely evolving something that already worked.

## Prerequisites

Completed [Exercise 5](05-safe-evolution-and-regression-protection.md). Both `event_log` and the `can_driver` integration are implemented, tested, and green.

---

## Step 1 — Two Checklists, One Shared Standard (7 minutes)

Nothing ships without both columns checked — for whichever artifact applies.

**Greenfield ready to ship** (`event_log`):
- [ ] Every acceptance criterion from `spec.md` has a passing test
- [ ] Architecture matches what was designed in Exercise 1 — no undocumented drift
- [ ] Static analysis clean; build passes on the full target toolchain
- [ ] Interfaces documented for the next engineer who extends this
- [ ] A PR description could name which spec this implements

**Brownfield ready to ship** (the `can_driver` integration):
- [ ] Full regression suite passes — not just the new test
- [ ] Diff is minimal and isolated to the scoped extension point
- [ ] Every changed interface's callers were checked, not assumed safe
- [ ] Behavior preservation validated against `test_can_driver.c` unmodified
- [ ] A PR description could explain what was preserved as clearly as what changed

Go through both lists honestly. An unchecked box isn't a failed exercise — it's exactly the kind of gap worth naming before Module 06 builds the formal test strategy on top of what you did today.

## Step 2 — Fill In the Comparison, From Experience (5 minutes)

You saw this table in Exercise 1 as a preview. Now fill in a row yourself, from what you actually just did, not from the abstract description:

| SDLC Stage | Greenfield — what you actually did | Brownfield — what you actually did |
|---|---|---|
| Problem Framing | | |
| Architecture | | |
| Implementation | | |
| Testing | | |
| Release Readiness | | |

## Step 3 — Debrief (3 minutes)

Answer honestly, and compare notes with a neighbor or your facilitator if time allows:

- Which half took longer — and was that expected?
- Which half felt riskier while you were doing it? Was that the same half that actually took longer?
- Exercise 4's archaeology produced no code at all for 45 minutes. Did that feel like the right amount of time, or did you want to start editing `can_driver.c` sooner than the exercise let you?

---

## Module 05 Outcomes

- [ ] Can walk the seven-stage SDLC from problem framing to release readiness
- [ ] Practiced repository archaeology — architecture, dependencies, interfaces, HAL boundaries — on a real module before changing it
- [ ] Can explain how each SDLC stage differs between greenfield and brownfield work
- [ ] Know the release-readiness checklist for both engineering flavours
- [ ] Built a greenfield feature end to end from a specification
- [ ] Applied the minimal-change strategy to a real brownfield enhancement
- [ ] Validated behavior preservation against a documented baseline (the unmodified `test_can_driver.c`)
- [ ] Have two real artifacts — greenfield and brownfield — ready for Module 06's test strategy

**Module 05 complete.** Next: **Module 06 — Embedded Test Strategy, Validation and Regression Engineering** (2.5 hours). Host-based unit testing, mocks/stubs/fakes, boundary and negative testing, static analysis, and full specification-to-test traceability — built directly on the two artifacts from today.
