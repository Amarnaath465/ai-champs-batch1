# Exercise 5: Validate Traceability

**Duration:** 15 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Prove — not assume — that every acceptance criterion in `spec.md` maps to implemented, tested behavior. This is the step that makes specification compliance checkable later, by a human reviewer in Module 09's PR process or by an LLM-as-Judge rubric.

## Prerequisites

Completed [Exercise 4](04-implement-against-the-spec.md). `make test` passes with your new `sensor_poll` tests included.

---

## Step 1 — Build the Traceability Matrix (7 minutes)

Create `sample-repo/specs/001-sensor-fault-diagnostics/traceability.md` with one row per acceptance criterion, following the same REQ → CON → AC → Task → Test chain from Exercise 1:

```markdown
# Traceability: Sensor Fault Diagnostics

| Requirement | Constraint | Acceptance Criterion | Task | Test |
|---|---|---|---|---|
| REQ-1 | CON-1 | AC-1 (no fault → returns 0) | T-2 | test_no_fault_returns_zero |
| REQ-1 | CON-3 | AC-2 (temperature fault message) | T-3 | test_temperature_fault_message |
| REQ-1 | CON-3 | AC-3 (pressure fault message) | T-4 | test_pressure_fault_message |
| REQ-1 | CON-2 | AC-4 (door+motion fault message) | T-5 | test_door_motion_fault_message |
| REQ-2 | — | AC-x (priority order) | T-6 | test_priority_order_on_multiple_faults |
| REQ-3 | CON-1 | AC-x (buffer too small) | T-7 | test_buffer_too_small_returns_zero |
```

Fill in your actual REQ/CON/AC/Task IDs from your own `spec.md`, `plan.md`, and `tasks.md` — this table only has value if every ID in it is real and cross-checkable, not illustrative.

For each row, open the actual test function named in the last column and confirm it exists and asserts what the row claims. If a row's test doesn't exist yet, or doesn't actually test that acceptance criterion, that's a gap in your implementation, not a documentation nit — go fix it before continuing.

## Step 2 — Final Verification (3 minutes)

```sh
cd sample-repo
make test
```

Capture (mentally or in a scratch note) the pass count. This is your evidence artifact — the same kind of test evidence Module 06's test strategy and Module 09's PR quality gates will expect attached to every SDD-developed change.

## Step 3 — Anti-Pattern Self-Audit (3 minutes)

Go back to Exercise 1's Do This / Not That table and check your own work against all five rows honestly:

- [ ] Are your acceptance criteria testable, observable conditions — or did any slip back into vague adjectives under time pressure?
- [ ] If you changed your mind about anything mid-implementation (the priority order, the error code, the empty-buffer behavior), did you update `spec.md` to match, or does it now say something your code doesn't do?
- [ ] Did you keep the plan step, or did Exercise 3 get rushed/skipped?
- [ ] Would a reviewer be able to check your diff against `spec.md` directly, without you explaining your intent out loud?
- [ ] Do your acceptance criteria and tests actually correspond 1:1, or did the test file end up testing different things than the spec promised?

If any box is unchecked, that's not a failed exercise — it's exactly the kind of drift SDD is designed to make visible. Note it; you'll want to watch for it again in Module 05's larger-scale build.

## Step 4 — Checkpoint Question

Pick any single line inside your `sensor_poll_get_fault_diagnostics()` implementation (or your feature's equivalent function name, if you named it differently) and answer, in one sentence: **which requirement made this line necessary?**

If you can't answer immediately for a line you wrote 20 minutes ago, that's worth noticing — it's a preview of what a reviewer without your context will feel looking at the same line in a PR six weeks from now.

---

## Checkpoint

- [ ] `traceability.md` exists with every acceptance criterion mapped to a real task and a real, verified test
- [ ] `make test` passes, and you have the evidence (pass/fail count) noted
- [ ] You completed the five-row anti-pattern self-audit honestly, including any unchecked boxes
- [ ] You can answer the checkpoint question for at least one line of your implementation

## Where This Goes Next

- `spec.md`, `plan.md`, `tasks.md`, and `traceability.md` are now real artifacts in `sample-repo/specs/001-sensor-fault-diagnostics/` — carry them forward; Module 05 builds a complete greenfield feature the same way, at larger scale, and then applies the same spec-first discipline to brownfield firmware changes.
- The traceability chain you just built by hand is exactly what Module 09's LLM-as-Judge PR review checks automatically — specification compliance is only checkable because the chain exists to check against.

**Module 04 complete.** Next: **Module 05 — Embedded Development: SDD to Complete Software SDLC** (3.5 hours). Build a greenfield feature from specification through implementation and testing, then analyze a brownfield firmware repository and apply the same discipline safely to existing code.
