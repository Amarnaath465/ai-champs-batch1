# Module 03 — Guided Lab: Prompt Engineering Recap and Context Engineering

**Duration:** 2 hours | **Format:** Guided recap + progressive lab | **Audience:** All roles, technical hands-on depth for Embedded/Firmware Developers, Architects, Testers, DevOps/SRE, Engineering Leads

From prompt-only guesswork to structured, token-aware context — the discipline every SDD, MCP, and PR-quality module from here depends on. This module reuses the same [`sample-repo/`](../module-02/sample-repo/) from Module 02; there's no new codebase to learn.

---

## Learning Objectives

By the end of this lab, you will have:

1. Made the six prompt-engineering building blocks explicit, and seen a weak and a strong prompt solve the same problem side by side.
2. Learned the nine-source, four-category embedded context inventory — and practiced scoping it to a specific task rather than supplying it wholesale.
3. Learned the five context-engineering practices (selection, layering, compression, task-scoped boundaries, token-awareness) and the anti-patterns that cause context inflation.
4. Solved the same embedded task **four times** — prompt-only, +code context, +design context, compressed & scoped — and measured output quality, estimated token cost, iteration count, and completion time across all four.
5. Identified, from your own data, where adding context stops paying for itself.

---

## Before You Start

**Complete [setup.md](setup.md) first.** It's short — this module reuses Module 02's repository rather than shipping a new one.

---

## Agenda

| # | Block | Duration | Exercise File |
|---|-------|----------|----------------|
| 1 | Prompt Engineering Recap & Weak-vs-Strong Walkthrough | 30 min | [01-prompt-recap-and-weak-vs-strong.md](01-prompt-recap-and-weak-vs-strong.md) |
| 2 | The Embedded Context Inventory | 20 min | [02-embedded-context-inventory.md](02-embedded-context-inventory.md) |
| 3 | Context Layering & Compression | 20 min | [03-context-layering-and-compression.md](03-context-layering-and-compression.md) |
| 4 | Four-Round Progressive Lab + Measure & Compare | 50 min | [04-four-round-progressive-lab.md](04-four-round-progressive-lab.md) |

Exercises are sequential. Exercise 4 is the centerpiece — it directly reuses the task-scoping decisions from Exercise 2 and the layered-context plan you write in Exercise 3, so don't skip ahead to it cold.

---

## The Centerpiece: One Task, Four Rounds

Exercise 4 asks you to implement the exact same small function — a CAN driver error-summary formatter — four separate times, changing only how much (and what kind of) context you supply each round:

| Round | Context |
|---|---|
| 1 | None — task framing only |
| 2 | + Source/header files open |
| 3 | + Design docs (coding standards, architecture) open |
| 4 | Same facts as Round 3, delivered as a compressed, scoped prompt instead of open files |

You'll score each round's output against a 5-point quality rubric, estimate its token cost, count iterations, and time it — captured in [`scratch/measurement-worksheet.md`](scratch/measurement-worksheet.md). This becomes your own first data point for the token/cost and ROI conversation that resumes properly in Module 11.

---

## Deliverables Checklist

Walk out of Module 03 with:

- [ ] A weak and a strong prompt for the same task, with the difference annotated against the six building blocks (Exercise 1)
- [ ] A completed context-inventory mapping for three different task types (Exercise 2)
- [ ] A written, layered context plan for the Exercise 4 task (Exercise 3)
- [ ] Four captured code samples in `scratch/round-1..4-*.c`, each scored (Exercise 4)
- [ ] A completed measurement worksheet with a quality-vs-token comparison across all four rounds (Exercise 4)

---

## What's Next

**Module 04 — Spec-Driven Development for Embedded Software** (2 hours). A specification is the next, larger unit of context — the same selection, layering, and compression discipline you practiced today on a single function applies at the scale of a full feature, using GitHub Spec Kit / OpenSpec.

For facilitators: see [facilitator-guide.md](facilitator-guide.md) for the run sheet and troubleshooting notes.
