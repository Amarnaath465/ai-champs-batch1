# Exercise 1: SDD Fundamentals & Spec Anatomy

**Duration:** 35 minutes | **Format:** Guided recap → individual practice

## Objective

Learn the spec → plan → tasks → implementation flow, what belongs in a good specification, and how to tell a weak acceptance criterion from a strong one — before you write a real spec of your own in Exercise 2.

## The Flow: Spec → Plan → Tasks → Implement

Four stages, each one validating the next:

| Stage | Contains | Answers |
|---|---|---|
| **Specify** | Requirements, constraints, interfaces & acceptance criteria | What does "done" mean, in writing? |
| **Plan** | Architecture & implementation approach that satisfies the spec | How will this be built, before any code exists? |
| **Tasks** | The plan broken into small, independently-verifiable steps | What's the next concrete, checkable action? |
| **Implement** | Copilot-assisted implementation, each task checked back against the spec as it lands | Does what just got built actually match what was specified? |

**The rule that makes this work:** every stage traces back to the one before it. A task with no line back to a requirement is a task worth questioning.

This is tool-agnostic — whether your team uses GitHub Spec Kit's `/specify` `/plan` `/tasks` `/implement` commands, an OpenSpec-equivalent pattern, or a hand-written spec doc, it's the four-stage discipline that matters, not the specific CLI. Today's lab writes spec/plan/tasks as plain markdown files so the discipline is visible either way.

## What Goes Into a Specification

A good spec is **scoped, not exhaustive** — it covers exactly what this feature needs from each category, the same task-scoping discipline from Module 03, applied to a document instead of a prompt.

| Category | Covers |
|---|---|
| **Requirements** | Functional requirements, non-functional requirements, stakeholder intent |
| **Constraints** | Timing/resource constraints, memory & performance limits, platform & toolchain limits |
| **Interfaces & Contracts** | Function signatures & structs, API/driver boundaries, existing behavior to preserve |
| **Acceptance Criteria** | Observable pass/fail conditions, edge & negative cases |

## What the Calibration Survey Told Us

Real answers from 19 Honeywell engineers, gathered before this programme was designed:

- **15 of 19 (79%)** already work from some form of specification before implementation — 8 use formal spec → plan → tasks, 7 use spec-and-design-docs → tests, and only 4 go straight from prompt/discussion to code.
- Asked how their team specifies new features: 8 said user stories or tickets, 5 a mix, 4 requirements documents, 2 technical specifications.
- **Only 3 of 19** explicitly asked to "learn specification-driven development" as a training goal.

Put together: **this isn't unfamiliar territory for most of this room — it's under-tooled.** User stories and tickets rarely carry acceptance criteria or traceability. Today's module gives the practice this cohort already leans toward a name, a tool, and a traceable structure — without slowing anyone down.

## Prompt-Only vs. Spec-Driven Development

The same distinction from Module 03, now applied to a whole feature instead of a single task.

| Prompt-Only Development | Spec-Driven Development |
|---|---|
| "Add a feature that does X" — acceptance criteria exist only in the requester's head | Acceptance criteria are written down before implementation starts — observable, testable |
| No plan step: Copilot jumps straight from request to code, right or wrong | A plan step validates the approach against constraints before any code is generated |
| Interfaces & constraints get discovered by trial and error, mid-implementation | Interfaces & constraints are stated up front, scoped exactly like Module 03's context layers |
| No traceability — impossible to prove later that the requirement was actually met | Every task traces back to a requirement — traceability is a byproduct, not extra work |
| Review has to re-derive intent from a diff, since there's no spec to check against | Review checks the diff against the spec directly — faster, more objective sign-off |

## Specification Quality: What "Good" Looks Like

Five checks that separate a traceable spec from a wish list:

1. **Testable** — every requirement resolves to a pass/fail condition. "Works correctly" is never an acceptance criterion.
2. **Bounded** — constraints are explicit: timing, memory, resource limits, stated as numbers, not adjectives.
3. **Interface-Accurate** — function signatures and contracts match what the codebase actually exposes, not an idealized version of it.
4. **Traceable** — each requirement carries an identifier a task and a test can reference back to.
5. **Reviewed** — a second engineer has checked the spec itself, before implementation, not just the code after.

