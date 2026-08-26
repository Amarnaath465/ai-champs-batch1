# Exercise 4: Static Analysis & Build Validation

**Duration:** 20 minutes | **Format:** Individual, hands-on in `sample-repo/`

## Objective

The automated gate that runs before any human opens the diff. Run this before you ask for review: a PR that already passed these checks gets reviewed for judgment, not caught on mechanics.

## The Four-Stage Gate

| Stage | What it catches |
|---|---|
| **Static analysis** | Coding-standard violations, unreachable code, likely bugs — no execution required |
| **Build validation** | Confirms clean compilation across every target in the toolchain, not just one |
| **Sanitizers** | Runtime checks for memory errors, undefined behavior, and data races — on host builds |
| **Feeds the PR directly** | These same checks reappear as evidence in Module 09's PR quality gate |

---

## Step 1 — Confirm the Compiler Gate Is Still Clean (3 minutes)

The Makefile already builds with `-Wall -Wextra`. Confirm zero warnings across every file touched today:

```sh
cd sample-repo
make clean && make test 2>&1 | grep -i warning
```

No output means no warnings. If anything shows up, fix it now — a warning left in place today is a warning a reviewer has to explain away in Module 09.

## Step 2 — Sanitizer Build (12 minutes)

`-Wall -Wextra` catches what the compiler can see statically. Memory errors and undefined behavior often only show up at runtime — that's what `-fsanitize=address,undefined` is for. Build and run every test binary this way, once, by hand:

```sh
for t in tests/test_*.c; do
  name=$(basename "$t" .c)
  if [ "$name" = "test_device_e2e" ]; then
    gcc -std=c11 -Wall -Wextra -fsanitize=address,undefined -g -Iinclude -Itests/fakes \
      -o /tmp/san_$name "$t" src/can_driver.c src/sensor_poll.c src/state_machine.c \
      src/diag_formatter.c src/event_log.c tests/fakes/hal_adc_fake.c tests/fakes/hal_gpio_fake.c
  else
    gcc -std=c11 -Wall -Wextra -fsanitize=address,undefined -g -Iinclude \
      -o /tmp/san_$name "$t" src/can_driver.c src/sensor_poll.c src/hal_adc.c \
      src/hal_gpio.c src/state_machine.c src/diag_formatter.c src/event_log.c
  fi
  echo "--- $name ---"
  /tmp/san_$name
  rm -f /tmp/san_$name
done
```

(If `tests/test_device_e2e.c` doesn't exist yet, skip it for now — it's Exercise 5's file. Run this again once it exists.)

Every binary should run clean — no `ERROR: AddressSanitizer` or `runtime error:` lines. This is a real, host-only check: no target hardware needed, and it catches an entire category of embedded defects (buffer overruns, use-after-free, signed-integer overflow) that `-Wall -Wextra` alone cannot.

## Step 3 — Static Analysis, If Available (5 minutes)

```sh
which cppcheck
```

If it's installed:

```sh
cppcheck --enable=warning,style -Iinclude src/*.c
```

If it's not installed, that's fine — note it as a gap in today's evidence rather than skip the step silently. The compiler warnings and the sanitizer build are the required floor for today; `cppcheck` (or an equivalent static analyzer) is the natural next tool to add to a real CI pipeline, not a blocker for this lab.

---

## Checkpoint

- [ ] `make test` produces zero compiler warnings across every file
- [ ] Every test binary runs clean under `-fsanitize=address,undefined` — no reported errors
- [ ] You know whether `cppcheck` (or an equivalent) is available in your environment, and ran it if so
- [ ] You can explain, in one sentence, what a sanitizer catches that `-Wall -Wextra` does not

## Where This Goes Next

This four-stage gate is what a reviewer expects to already be clean before they open your diff — Module 09 formalizes exactly this into an automated PR quality check. Exercise 5 writes the last missing test (the E2E gap from Exercise 1) and runs everything, including today's new sanitizer and static-analysis passes, as one evidence-producing pass.
