# Exercise 5: Manual vs. AI-Assisted Comparison

**Duration:** 20 minutes | **Format:** Individual worksheet → small-group share

## Objective

Turn today's lab into measured evidence, not anecdote. Record how long each task actually took and how confident you are in the result, then compare against the success-metrics baseline your group set in Module 01.

## Prerequisites

Completed Exercises 1–4. This exercise doesn't touch the codebase further — it's a reflection and measurement pass.

---

## Step 1 — Fill In Your Task Log (10 minutes)

For each task, record how long it actually took you (not counting time reading these instructions), and rate your confidence in the result before you'd hand it to a reviewer.

| Task | Time Taken | Confidence (1–5) | Would you ship this to a reviewer as-is? |
|---|---|---|---|
| Generate `diag_format_sensor_fault` (Ex. 1A) | | | |
| Explain the state machine (Ex. 1B) | | | |
| Refactor `sensor_poll_all` (Ex. 1C) | | | |
| Root-cause the CAN driver defect (Ex. 2, Steps 1–2) | | | |
| Fix the CAN driver defect (Ex. 2, Step 3) | | | |
| Generate `hal_adc` boundary tests (Ex. 3A) | | | |
| AI-assisted PR review pass (Ex. 3B) | | | |
| `fault_monitor` via Agent Mode, full cycle (Ex. 4) | | | |

**Confidence scale:** 1 = "I'd want a second pair of eyes on every line," 5 = "I'd merge this without further review."

## Step 2 — Compare Against a Manual Baseline (5 minutes)

For at least 2 of the 8 tasks above, estimate how long the same task would have taken **without** AI assistance — writing it, tracing it, or testing it by hand. Be honest; don't lowball the manual estimate to make the comparison look better than it is.

| Task | AI-Assisted Time | Estimated Manual Time | Delta |
|---|---|---|---|
| | | | |
| | | | |

## Step 3 — Connect to Module 01's Baseline (5 minutes)

Pull out your GBE's success-metrics worksheet from Module 01 Exercise 2. Compare:

| Metric | Module 01 Baseline (estimate) | What today's lab suggests |
|---|---|---|
| Feature/defect cycle time | | Based on your Exercise 2 (debug) and Exercise 4 (Agent Mode) timings |
| PR review latency | | Based on your Exercise 3B review pass |
| AI cost per accepted change | | *(Not directly measurable without Agent Prism — flag as a Module 10/11 follow-up)* |

---

## Discussion (small-group share, if time allows)

- Which task had the **biggest gap** between confidence and "would ship as-is"? What made you hesitate?
- Which task would you trust Agent Mode with again unsupervised for the *next* similar change — and which would you scope more narrowly next time?
- Looking at your Strong-vs-Weak table from Exercise 0: did today's tasks land where you expected (strong on scaffolding/tests, weaker on driver-layer logic), or did anything surprise you?

## Where This Goes Next

- This log is your personal evidence base for the manual-vs-AI conversation that recurs in Module 06 (test strategy), Module 09 (PR quality), and Module 11 (ROI & token economics) — where the same comparison gets made with real token-cost and Agent Prism data instead of a stopwatch.
- Bring your completed task log to the Module 01 30-day catch-up review.

**Module 02 complete.** Next: **Module 03 — Prompt Engineering Recap and Context Engineering** (2 hours), where you'll compare prompt-only context against structured repository and design context on a new task — using the same `sample-repo/` conventions you just built fluency with.
