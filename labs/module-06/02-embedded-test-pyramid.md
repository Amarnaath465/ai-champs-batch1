# Exercise 2: The Embedded Test Pyramid

**Duration:** 20 minutes | **Format:** Individual + discussion

## Objective

Three layers, growing cost and confidence — add the next one only when the last isn't enough. Classify what already exists, then decide where each of Exercise 1's three gaps belongs before writing a single line of new test code.

## The Pyramid

| Layer | What it verifies | Cost |
|---|---|---|
| **Host-based unit tests** | Individual functions, fast, isolated — no hardware needed | Seconds per run |
| **Integration tests** | Modules work together correctly — real interfaces, mocked hardware boundaries | Minutes per run |
| **Software-level E2E tests** | Full feature validation against acceptance criteria — closest to production behavior, without hardware-in-the-loop | Longest, highest confidence |

**Hardware-in-the-loop** sits conceptually above the E2E layer for teams that need it — this programme stays entirely software-level; HIL is discussed only as a concept, never demonstrated.

---

## Step 1 — Classify What Already Exists (8 minutes)

For each test binary already in `sample-repo/tests/`, decide which layer it belongs to and write one sentence justifying it:

- `test_can_driver.c`
- `test_event_log.c`
- `test_can_driver_event_log.c`
- `test_sensor_poll.c` (if you built it in Module 04)

Most of these are unit-level — a single module's logic, in isolation. Is `test_can_driver_event_log.c` still "unit," or does exercising two modules together (`can_driver` calling into `event_log`) make it something closer to integration? There's a real answer here, not just a label to memorize: it tests the *seam* between two modules, which is exactly what distinguishes integration tests from unit tests.

## Step 2 — Place Exercise 1's Gaps on the Pyramid (8 minutes)

For each of the three gaps you found in Exercise 1, decide which layer it belongs at:

1. **The capacity-1 boundary case** — this is a single function's internal logic under a specific input. Which layer?
2. **The `NULL`-out negative case** — same question: is this about one function's contract, or about how modules interact?
3. **The missing multi-module scenario** (`sensor_poll` + `can_driver` + `event_log` together) — which layer does *this* belong at, and why can't a unit test cover it no matter how you write it?

Write your answers down. If two of the three land in the same place, that's expected — most gaps are unit-level; only the third genuinely needs the top of the pyramid.

## Step 3 — Discuss (4 minutes)

If working with others: compare where you placed test #3. What would it actually take to write it — what would the test function need to set up, call, and assert, across how many modules?

---

## Checkpoint

- [ ] Every existing test binary is classified by pyramid layer, with a one-sentence justification
- [ ] Each of Exercise 1's three gaps is assigned a layer
- [ ] You can explain, in one sentence, why the third gap can't be closed by a unit test alone

## Where This Goes Next

Exercise 3 closes the two unit-level gaps (and builds the tooling — fakes — needed for the third). Exercise 5 uses that tooling to close the integration/E2E gap.