**Quick test:** if you can't write the acceptance-criteria checklist from the spec alone, the spec isn't done yet.

---

## Worked Example: Acceptance Criteria, Weak vs. Strong (10 minutes)

The same feature request, specified two ways. Read both, then answer the questions below.

> **Weak:** *"The sensor-polling loop should handle errors gracefully and not impact performance."*

Problems with this, made explicit:
- "Gracefully" has no test
- "Not impact performance" has no threshold
- No stated polling interval or timeout behavior
- Nothing to check the implementation against

> **Strong:** *"AC-1: On sensor read timeout (>50ms), retry once then log `SENSOR_TIMEOUT` and return last-known value. AC-2: Polling loop completes within 2ms at 100Hz, measured over 1,000 cycles."*

Why this works:
- Explicit threshold: 50ms timeout, 2ms budget
- Named, checkable behavior on failure
- Directly convertible into a unit test

**Notice:** the strong version reads like a test case, because it's meant to become one. That's the quality bar from the checklist above, applied.

### Individual Practice (10 minutes)

Rewrite each weak acceptance criterion below as a strong one — testable, bounded, and directly convertible into a test. Invent reasonable numbers; the goal is the *shape* of a strong AC, not a specific correct threshold.

1. Weak: *"The CAN driver should recover from bus-off reasonably quickly."*
   Strong: _______________________________________________

2. Weak: *"Diagnostic messages should be properly formatted."*
   Strong: _______________________________________________

3. Weak: *"The system should not crash if a sensor is disconnected."*
   Strong: _______________________________________________

Compare your rewrites with a neighbor if working in a group session — a common failure mode is writing a strong-*sounding* AC that's still not actually testable (e.g., "recovers within a reasonable number of ticks" is still weak — "reasonable" is doing the same job "gracefully" did).

---

## Traceability & Change Control (5 minutes, guided)

Every implementation decision should answer one question: **which requirement made me necessary?**

A single requirement traces end to end through five identifiers:

```
REQ-014 "Diagnostic messages must include a monotonic timestamp"
  → CON-03 "formatter must not allocate on the heap"
  → AC-014a "timestamp field present and increasing across 100 consecutive messages"
  → T-027 "implement timestamp field in diag_format()"
  → TC-014a "unit test asserting monotonic timestamps under load"
```

**When the spec changes mid-flight:** update the requirement first, then let the change ripple forward through constraint → acceptance criterion → task → test. Never patch a task without touching the spec it traces to — a task that silently drifts from its requirement is exactly what makes review (Module 09's LLM-as-Judge included) unable to check compliance later.

---

## Anti-Patterns: How Spec-Driven Development Goes Wrong

Five habits that quietly turn a spec into paperwork nobody actually uses:

| Do This | Not That |
|---|---|
| Write acceptance criteria as testable, observable conditions | Write acceptance criteria as vague adjectives ("fast," "robust") |
| Update the spec first when scope changes mid-implementation | Patch the code and leave the spec stale and misleading |
| Keep the plan step even for small features | Skip straight from spec to code "to save time" |
| Review the spec itself before implementation starts | Only review the diff, after the fact |
| Let acceptance criteria double as the test list | Write acceptance criteria and tests as unrelated afterthoughts |

Keep this table in view — Exercise 5 asks you to self-audit your own spec against it.

---

## Checkpoint

- [ ] Can you explain, in one sentence, why a task with no traceable requirement is worth questioning?
- [ ] Can you name the four categories a specification covers?
- [ ] Did all three of your weak-to-strong rewrites end up with an explicit number or named condition, not just more words?

## Where This Goes Next

Exercise 2 hands you a real, fictional ticket against `sample-repo/` and asks you to write an actual spec.md from it — applying every check on this page to a feature that doesn't exist in the codebase yet.
