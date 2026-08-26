# Exercise 2: The Embedded Context Inventory

**Duration:** 20 minutes | **Format:** Guided walkthrough → individual mapping exercise

## Objective

Learn the nine sources of context available in an embedded repository, grouped into four categories, then practice the single most important discipline in this module: pulling only what a specific task actually needs — never supplying the whole inventory by default.

## The Inventory

| Category | Sources |
|---|---|
| **Code Context** | Source/header relationships · Interfaces & contracts |
| **Build Context** | Build files · Configuration |
| **Design Context** | Hardware-abstraction boundaries · Design notes · Coding standards |
| **History Context** | Issue history · Tests |

**Task-scoped, not repository-wide.** This is a menu, never a checklist to supply every time. The calibration survey found 8 of 19 engineers already default to something like this pattern (repo + architecture + design + test context, analyzed before asking for a change) — but 10 of 19 still hand that context to AI mainly through prompts alone. The instinct exists; this module gives it a repeatable method.

---

## Where Each Source Lives in `sample-repo/`

| Inventory item | File(s) in `sample-repo/` |
|---|---|
| Source/header relationships | Any `.c`/`.h` pair, e.g. `src/can_driver.c` + `include/can_driver.h` |
| Interfaces & contracts | `include/fault_monitor.h` (contract-only, nothing implemented yet) |
| Build files | `Makefile` |
| Configuration | *(none in this minimal sample — real repos: Kconfig/prj.conf, build flags)* |
| Hardware-abstraction boundaries | `include/hal_gpio.h`, `include/hal_adc.h`, and the layering rules in `docs/ARCHITECTURE.md` |
| Design notes | `docs/ARCHITECTURE.md` |
| Coding standards | `docs/CODING_STANDARDS.md` |
| Issue history | *(none in this minimal sample — real repos: GitHub Issues, Jira)* |
| Tests | `tests/test_can_driver.c` |

---

## Mapping Exercise (15 minutes)

For each of the three tasks below, check which inventory items are actually **in scope** — resist the urge to check everything "just in case." Then write one sentence justifying anything you left unchecked that someone might assume you'd need.

### Task A: "Fix a typo in a diagnostic message's wording in `diag_formatter.c`."

| Inventory item | In scope? |
|---|---|
| Source/header relationships | ☐ |
| Interfaces & contracts | ☐ |
| Build files | ☐ |
| Configuration | ☐ |
| Hardware-abstraction boundaries | ☐ |
| Design notes | ☐ |
| Coding standards | ☐ |
| Issue history | ☐ |
| Tests | ☐ |

Justify one thing you left unchecked: _______________________________________________

### Task B: "Add a new function to `can_driver.c` that summarizes the driver's error state as a diagnostic string."

| Inventory item | In scope? |
|---|---|
| Source/header relationships | ☐ |
| Interfaces & contracts | ☐ |
| Build files | ☐ |
| Configuration | ☐ |
| Hardware-abstraction boundaries | ☐ |
| Design notes | ☐ |
| Coding standards | ☐ |
| Issue history | ☐ |
| Tests | ☐ |

Justify one thing you left unchecked: _______________________________________________

*(This is the exact task you'll run through all four context rounds in Exercise 4 — the scoping you do here previews that lab.)*

### Task C: "Investigate why a brownfield state-machine transition regressed after a recent change."

| Inventory item | In scope? |
|---|---|
| Source/header relationships | ☐ |
| Interfaces & contracts | ☐ |
| Build files | ☐ |
| Configuration | ☐ |
| Hardware-abstraction boundaries | ☐ |
| Design notes | ☐ |
| Coding standards | ☐ |
| Issue history | ☐ |
| Tests | ☐ |

Justify one thing you left unchecked: _______________________________________________

**Notice the pattern:** Task A needs almost nothing outside the one file. Task B needs Code + Design context but not History. Task C — a brownfield regression investigation — is the one case where History context (issue history, prior tests) genuinely earns its token cost. That's Layer 4 in Exercise 3, and it's reserved for exactly this kind of task.

---

## Discussion (5 minutes)

- For Task B, did you check "Coding standards"? If you didn't, would the function you'd get back actually match this repo's error-code and naming conventions?
- Which inventory item did you almost check for every task, out of habit, before catching yourself?

## Where This Goes Next

Task B's scoping carries directly into [Exercise 4](04-four-round-progressive-lab.md) — Round 2, 3, and 4 are literally "supply exactly the items you just checked, in increasing amounts." [Exercise 3](03-context-layering-and-compression.md) covers *how* to supply them without inflating token cost.
