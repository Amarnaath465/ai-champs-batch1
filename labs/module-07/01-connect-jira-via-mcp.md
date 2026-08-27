# Exercise 1: Connect Jira via MCP

**Duration:** 20 minutes | **Format:** Individual, hands-on, MCP client configuration

## Objective

Slide 4's governing idea: *"an agent's capability is exactly the set of tools it's been granted — nothing implicit, nothing assumed."* Before asking the agent to touch Jira at all, confirm exactly what it can and can't do there, the same read/write split from Slide 7.

---

## Step 1 — Confirm the Connection (5 minutes)

If you completed [setup.md](setup.md), your MCP client is already configured. In Copilot Chat, run:

```
List every tool the atlassian (or jira) MCP server has given you access to. Group them into read tools and write tools.
```

Compare the result against what setup.md told you to expect. If a tool you were told to expect is missing, or one you weren't expecting appears, that's not a bug to ignore — it's the scope you're actually working under today. Write down the real list.

## Step 2 — Read-Only Recon (10 minutes)

Using only the **read** tools, ask the agent:

```
Using the Jira MCP tools, list the open issues in project <YOUR_PROJECT_KEY>. Don't create or change anything.
```

Confirm:
- The agent used a read tool, not a write tool, for this
- The response reflects real data from your Jira site, not an invented answer
- No approval prompt appeared for this step (read-only calls should be able to run without a per-call human gate, per Slide 7's "generally autonomous" column)

Now try a query that *would* need a write tool, but tell the agent explicitly not to execute it:

```
If you needed to create a new story in <YOUR_PROJECT_KEY>, which tool would you call, and what fields would it require? Don't call it yet.
```

Confirm the agent names a specific write tool and its required fields (typically: project key, issue type, summary, description) without calling it. This is the write-path preview you'll actually use in Exercise 2.

## Step 3 — Name the Boundary (5 minutes)

Answer, in your own words, before moving on:

1. Which Jira tools can this agent call without asking you first?
2. Which Jira tools require your explicit approval every time, regardless of how many times you've approved them before?
3. If the agent's Jira MCP connection got revoked mid-session, what would visibly stop working, and what wouldn't be affected?

---

## Checkpoint

- [ ] You have a written list of the exact tools your Jira MCP connection grants, not an assumed list
- [ ] You confirmed a read-only Jira query works without a write-tool call
- [ ] You know which write tool creates an issue and what fields it needs — but haven't called it yet
- [ ] You can state the read/write boundary for this connection in one sentence

## Where This Goes Next

Exercise 2 uses the exact create-issue tool you just previewed — for real this time, with your explicit approval — to file today's Jira story.
