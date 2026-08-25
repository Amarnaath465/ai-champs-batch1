# Exercise 1: Generate, Explain & Refactor Live

**Duration:** 20 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Use chat, inline code assistance, and code explanation together on real files: complete a diagnostic formatter matching existing conventions, get a guided walkthrough of an unfamiliar state machine, and safely refactor a monolithic polling loop.

## Prerequisites

Completed [Exercise 0](00-capability-map-walkthrough.md) — `sample-repo/` open as your workspace root, build confirmed (failures expected and fine).

---

## Part A — Generate: Complete the Diagnostic Formatter (7 minutes)

**File:** `sample-repo/include/diag_formatter.h` and `sample-repo/src/diag_formatter.c`

1. Open `include/diag_formatter.h`. Read the `TODO` comment above the `diag_format_sensor_fault` declaration — it specifies the exact output format and tells you to follow the existing `diag_format_message` pattern.
2. In `diag_formatter.c`, place your cursor below the existing `diag_format_message` implementation and start typing the function signature:
   ```c
   size_t diag_format_sensor_fault(char *buf, size_t buf_len, uint8_t channel, uint16_t raw_value)
   ```
   Let inline suggestions complete the body. Accept, reject, or edit — don't accept blindly.
3. Add the matching declaration to `diag_formatter.h` (replace the TODO comment).
4. Verify the output format matches the spec exactly: `"[0x1001] sensor <channel> out of range (raw=<value>)"`. If Copilot's first suggestion doesn't match — e.g., wrong error code, wrong field order — that's expected; refine your prompt or hand-edit rather than accepting on faith.

**Checkpoint:** Does your implementation reuse `diag_format_message()` internally, or does it duplicate the `snprintf` pattern? Either can work — but check which one Copilot defaulted to, and decide if that matches your team's DRY conventions.

---

## Part B — Explain: Walk the State Machine (6 minutes)

**File:** `sample-repo/src/state_machine.c`

1. Open `state_machine.c` and select the entire `transition_table` definition plus `device_sm_handle_event`.
2. Ask Copilot Chat:
   > "Explain this state machine: what are the valid transitions from each state, and which events are illegal from CALIBRATING?"
3. Cross-check the answer against the table yourself — don't just accept it. Specifically verify: is `DEV_EVENT_SHUTDOWN_REQUESTED` legal from every state? Is `SAFE_SHUTDOWN` really terminal (no legal outgoing transitions)?
4. Ask a follow-up: "If I wanted to add a new event that lets FAULT return directly to CALIBRATING instead of RUNNING, what exactly would I need to change?" — don't make the change, just confirm you understand the blast radius of a transition-table edit before Module 05's brownfield work asks you to make one for real.

**Checkpoint:** Could you now explain this state machine to a teammate without looking at the table? That's the bar — "understand before you extend," as the deck puts it.

---

## Part C — Refactor: Break Up the Monolithic Polling Loop (7 minutes)

**File:** `sample-repo/src/sensor_poll.c`

`sensor_poll_all()` does five things in one function body: reads temperature, reads pressure, reads flow, reads two GPIO pins, and combines two of those into a fault flag. It's a realistic "written during bring-up, never revisited" function.

1. Select the full body of `sensor_poll_all()`.
2. Ask Copilot Chat or use inline refactor:
   > "Extract this into named per-sensor helper functions — one per sensor — while keeping sensor_poll_all's behavior and fault_flags output identical."
3. Before accepting the refactor, write down (on paper or in a scratch comment) what `fault_flags` should equal for a known input, e.g., temperature raw = 4000, pressure raw = 3000, door_open = true, motion_detected = true → expect `fault_flags = 0x01 | 0x04 = 0x05`.
4. Apply the refactor, then rebuild:
   ```sh
   make test
   ```
   The `sensor_poll` module has no dedicated test file yet, so this only confirms the refactor compiles cleanly — it does **not** confirm behavior is unchanged. That's the point of the next step.
5. Manually trace your refactored code against the known input from step 3. Does it still produce `0x05`? If you're not sure, that's a live example of "refactor without regressing" being harder than it looks — and exactly why Module 06 exists.

**Checkpoint:** Did the refactored version preserve the exact bit values in `fault_flags`, including the combined-condition check (`door_open && motion_detected`)? A common failure mode here is extracting the individual sensor reads correctly but losing the cross-sensor fault logic in translation.

---

## Where This Goes Next

- Your completed `diag_format_sensor_fault` gets reused by `fault_monitor` in [Exercise 4](04-agent-mode-repository-task.md).
- The refactored `sensor_poll.c` is a live example for [Exercise 5](05-manual-vs-ai-comparison.md)'s manual-vs-AI comparison — note how long Part C actually took you.
- Move to [Exercise 2](02-debug-a-defect.md) next — you'll use Chat + inline assist again, this time to root-cause the CAN driver defect you've been building around all exercise.
