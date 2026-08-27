# Exercise 3: Write the Spec with GitHub Spec Kit

**Duration:** 30 minutes | **Format:** Individual, hands-on, `sample-repo/`

## Objective

Module 04's bonus exercise showed you the real Spec Kit CLI on a greenfield CRC-8 feature in a throwaway copy of the repo. Today you run the same CLI, in `sample-repo/` itself, on a real Jira-sourced fix — and the spec's input is a Jira issue key, not a paragraph you typed fresh.

If you haven't done Module 04's Spec Kit bonus exercise, do Steps 1–2 of it first (installing the CLI, confirming `.specify/` and the `speckit-*` skills exist) — today assumes that machinery is already in place.

---

## Step 1 — Confirm Spec Kit Is Live in `sample-repo/` (3 minutes)

```sh
cd sample-repo
ls .specify/ 2>/dev/null && ls .github/skills/ | grep speckit
```

If `.specify/` doesn't exist yet in `sample-repo/` (Module 04's bonus exercise used a *separate* copy of the repo, by design), initialize it here now:

```sh
uvx --from git+https://github.com/github/spec-kit.git specify init --here --integration copilot
```

Confirm the merge prompt (expected — `sample-repo/` is not empty).

## Step 2 — Specify, Grounded in the Jira Issue (12 minutes)

In Copilot Chat, inside `sample-repo/`:

```
/speckit-specify Read Jira issue <YOUR_ISSUE_KEY> using the Jira MCP tools
and use its title, description, and acceptance criteria as the basis for
this spec. Do not invent acceptance criteria beyond what the issue states.
```

Notice what's different from Module 04's version of this step: there, you typed the problem statement directly into the slash command. Here, the agent has to use a **second** MCP connection (Jira) to pull the actual requirement before it can even start drafting — this is Slide 10's "Repository Analysis" step, except the analysis target is an issue tracker, not the codebase.

Open the generated `specs/00N-.../spec.md`. Confirm:
- [ ] Every acceptance criterion in your Jira issue (Exercise 2, Step 2) appears in the spec, in some form
- [ ] The spec doesn't add acceptance criteria your Jira issue never stated — if it did, that's a real gap between what the agent read and what it should have scoped to; fix the spec by hand
- [ ] The interface section proposes changing `diag_format_message`'s **behavior**, not its **signature** — this is a pure bug-fix feature, and a signature change would break every existing caller

Run the five-point review from Module 04: **Testable, Bounded, Interface-Accurate, Traceable, Reviewed.** Specifically check AC wording against the fallback text you asked for (`"(no detail)"`) — if Spec Kit chose different wording, that's fine as long as it's still a deterministic, checkable string.

## Step 3 — Plan and Tasks (10 minutes)

```
/speckit-plan
```

then

```
/speckit-tasks
```

Review the plan against `docs/ARCHITECTURE.md`'s layering rule 4 ("Diagnostics are cross-cutting... has no dependency on any other module") — confirm the plan doesn't propose adding a dependency from `diag_formatter.c` to anything else. Review the task list against the spec's acceptance criteria, the same traceability check from Module 04 Exercise 3.

## Step 4 — Update the Jira Issue with the Spec Link (5 minutes)

Before moving to implementation, close the traceability loop in the other direction:

```
Using the Jira MCP tools, add a comment to <YOUR_ISSUE_KEY> linking to
specs/00N-diag-null-safe-formatting/spec.md and summarizing the approach
in two sentences.
```

Approve the write call. This is the first of two Jira writes today — Exercise 5 does the second (the status transition), after there's real evidence to attach.

---

## Checkpoint

- [ ] `specs/00N-.../spec.md`, `plan.md`, and `tasks.md` exist and passed your five-point review
- [ ] The spec's acceptance criteria trace directly to your Jira issue's acceptance criteria — you checked this by hand, not by trusting the agent's summary
- [ ] The plan respects the diagnostics-module layering rule
- [ ] Your Jira issue now has a comment linking back to the spec

## Where This Goes Next

Exercise 4 runs `/speckit-implement` against the task list you just reviewed, then proves the fix with a real test and a sanitizer run — the same evidence bar Module 06 set.
