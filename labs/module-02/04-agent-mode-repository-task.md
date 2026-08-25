# Exercise 4: Agent Mode on a Repository Task

**Duration:** 25 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Hand Copilot Agent Mode a scoped, repository-aware task — implementing `fault_monitor`, the one module in this repo that doesn't exist yet — and supervise it end-to-end through the six-step Agent Mode pattern: scope, explore, plan, implement, review, iterate.

## Prerequisites

Completed [Exercise 3](03-generate-tests-and-pr-review.md). `make test` should be green (6+ tests passing, including your new `test_hal_adc.c`).

---

## Background: The Agent Mode Pattern

| Step | What happens |
|---|---|
| 1. Scope the task | You give Agent Mode a specific, bounded task — not "improve the codebase" |
| 2. Explore repository context | Agent reads source, headers, build files & conventions before proposing anything |
| 3. Propose a plan | Agent surfaces its intended approach before making a single change |
| 4. Implement across files | Agent edits related files coherently — source, header, and test together |
| 5. Human reviews the diff | You inspect every change against firmware architecture & standards |
| 6. Iterate or accept | You refine the prompt/scope, or accept the change into the branch |

**Rule of thumb:** the narrower the scope you hand Agent Mode, the more trustworthy the diff. "Implement fault_monitor.c per the contract in fault_monitor.h" beats "add fault handling to this repo" every time.

---

## Step 1 — Scope the Task (3 minutes)

Open `include/fault_monitor.h` and read the contract comment in full — it already specifies the exact behavior, the three-step algorithm, and the layering constraint ("must not reach into `can_driver_t` fields directly").

Your prompt to Agent Mode needs to be this specific, not vaguer. Draft it now (write it down before opening Agent Mode):

> Scope: _______________________________________________

A good scope statement names the file(s) to create/touch and points at the existing contract rather than re-describing it from scratch.

## Step 2 — Launch Agent Mode (2 minutes)

Open Agent Mode in your IDE and give it your scoped prompt, for example:

> "Implement fault_monitor.c and update fault_monitor.h if needed, following the contract already documented in include/fault_monitor.h. Use can_driver_get_state() only — never reach into can_driver_t fields directly, per docs/ARCHITECTURE.md's layering rules. Also create tests/test_fault_monitor.c covering: (1) no fault raised while the CAN driver stays ERROR_ACTIVE, (2) a fault is raised exactly once when the driver transitions into BUS_OFF, (3) no duplicate fault is raised on a second check while still in BUS_OFF."

## Step 3 — Watch It Explore and Plan (5 minutes)

Before Agent Mode writes any code, it should read `can_driver.h`, `state_machine.h`, `diag_formatter.h`, and likely `docs/ARCHITECTURE.md`. Watch what it pulls into context.

When it proposes a plan, **stop and read it before letting it implement.** Check the plan against:

- [ ] Does it call `can_driver_get_state()` only, or does it plan to touch driver-internal fields?
- [ ] Does it correctly identify "just transitioned" (edge-triggered) vs. "currently in" (level-triggered) BUS_OFF state — the difference between raising the fault once vs. every tick?
- [ ] Does it plan to use `device_sm_handle_event()` with `DEV_EVENT_FAULT_DETECTED`, matching the state machine's actual event enum?
- [ ] Does it plan to use `diag_format_message()` with `DIAG_ERR_CAN_BUSOFF`, matching the diagnostics module's actual error-code convention?

If the plan gets any of these wrong, **correct it before implementation**, not after — that's cheaper than reviewing a wrong diff.

## Step 4 — Let It Implement, Then Review the Diff (10 minutes)

Let Agent Mode implement across `fault_monitor.c`, `fault_monitor.h` (if it needs adjusting), and `tests/test_fault_monitor.c`.

When it's done, review the diff file-by-file — do not accept in bulk:

1. **`fault_monitor.c`** — does `fault_monitor_check()` correctly track "last seen state" to detect the *transition into* BUS_OFF, rather than firing every tick while already in BUS_OFF? This is the most common mistake an under-scoped prompt produces.
2. **Layering check** — grep the new file for any direct access to `can_driver_t` struct fields (`drv->state`, `drv->tx_error_count`, etc.). There should be none — only `can_driver_get_state()` calls.
3. **`tests/test_fault_monitor.c`** — do the three cases from your prompt actually exist, and do they test what they claim to?
4. Build and run:
   ```sh
   make test
   ```
   All tests — the original CAN driver suite, your `hal_adc` tests, and the new `fault_monitor` tests — should pass.

## Step 5 — Iterate If Needed (5 minutes)

If the diff has a problem (wrong event, direct field access, missing edge-detection logic), don't hand-fix it silently — go back to Agent Mode with a narrower follow-up prompt naming the specific defect, and watch how it responds to a correction. This mirrors the real workflow: Agent Mode iterations are cheap; silently patching around a wrong plan just hides the prompt-scoping lesson.

---

## Checkpoint

- [ ] `fault_monitor.c` exists and implements the documented contract
- [ ] No direct access to `can_driver_t` internals — only `can_driver_get_state()`
- [ ] The fault fires once on transition into BUS_OFF, not repeatedly while already there
- [ ] `make test` is fully green
- [ ] You can explain, in one sentence, the one place your scoped prompt had to be corrected (if any) — or why it didn't need correcting

## Where This Goes Next

Commit this work to your branch from Exercise 3. The full branch (CAN fix + `hal_adc` tests + `fault_monitor`) is your artifact for [Exercise 5](05-manual-vs-ai-comparison.md)'s time/quality comparison, and previews the kind of scoped, multi-file, human-supervised task Module 07 (MCP-Enabled Agentic Embedded Engineering) builds on.
