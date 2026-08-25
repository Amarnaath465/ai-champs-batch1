# Setup — Module 02 Lab

Do this before the session starts. It takes about 10 minutes.

## 1. Access Checklist

- [ ] GitHub Copilot Enterprise seat active on your account
- [ ] Your IDE (VS Code or equivalent) has the Copilot and Copilot Chat extensions installed and signed in
- [ ] Agent Mode is enabled and visible in your IDE — this is not the same as Chat; confirm you can see an "Agent" mode toggle, not just "Ask"/"Edit"
- [ ] You can reach GitHub.com with your enterprise account (needed for Exercise 3's PR flow, if your cohort has a shared lab repository)
- [ ] A terminal with `gcc` and `make` available

Check the toolchain:

```sh
gcc --version
make --version
```

Any reasonably recent `gcc` (or `clang` aliased as `gcc`) works — the sample repository uses plain C11 with no external dependencies.

## 2. Get the Sample Repository

The sample repository ships inside this lab folder — no cloning required:

```sh
cd labs/module-02/sample-repo
make test
```

**Expect 3 failing assertions.** This is intentional — see `sample-repo/README.md`. If instead you get a **compile error**, that's not expected; check your `gcc`/`make` versions or flag it to your facilitator before the session starts.

## 3. Open the Right Workspace Root

Open `labs/module-02/sample-repo/` (not the whole repository, and not `labs/module-02/`) as your IDE workspace root. Copilot's repository-aware features — knowledge base indexing, agent mode context discovery — work best scoped to the actual project, not the surrounding lab-documentation tree.

## 4. Optional: Shared Lab Repository for the PR Exercise

Exercise 3 includes a PR-review pass. If your cohort has a shared GitHub repository for this purpose, confirm you have push access before the session. If not, Exercise 3 includes an offline fallback using `git diff` locally — no setup needed for that path.

## 5. Skim the Reference Docs

Two short files inside `sample-repo/` are referenced throughout every exercise — read them now so you're not context-switching mid-exercise:

- [`sample-repo/docs/ARCHITECTURE.md`](sample-repo/docs/ARCHITECTURE.md) — module layering and the rules Agent Mode has to respect in Exercise 4
- [`sample-repo/docs/CODING_STANDARDS.md`](sample-repo/docs/CODING_STANDARDS.md) — naming/error-code conventions used throughout

---

Once your access checklist is complete and `make test` runs (with the expected 3 failures), you're ready for [Exercise 0](00-capability-map-walkthrough.md).
