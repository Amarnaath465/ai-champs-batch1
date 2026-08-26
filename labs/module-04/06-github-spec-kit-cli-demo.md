# Bonus Exercise: The Real GitHub Spec Kit CLI

**Duration:** ~30–40 minutes | **Format:** Individual, self-paced | **Status:** Optional — not part of Module 04's required 2-hour agenda

## Objective

Everything in Exercises 1–5 was the spec → plan → tasks → implement discipline, done by hand, in plain markdown, precisely so the *discipline* stayed visible regardless of tooling. This bonus exercise swaps the hand-written templates for the **real** GitHub Spec Kit CLI — the actual `specify` tool, its actual slash commands, its actual generated files — so you can see exactly what it automates and, just as importantly, what it doesn't.

This is not a retrofit of Exercises 1–5; it's a fresh, small, standalone demonstration. Do it after Exercise 5, in fast-finisher time, or as a separate short session.

---

## Why a New, Standalone Repo — Not `sample-repo/`

Real Spec Kit's core convention is one git branch and one `specs/NNN-feature-name/` folder per feature, created automatically the moment you run its specify command. `sample-repo/` (the shared codebase every module reuses) is a plain directory tracked inside this training repo's own git history — it isn't its own git repo, and giving it one now would permanently mix Spec Kit's scaffolding into the codebase every other module depends on, for every future participant.

So: today you'll copy `sample-repo/`'s **files** (not its git history) into a fresh directory of your own, make that its own git repo, and let Spec Kit initialize there. You keep the same familiar codebase — same `can_driver`, same `docs/ARCHITECTURE.md` and `docs/CODING_STANDARDS.md` — just with Spec Kit given a clean git home instead of the shared training repo.

## Step 1 — Stand Up Your Own Copy (5 minutes)

```sh
cp -r sample-repo ~/spec-kit-demo
cd ~/spec-kit-demo
rm -rf bin
git init
git add -A
git commit -m "baseline: copy of Module 02 sample-repo"
```

## Step 2 — Install and Run the Real CLI (5 minutes)

Spec Kit ships as `specify-cli`; the standard way to run it without a persistent install is via `uvx`:

```sh
uvx --from git+https://github.com/github/spec-kit.git specify check
```

This lists every coding agent Spec Kit can integrate with and confirms your tools are ready — GitHub Copilot shows as "IDE-based, no CLI check," which is expected; it's checked through your editor, not a terminal binary.

Now initialize, in the current directory, targeting Copilot:

```sh
uvx --from git+https://github.com/github/spec-kit.git specify init --here --integration copilot
```

Confirm the merge prompt (you're initializing into a non-empty directory — that's expected, since it already has the sample-repo files in it).

**What this actually creates** — verified by running it: a `.specify/` directory (`.specify/memory/constitution.md`, `.specify/templates/`, `.specify/scripts/bash/*.sh` — the machinery behind numbered feature folders and branches) and a `.github/skills/` directory containing one `SKILL.md` per slash command: `speckit-constitution`, `speckit-specify`, `speckit-plan`, `speckit-tasks`, `speckit-implement`, plus optional ones (`speckit-clarify`, `speckit-analyze`, `speckit-checklist`, `speckit-converge`). These are real GitHub Copilot Skills, invoked in Copilot Chat exactly the way you'd invoke any slash command.

**If your CLI output shows different command names than listed here:** the tool is under active development and its exact command set has changed before. Run `specify check` and look inside `.github/skills/` after `init` — trust what's actually on disk over these instructions.

## Step 3 — Establish a Constitution (Optional, 5 minutes)

In Copilot Chat, inside your new repo:

```
/speckit-constitution
```

When it asks what principles to encode, feed it what `docs/CODING_STANDARDS.md` and `docs/ARCHITECTURE.md` already say — snake_case naming, no dynamic allocation, the module-prefix convention, the layering rules. This is the one step with no equivalent in Exercises 1–5: a constitution persists across every future feature you spec in this repo, so you stop re-explaining house style in every prompt.

## Step 4 — Specify the Feature (10 minutes)

Today's feature: a **CRC-8 checksum utility** for validating `can_message_t` payloads — genuinely new, untouched by anything in Modules 04 or 05, small enough to finish in this exercise, and with an unambiguous, well-known correct answer (a real checksum standard) rather than a judgment call.

In Copilot Chat:

```
/speckit-specify Add a CRC-8 checksum function so can_driver can validate the integrity
of a received CAN message payload before acting on it. It needs to compute a single
checksum byte over an arbitrary-length byte buffer, matching a standard, verifiable
CRC-8 algorithm so results can be checked against known reference values.
```

Notice what you did — and didn't — say: a plain-language problem statement, no function signature, no mention of the polynomial. That's deliberate; it mirrors how EVENTLOG-01 and SENSOR-142 were written as tickets, not designs.

Open the `specs/001-.../spec.md` file this generates. Compare its structure against Module 04 Exercise 2's hand-written template — same four ideas (requirements, constraints, interfaces, acceptance criteria), auto-scaffolded into place with a numbered folder and a dedicated git branch, instead of you creating both by hand.

Run the same five-point review from Exercise 1 against it: **Testable, Bounded, Interface-Accurate, Traceable, Reviewed.** Tool-generated is not the same as tool-verified — if the spec is vague on the exact polynomial/initial-value/reflection choice, that's your job to pin down before moving on, the same as it would be by hand. (For reference: CRC-8/SMBUS — polynomial `0x07`, initial value `0x00`, no input or output reflection, no final XOR — is a defensible, verifiable choice; its catalog check value is `0xF4` for the ASCII bytes `"123456789"`.)

## Step 5 — Plan and Tasks (5 minutes)

```
/speckit-plan
```

then

```
/speckit-tasks
```

Review both the same way Module 04 Exercise 3 asked you to review a hand-drafted plan: does it respect the "no dynamic allocation" constraint, does it name the exact files it'll touch, does the task list trace back to the spec's acceptance criteria row by row? A generated plan you don't review is exactly as risky as a hand-written one you don't review.

## Step 6 — Implement and Validate (10 minutes)

```
/speckit-implement
```

Watch it work through the task list. When it's done:

```sh
make test
```

Confirm your new CRC-8 test(s) pass — specifically the known catalog check value, not just a self-consistency check against your own implementation.

---

## Debrief

Answer these before moving on:

- What did the tool automate that you did by hand in Exercise 2? (Folder numbering, branch creation, template boilerplate, the plan/tasks scaffolding structure.)
- What did the tool *not* do for you, regardless of how good the CLI is? (Decide the actual requirement — nobody told it "CRC-8/SMBUS specifically"; verify the acceptance criteria are genuinely testable; review the generated plan before trusting it.)
- Is the discipline from Exercises 1–5 still recognizable inside the automated version, or did something get lost in translation?

## Where This Goes Next

The four-stage discipline is the same whether you write `spec.md` by hand or generate it with `/speckit-specify` — that's the point Module 04 opened with, and this exercise exists to prove it, not to argue you should switch tools. Module 05's greenfield/brownfield work continues using the hand-written approach, so the underlying discipline stays visible without depending on any one CLI's continued existence or command names.
