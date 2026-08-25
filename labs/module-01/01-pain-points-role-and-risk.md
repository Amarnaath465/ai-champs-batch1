# Exercise 1: Pain Points, Role Fit & Risk Snapshot

**Duration:** 35 minutes | **Format:** Individual (5 min) → Small group by GBE (25 min) → Report-out (5 min)

## Objective

In one pass, surface your team's real delivery pain points, place yourself in the AI Champion/Evangelist/Sponsor model, and name the risks of unmanaged AI usage your team is actually exposed to. One worksheet, one group conversation.

---

## Step 1 — Individual (5 minutes)

Jot quick answers — phrases, not essays.

**Three pain points** from the last 3 months (pick any that fit): feature implementation / code analysis, build & test cycles, PR review latency, or ad-hoc AI usage with no visibility into cost or quality.

1.
2.
3.

**Your role today:** ☐ Architect ☐ Embedded/Firmware Developer ☐ Tester ☐ DevOps/SRE ☐ Engineering Lead ☐ Program/Product

**Which of these do you want to carry forward?** ☐ AI Champion (hands-on driver) ☐ AI Evangelist (share wins, unblock peers) ☐ AI Sponsor (remove org blockers) ☐ Not sure yet — General Participant for now

---

## Step 2 — Group (25 minutes)

Form groups by GBE (PA / IA / BA) or by team.

1. **Cluster & vote (8 min):** Read out pain points, cluster duplicates, dot-vote (3 votes each) to rank the top 5.
2. **Tag & rate (10 min):** For your top 5, fill the combined worksheet below — lifecycle stage, and whether it's really a *risk* (something an AI-assisted workflow could make worse if ungoverned) or purely a *productivity* pain point.
3. **Risk check (7 min):** For any item tagged as a risk, rate it and answer the litmus-test question.

### Worksheet: Top 5 Pain Points

| # | Pain Point | Lifecycle Stage | Greenfield / Brownfield | Productivity or Risk? | If Risk: Likelihood×Impact (1–5 each) |
|---|---|---|---|---|---|
| 1 | | | | | |
| 2 | | | | | |
| 3 | | | | | |
| 4 | | | | | |
| 5 | | | | | |

*Lifecycle stages:* Requirements & Spec · Architecture & HAL Design · Implementation · Build & Toolchain · Test & Validation · PR Review

*Common risk patterns to check against:* silent architecture/standards violations · hard-to-diagnose brownfield regressions · closed-toolchain/RTOS hallucination · spec-free prompt-only development · context inflation/token waste · zero cost/usage visibility

### Litmus test (answer as a group)

> "Would we approve a PR that compiles, passes tests, and meets spec — but uses more memory than budgeted, breaks a design pattern, or regresses timing under load?"

Our answer and why: _______________________________________________

### Top risk to escalate

The **one** risk from above we'd flag to our Engineering Lead / Sponsor first, and why:

_______________________________________________

---

## Step 3 — Report-out (5 minutes)

One spokesperson per group shares: top pain point, one role commitment from the group, and the top risk to escalate. Facilitator captures these — they carry straight into Exercise 2.

## Where This Goes Next

Your top 5 pain points and top risk become the **current-state** input to [Exercise 2](02-target-state-canvas-and-metrics.md).
