# Module 06 — Guided Lab: Embedded Test Strategy, Validation and Regression Engineering

**Duration:** 2.5 hours | **Format:** Guided Build + Break-It Lab | **Audience:** All roles, technical hands-on depth for Embedded/Firmware Developers, Architects, Testers, DevOps/SRE, Engineering Leads

Proving what Module 05 built actually works — host-based tests, mocks for hardware, static analysis, and a defect the strategy has to catch. This module ships no new feature. Everything here is testing work performed directly on the `event_log` module and its `can_driver` integration from Module 05.

---

## Learning Objectives

By the end of this lab, you will have:

1. Derived a test strategy directly from a specification's acceptance criteria, and used it to find real gaps in already-shipped code.
2. Classified tests by the three-layer embedded test pyramid — unit, integration, software-level E2E — and known when each layer is enough.
3. Built mocks, stubs, and fakes for hardware-dependent interfaces, closing a real, verified gap in the existing HAL stub.
4. Practiced boundary and negative testing, including reproducing and then fixing a real crash.
5. Run static analysis, a full build-validation pass, and a sanitizer build as an automated gate before human review.
6. Run a full regression suite against a brownfield change as actual proof — not an assumption — that nothing broke.
7. Injected a real defect and proved the test strategy catches it, then assembled a test-evidence package a reviewer could check in under a minute.

---

## Before You Start

**Complete [setup.md](setup.md) first.** Module 06 has hard dependencies on Module 05's actual artifacts — confirm they're present before continuing.

---

## Agenda

| # | Block | Duration | Exercise File |
|---|-------|----------|----------------|
| 1 | Spec-to-Test Traceability | 20 min | [01-spec-to-test-traceability.md](01-spec-to-test-traceability.md) |
| 2 | The Embedded Test Pyramid | 20 min | [02-embedded-test-pyramid.md](02-embedded-test-pyramid.md) |
| 3 | Mocks, Stubs & Fakes | 25 min | [03-mocks-stubs-and-fakes.md](03-mocks-stubs-and-fakes.md) |
| 4 | Static Analysis & Build Validation | 20 min | [04-static-analysis-and-build-validation.md](04-static-analysis-and-build-validation.md) |
| 5 | Write & Run the Test Suite | 35 min | [05-write-and-run-the-test-suite.md](05-write-and-run-the-test-suite.md) |
| 6 | Inject a Defect, Prove the Strategy | 30 min | [06-inject-a-defect-prove-the-strategy.md](06-inject-a-defect-prove-the-strategy.md) |

Exercises are sequential. Exercise 1 finds three real gaps in Module 05's shipped code; Exercise 2 classifies them; Exercise 3 closes two of them and builds the tooling for the third; Exercise 4 validates everything built so far; Exercise 5 closes the third gap and runs the full regression suite; Exercise 6 proves the whole thing actually catches a real defect.

---

## Extending Module 05, Not Replacing It

Module 05 shipped two real artifacts: a greenfield `event_log` module and a brownfield integration wiring it into `can_driver.c`. Both had tests. Neither had a **formal test strategy** — a document proving every acceptance criterion is covered, every constraint has a boundary/negative test, and every claim of "it works" is backed by evidence a reviewer can check.

Exercise 1 finds exactly what's missing by holding Module 05's actual shipped code up against its own spec:

| Gap Found | Real, Verified? | Closed In |
|---|---|---|
| No test one entry below capacity | Yes — genuine boundary not previously tested | Exercise 3 |
| `event_log_get(log, index, NULL)` crashes | Yes — reproduces as a real segfault against Module 05's shipped code | Exercise 3 |
| No test exercises `sensor_poll` + `can_driver` + `event_log` together | Yes — the real HAL stub can't even be driven to a specific fault state on demand | Exercises 3 & 5 |

Every gap in this table was verified before these instructions were written — the crash is real, and the HAL stub's door+motion fault path being permanently unreachable (`hal_gpio_read`'s formula never returns true for the door or motion pins) is a real, confirmed property of the shipped code, not a hypothetical teaching example.

---

## Deliverables Checklist

Walk out of Module 06 with:

- [ ] `test-strategy.md` — every acceptance criterion and regression guarantee from Module 05's `spec.md`/`brownfield-plan.md`, mapped to a real, verified test (Exercise 1)
- [ ] A pyramid classification of every test in the repository, plus the three Exercise 1 gaps (Exercise 2)
- [ ] `tests/fakes/hal_adc_fake.{h,c}` and `tests/fakes/hal_gpio_fake.{h,c}`, wired into the Makefile, plus `tests/test_event_log_boundary.c` with both new tests passing (Exercise 3)
- [ ] A confirmed-clean sanitizer build (`-fsanitize=address,undefined`) across every test binary (Exercise 4)
- [ ] `tests/test_device_e2e.c` — a genuine multi-module test using the fakes — plus a fully green `make test` across the whole repository (Exercise 5)
- [ ] `test-evidence.md` with a real traceability table, build/static-analysis log, test run output, and regression confirmation, plus a completed anti-pattern self-audit (Exercise 6)

---

## What's Next

**Module 07 — MCP-Enabled Agentic Embedded Engineering and Reusable Skills** (2 hours). Connect agents to approved repositories, build/test tools, and CI services — then package today's test-strategy discipline as a reusable, versioned skill.

For facilitators: see [facilitator-guide.md](facilitator-guide.md) for the run sheet, the two verified injectable defects, and troubleshooting notes.
