# Exercise 0: Capability Map Walkthrough & Repository Orientation

**Duration:** 15 minutes | **Format:** Guided demo + individual exploration

## Objective

Get oriented on GitHub Copilot Enterprise's 13 capabilities (five clusters) and on the sample repository's layout before touching any code. This is a fast orientation pass, not a deep-dive — you'll use every cluster hands-on in Exercises 1–5.

## The Capability Map

| Cluster | Capabilities |
|---|---|
| Conversational & Inline Assistance | Chat/Conversation · Inline Code Assistance · Code Explanation |
| Code Quality Assistance | Refactoring · Debugging · Test Generation |
| Autonomous & Repository-Aware | Agent Mode · Repository-Aware Assistance · Model/Task Selection |
| Workflow Integration | GitHub.com Workflows · Terminal/CLI Workflows · PR/Code-Review Assistance |
| Reuse & Governance | Custom/Reusable Instructions & Skills · Safe Enterprise Usage |

You'll touch every cluster today: Exercise 1 covers the first cluster, Exercise 2 the second (debugging), Exercise 3 continues code quality (test generation) plus workflow integration (PR review), Exercise 4 is the autonomous/repository-aware cluster, and reuse/governance shows up throughout as house-style conventions Copilot should follow.

---

## Step 1 — Confirm Access (5 minutes)

- [ ] GitHub Copilot Enterprise is active in your IDE (check the Copilot status icon)
- [ ] You can open Copilot Chat (`Ctrl+Shift+I` / `Cmd+Shift+I` in VS Code, or your IDE's equivalent)
- [ ] You have Agent Mode available (not just inline suggestions/chat — confirm with your facilitator if unsure)
- [ ] You can reach GitHub.com with your enterprise account

If any of these are missing, flag it now — don't wait until Exercise 4 to discover Agent Mode isn't provisioned.

## Step 2 — Open the Sample Repository (5 minutes)

The repository lives at [`sample-repo/`](sample-repo/) in this lab folder.

1. Open `sample-repo/` as a workspace root in your IDE (not the whole `labs/module-02` folder — Copilot's repository-aware features work best with a focused workspace root).
2. Confirm it builds:
   ```sh
   cd sample-repo
   make test
   ```
   **Expect failures.** Three assertions in `tests/test_can_driver.c` fail on a fresh checkout — that's an intentional defect for Exercise 2, not a broken lab. Don't fix it yet.
3. Read `README.md`, then skim `docs/ARCHITECTURE.md`'s module table and layering diagram — you'll need the module names (`can_driver`, `sensor_poll`, `state_machine`, `diag_formatter`, `hal_gpio`/`hal_adc`, `fault_monitor`) for the rest of today.

## Step 3 — Where Copilot Touches This Repository (5 minutes)

Seven surfaces recur across every exercise today. As you skim the codebase, note one file per surface:

| Surface | File(s) in this repo |
|---|---|
| Source & header pairs | `src/can_driver.c` / `include/can_driver.h` |
| Interfaces & contracts | `include/fault_monitor.h` (contract-only, not yet implemented) |
| Configuration | *(none in this minimal sample — real repos: Kconfig/prj.conf)* |
| Diagnostics & logging | `src/diag_formatter.c` |
| State machines | `src/state_machine.c` |
| Drivers & adapters | `src/can_driver.c`, `src/hal_gpio.c`, `src/hal_adc.c` |
| Build & toolchain files | `Makefile` |

---

## Where Copilot Is Strong vs. Weak (keep this in mind all day)

| Strong — well-represented in training data | Weak — thin training-data coverage |
|---|---|
| Boilerplate & scaffolding (struct defs, getters/setters) | Closed-source vendor toolchains & proprietary APIs |
| Driver scaffolding following conventional HAL structure | RTOS internals (schedulers, memory managers) at implementation depth |
| Documentation & explanation of conventionally-written code | Narrow, licensed embedded standards (AUTOSAR/CAPL) |
| Test generation for well-defined, narrow interfaces | Timing-critical & interrupt-sensitive logic |
| General C/C++ idioms & standard library usage | Undocumented hardware quirks baked into brownfield code |

Set your trust level by task type, not by tool reputation — you'll feel the difference directly in Exercise 2 (debugging a driver-layer defect, where Copilot proposes hypotheses but you verify against the actual counter logic).

## Checkpoint

Before moving to Exercise 1, you should be able to answer: which module in this repo has the CAN error-confinement logic, which one is the intentionally-monolithic refactor target, and which one doesn't exist yet at all?

## Where This Goes Next

Exercises 1–5 all work inside `sample-repo/`. Keep it open as your workspace root for the rest of Module 02.
