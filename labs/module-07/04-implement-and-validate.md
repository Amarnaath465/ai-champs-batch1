# Exercise 4: Implement, Test & Gather Evidence

**Duration:** 40 minutes | **Format:** Individual, hands-on, `sample-repo/`

## Objective

Slide 10's workflow: repository analysis → spec validation → build/test → PR evidence. You've done the first two. Now build/test, and assemble evidence a reviewer — human or the Exercise 5 Jira comment — could check in under a minute.

---

## Step 1 — Baseline Before You Touch Anything (5 minutes)

```sh
cd sample-repo
make test
```

Confirm the full suite is green before you start — if it isn't, you're not looking at the gap this lab targets; stop and check with your facilitator.

Reproduce the actual gap yourself, the same discipline as Module 06 Exercise 1's crash probe:

```c
/* scratch.c — compile against your real diag_formatter.c and run it */
#include "diag_formatter.h"
#include <stdio.h>
int main(void) {
    char buf[64];
    size_t n = diag_format_message(buf, sizeof(buf), DIAG_ERR_CAN_BUSOFF, NULL);
    printf("n=%zu buf=\"%s\"\n", n, buf);
    return 0;
}
```

Compile and run it. On most host libc, you'll see `buf="[0x2001] (null)"` — not a crash here, but genuinely undefined behavior per the C standard, and a real crash risk on a leaner embedded libc that doesn't special-case a `NULL` `%s` argument. That gap between "happens to work on my laptop" and "guaranteed by the standard" is exactly what today's fix closes.

## Step 2 — Implement via Spec Kit (15 minutes)

```
/speckit-implement
```

Watch it work through `tasks.md`. When it's done, read the diff to `src/diag_formatter.c` yourself before running anything — confirm it's a small, additive guard (matching the shape of `event_log_get`'s `out == NULL ||` fix from Module 06), not a rewrite of the function's control flow.

Confirm a new test landed in `tests/test_diag_formatter.c` covering `detail == NULL`. If Spec Kit didn't generate one, write it yourself now — Module 06's rule applies here too: an untested acceptance criterion is a gap, not a formality.

## Step 3 — Prove It (15 minutes)

```sh
make test
```

Confirm every binary passes, including your new NULL-detail test and every test that existed before you started (regression, not just new coverage).

Run the sanitizer build, the same as Module 06 Exercise 4:

```sh
gcc -fsanitize=address,undefined -Wall -Wextra -o /tmp/diag_san \
  tests/test_diag_formatter.c src/diag_formatter.c && /tmp/diag_san
```

Re-run your Step 1 scratch probe against the **fixed** code and confirm the output now shows your placeholder text (e.g. `"(no detail)"`), not a dereferenced `NULL`.

## Step 4 — Assemble the Evidence (5 minutes)

Write `specs/00N-diag-null-safe-formatting/evidence.md`:

```markdown
# Evidence: diag_format_message NULL-detail fix

| Check | Result |
|---|---|
| `make test` — full suite | PASS (N/N assertions) |
| New test: detail == NULL | PASS |
| Sanitizer build (asan+ubsan) | Clean |
| Manual NULL-detail probe, before fix | UB — printed "(null)" on host libc |
| Manual NULL-detail probe, after fix | Deterministic placeholder, no dereference |
| Regression: existing diag_formatter tests | All still PASS |
```

Fill in real numbers from your own run, not placeholder text.

---

## Checkpoint

- [ ] `src/diag_formatter.c` has the guard fix, reviewed by you before you ran anything
- [ ] `tests/test_diag_formatter.c` has a new, passing test for `detail == NULL`
- [ ] `make test` and the sanitizer build are both clean
- [ ] `evidence.md` exists with real, specific numbers

## Where This Goes Next

Exercise 5 attaches exactly this evidence file to your Jira issue and moves it to done — the step that makes today's loop actually close, not just stop at "code compiles."
