# Setup — Module 04 Lab

Do this before the session starts. Takes about 5 minutes if you completed Modules 02–03; a bit longer otherwise.

## 1. This Module Reuses the Module 02 Sample Repository

Module 04 does not ship its own codebase — it works against the same [`sample-repo/`](../module-02/sample-repo/) used in Modules 02 and 03. No duplication, no drift.

```sh
cd labs/module-02/sample-repo
make test
```

## 2. What You Need From Module 02

Today's feature reuses `diag_format_sensor_fault()`, which you built in Module 02, Exercise 1 as an inline-assist task. Check it's there:

```sh
grep -n "diag_format_sensor_fault" include/diag_formatter.h src/diag_formatter.c
```

You should see a real declaration and implementation, not the original `TODO` comment. If it's still a `TODO`, implement it now (it's a short function — see the original instructions in [`../module-02/01-generate-explain-refactor.md`](../module-02/01-generate-explain-refactor.md), Part A) or flag it to your facilitator before Exercise 2 starts.

Nothing else from Module 02 or Module 03 is a hard dependency — whether or not you fixed the CAN driver defect, finished `fault_monitor`, or completed Module 03's four-round lab doesn't block today's work.

## 3. Access Checklist

- [ ] GitHub Copilot Enterprise seat active, Chat available
- [ ] `sample-repo/` open as your IDE workspace root
- [ ] `diag_format_sensor_fault()` confirmed implemented (Step 2 above)
- [ ] `make test` runs (some pre-existing failures are fine if you haven't fixed Module 02's CAN driver defect — today's work doesn't depend on it)

## 4. Know Where the Reference Docs Are

Three files inside `sample-repo/` get referenced by name throughout today's exercises:

- [`sample-repo/docs/ARCHITECTURE.md`](../module-02/sample-repo/docs/ARCHITECTURE.md) — module layering rules
- [`sample-repo/docs/CODING_STANDARDS.md`](../module-02/sample-repo/docs/CODING_STANDARDS.md) — naming, error-code ranges, function conventions
- [`sample-repo/include/sensor_poll.h`](../module-02/sample-repo/include/sensor_poll.h) and [`src/sensor_poll.c`](../module-02/sample-repo/src/sensor_poll.c) — where today's new feature lives

## 5. This Module's Own Artifacts

Unlike Module 03 (which deliberately stayed in a `scratch/` folder to avoid touching real files), Module 04 writes real, permanent artifacts into the sample repository — because writing a spec you actually implement against is the point. You'll create:

```
sample-repo/specs/001-sensor-fault-diagnostics/
├── spec.md            (Exercise 2)
├── plan.md             (Exercise 3)
├── tasks.md             (Exercise 3)
└── traceability.md      (Exercise 5)
```

plus real changes to `include/sensor_poll.h`, `src/sensor_poll.c`, and a new `tests/test_sensor_poll.c` (Exercise 4).

---

Once your access checklist is complete, start with [Exercise 1](01-sdd-fundamentals-and-spec-anatomy.md).
