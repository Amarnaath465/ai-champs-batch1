# Exercise 2: Create the User Story in Jira

**Duration:** 15 minutes | **Format:** Individual, hands-on, `sample-repo/` + Jira

## Objective

Turn a real, already-documented gap into a real Jira story — using the agent's write tool, with your explicit approval, exactly once.

---

## Step 1 — Read the Source Finding (3 minutes)

Open `sample-repo/docs/CODE_REVIEW_REPORT.md` and find the **High** finding:

> `src/diag_formatter.c:13` — `snprintf(..., "%s", detail)` is called without checking whether `detail` is `NULL`. Impact: undefined behavior or a crash on some libc implementations.

Open `src/diag_formatter.c` and confirm it yourself at line 13. Then open `tests/test_diag_formatter.c` and confirm no existing test passes `NULL` as `detail` — the same "prove the gap is real" discipline from Module 06 Exercise 1, applied to a code-review finding instead of a spec.

## Step 2 — Draft the Story, Don't Skip This (5 minutes)

Write the story yourself, in plain language, before asking the agent to file it — a Jira ticket the agent drafts *and* files in one uninspected step is exactly the "leave a useful prompt unshared" anti-pattern from Slide 13, just relocated to Jira instead of chat history.

```
Title: diag_format_message must not pass a NULL detail to snprintf's %s

As a firmware engineer, I want diag_format_message() to handle a NULL
`detail` argument safely, so that diagnostic formatting never risks
undefined behavior or a crash on any target libc.

Background: sample-repo/docs/CODE_REVIEW_REPORT.md flags this as a
High finding at src/diag_formatter.c:13. No existing test in
tests/test_diag_formatter.c exercises detail == NULL.

Acceptance criteria:
- diag_format_message(buf, len, code, NULL) does not invoke undefined
  behavior on any supported target libc.
- When detail is NULL, the formatted message contains a clear
  placeholder (e.g. "(no detail)") instead of dereferencing NULL.
- Existing behavior for a non-NULL detail is unchanged.
- A new test in tests/test_diag_formatter.c exercises detail == NULL.
```

## Step 3 — File It Through the Agent (5 minutes)

Now ask the agent to create it, naming the exact write tool from Exercise 1:

```
Using the Jira create-issue tool, file a Story in project <YOUR_PROJECT_KEY>
with this exact title and description: [paste your draft from Step 2].
Show me the tool call before you send it.
```

Confirm before approving:
- [ ] Project key is correct
- [ ] Issue type is Story (not Bug/Task) — a deliberate framing choice for this exercise; note in your own words why a real team might file the same gap as a Bug instead, and when that distinction matters
- [ ] Title and description match what you drafted — the agent should not be inventing acceptance criteria you didn't write

Approve the call. Record the returned issue key (e.g. `EMBED-101`) — you'll need it in Exercise 3.

---

## Checkpoint

- [ ] A real Jira issue exists with your drafted title, description, and acceptance criteria
- [ ] You wrote the acceptance criteria yourself before the agent touched Jira, not after
- [ ] You have the issue key recorded
- [ ] You can explain why this write call needed your approval and the Exercise 1 read calls didn't

## Where This Goes Next

Exercise 3 hands this exact issue key to `/speckit-specify` — the spec's requirements should trace back to the acceptance criteria you just wrote, not reinvent them.
