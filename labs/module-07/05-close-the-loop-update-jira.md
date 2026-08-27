# Exercise 5: Close the Loop — Update Jira

**Duration:** 15 minutes | **Format:** Individual, hands-on, `sample-repo/` + Jira

## Objective

Every earlier module in this programme stopped at a local artifact — a passing test suite, a reviewed spec, a draft PR. Today's is the first to close the loop all the way back to the system of record a program manager actually looks at. Slide 8's rule still applies: **the write action is always approval-gated, no matter how many times you've approved one like it today.**

---

## Step 1 — Preview the Transition, Don't Just Fire It (5 minutes)

Ask the agent what's possible before asking it to act:

```
Using the Jira MCP tools, show me the available status transitions for
<YOUR_ISSUE_KEY> from its current status.
```

Pick the transition that actually matches your team's workflow — for most Jira setups, that's something like **In Progress → In Review** or **In Progress → Done**, not necessarily "Done" outright if your process expects a human PR review first. Decide this yourself; don't let the agent pick the most final-sounding option by default.

## Step 2 — Attach the Evidence (5 minutes)

```
Using the Jira MCP tools, add a comment to <YOUR_ISSUE_KEY> with the
contents of specs/00N-diag-null-safe-formatting/evidence.md, and a note
that the fix is in src/diag_formatter.c with a new test in
tests/test_diag_formatter.c.
```

Show the tool call before approving it. Confirm the comment text is your real evidence file's content, not a paraphrase the agent generated on its own — if it paraphrased, ask it to paste the actual file content instead.

## Step 3 — Transition the Issue (3 minutes)

```
Using the Jira MCP tools, transition <YOUR_ISSUE_KEY> to <the status you
picked in Step 1>.
```

Approve the call. Then verify independently — don't just trust the agent's "done" message:

```
Using the Jira MCP tools, get the current status of <YOUR_ISSUE_KEY> and
show me its full comment history.
```

Confirm the status change and your evidence comment both actually landed.

## Step 4 — Debrief (2 minutes)

Answer before moving on:

1. Point to every place in today's lab a write action needed your explicit approval. Count them.
2. If you had let the agent both file the story *and* transition it to Done in the same uninterrupted turn, what oversight would you have lost?
3. What's the one thing in this whole loop — Jira → spec → code → test → Jira — that a human still has to decide, no matter how good the agent gets?

---

## Checkpoint

- [ ] The Jira issue is in the status you deliberately chose, verified by a read call, not assumed
- [ ] The issue's comment history contains your real evidence content
- [ ] You can list every approval gate you passed through today, in order
- [ ] You can answer Step 4's three debrief questions without looking anything up

## Where This Goes Next

You've now run the exact issue-to-validated-fix loop ~68% of this cohort named as their top MCP priority — grounded in a real finding, a real spec, a real test, and a real status update. Module 08 hands this same Jira data to program and product roles, through a low-code interface instead of code — but the governance boundary you just practiced (read freely, write only with approval) doesn't change just because the interface does.
