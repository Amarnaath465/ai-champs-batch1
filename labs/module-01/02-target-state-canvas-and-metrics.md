# Exercise 2: Target-State Canvas & Success Metrics

**Duration:** 30 minutes | **Format:** Small group by GBE (25 min) → Report-out (5 min)

## Objective

Turn today's pain points into one canvas: what changes at each lifecycle stage, how we'll know it worked, and which two real pieces of work (one greenfield, one brownfield) we'll use to prove it in Module 05.

Same groups as Exercise 1. Use your top 5 pain points as the starting input.

---

## Step 1 — Current → Target Canvas (12 minutes)

For each stage, note the current pain (pull from Exercise 1) and what "good" looks like once AI-assisted, plus which later module owns delivering it.

**GBE:** _______________

| Stage | Current Pain | Target State | Owning Module |
|---|---|---|---|
| Spec / Requirements | | | Module 4 (SDD) |
| Architecture & Design | | | Module 4–5 |
| Implementation | | | Module 2, 5 |
| Build & Test | | | Module 6 |
| PR Review | | | Module 9 |
| Monitoring / Cost | | | Module 10–11 |

## Step 2 — Success Metrics (5 minutes)

Rough baselines are fine — precision isn't the point, direction is.

| Metric | Baseline Today (estimate) | Target |
|---|---|---|
| Feature/defect cycle time | | |
| PR review latency | | |
| Regression/defect rate (brownfield) | | |
| AI cost per accepted change | | |
| Team adoption rate | | |

## Step 3 — Pick Your Two Use Cases (8 minutes)

One **greenfield** (new feature, spec-driven, no legacy constraints) and one **brownfield** (existing firmware, must preserve behaviour) candidate — representative of real work, not a toy example.

| | Greenfield Candidate | Brownfield Candidate |
|---|---|---|
| Short description | | |
| Why representative | | |
| Key constraint to respect | | |
| Clear "done" / acceptance criterion | | |

**Quick sanity check** — both candidates should be: software-only (no hardware integration), safe to use with a sanitized/sample codebase, small enough for a Module 05 lab session, and have a testable acceptance criterion. If either fails this, swap it for something smaller.

---

## Step 4 — Report-out (5 minutes)

One spokesperson per group shares: the biggest current→target gap, and the two use cases selected. Facilitator captures all GBE canvases for reference in later modules.

## Where This Goes Next

- Keep this canvas — it's referenced again in Module 05, Module 09, Module 10, and Module 11.
- Your two use cases are the starting point for Module 05's hands-on greenfield/brownfield labs.
