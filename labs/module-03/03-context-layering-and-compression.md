# Exercise 3: Context Layering & Compression

**Duration:** 20 minutes | **Format:** Guided walkthrough → individual worksheet

## Objective

Learn the five context-engineering practices, see how token cost scales with each added layer, and build your own layered context stack for the task you'll actually run through Exercise 4 — on paper first, so the choices are deliberate rather than improvised mid-lab.

## The Five Practices

| Practice | What it means |
|---|---|
| **Context Selection** | Choose which inventory items this specific task actually needs — resist supplying everything "just in case." |
| **Layering** | Build context in ordered layers — task, then repository, then design — rather than one flat dump. |
| **Compression** | Summarize long design docs and issue threads into the two or three facts that matter for this task. |
| **Task-Scoped Boundaries** | Draw an explicit line: these files are in scope, everything else is out — stated, not assumed. |
| **Token-Aware Practices** | Treat context like a budget. Every file you add has a cost; spend it where it changes the output. |

"Use tokens more efficiently" was a top-three training ask in the pre-programme survey (7 of 19) — Practice 5 is built for exactly that.

---

## Context Layering in Action

Layers stack in order of cost — add a layer only when the task actually demands it.

| Layer | Contains | Approx. Token Cost |
|---|---|---|
| 1 — Task Framing | Goal, scope, and definition of done. Always present, always cheapest. | ~200 |
| 2 — Code Context | Relevant source/header pairs & interfaces the task will actually touch. | ~800 |
| 3 — Design Context | HAL boundaries, coding standards & design notes — add only for non-trivial changes. | ~1,500 |
| 4 — History Context | Issue history & prior related tests — reserved for brownfield or regression-sensitive work. | ~2,800+ |

**The rule:** stop adding layers the moment the task is well-specified. A one-function bug fix rarely needs Layer 4 — a brownfield behaviour-preservation task almost always does. These figures are illustrative reference points, not a metering tool — Module 10 (Agent Prism) is where you get real, per-request token telemetry.

---

## Anti-Patterns: How Context Inflation Happens

| Do This | Not That |
|---|---|
| Scope context to the files this task touches | Paste the entire repository "just to be safe" |
| Summarize a long design doc into 2–3 relevant facts | Attach the full design document unfiltered |
| Add history/issue context only for brownfield work | Include full issue history for every task by default |
| State an explicit in-scope/out-of-scope boundary | Let Copilot infer scope from whatever's open |
| Re-use a compressed context layer across a session | Re-explain the same background in every new prompt |

### Quick Check (2 minutes)

For each habit below, mark **Do This** or **Not That**:

1. Opening all 7 source files in the repo before asking a one-line question about `diag_formatter.c`. → ______
2. Writing "In `can_driver.c`, in the bus-off recovery path..." instead of pasting the whole file. → ______
3. Re-typing the full architecture explanation in every new Chat session instead of referencing a saved summary. → ______
4. Telling Copilot "everything except `tests/` is out of scope for this change" before asking for the change. → ______

---

## Build Your Own Layered Stack (10 minutes)

**Task (same as Exercise 2's Task B, carried forward into Exercise 4):** Add `can_driver_get_error_summary()` to `can_driver.c` — a function that formats the driver's current error state into a diagnostic string.

For each layer, write down **exactly** what you'd include — not "the header file," but which specific facts from it:

**Layer 1 — Task Framing:**
_______________________________________________

**Layer 2 — Code Context** (which specific struct fields / function signatures, not "open the file"):
_______________________________________________

**Layer 3 — Design Context** (which specific convention from `docs/CODING_STANDARDS.md` or `docs/ARCHITECTURE.md` — name the exact rule, not "the standards doc"):
_______________________________________________

**Layer 4 — History Context:**
Does this task need Layer 4 at all? ☐ Yes ☐ No — why: _______________________________________________

---

## Where This Goes Next

You'll use exactly this layered stack in [Exercise 4](04-four-round-progressive-lab.md), Rounds 2 and 3 — and then deliberately compress it in Round 4 to test whether the same quality survives with a smaller token footprint.
