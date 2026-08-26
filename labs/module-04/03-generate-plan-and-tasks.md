# Exercise 3: Generate Plan & Tasks

**Duration:** 20 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Turn `spec.md` into a reviewed implementation plan and a small, ordered, independently-verifiable task list — the step that prompt-only development skips entirely. No implementation code gets written in this exercise.

## Prerequisites

Completed [Exercise 2](02-write-the-specification.md). `sample-repo/specs/001-sensor-fault-diagnostics/spec.md` exists with all four sections filled in and self-reviewed.

---

## Step 1 — Generate a Draft Plan with Copilot (7 minutes)

Open `spec.md` in your IDE (so it's in context) and ask Copilot Chat something like:

> "Here's my spec for a new sensor_poll function (spec.md is open). Propose an implementation plan: which files it touches, what it reuses from diag_formatter, and the priority-check algorithm — matching the layering rules in docs/ARCHITECTURE.md and the conventions in docs/CODING_STANDARDS.md. Don't write code yet, just the plan."

This mirrors GitHub Spec Kit's `/plan` step: an architecture-and-approach document that gets reviewed *before* any code is generated — the stage prompt-only development skips, going straight from request to diff.

Save the result (edited by you — don't accept it uncritically) as `sample-repo/specs/001-sensor-fault-diagnostics/plan.md`, covering:

```markdown
# Plan: Sensor Fault Diagnostics

**Traces to:** spec.md

## Approach
(2-4 sentences: where the function lives, what it reuses, how the priority
check works)

## Files Touched
- include/sensor_poll.h — ...
- src/sensor_poll.c — ...
- tests/test_sensor_poll.c — ...

## Constraint Checks
- [ ] No dynamic allocation
- [ ] No direct hal_adc_*/hal_gpio_* calls from the new function
- [ ] Reuses diag_format_message() / diag_format_sensor_fault() rather than duplicating snprintf logic

## Open Questions / Risks
(anything the spec left ambiguous that you resolved while planning — name it, don't silently decide)
```

## Step 2 — Review the Plan Against the Spec (5 minutes)

Before breaking the plan into tasks, check it line by line against `spec.md`:

- [ ] Does the plan's approach actually satisfy every acceptance criterion in your spec — not just the happy path?
- [ ] Does "Files Touched" match your spec's Interfaces & Contracts section exactly (same function name, same signature)?
- [ ] Did Copilot's proposed approach respect the layering constraint (no `hal_*` calls), or does it need correcting? If it needs correcting, fix the plan now — this is the cheap moment to catch it, per Module 02's Agent Mode lesson: **correcting a plan is cheaper than reviewing a wrong diff.**

If anything in the plan doesn't trace back to a REQ/CON/AC in your spec, either the plan is over-building or your spec had a gap — resolve which one it is before moving on.

## Step 3 — Break the Plan into Tasks (8 minutes)

Ask Copilot to break `plan.md` into small, ordered, independently-verifiable tasks, each one traceable to a spec ID. Something like:

> "Break plan.md into a task list — small, ordered, each independently verifiable, and each one naming which REQ/CON/AC it satisfies."

Save the result as `sample-repo/specs/001-sensor-fault-diagnostics/tasks.md`, as a table:

```markdown
# Tasks: Sensor Fault Diagnostics

**Traces to:** plan.md

| Task ID | Description | Traces to | Verification |
|---|---|---|---|
| T-1 | Add function declaration + contract comment to sensor_poll.h | REQ-1, Interfaces | Header compiles; comment states priority rule |
| T-2 | Implement no-fault case (return 0, buf untouched) | AC-1 | Unit test |
| T-3 | Implement temperature-fault branch via diag_format_sensor_fault | AC-2 | Unit test |
| T-4 | Implement pressure-fault branch | AC-3 | Unit test |
| T-5 | Implement door+motion branch via diag_format_message | AC-4 | Unit test |
| T-6 | Implement priority ordering across simultaneous faults | AC-x (your multi-fault AC) | Unit test |
| T-7 | Implement buffer-too-small handling | AC-x (your overflow AC) | Unit test |
| T-8 | Write tests/test_sensor_poll.c covering T-2..T-7 | all ACs | make test |
```

Your exact task list will depend on how many acceptance criteria your `spec.md` ended up with — adjust rows accordingly, but keep each task small enough that it corresponds to roughly one focused Copilot interaction and one or two assertions in the test file, not a whole feature at once.

**Sanity check before moving on:** pick any one task at random and ask yourself "which requirement made this necessary?" If you can't answer immediately, that task doesn't trace cleanly — fix it now, not during Exercise 5.

---

## Checkpoint

- [ ] `plan.md` exists, reviewed against the spec, with constraint checks ticked
- [ ] `tasks.md` exists as an ordered table, every row naming a spec ID it traces to
- [ ] No task in the list involves more than one acceptance criterion's worth of new behavior

## Where This Goes Next

Exercise 4 executes `tasks.md` one row at a time with Copilot — each task's diff gets checked against the spec as it lands, which is the whole point of having written one.
