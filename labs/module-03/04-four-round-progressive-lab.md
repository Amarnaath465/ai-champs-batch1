# Exercise 4: Four-Round Progressive Lab — Measure & Compare

**Duration:** 50 minutes (40 + 10) | **Format:** Individual, hands-on in `sample-repo/`

## Objective

Solve the **same task four times**, adding exactly one context layer each round, and measure what changes: output quality, estimated token cost, iteration count, and completion time. This turns "context engineering helps" from a claim into your own data.

## Prerequisites

Completed Exercises 1–3. You should already have a written layered-context plan from Exercise 3 for the task below — use it now instead of improvising.

## The Task (same across all four rounds)

> Add a function to `sample-repo/src/can_driver.c` (and declare it in `include/can_driver.h`) called `can_driver_get_error_summary()` that formats the driver's current error state into a short diagnostic string — suitable for a diagnostic log line.

**Do not edit the real `can_driver.c`/`can_driver.h` files during this exercise.** Capture each round's generated function into the matching scratch file instead, so all four are visible side by side at the end:

- [`scratch/round-1-prompt-only.c`](scratch/round-1-prompt-only.c)
- [`scratch/round-2-code-context.c`](scratch/round-2-code-context.c)
- [`scratch/round-3-design-context.c`](scratch/round-3-design-context.c)
- [`scratch/round-4-compressed-scoped.c`](scratch/round-4-compressed-scoped.c)

Open [`scratch/measurement-worksheet.md`](scratch/measurement-worksheet.md) now and keep it open the whole exercise — fill in each row immediately after finishing that round, not from memory afterward.

---

## Round 1 — Prompt-Only (10 minutes)

**Context to supply: none.** Close every `sample-repo/` file in your IDE. Don't mention struct names, existing conventions, or file paths you haven't verified from memory.

1. Open a fresh Copilot Chat (or a new scratch file with nothing else open).
2. Write a task-framing-only prompt — state the goal, nothing else. Something like: *"Write a C function that summarizes CAN driver error state into a diagnostic string."*
3. Send it. Copy the result into `scratch/round-1-prompt-only.c`, along with your exact prompt (there's a spot for it in the file's header comment).
4. Score it against the [quality rubric](scratch/measurement-worksheet.md) — check the boxes honestly. A prompt-only response has no way to know your struct field names, your `diag_format_message()` convention, or your error-code ranges, so don't be surprised by a low score. That's the baseline, not a failure.
5. Fill in Round 1's row in the measurement worksheet: estimated tokens (prompt length only, since no files were open), iteration count, time taken.

## Round 2 — + Code Context (10 minutes)

**Context to supply: `can_driver.h` and `can_driver.c`, open in your IDE.**

1. Open both files as your only additional context — still no `diag_formatter.h`, no `docs/`.
2. Write a prompt that references the real struct and function names now visible to Copilot (e.g., naming `can_driver_t`, `tx_error_count`, `can_error_state_t`) — but don't yet mention `diag_format_message()` or the coding standards explicitly. See if repository-aware assistance finds them on its own.
3. Send it. Copy the result into `scratch/round-2-code-context.c` with your prompt.
4. Score it. Did it discover `diag_formatter.c` unprompted, or invent its own formatting?
5. Fill in Round 2's row — for estimated tokens, add the character count of `can_driver.h` + `can_driver.c` to your prompt length (see the worksheet's estimation formula).

## Round 3 — + Design Context (10 minutes)

**Context to supply:** the Round 2 files, **plus** `include/diag_formatter.h` and `docs/CODING_STANDARDS.md`, open in your IDE.

1. Add both files to your open tabs.
2. Write a prompt that explicitly references what you found in Exercise 3's layering worksheet: name `diag_format_message()` directly, name the correct `DIAG_ERR_*` code range, and state the `can_driver_` naming / `size_t`-return convention.
3. Send it. Copy the result into `scratch/round-3-design-context.c` with your prompt.
4. Score it — this round should score highest, or close to it. If it doesn't, that's useful data too: note what still went wrong.
5. Fill in Round 3's row — estimated tokens now include all four open files.

## Round 4 — Compressed & Scoped (10 minutes)

**Context to supply: none of the files opened — only a tightly-written prompt** carrying the same facts Round 3 supplied by full files.

1. Close every `sample-repo/` file again.
2. Write one dense prompt that states, directly, the 2–3 facts Round 3's open files supplied implicitly: the function signature to add, "reuse `diag_format_message(buf, len, code, detail)` from `diag_formatter.h`," which `DIAG_ERR_*` code to use and when, and the naming/return-type convention.
3. Send it. Copy the result into `scratch/round-4-compressed-scoped.c` with your prompt.
4. Score it against the same rubric.
5. Fill in Round 4's row — estimated tokens should be dramatically lower than Round 3's (prompt-only character count, no open files), since the goal is matching Round 3's quality via compression rather than volume.

---

## Step 5 — Measure & Compare (10 minutes)

Your worksheet should now have all four rows filled in. Complete the reflection questions at the bottom of [`scratch/measurement-worksheet.md`](scratch/measurement-worksheet.md):

- Which round had the best quality-to-token ratio?
- Did Round 4 match Round 3's quality with fewer estimated tokens? If not, what got lost in compression?
- Where did quality plateau?

### Build the Summary Chart

Plot (on paper, in a spreadsheet, or just eyeballing the table) quality score against estimated tokens for all four rounds. You're looking for the "knee" of the curve — the point past which more context stopped buying more quality. That knee is the practical argument for context engineering: it's not "more context is always better," it's "the right context, once, is worth more than either extreme."

### Checkpoint

Can you state, in one sentence, which round you'd actually use in real work for a task like this — and why it's not automatically Round 3 (the one with the most context)?

---

## Where This Goes Next

- These four signals — output quality, token usage, iteration count, completion time — reappear as the token/cost and ROI model in Module 11. Today's worksheet is the first real data point in that series.
- Module 04 (Spec-Driven Development) treats a specification as the next, larger unit of context — the same layering and compression discipline you just practiced applies at the scale of an entire feature, not just one function.

**Module 03 complete.** Next: **Module 04 — Spec-Driven Development for Embedded Software** (2 hours). Requirements, constraints, interfaces & acceptance criteria — spec → plan → tasks → implementation with GitHub Spec Kit / OpenSpec.
