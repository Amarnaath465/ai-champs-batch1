# Exercise 1: Problem Framing & Architecture

**Duration:** 30 minutes | **Format:** Recap + individual, hands-on in `sample-repo/`

## Objective

Before any code gets written today, frame the problem you're solving and design the shape of the solution — the module boundary, the interfaces, the constraints. This is the step both engineering flavours share, and the one prompt-only development skips straight past.

---

## Two Engineering Flavours, One Disciplined Lifecycle

Today you'll build software two different ways, and neither is the "easy" path — they optimize for different risks.

| | Greenfield — built from specification | Brownfield — safe evolution of existing code |
|---|---|---|
| **The risk** | Building the wrong thing well | Breaking something that already works |
| **Architecture & interfaces** | Designed fresh | Discovered through repository archaeology |
| **Success looks like** | Complete feature, clean structure, full test coverage from day one | Minimal, well-scoped change with proven behavior preservation |
| **Where Copilot is most confident** | Clear scope, clean slate, well-represented patterns | Needs the most supervision — undocumented history, thin coverage |
| **The discipline that matters** | Don't let a clean slate become an unscoped one | Understand before you touch, then change as little as possible |

Both paths walk the same seven-stage SDLC — you'll walk it twice today, once for each flavour:

| Stage | What it means |
|---|---|
| Problem Framing | What are we actually solving, and for whom? |
| Architecture & Interfaces | Module boundaries, contracts, HAL touchpoints |
| Module Structure | How the feature decomposes into files & functions |
| C/C++ Implementation | Copilot-assisted, checked against spec at every step |
| Test & Static Analysis | Unit, integration, and static checks before anything ships |
| Build & CI/CD | Toolchain build, pipeline validation, reproducibility |
| Release Readiness | Everything that must be true before this ships |

What differs between the two paths is not *which* stages happen — it's how much discovery precedes each one. Exercise 6 will ask you to fill in what changed at each stage, from what you actually did today, not from this table.

---

## The Problem: EVENTLOG-01

> **EVENTLOG-01** — When a field unit's CAN bus goes into `BUS_OFF`, we only find out days later from a customer complaint. We have no record of when it happened, how often, or whether it's recovering on its own. We need something that keeps a running record of diagnostic events on the device itself, so a field technician (or a later software query) can retrieve recent fault history without needing to reproduce the failure live.

This is deliberately under-specified, the same way Module 04's SENSOR-142 ticket was — it tells you the problem, not the design. Today, you're framing and architecting a solution from scratch: a new module, greenfield, with no existing code to preserve or work around.

## Step 1 — Where Does This Module Live? (5 minutes)

Open [`sample-repo/docs/ARCHITECTURE.md`](../module-02/sample-repo/docs/ARCHITECTURE.md) and look at the layer diagram. `diag_formatter` is described as "cross-cutting" — any layer may call it, and it depends on nothing else in the codebase.

Decide: is an event log a **driver**, a **logic-layer** module, or **cross-cutting infrastructure** like `diag_formatter`? Write down your answer and your reasoning in one or two sentences. This decision determines who's allowed to call it later — including, eventually, `can_driver.c` in Part 2 of today's lab.

## Step 2 — Four Architecture Decisions (15 minutes)

Before you write a formal spec (that's Exercise 2), sketch answers to four concrete design questions. There's a right *kind* of answer to each (informed by the coding standards), but the exact values are yours to decide and defend:

1. **Capacity.** This is an embedded target — no dynamic allocation (`docs/CODING_STANDARDS.md`). Pick a fixed capacity for how many events the log holds at once. What's a defensible number for a diagnostic log on a resource-constrained device, and why?
2. **What happens when it's full?** Two real options: reject new events once full, or overwrite the oldest. Which serves "figure out what went wrong in the field" better — and what does the *other* option quietly cost you?
3. **What does one entry need to hold?** At minimum: something identifying *what* happened, and *when*. Look at `diag_formatter.h`'s `diag_error_code_t` enum — could an event log entry reuse it instead of inventing a new code space? What are the timestamp options available to a host-buildable module that has no real hardware clock?
4. **How does something *else* attach to this log?** You don't know yet exactly what will feed events into your log (that's Part 2 of today's lab) — but whatever you design must be attachable to another module *without changing that module's existing function signatures*. Sketch what that attachment might look like at the interface level — you'll find out in Exercise 4 whether your sketch holds up.

Write your four answers down — a few lines each is enough. You'll turn this directly into `spec.md`'s Requirements and Constraints sections in Exercise 2.

## Step 3 — Draft the Interface (10 minutes)

Sketch — on paper, in a scratch file, wherever's fastest — the function signatures you think this module needs. Don't worry about getting it exactly right; this draft is allowed to change once you formalize it as a spec. At minimum, you'll likely need something to initialize the log, something to record an event, something to read entries back out, and something to check how many events (or how many were lost) are in the log.

Check your draft against `docs/CODING_STANDARDS.md`: `snake_case`, a module prefix on every public symbol, `_t` on types, `bool` for success/failure, `size_t` for "how much."

---

## Checkpoint

- [ ] You can state, in one sentence, which architectural layer this module belongs to and why
- [ ] You have written answers to all four architecture-decision questions
- [ ] You have a draft function-signature list, even if rough

## Where This Goes Next

Exercise 2 turns this sketch into a real `spec.md` using the same four-section template from Module 04, then implements it task by task. The attachment mechanism you sketched in Step 2, Question 4 will matter again in Exercise 4 — hold onto it.
