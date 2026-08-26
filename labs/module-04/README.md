# Module 04 — Guided Lab: Spec-Driven Development for Embedded Software

**Duration:** 2 hours | **Format:** Guided recap + hands-on spec-to-implementation lab | **Audience:** All roles, technical hands-on depth for Embedded/Firmware Developers, Architects, Testers, DevOps/SRE, Engineering Leads

From requirement to traceable implementation — spec → plan → tasks → implementation, with GitHub Spec Kit / OpenSpec turning Module 03's context-engineering discipline into a repeatable workflow. This module reuses the same [`sample-repo/`](../module-02/sample-repo/) from Modules 02–03; there's no new codebase to learn.

---

## Learning Objectives

By the end of this lab, you will have:

1. Explained the spec → plan → tasks → implementation flow and why each stage validates the next.
2. Learned what belongs in a specification — requirements, constraints, interfaces & contracts, acceptance criteria — and the five-point bar that separates a traceable spec from a wish list.
3. Written a real specification for a genuinely unimplemented embedded feature, using GitHub Spec Kit / OpenSpec patterns.
4. Generated a reviewed implementation plan and task breakdown directly from that specification.
5. Implemented against the spec with Copilot, task by task, checking each diff against its acceptance criterion as it landed.
6. Built a traceability matrix proving every acceptance criterion maps to implemented, tested behavior — and audited your own work against five common SDD anti-patterns.

---

## Before You Start

**Complete [setup.md](setup.md) first.** It's short — this module reuses Module 02's repository and one function you built there.

---

## Agenda

| # | Block | Duration | Exercise File |
|---|-------|----------|----------------|
| 1 | SDD Fundamentals & Spec Anatomy | 35 min | [01-sdd-fundamentals-and-spec-anatomy.md](01-sdd-fundamentals-and-spec-anatomy.md) |
| 2 | Write a Specification, Live | 25 min | [02-write-the-specification.md](02-write-the-specification.md) |
| 3 | Generate Plan & Tasks | 20 min | [03-generate-plan-and-tasks.md](03-generate-plan-and-tasks.md) |
| 4 | Implement Against the Spec | 25 min | [04-implement-against-the-spec.md](04-implement-against-the-spec.md) |
| 5 | Validate Traceability | 15 min | [05-validate-traceability.md](05-validate-traceability.md) |

Exercises are sequential — each stage's artifact feeds the next. Exercise 2's `spec.md` is the input to Exercise 3's `plan.md`/`tasks.md`, which drive Exercise 4's implementation, which Exercise 5 proves against the original spec. Don't skip ahead; there's no reference spec to fall back on if you do.

---

## Optional: Try the Real Tool

Exercises 1–5 deliberately use hand-written `spec.md`/`plan.md`/`tasks.md` files so the spec → plan → tasks → implement discipline stays visible regardless of tooling. If you finish early, or want to see the same discipline automated, [06-bonus-real-github-spec-kit-cli.md](06-bonus-real-github-spec-kit-cli.md) walks you through the actual GitHub Spec Kit CLI — real `/speckit-specify`, `/speckit-plan`, `/speckit-tasks`, `/speckit-implement` slash commands, in a fresh standalone repo — on one new, small feature. Not required, not timed into today's 2 hours.

---

## The Centerpiece: One Feature, Four Traceable Artifacts

Exercises 2–5 walk one real, currently-unimplemented feature through the complete SDD lifecycle:

> **SENSOR-142** — `sensor_poll_all()` already sets fault bits when a sensor reading is out of range, but nothing turns those bits into a diagnostic message. You'll specify, plan, implement, and validate a new function that does — deciding, and writing down, exactly what today's five-point spec-quality bar demands: a precise signature, a priority rule for simultaneous faults, the right error-code range, and defined behavior for the empty and buffer-too-small cases.

Each stage produces a real artifact inside `sample-repo/specs/001-sensor-fault-diagnostics/`:

| Stage | Artifact | Exercise |
|---|---|---|
| Specify | `spec.md` | 2 |
| Plan | `plan.md` | 3 |
| Tasks | `tasks.md` | 3 |
| Implement | `sensor_poll.h`/`.c`, `tests/test_sensor_poll.c` | 4 |
| Validate | `traceability.md` | 5 |

Unlike Module 03's `scratch/` experiments, these are real, permanent changes to the shared repository — this is the one place in the programme where "spec-driven" gets to mean "actually shipped," not "practiced in isolation."

---

## Deliverables Checklist

Walk out of Module 04 with:

- [ ] Three weak-to-strong acceptance-criteria rewrites, checked against the five-point quality bar (Exercise 1)
- [ ] A complete `spec.md` — requirements, constraints, interfaces & contracts, acceptance criteria — for a real, previously-unimplemented feature (Exercise 2)
- [ ] A reviewed `plan.md` and an ordered, traceable `tasks.md` (Exercise 3)
- [ ] A working implementation with `make test` green, built task-by-task against the spec (Exercise 4)
- [ ] A `traceability.md` matrix mapping every acceptance criterion to an implemented, tested behavior, plus a completed anti-pattern self-audit (Exercise 5)

---

## What's Next

**Module 05 — Embedded Development: SDD to Complete Software SDLC** (3.5 hours). Build a full greenfield feature from specification through architecture, implementation, and testing — then apply the same spec-first discipline to a brownfield firmware repository, safely, without breaking existing behavior.

For facilitators: see [facilitator-guide.md](facilitator-guide.md) for the run sheet, troubleshooting notes, and a reference design for the SENSOR-142 feature.
