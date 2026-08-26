# Four-Round Measurement Worksheet

Fill this in as you go — don't reconstruct it from memory afterward. One row per round.

## Output Quality Rubric (score 0–5, one point per item)

For each round's generated `can_driver_get_error_summary()`, check off:

- [ ] Reuses `diag_format_message()` rather than reinventing `snprintf` formatting from scratch
- [ ] Picks an error code from the correct `DIAG_ERR_*` range (`0x2xxx`, CAN driver's range) rather than inventing an unrelated code or none at all
- [ ] Detail string includes both the driver's state and its `tx_error_count`
- [ ] Follows the `can_driver_` naming prefix and returns `size_t` (matching `diag_format_message`'s convention)
- [ ] No dynamic allocation (`malloc`/`free`)

Score = number of boxes checked (0–5).

## Token Estimation (proxy, not exact metering)

Real per-request token counts aren't visible from the IDE in this lab — that level of measurement is what Agent Prism gives you starting Module 10. For now, use this rough proxy:

> **Estimated tokens ≈ (characters in your prompt + characters in every file you had open/referenced) ÷ 4**

It's a standard rough approximation (not exact), but it's consistent across rounds, which is what matters for a same-task comparison. Note file sizes with `wc -c <file>` if you want a quick character count.

## The Table

| Round | Context Supplied | Output Quality (0–5) | Estimated Tokens | Iterations | Time (min:sec) |
|---|---|---|---|---|---|
| 1 — Prompt-Only | None | | | | |
| 2 — + Code Context | `can_driver.h`, `can_driver.c` open | | | | |
| 3 — + Design Context | + `diag_formatter.h`, `docs/CODING_STANDARDS.md` | | | | |
| 4 — Compressed & Scoped | Same facts as Round 3, stated directly (no open files) | | | | |

## Reflection

- Which round had the best quality-to-token ratio?
- Did Round 4 match Round 3's quality with fewer estimated tokens? If not, what did the compressed prompt leave out that the open files supplied implicitly?
- Where did quality plateau — i.e., after which round did adding more context stop improving the result?
