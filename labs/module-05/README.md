# Module 05 — Guided Lab: Embedded Development, SDD to Complete Software SDLC

**Duration:** 3.5 hours | **Format:** Twin-track build lab | **Audience:** All roles, technical hands-on depth for Embedded/Firmware Developers, Architects, Testers, DevOps/SRE, Engineering Leads

Two engineering flavours, one disciplined lifecycle. You'll build a genuinely new embedded module from scratch — problem framing through release readiness — and then take the discipline you just practiced and apply it to the harder, more realistic case: safely evolving code that already exists and already works. This module reuses the same [`sample-repo/`](../module-02/sample-repo/) from Modules 02–04; there's no new codebase to learn, but today you'll modify two of its existing files for the first time in this programme.

---

## Learning Objectives

By the end of this lab, you will have:

1. Explained why greenfield and brownfield embedded work share the same seven-stage SDLC but carry different risk at every stage.
2. Framed a problem and designed a module's architecture and interfaces before writing any code.
3. Built a complete new embedded module from a specification through implementation, host-based testing, and build validation.
4. Practiced repository archaeology — architecture analysis, dependency mapping, interface contracts, HAL boundaries, change-impact analysis, extension points — on a real existing module before changing it.
5. Applied a minimal-change strategy to safely wire a new capability into existing, tested firmware, and proved you didn't break it.
6. Compared what "done" means for a greenfield feature versus a brownfield enhancement, stage by stage.

---

## Before You Start

**Complete [setup.md](setup.md) first.** The one hard blocker: Module 02's CAN driver defect must already be fixed, or today's brownfield exercises have nothing safe to build on.

---

## Agenda

| # | Block | Duration | Exercise File |
|---|-------|----------|----------------|
| 1 | Problem Framing & Architecture | 30 min | [01-problem-framing-and-architecture.md](01-problem-framing-and-architecture.md) |
| 2 | Greenfield: Spec to Implementation | 60 min | [02-greenfield-spec-to-implementation.md](02-greenfield-spec-to-implementation.md) |
| 3 | Testing & Build Validation | 30 min | [03-testing-and-build-validation.md](03-testing-and-build-validation.md) |
| 4 | Brownfield: Repository Archaeology | 45 min | [04-brownfield-repository-archaeology.md](04-brownfield-repository-archaeology.md) |
| 5 | Safe Evolution & Regression Protection | 30 min | [05-safe-evolution-and-regression-protection.md](05-safe-evolution-and-regression-protection.md) |
| 6 | Compare & Release Readiness | 15 min | [06-compare-and-release-readiness.md](06-compare-and-release-readiness.md) |

Exercises are sequential. Exercise 1's architecture sketch feeds Exercise 2's spec; Exercise 2's implementation is what Exercise 3 tests and validates; Exercise 4's archaeology is what makes Exercise 5's change safe; Exercise 6 compares both finished artifacts side by side.

---

## The Centerpiece: One New Module, One Safely-Evolved Module

### Part 1 — Greenfield: `event_log`

> **EVENTLOG-01** — When a field unit's CAN bus goes into `BUS_OFF`, today there's no record of when it happened, how often, or whether it recovered on its own — only a customer complaint days later. You'll specify, design, implement, and test a fixed-capacity diagnostic event log from a clean slate: no existing code to preserve, but real embedded constraints to satisfy — no dynamic allocation, a defined overwrite-vs-reject policy under load, and an interface the rest of the codebase can adopt without any changes to itself.

### Part 2 — Brownfield: Wiring It Into `can_driver`

> Once `event_log` exists and is fully tested, you'll do the harder thing: analyze the **existing**, already-shipped `can_driver.c` state machine before touching it, then wire in exactly one call — at the moment the driver transitions into `CAN_STATE_BUS_OFF` — that records the event. The acceptance bar isn't just "it logs the event." It's "every existing caller and every existing test behaves exactly as before, unless they explicitly opt in."

| Stage | Artifact | Exercise |
|---|---|---|
| Frame & Architect | architecture sketch (scratch) | 1 |
| Specify (greenfield) | `spec.md`, `plan.md`, `tasks.md` | 2 |
| Implement (greenfield) | `include/event_log.h`, `src/event_log.c` | 2 |
| Test & Validate (greenfield) | `tests/test_event_log.c`, green `make test` | 3 |
| Archaeology (brownfield) | change-impact analysis (scratch) | 4 |
| Change Plan (brownfield) | `brownfield-plan.md` | 5 |
| Implement (brownfield) | minimal diff to `can_driver.h`/`.c` | 5 |
| Regression-Protect (brownfield) | `tests/test_can_driver_event_log.c`, full green suite, `test_can_driver.c` untouched | 5 |
| Compare | release-readiness self-audit | 6 |

---

## Deliverables Checklist

Walk out of Module 05 with:

- [ ] An architecture sketch for `event_log` made *before* any code was written (Exercise 1)
- [ ] A complete `spec.md`, reviewed `plan.md`, and ordered `tasks.md` for the greenfield feature (Exercise 2)
- [ ] A working `event_log` module — implementation and tests — with `make test` green (Exercises 2–3)
- [ ] A written change-impact analysis of `can_driver.c` done *before* it was modified (Exercise 4)
- [ ] A `brownfield-plan.md` naming how the change satisfies all four minimal-change principles (Exercise 5)
- [ ] A minimal, additive diff to `can_driver.h`/`.c`, a new regression test file, and a fully green `make test` run with the original `test_can_driver.c` unchanged (Exercise 5)
- [ ] A completed greenfield-vs-brownfield release-readiness self-audit (Exercise 6)

---

## What's Next

**Module 06 — Embedded Test Strategy, Validation and Regression Engineering** (2.5 hours). Both artifacts you build today — the greenfield `event_log` module and the brownfield `can_driver` change — feed directly into Module 06's test-strategy lab: specification-to-test traceability, mocks/stubs/fakes, boundary and negative testing, and proving a deliberately injected defect gets caught.

For facilitators: see [facilitator-guide.md](facilitator-guide.md) for the run sheet, reference designs, troubleshooting notes, and output-collection checklist.
