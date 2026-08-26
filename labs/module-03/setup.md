# Setup — Module 03 Lab

Do this before the session starts. Takes about 5 minutes if you completed Module 02; a bit longer if this is your first lab.

## 1. This Module Reuses the Module 02 Sample Repository

Module 03 does not ship its own codebase — it works against the same [`sample-repo/`](../module-02/sample-repo/) used in Module 02. No duplication, no drift between the two.

```sh
cd labs/module-02/sample-repo
make test
```

You don't need a clean/passing build to do Module 03's exercises — the task in [Exercise 4](04-four-round-progressive-lab.md) (`can_driver_get_error_summary`) is independent of the CAN driver defect from Module 02. If you already fixed that defect in Module 02, that's fine; if you didn't, that's also fine.

## 2. Access Checklist

- [ ] GitHub Copilot Enterprise seat active, Chat available
- [ ] `sample-repo/` (from Module 02) open as your IDE workspace root
- [ ] You can open and close files in your IDE quickly — several exercises today depend on deliberately controlling what's open, not just what exists on disk

## 3. Know Where the Reference Docs Are

Two files inside `sample-repo/` get referenced by name throughout today's exercises:

- [`sample-repo/docs/ARCHITECTURE.md`](../module-02/sample-repo/docs/ARCHITECTURE.md)
- [`sample-repo/docs/CODING_STANDARDS.md`](../module-02/sample-repo/docs/CODING_STANDARDS.md)

If Module 02 feels distant, skim both again now — Exercise 2 and 3 assume you can name specific rules from them, not just that you've seen them before.

## 4. This Module's Own Files

Module 03 adds one folder of its own — [`scratch/`](scratch/) — where you'll capture the four rounds of Exercise 4 without touching the real `sample-repo/` source files. Nothing to set up there now; you'll use it starting in Exercise 4.

---

Once your access checklist is complete, start with [Exercise 1](01-prompt-recap-and-weak-vs-strong.md).
