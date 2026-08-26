# Exercise 1: Prompt Engineering Recap & Weak-vs-Strong Walkthrough

**Duration:** 30 minutes (15 + 15) | **Format:** Guided recap → individual practice in `sample-repo/`

## Objective

This isn't new material — it's the prompting discipline you already use, made explicit, before Exercise 2 adds structured context on top of it. You'll recap the six building blocks, see a weak prompt and a strong prompt solve the same defect side by side, then write your own weak/strong pair against a real task.

## Prerequisites

Complete [setup.md](setup.md) first — this exercise works in the same `sample-repo/` from Module 02 (referenced, not duplicated).

---

## Part A — The Six Building Blocks (10 minutes, guided recap)

| # | Building Block | What it means |
|---|---|---|
| 1 | **Task Framing** | State the goal, the file(s) in scope, and what "done" looks like — before asking for code. |
| 2 | **Instructions** | Explicit, ordered steps beat a single vague request — especially for multi-file changes. |
| 3 | **Constraints** | Say what must **not** change: timing behaviour, public API, existing test results. |
| 4 | **Examples** | Show one existing function in the target style; Copilot mirrors it far better than a description. |
| 5 | **Decomposition** | Break a large task into independently-verifiable steps — same discipline as breaking down a user story. |
| 6 | **Iterative Prompting & Verification** | Treat the first response as a draft. Refine, re-check against constraints, repeat. |

This is a recap, not a lecture — if your prompting habits already do most of this, say so. The calibration survey found 13 of 19 engineers already work out architecture, interfaces, and dependencies before writing anything, unprompted. The gap isn't the instinct — it's getting that instinct in front of the AI assistant consistently, which is where Exercise 2 picks up.

## Part B — Weak vs. Strong, Worked Example (5 minutes)

Same defect, same engineer — only the prompt changes.

| Weak Prompt | Strong Prompt |
|---|---|
| *"The CAN driver has a bug. Can you fix it?"* | *"In can_driver.c, the retry counter in the bus-off recovery path doesn't reset after a successful recovery. Fix only that reset logic — don't change the retry timing constants. Match the error-handling style used in can_driver_send()."* |
| ✗ No file or function named | ✓ Names the file and the specific logic path |
| ✗ No definition of "bug" or expected behaviour | ✓ States exactly what's wrong and what must not change |
| ✗ No constraint on what must stay the same | ✓ Points to an existing function as the style example |
| ✗ No example of the surrounding code style | |

Notice: the strong prompt isn't longer for its own sake — every added phrase maps directly to one of the six building blocks above. Annotate the strong prompt now: which phrase is Task Framing? Which is a Constraint? Which is an Example?

| Phrase from the strong prompt | Building block |
|---|---|
| "In can_driver.c, the retry counter..." | |
| "Fix only that reset logic" | |
| "don't change the retry timing constants" | |
| "Match the error-handling style used in can_driver_send()" | |

## Part C — Write Your Own Weak/Strong Pair (15 minutes, hands-on)

**Task for this exercise:** `sample-repo/src/fault_monitor.c` doesn't exist yet (see [`include/fault_monitor.h`](../module-02/sample-repo/include/fault_monitor.h)'s contract if you're curious — you're not implementing it here, just practicing prompting against it). Imagine you need one small piece of it: **a debounce counter so a transient single-tick failure doesn't immediately report a fault.**

1. In Copilot Chat, write a **weak** prompt for this — deliberately vague, the way you might type something fast under deadline pressure. Something like: *"Add debouncing to the fault monitor."*
2. Send it. Read the response. Don't fix it — just note what's missing or wrong (wrong file assumed? Invented struct fields? No connection to the real `can_driver_get_state()` accessor?).
3. Now write a **strong** version, hitting all six building blocks: name the file, state the exact debounce behavior (e.g., "require 3 consecutive BUS_OFF observations before raising the fault, not 1"), name a constraint (must still respect the layering rule — no direct `can_driver_t` field access), and point to an example (`fault_monitor.h`'s documented contract, or `can_driver.c`'s existing counter-based logic as a style reference).
4. Send it. Compare the two responses side by side.

**Checkpoint:** Write one sentence: which single addition to your strong prompt made the biggest difference to the response's usefulness?

---

## Where This Goes Next

You'll use this same weak-vs-strong discipline, deliberately, in [Exercise 4](04-four-round-progressive-lab.md)'s four rounds — but the variable there shifts from *prompt wording* to *what context surrounds the prompt*. Exercise 2 and 3 build the vocabulary for that shift.
