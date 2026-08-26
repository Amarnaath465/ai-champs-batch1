# Setup — Module 06 Lab

Do this before the session starts. Takes about 5 minutes.

## 1. This Module Extends Module 05's Artifacts — It Doesn't Replace Them

Module 06 does not introduce a new feature. Everything today is testing work performed directly on top of what Module 05 built: the `event_log` module and its integration into `can_driver.c`. If you didn't complete Module 05, today's exercises will still make sense conceptually, but you'll be testing code you didn't write yourself — pair with someone who did, or do a quick read of [`../module-05/facilitator-guide.md`](../module-05/facilitator-guide.md)'s Reference Design section first.

```sh
cd labs/module-02/sample-repo
make test
```

## 2. Hard Dependencies From Module 05

Confirm these exist before continuing:

- [ ] `include/event_log.h` and `src/event_log.c` — the greenfield module
- [ ] `can_driver_t` has an `event_log` field and `can_driver_set_event_log()` exists in `include/can_driver.h`/`src/can_driver.c` — the brownfield integration
- [ ] `tests/test_event_log.c` and `tests/test_can_driver_event_log.c` exist and pass
- [ ] `sample-repo/specs/002-event-log-diagnostics/spec.md` and `brownfield-plan.md` exist — today's Exercise 1 reads these directly

```sh
grep -n "event_log" include/can_driver.h
make test
```

You should see `test_event_log` and `test_can_driver_event_log` among the binaries, all green.

## 3. Access Checklist

- [ ] GitHub Copilot Enterprise seat active, Chat and inline assist available
- [ ] `sample-repo/` open as your IDE workspace root
- [ ] A C compiler with sanitizer support — `gcc` or `clang` on macOS/Linux both support `-fsanitize=address,undefined` out of the box; no extra install needed
- [ ] (Optional) `cppcheck` installed, if you want the static-analysis step to include a real second tool. Not required — the compiler's own `-Wall -Wextra` plus the sanitizer build are the floor for today, not `cppcheck`.

## 4. This Module's Own Artifacts

New files land in `sample-repo/`:

```
specs/002-event-log-diagnostics/
├── test-strategy.md          (Exercise 1)
└── test-evidence.md          (Exercise 6)

tests/
├── test_event_log_boundary.c        (Exercise 3)
├── test_device_e2e.c                (Exercise 5)
└── fakes/
    ├── hal_adc_fake.h / .c           (Exercise 3)
    └── hal_gpio_fake.h / .c          (Exercise 3)
```

Plus a small, additive fix to `src/event_log.c` (Exercise 3, closing a real gap Exercise 1 will surface) and a new `Makefile` rule (Exercise 3, wiring the fakes into the build without disturbing the existing pattern rule).

---

Once your access checklist is complete, start with [Exercise 1](01-spec-to-test-traceability.md).
