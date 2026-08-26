# Exercise 2: Write a Specification, Live

**Duration:** 25 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Turn a short, informal feature request into a real specification — requirements, constraints, interfaces & contracts, and acceptance criteria — for a feature that genuinely does not exist yet in `sample-repo/`. You'll implement this exact spec in Exercises 3–5, so the decisions you make here are the ones you'll live with for the rest of the module.

## Prerequisites

Completed [Exercise 1](01-sdd-fundamentals-and-spec-anatomy.md) and [setup.md](setup.md). Have these open for reference:

- `sample-repo/include/sensor_poll.h` and `sample-repo/src/sensor_poll.c`
- `sample-repo/include/diag_formatter.h` and `sample-repo/src/diag_formatter.c`
- `sample-repo/docs/CODING_STANDARDS.md`
- `sample-repo/docs/ARCHITECTURE.md`

---

## The Ticket

> **SENSOR-142 — Surface sensor faults as diagnostic messages**
>
> Today, `sensor_poll_all()` sets bits in `sensor_snapshot_t.fault_flags` when a sensor reading is out of range or when the door+motion combination fires, but nothing ever turns those bits into a human-readable diagnostic message. Field support has asked for a function that produces one diagnostic string per polling tick, in the same `[0xCCCC] detail` format already used elsewhere in this firmware, so it can be logged or displayed. When more than one fault is active at once, they want to see the single most important one — not be flooded with every active fault every tick.

That's it — that's the whole ticket. Notice what it does *not* tell you: the exact function signature, which fault wins when two are active at once, which error-code range to use, or what happens when the caller's buffer is too small. **Translating an under-specified request like this into a precise, implementable spec is exactly the gap this module exists to close** — a real business risk this programme was built to reduce (see the course design's "weak translation of embedded requirements... into precise implementation tasks" problem statement).

## Step 1 — Read the Existing Contract Surface (5 minutes)

Before writing anything, confirm what's already there so your spec doesn't reinvent it:

1. In `sensor_poll.c`, find the three fault conditions and their bits: temperature high (bit 0), pressure high (bit 1), door+motion combined (bit 2). Note the ADC channel constants (`ADC_CH_TEMPERATURE`, `ADC_CH_PRESSURE`) — they're private to this file, not exposed in the header.
2. In `diag_formatter.h`/`.c`, confirm `diag_format_message(buf, buf_len, code, detail)` is fully implemented, and `diag_format_sensor_fault(buf, buf_len, channel, raw_value)` exists (you built it in Module 02, Exercise 1 — if you skipped that, implement it now or flag it to your facilitator; the rest of this exercise assumes it exists).
3. In `CODING_STANDARDS.md`, re-read the error-code range table and the "no dynamic allocation" / "return `size_t` for how-much-did-you-write" rules — both apply directly to what you're about to spec.
4. In `ARCHITECTURE.md`, re-read layering rule 4: "Diagnostics are cross-cutting... any layer may call `diag_format_message()`." Note there's no rule granting `sensor_poll` access to `hal_adc`/`hal_gpio` *from a function that only reads an already-filled snapshot* — a new function here should not need to touch HAL at all.

## Step 2 — Author `spec.md` (15 minutes)

Create the folder `sample-repo/specs/001-sensor-fault-diagnostics/` and a `spec.md` file inside it, using the template below. This mirrors GitHub Spec Kit's numbered-feature-folder convention (`specs/NNN-feature-name/`).

```markdown
# Spec: Sensor Fault Diagnostics

**Feature ID:** 001-sensor-fault-diagnostics
**Status:** Draft
**Source:** SENSOR-142

## 1. Requirements

### Functional
- REQ-1: ...
- REQ-2: ...

### Non-Functional
- REQ-3: ...

## 2. Constraints

- CON-1: ...
- CON-2: ...
- CON-3: ...

## 3. Interfaces & Contracts

- Function signature:
- Reuses:
- Must NOT:

## 4. Acceptance Criteria

- AC-1: ...
- AC-2: ...
- AC-3: ...
- AC-4: ...
```

Use Copilot Chat to help you draft — it's genuinely useful here for surfacing phrasing and catching gaps — but **you** make the four decisions below. Copilot cannot see the ticket's intent behind the words; only you can resolve real ambiguity.

Your spec must explicitly decide, and state:

1. **The function's exact signature** — name, parameters, return type. (Hint: match this codebase's conventions — `sensor_*` prefix, `size_t` return for "how much did you write," pointer-to-struct-first for anything that reads driver/sensor state, `const` where the function only reads.)
2. **The priority rule** when more than one fault bit is active at once — which single fault wins, and why that order makes sense operationally (hint: which fault would a field engineer want to know about first?).
3. **Which error-code range applies** to the door+motion fault, and which existing formatter function(s) your implementation will reuse rather than duplicate — check `CODING_STANDARDS.md`'s range table again; door+motion is a sensor-domain condition even though it isn't literally "out of range."
4. **What happens when `buf`/`buf_len` can't hold the message, or no fault is active at all** — state the return value in both cases, matching the convention `diag_format_message()` already established.

Write real requirement, constraint, and acceptance-criteria text — not placeholders. Aim for at least 2 functional requirements, 3 constraints, and 4 acceptance criteria. Run each acceptance criterion through Exercise 1's quality bar: **testable, bounded, interface-accurate, traceable** (give it an ID), and ready to be **reviewed**.

## Step 3 — Self-Review Against the Quality Checklist (5 minutes)

Before moving on, check your own `spec.md` against Exercise 1's five-point bar:

- [ ] **Testable** — could someone else write a unit test from AC-1 through AC-4 without asking you a clarifying question?
- [ ] **Bounded** — are your constraints stated as concrete rules ("no `malloc`/`free`," "caller-owned buffer"), not adjectives?
- [ ] **Interface-Accurate** — does your function signature actually match this codebase's real conventions, not an idealized one?
- [ ] **Traceable** — does every REQ, CON, and AC have an ID?
- [ ] **Reviewed** — if working in a group session, trade specs with a neighbor for two minutes and have them try to poke a hole in one acceptance criterion.

If a reviewer (or you, re-reading it cold) can't tell from AC-1–AC-4 alone what the function should return when zero faults are active, that's a gap — fix it now, not during Exercise 4.

---

## Checkpoint

- [ ] `sample-repo/specs/001-sensor-fault-diagnostics/spec.md` exists with all four sections filled in
- [ ] Every acceptance criterion has an ID and is testable without additional clarification
- [ ] You've made and written down all four required decisions (signature, priority rule, error-code range, empty/overflow behavior)

## Where This Goes Next

Exercise 3 turns this spec into a plan and a task list — without writing any implementation code yet. Keep `spec.md` open; you'll reference its REQ/CON/AC IDs directly.
