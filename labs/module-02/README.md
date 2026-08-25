# Module 02 — Guided Lab: GitHub Copilot Enterprise Features for Embedded Engineering

**Duration:** 2 hours | **Format:** Hands-on lab + guided demo | **Audience:** All roles, technical hands-on depth for Embedded/Firmware Developers, Architects, Testers, DevOps/SRE, Engineering Leads

This is a **hands-on coding lab** against a real (if minimal) C codebase — [`sample-repo/`](sample-repo/), a host-buildable simulation of a Honeywell PA/IA/BA field controller node. Every exercise works directly in that repository with GitHub Copilot Enterprise.

---

## Learning Objectives

By the end of this lab, you will have:

1. Used all five Copilot capability clusters — conversational/inline, code quality, autonomous/repository-aware, workflow integration, and reuse/governance — hands-on, in one repository.
2. Generated, explained, and safely refactored real embedded C code.
3. Root-caused and fixed a live defect in the CAN driver's error-confinement logic.
4. Generated host-based unit tests (including boundary/negative cases) and run an AI-assisted PR review pass.
5. Scoped and supervised an Agent Mode task that implements a new module across multiple files.
6. Measured — not guessed at — the time and confidence delta between manual and AI-assisted work, against your Module 01 baseline.

---

## Before You Start

**Complete [setup.md](setup.md) first** — access checklist, toolchain check, and confirming the sample repository builds (with its intentional failing tests) before the session begins.

---

## Agenda

| # | Block | Duration | Exercise File |
|---|-------|----------|----------------|
| 0 | Capability Map Walkthrough & Repository Orientation | 15 min | [00-capability-map-walkthrough.md](00-capability-map-walkthrough.md) |
| 1 | Generate, Explain & Refactor Live | 20 min | [01-generate-explain-refactor.md](01-generate-explain-refactor.md) |
| 2 | Debug a Real Defect | 20 min | [02-debug-a-defect.md](02-debug-a-defect.md) |
| 3 | Generate Tests & Review a PR | 20 min | [03-generate-tests-and-pr-review.md](03-generate-tests-and-pr-review.md) |
| 4 | Agent Mode on a Repository Task | 25 min | [04-agent-mode-repository-task.md](04-agent-mode-repository-task.md) |
| 5 | Manual vs. AI-Assisted Comparison | 20 min | [05-manual-vs-ai-comparison.md](05-manual-vs-ai-comparison.md) |

Exercises are sequential — each one builds on the code state left by the previous one. Don't skip ahead; Exercise 4 in particular assumes Exercise 2's fix and Exercise 3's test file are already in place.

---

## The Sample Repository

[`sample-repo/`](sample-repo/) is a small, dependency-free C codebase: a CAN driver, sensor polling, a device state machine, a diagnostics formatter, and HAL stubs — all host-buildable with nothing but `gcc`/`make`. No hardware integration is required or demonstrated, consistent with this programme's software-level-only scope.

It ships with:
- **An intentional defect** in the CAN driver (Exercise 2's target)
- **An intentionally monolithic function** in `sensor_poll.c` (Exercise 1's refactor target)
- **An unimplemented function** in `diag_formatter` (Exercise 1's inline-assist target)
- **An untested module** (`hal_adc`'s conversion function — Exercise 3's target)
- **A module that doesn't exist yet** (`fault_monitor` — Exercise 4's Agent Mode target)

See [`sample-repo/README.md`](sample-repo/README.md) and [`sample-repo/docs/ARCHITECTURE.md`](sample-repo/docs/ARCHITECTURE.md) for full details.

---

## Deliverables Checklist

Walk out of Module 02 with:

- [ ] A working `diag_format_sensor_fault` implementation (Exercise 1)
- [ ] A refactored `sensor_poll_all` with verified-unchanged behavior (Exercise 1)
- [ ] The CAN driver defect fixed, with a clean `make test` run (Exercise 2)
- [ ] Boundary/negative-case tests for `hal_adc_raw_to_millivolts` (Exercise 3)
- [ ] A completed AI-assisted PR review pass, with notes on what it caught vs. missed (Exercise 3)
- [ ] A working `fault_monitor` module built via supervised Agent Mode (Exercise 4)
- [ ] A completed manual-vs-AI task log, connected to your Module 01 success-metrics baseline (Exercise 5)

---

## What's Next

**Module 03 — Prompt Engineering Recap and Context Engineering** (2 hours). You'll take a new task in this same `sample-repo/` and compare prompt-only context against structured repository and design context — measuring output quality, token usage, iteration count, and completion time. Keep the repository and your Exercise 5 task log; both get reused.

For facilitators: see [facilitator-guide.md](facilitator-guide.md) for the run sheet, common pitfalls, and troubleshooting.
