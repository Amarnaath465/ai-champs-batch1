# Module 01: AI Champions Kick-off and Embedded Engineering Enterprise Context

## Honeywell Embedded Engineering Teams — Comprehensive Guide

---

## Document Revision

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 25 Aug 2025 | Initial comprehensive guide |
| 2.0 | 25 Aug 2026 | Synced with revised course outline v3, calibration analysis report, and Module 01 presentation |

---

## Table of Contents

1. [Module Overview](#1-module-overview)
2. [Cohort Profile & Calibration Insights](#2-cohort-profile--calibration-insights)
3. [Why Honeywell Embedded Teams Need AI Champions](#3-why-honeywell-embedded-teams-need-ai-champions)
4. [The Incremental Engineering Journey](#4-the-incremental-engineering-journey)
5. [Enterprise Context: Current State vs Target State](#5-enterprise-context-current-state-vs-target-state)
6. [Role-Based Expectations](#6-role-based-expectations)
7. [Business and Engineering Risks of Unmanaged AI Usage](#7-business-and-engineering-risks-of-unmanaged-ai-usage)
8. [Embedded Software Lifecycle Context](#8-embedded-software-lifecycle-context)
9. [Agent Prism: The Monitoring Lens](#9-agent-prism-the-monitoring-lens)
10. [Pain Points in Embedded Software Delivery](#10-pain-points-in-embedded-software-delivery)
11. [Success Metrics Framework](#11-success-metrics-framework)
12. [Architecture Diagrams and Visual Flow](#12-architecture-diagrams-and-visual-flow)
13. [Workshop Canvas and Exercises](#13-workshop-canvas-and-exercises)
14. [Reference Links and Resources](#14-reference-links-and-resources)

---

## 1. Module Overview

**Duration:** 1.5 Hours (Revised from 2 Hours)  
**Format:** Instructor-led + Workshop  
**Primary Tools:** Slides, Role-Mapping Canvas, Current/Target-State Workflow Canvas, Success-Metrics Worksheet, Agent Prism Overview

### Module Objectives

By the end of this module, participants will:

- Understand why Honeywell-style embedded engineering teams need **AI Champions**
- Recognize the shift from isolated AI experimentation to **disciplined enterprise adoption**
- Define role-based expectations across embedded engineering roles
- Identify business and engineering risks of unmanaged AI/agent usage
- Map current-state vs target-state engineering workflows
- Understand Agent Prism as the monitoring and measurement lens

### Module 01 Context: Pre-Programme Calibration Data

This module is informed by a **pre-programme calibration survey** of 19 participants. Key findings shape the content emphasis:

| Finding | Data Point | Implication for Module 01 |
|---------|------------|---------------------------|
| Senior cohort | 68% have 8+ years experience | Can move quickly through fundamentals |
| C/C++ expertise | 74% rate Advanced/Expert | Focus on AI technique, not embedded basics |
| AI usage | 84% use Copilot regularly/daily | Position as deepening, not first exposure |
| Specification instinct | 79% already use spec-led patterns | SDD formalises existing instinct |
| Testing gap | 42% have little more than compile check | Validates Module 6 emphasis |
| MCP demand | 68% rank MCP as top training priority | Highest-leverage module for this cohort |

---

## 2. Cohort Profile & Calibration Insights

### 2.1 Pre-Programme Survey Summary

**Basis:** 19 pre-programme calibration responses (30-question survey)

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    COHORT PROFILE SNAPSHOT                               │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ROLES REPRESENTED                                              │   │
│  │                                                                │   │
│  │  Embedded Software Developer  ████████████████████  42% (8)   │   │
│  │  Firmware Developer           ██████████           21% (4)    │   │
│  │  Software Architect           ██████████           21% (4)    │   │
│  │  Test/Validation Engineer     ███                   5% (1)    │   │
│  │  Engineering Manager          ███                   5% (1)    │   │
│  │  Technical Lead               ███                   5% (1)    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  EXPERIENCE DISTRIBUTION                                        │   │
│  │                                                                │   │
│  │  12+ years     ██████████████████████████  47% (9)            │   │
│  │  8–12 years    ███████████                 21% (4)            │   │
│  │  5–8 years     ████████                    16% (3)            │   │
│  │  2–5 years     ██████                      11% (2)            │   │
│  │  <2 years      ███                          5% (1)            │   │
│  │                                                                │   │
│  │  → 68% are 8+ years experienced (senior audience)              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TECHNOLOGY FOOTPRINT                                           │   │
│  │                                                                │   │
│  │  Languages: C (8), C++ (8), C# (2), Python (1)                │   │
│  │  C/C++ Proficiency: 74% Advanced/Expert                        │   │
│  │  IDE: VS Code (8), Visual Studio (4), IAR (2), GCC (2)        │   │
│  │  Source Control: GitHub (79%), Bitbucket, Azure DevOps          │   │
│  │  GitHub Comfort: 84% Comfortable                               │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.2 Current AI Usage Maturity

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    AI TOOLING MATURITY                                   │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ADOPTION LEVEL                                                │   │
│  │                                                                │   │
│  │  Use it daily      ██████████████████████         32% (6)      │   │
│  │  Use it regularly  ██████████████████████████████ 53% (10)     │   │
│  │  Tried occasionally████████                        16% (3)      │   │
│  │                                                                │   │
│  │  → 84% already use AI coding assistant regularly/daily         │   │
│  │  → NOT a cold-start cohort — position as capability deepening  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CAPABILITIES TRIED                                             │   │
│  │                                                                │   │
│  │  Code generation           ██████████████████████████  11      │   │
│  │  Code explanation          ███████                       3      │   │
│  │  Code review               █████                         2      │   │
│  │  Unit-test generation      ███                           1      │   │
│  │  Requirements/spec gen     ███                           1      │   │
│  │  Architecture assistance   ███                           1      │   │
│  │                                                                │   │
│  │  → Usage heavily concentrated in code generation               │   │
│  │  → Higher-value capabilities barely explored                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONTEXT SUPPLY METHOD                                         │   │
│  │                                                                │   │
│  │  Ad-hoc prompting          ██████████████████████  10          │   │
│  │  Repo context              ████████                4          │   │
│  │  Documentation/specs       ██████                  3          │   │
│  │  Hand-picked files         ████                    2          │   │
│  │                                                                │   │
│  │  → Context is mostly ad-hoc prompting                          │   │
│  │  → Validates Module 3 (Context Engineering) as essential       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.3 Trust & Confidence in AI-Generated Code

| Confidence Level | Count | % |
|------------------|-------|---|
| Confident with small changes | 11 | 58% |
| Confident with complex changes (if validated) | 4 | 21% |
| Somewhat confident | 3 | 16% |
| Not confident | 1 | 5% |

**Key Insight:** Trust is **conditional and validation-dependent** — not blanket scepticism or blanket confidence. This is a healthy starting posture for a programme built around specification, testing and PR-quality gates.

### 2.4 Where Human Review is Non-Negotiable

| Area | Mentions | Priority Ranking |
|------|----------|------------------|
| Timing behaviour | 14 | #1 |
| Memory safety | 12 | #2 |
| Error handling | 10 | #3 |
| Hardware and driver boundaries | 9 | #4 |
| Concurrency | 7 | #5 |
| Resource constraints | 7 | #5 |
| Regression risk | 6 | #7 |
| API and interface compatibility | 6 | #7 |
| Security | 6 | #7 |
| Build and compile correctness | 5 | #10 |
| Test coverage | 4 | #11 |
| Coding standards | 4 | #11 |

**Implication for Module 9:** The review rubric should anchor on **timing behaviour, memory safety, and error handling** ahead of generic coding-standards checks.

### 2.5 Training Priorities (What the Cohort Wants)

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TRAINING PRIORITIES (Pick up to 3)                    │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  Learn MCP and agentic workflows    ██████████████████████████████ 68% │
│  Use tokens more efficiently        █████████████████              37% │
│  Improve engineering productivity   █████████████████              37% │
│  Improve code quality               ████████████                   26% │
│  Understand existing code faster    ██████████                     21% │
│  Improve testing                    ██████████                     21% │
│  Improve debugging                  ██████████                     21% │
│  Set up enterprise AI practices     ███████                        16% │
│  Learn SDD                          ███████                        16% │
│  Understand AI cost                 █████                          11% │
│  Write code faster                  █████                          11% │
│  Cut PR/review effort               █████                          11% │
│                                                                         │
│  → MCP is #1 priority by wide margin (68%)                              │
│  → Module 7 is highest-leverage module for this cohort                  │
│  → Protect Module 7 pacing — most at risk of compression                │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.6 Calibration-Driven Programme Implications

| Finding | Programme Response |
|---------|-------------------|
| Senior audience (68% at 8+ years) | Move quickly through embedded fundamentals; spend more time on AI technique |
| 84% already using Copilot | Module 2 can fast-path basics into agent mode, reusable instructions |
| 79% already spec-led | Module 4 formalises and tools an existing instinct |
| 42% have little automated validation | Module 6 (test strategy) is highest-value module for risk reduction |
| MCP is top want (68%) with near-zero exposure | Module 7 must be protected from time compression |
| PR-approval consensus on non-functional criteria | Module 9 rubric should score memory/pattern criteria as first-class gates |
| Fragmented change-impact analysis | Module 5 repository-archaeology and MCP-enabled repo analysis address this |
| Knowledge silos | AI-powered documentation and architecture explanation reduce bottleneck |

### 2.7 Calibration Scenario Insights

#### Scenario: First MCP Workflow to Automate

The dominant answer, converging independently across roughly two-thirds of respondents, was an **issue-to-validated-PR workflow**:

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    PREFERRED FIRST MCP WORKFLOW                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐             │
│  │  Pull   │───→│  Locate │───→│Implement│───→│ Run     │             │
│  │  Issue  │    │  Code & │    │  Fix    │    │ Build/  │             │
│  │         │    │  Docs   │    │         │    │ Test/   │             │
│  │         │    │         │    │         │    │ Static  │             │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘             │
│       │              │              │              │                     │
│       ▼              ▼              ▼              ▼                     │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐             │
│  │Generate │    │Evidence │    │  Human  │    │  Merge  │             │
│  │   PR    │───→│Collection│───→│ Review  │───→│         │             │
│  │         │    │         │    │         │    │         │             │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘             │
│                                                                         │
│  → Maps almost exactly to Module 7 hands-on exercise                   │
│  → Lab exercise should feel immediately relevant to cohort             │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

#### Scenario: Would You Approve an AI PR That Passes Tests But Uses More Memory?

**Response: Near-unanimous NO.**

Passing tests and meeting specification were consistently described as **necessary but not sufficient**. Respondents want non-functional criteria evaluated explicitly:
- Memory footprint
- Established design patterns
- Maintainability
- Justification required before any exception

**Implication for Module 9:** The PR quality rubric should score non-functional and pattern-conformance criteria as **first-class gates, not soft advisories**.

#### Scenario: 12-Month Vision

Three themes recur across nearly every open-text answer:
1. **Faster development and debug cycles** — less time on routine coding, AI absorbing repetitive work
2. **Higher, more provable code quality** — proactive defect detection, stronger automated test generation
3. **Better knowledge access** — AI-powered documentation reducing tribal-knowledge dependency

---

## 3. Why Honeywell Embedded Teams Need AI Champions

### 3.1 The AI Champion Role Defined

```
┌─────────────────────────────────────────────────────────────────────────┐
│                        AI CHAMPION ROLE MODEL                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│   ┌──────────────┐    ┌──────────────┐    ┌──────────────┐             │
│   │  TECHNICAL    │    │  PROCESS      │    │  GOVERNANCE   │             │
│   │  EXPERT       │    │  CATALYST     │    │  GUARDIAN     │             │
│   │              │    │              │    │              │             │
│   │ • Copilot    │    │ • SDD        │    │ • Token       │             │
│   │   mastery    │    │   champion   │    │   governance  │             │
│   │ • Prompt/    │    │ • Testing    │    │ • Quality     │             │
│   │   context    │    │   discipline │    │   gates       │             │
│   │   engineering│    │ • Workflow   │    │ • Security    │             │
│   │ • MCP        │    │   optimization│   │   compliance  │             │
│   │   integration│    │ • Brownfield │    │ • Cost        │             │
│   │              │    │   best       │    │   oversight   │             │
│   │              │    │   practices  │    │              │             │
│   └──────────────┘    └──────────────┘    └──────────────┘             │
│           │                  │                    │                      │
│           └──────────────────┼────────────────────┘                      │
│                              ▼                                          │
│                    ┌──────────────────┐                                 │
│                    │  AI CHAMPION     │                                 │
│                    │  (Combined Role) │                                 │
│                    └──────────────────┘                                 │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 3.2 The Three Pillars of AI Champion Responsibility

| Pillar | Description | Key Activities |
|--------|-------------|----------------|
| **Technical Excellence** | Master AI tools and embed them into daily engineering workflows | Copilot proficiency, prompt engineering, context engineering, MCP integration |
| **Process Catalyst** | Drive adoption of specification-driven development and testing discipline | SDD champion, test strategy, workflow optimization, brownfield safety |
| **Governance Guardian** | Ensure responsible, measurable, and secure AI usage | Token oversight, quality gates, compliance monitoring, ROI tracking |

### 3.3 Why This Matters for Honeywell

Honeywell's embedded engineering teams operate in a **safety-critical, highly regulated environment**. Unlike general software development, embedded systems have:

- **Hardware-software boundaries** that constrain AI-generated code
- **Real-time requirements** where AI suggestions must respect timing constraints
- **Resource limitations** (memory, CPU, power) that AI must understand
- **Regulatory compliance** (DO-178C, IEC 61508, etc.) that governs all changes
- **Brownfield complexity** where most work enhances existing firmware, not greenfield

An AI Champion bridges the gap between **AI potential** and **embedded engineering reality**.

---

## 3. The Incremental Engineering Journey

### 3.1 Programme Structure Overview

The programme follows an **incremental engineering journey** rather than a collection of AI tool topics:

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    INCREMENTAL ENGINEERING JOURNEY                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐    │
│  │ Module  │  │ Module  │  │ Module  │  │ Module  │  │ Module  │    │
│  │   01    │→ │   02    │→ │   03    │→ │   04    │→ │   05    │    │
│  │         │  │         │  │         │  │         │  │         │    │
│  │Enterprise│  │Copilot  │  │Prompt/  │  │  SDD    │  │Greenfld/│    │
│  │Context  │  │Features │  │Context  │  │         │  │Brownfld │    │
│  └─────────┘  └─────────┘  └─────────┘  └─────────┘  └─────────┘    │
│       │            │            │            │            │              │
│       ▼            ▼            ▼            ▼            ▼              │
│  ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐    │
│  │ Module  │  │ Module  │  │ Module  │  │ Module  │  │ Module  │    │
│  │   06    │→ │   07    │→ │   08    │→ │   09    │→ │   10    │    │
│  │         │  │         │  │         │  │         │  │         │    │
│  │Testing  │  │  MCP    │  │Atlassian│  │PR/QA    │  │Agent    │    │
│  │Strategy │  │         │  │Rovo     │  │LLM-Judge│  │Prism    │    │
│  │         │  │         │  │Studio   │  │         │  │         │    │
│  └─────────┘  └─────────┘  └─────────┘  └─────────┘  └─────────┘    │
│       │            │            │            │            │              │
│       ▼            ▼            ▼            ▼            ▼              │
│  ┌─────────┐  ┌─────────┐                                              │
│  │ Module  │  │ Module  │                                              │
│  │   11    │→ │   12    │                                              │
│  │         │  │         │                                              │
│  │ROI/Token│  │Capstone │                                              │
│  │Economics│  │& Roadmap│                                              │
│  └─────────┘  └─────────┘                                              │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 3.2 The Incremental Build Philosophy

Each module builds upon the previous one:

| Module | Focus | Builds On |
|--------|-------|-----------|
| **Module 01** | Establish WHY (enterprise context, pain points, metrics) | — |
| **Module 02** | Learn WHAT tools are available (Copilot capabilities) | Module 01 |
| **Module 03** | Learn HOW to use them effectively (prompt/context engineering) | Module 02 |
| **Module 04** | Apply structured approach (SDD for specifications) | Module 03 |
| **Module 05** | Build greenfield features + brownfield enhancement (complete SDLC) | Module 04 |
| **Module 06** | Validate with testing (test strategy, mocks/stubs, regression) | Module 05 |
| **Module 07** | Extend with MCP (tool integration, reusable skills) | Module 06 |
| **Module 08** | Studio-style workflows for business/program roles (Atlassian Rovo Studio) | Module 07 |
| **Module 09** | Automate quality (PR/LLM-as-Judge) | Module 08 |
| **Module 10** | Monitor and observe (Agent Prism) | Module 09 |
| **Module 11** | Measure value (ROI, token economics, governance) | Module 10 |
| **Module 12** | Demonstrate adoption (capstone, 90-day roadmap) | Module 11 |

---

## 4. Enterprise Context: Current State vs Target State

### 4.1 Current State: The Pain Points

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CURRENT STATE: EMBEDDED ENGINEERING PAIN POINTS       │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  FEATURE IMPLEMENTATION                                        │   │
│  │  • Manual code analysis of C/C++ repositories                   │   │
│  │  • Repetitive firmware changes across similar modules            │   │
│  │  • Inconsistent code generation quality                         │   │
│  │  • Time-consuming interface/header navigation                    │   │
│  │  • No specification traceability                                │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TESTING & VALIDATION                                          │   │
│  │  • Manual test creation for embedded features                   │   │
│  │  • Incomplete boundary/negative testing                         │   │
│  │  • Missing mocks/stubs for hardware-dependent code              │   │
│  │  • Regression testing overhead                                  │   │
│  │  • No specification-to-test traceability                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CODE REVIEW & PR PROCESS                                      │   │
│  │  • Latency in PR review cycles                                  │   │
│  │  • Inconsistent review quality                                  │   │
│  │  • Missing coding standards enforcement                         │   │
│  │  • No automated quality gates                                   │   │
│  │  • Manual regression risk assessment                            │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  AI USAGE BLIND SPOTS                                          │   │
│  │  • No visibility into token consumption                         │   │
│  │  • Untracked AI-assisted code changes                           │   │
│  │  • No quality measurement of AI output                          │   │
│  │  • Cost leakage without governance                              │   │
│  │  • Inconsistent AI adoption across teams                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 4.2 Target State: The Vision

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TARGET STATE: AI-ENABLED EMBEDDED ENGINEERING         │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  SPECIFICATION-DRIVEN DEVELOPMENT                              │   │
│  │  ✓ Structured specifications with acceptance criteria          │   │
│  │  ✓ Requirements → Plan → Tasks → Implementation traceability   │   │
│  │  ✓ Context-aware AI assistance                                 │   │
│  │  ✓ Repository-aware code generation                            │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  AUTOMATED QUALITY GATES                                       │   │
│  │  ✓ LLM-as-Judge PR review                                      │   │
│  │  ✓ Specification compliance checking                            │   │
│  │  ✓ Coding standards enforcement                                │   │
│  │  ✓ Test evidence collection                                    │   │
│  │  ✓ Regression risk assessment                                  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  GOVERNED AI USAGE                                             │   │
│  │  ✓ Token consumption monitoring                                 │   │
│  │  ✓ Cost tracking per feature/task                               │   │
│  │  ✓ Quality measurement of AI output                            │   │
│  │  ✓ Adoption tracking across teams                              │   │
│  │  ✓ ROI visibility                                              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  MCP-ENABLED TOOL INTEGRATION                                  │   │
│  │  ✓ Approved tool connections via MCP                            │   │
│  │  ✓ Build/test automation                                       │   │
│  │  ✓ Documentation generation                                    │   │
│  │  ✓ Issue system integration                                    │   │
│  │  ✓ Governed permissions and approvals                          │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STUDIO-STYLE WORKFLOWS (Atlassian Rovo Studio)                 │   │
│  │  ✓ Business/program roles author governed workflows            │   │
│  │  ✓ Agents grounded on Jira and Confluence content              │   │
│  │  ✓ Triggers, actions, approval flows                           │   │
│  │  ✓ Human-in-the-loop checkpoints                               │   │
│  │  ✓ Technical owner handoff without governance bypass           │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 4.3 Transformation Flow

```
CURRENT STATE                                    TARGET STATE
    │                                                  │
    ▼                                                  ▼
┌──────────────────┐    TRANSFORMATION    ┌──────────────────┐
│ Manual, slow,    │ ──────────────────→  │ Automated, fast, │
│ inconsistent,    │                      │ consistent,      │
│ no visibility    │                      │ governed,        │
│                  │                      │ measurable       │
└──────────────────┘                      └──────────────────┘
         │                                        │
         │   ┌────────────────────────────────┐   │
         └──→│  AI CHAMPION MEDIATED ADOPTION │←──┘
             │                                │
             │  • Enterprise context first    │
             │  • Incremental skill building  │
             │  • Governance and measurement  │
             │  • Quality gates at every step │
             └────────────────────────────────┘
```

---

## 5. Role-Based Expectations

### 5.1 Role Matrix for AI Champions Programme

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    ROLE-BASED EXPECTATIONS                               │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌──────────────────┐  ┌──────────────────┐  ┌──────────────────┐     │
│  │  EMBEDDED         │  │  ARCHITECTS      │  │  TESTERS          │     │
│  │  DEVELOPERS       │  │                  │  │                   │     │
│  │                  │  │                  │  │                   │     │
│  │ • Copilot        │  │ • Context        │  │ • Test strategy   │     │
│  │   mastery        │  │   engineering    │  │   from SDD        │     │
│  │ • Prompt/        │  │ • Architecture   │  │ • Mocks/stubs/   │     │
│  │   context        │  │   analysis       │  │   fakes           │     │
│  │   engineering    │  │ • Design         │  │ • Validation      │     │
│  │ • C/C++          │  │   patterns       │  │   automation      │     │
│  │   implementation │  │ • Integration    │  │ • Regression      │     │
│  │ • SDD adherence  │  │   boundaries     │  │   protection      │     │
│  └──────────────────┘  └──────────────────┘  └──────────────────┘     │
│                                                                         │
│  ┌──────────────────┐  ┌──────────────────┐  ┌──────────────────┐     │
│  │  DEVOPS / SRE    │  │  ENGINEERING     │  │  PROGRAM/PRODUCT │     │
│  │                  │  │  LEADS           │  │  ROLES           │     │
│  │                  │  │                  │  │                   │     │
│  │ • CI/CD          │  │ • Team adoption  │  │ • ROI measurement│     │
│  │   integration    │  │ • Quality gates  │  │ • Adoption       │     │
│  │ • Build system   │  │ • Governance     │  │   tracking       │     │
│  │   awareness      │  │   oversight      │  │ • Governance     │     │
│  │ • Static         │  │ • Workflow       │  │   reporting      │     │
│  │   analysis       │  │   optimization   │  │ • Business case  │     │
│  │ • MCP tooling    │  │ • ROI reporting  │  │   justification  │     │
│  └──────────────────┘  └──────────────────┘  └──────────────────┘     │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 5.2 Foundation vs Technical Deep-Dive

| Track | Target Roles | Focus |
|-------|--------------|-------|
| **Common Foundation** | Architects, Developers, Testers, DevOps, SRE, Engineering Leads, Program/Product | Enterprise context, Copilot basics, SDD, testing, MCP, Agent Prism |
| **Technical Deep-Dive** | Embedded/Firmware Developers, Architects, Testers, DevOps, SRE, Engineering Leads | C/C++ implementation, brownfield safety, embedded test strategy, token economics |

---

## 6. Business and Engineering Risks of Unmanaged AI Usage

### 6.1 Risk Categories

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    RISKS OF UNMANAGED AI USAGE                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TECHNICAL RISKS                                               │   │
│  │                                                                │   │
│  │  ┌────────────┐  ┌────────────┐  ┌────────────┐              │   │
│  │  │  CODE       │  │  SECURITY  │  │  REGRESSION│              │   │
│  │  │  QUALITY    │  │            │  │            │              │   │
│  │  │            │  │  • Secrets │  │  • State   │              │   │
│  │  │  • Defects │  │    exposure│  │    behavior│              │   │
│  │  │  • Standards│ │  • Vuls    │  │    changes │              │   │
│  │  │    violation│ │  • Supply  │  │  • Interface│             │   │
│  │  │  • Architecture││  chain    │  │    breaks  │              │   │
│  │  │    mismatch│  │  • Input   │  │  • Timing  │              │   │
│  │  │            │  │    validatn│  │    regressn│              │   │
│  │  └────────────┘  └────────────┘  └────────────┘              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PROCESS RISKS                                                 │   │
│  │                                                                │   │
│  │  ┌────────────┐  ┌────────────┐  ┌────────────┐              │   │
│  │  │  TOKEN      │  │  CONTEXT   │  │  QUALITY    │              │   │
│  │  │  LEAKAGE    │  │  INFLATION │  │  DEGRADATION│              │   │
│  │  │            │  │            │  │             │              │   │
│  │  │  • Excess  │  │  • Too much│  │  • Lower   │              │   │
│  │  │    spending│  │    context │  │    output   │              │   │
│  │  │  • No ROI  │  │  • Token   │  │  • More    │              │   │
│  │  │    visibility│ │    waste   │  │    iteratns│              │   │
│  │  │  • Budget  │  │  • Reduced │  │  • Human   │              │   │
│  │  │    overrun │  │    quality │  │    rework  │              │   │
│  │  └────────────┘  └────────────┘  └────────────┘              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  GOVERNANCE RISKS                                              │   │
│  │                                                                │   │
│  │  ┌────────────┐  ┌────────────┐  ┌────────────┐              │   │
│  │  │  COMPLIANCE │  │  AUDIT     │  │  IP        │              │   │
│  │  │  VIOLATION  │  │  TRAIL     │  │  EXPOSURE  │              │   │
│  │  │            │  │  GAP       │  │            │              │   │
│  │  │  • Safety  │  │  • No trace│  │  • Code    │              │   │
│  │  │    standards│ │    of AI   │  │    leakage │              │   │
│  │  │  • Regulatry│ │  • Cannot  │  │  • Training│              │   │
│  │  │    non-comp│  │    reproduce│ │    data    │              │   │
│  │  │  • Audit   │  │  • No      │  │  • Competitr│             │   │
│  │  │    failures│  │    accountabl│ │    intel   │              │   │
│  │  └────────────┘  └────────────┘  └────────────┘              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 6.2 The Cost of Unmanaged AI

| Risk Category | Potential Impact | Mitigation via AI Champions |
|---------------|------------------|----------------------------|
| **Code Quality Defects** | Safety-critical failures, field recalls | SDD, specification compliance, quality gates |
| **Token Leakage** | $10K-$100K+ annual waste per team | Token monitoring, context discipline, ROI tracking |
| **Context Inflation** | 50-70% reduced AI output quality | Task-scoped context, context engineering |
| **Security Vulnerabilities** | Data breaches, supply chain attacks | Approved tools only, MCP governance, security review |
| **Compliance Violations** | Regulatory fines, audit failures | Audit trail, specification traceability, LLM-as-Judge |

---

## 7. Embedded Software Lifecycle Context

### 7.1 The Embedded SDLC with AI Integration Points

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EMBEDDED SDLC WITH AI INTEGRATION                     │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐             │
│  │REQUIRE- │───→│DESIGN & │───→│IMPLEMENT│───→│  TEST   │             │
│  │MENTS    │    │  SPEC   │    │         │    │         │             │
│  │         │    │         │    │         │    │         │             │
│  │ AI:     │    │ AI:     │    │ AI:     │    │ AI:     │             │
│  │ • Analyze│   │ • SDD   │    │ • Copilot│   │ • Test  │             │
│  │   reqs  │    │ • Context│   │ • Agent  │   │   genern│             │
│  │ • Frame  │    │   engnr │    │   mode   │    │ • Mock  │             │
│  │   tasks │    │ • Arch  │    │ • Code   │    │   genern│             │
│  │         │    │   analysis│  │   explain│    │ • Validatn│            │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘             │
│       │              │              │              │                     │
│       ▼              ▼              ▼              ▼                     │
│  ┌─────────┐    ┌─────────┐    ┌─────────┐    ┌─────────┐             │
│  │  BUILD  │───→│PR REVIEW│───→│INTEGRATE│───→│RELEASE  │             │
│  │         │    │         │    │         │    │         │             │
│  │ AI:     │    │ AI:     │    │ AI:     │    │ AI:     │             │
│  │ • Build │    │ • LLM-  │    │ • MCP   │    │ • Doc   │             │
│  │   validatn│ │   Judge │    │   tools │    │   genern│             │
│  │ • Static│    │ • Coding│    │ • CI/CD │    │ • Changelog│           │
│  │   analys│    │   standrds│  │   integrn│   │   genern│             │
│  │         │    │ • Test  │    │         │    │         │             │
│  │         │    │   evidence│   │         │    │         │             │
│  └─────────┘    └─────────┘    └─────────┘    └─────────┘             │
│                                                                         │
│  ═══════════════════════════════════════════════════════════════════   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  OBSERVABILITY & MONITORING (Agent Prism)                       │   │
│  │                                                                │   │
│  │  • Traces and replay          • Token usage tracking           │   │
│  │  • Quality signals            • Cost monitoring                │   │
│  │  • Failure patterns           • Adoption metrics               │   │
│  │  • Prompt/output drift        • ROI calculation                │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 7.2 Greenfield vs Brownfield: Two Engineering Flavors

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    GREENFIELD vs BROWNFIELD                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌────────────────────────────┐  ┌────────────────────────────┐       │
│  │  GREENFIELD                │  │  BROWNFIELD                 │       │
│  │  (Build from Spec)         │  │  (Enhance Existing)         │       │
│  │                            │  │                             │       │
│  │  • New feature from SDD    │  │  • Understand existing      │       │
│  │  • No legacy constraints   │  │    architecture              │       │
│  │  • Clean interfaces        │  │  • Respect coding standards │       │
│  │  • Modern patterns         │  │  • Minimal change strategy  │       │
│  │  • Full test coverage      │  │  • Backward compatibility   │       │
│  │                            │  │  • Regression protection    │       │
│  │  Modules: 04, 05           │  │  Modules: 06                │       │
│  │                            │  │                             │       │
│  │  ┌──────────────────┐      │  │  ┌──────────────────┐       │       │
│  │  │ SDD → Spec →     │      │  │  │ Repo Archaeology │       │       │
│  │  │ Plan → Tasks →   │      │  │  │ → Architecture   │       │       │
│  │  │ Implement → Test │      │  │  │ Analysis → Change│       │       │
│  │  └──────────────────┘      │  │  │ Plan → Implement │       │       │
│  │                            │  │  │ → Validate       │       │       │
│  │                            │  │  └──────────────────┘       │       │
│  └────────────────────────────┘  └────────────────────────────┘       │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 8. Agent Prism: The Monitoring Lens

### 8.1 What is Agent Prism?

Agent Prism is positioned as the **live practice platform for monitoring and observability**. It provides visibility into:

- **Agent behaviour** — how AI agents interact with code
- **Traces** — complete execution history
- **Failures** — error patterns and root causes
- **Token usage** — consumption per task/feature
- **Cost leakage** — where money is being wasted
- **Quality signals** — output quality metrics
- **Control and operational adoption** — usage patterns across teams

### 8.2 Agent Prism Architecture

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    AGENT PRISM ARCHITECTURE                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │                    AGENT LAYER                                   │   │
│  │                                                                │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐     │   │
│  │  │ Copilot  │  │ MCP      │  │ Custom   │  │ LLM-as- │     │   │
│  │  │ Agent    │  │ Tools    │  │ Agents   │  │ Judge    │     │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │                    TELEMETRY LAYER                               │   │
│  │                                                                │   │
│  │  • Traces & Spans          • Token Counts                      │   │
│  │  • Prompt/Output Samples   • Cost Attribution                   │   │
│  │  • Error Events            • Quality Scores                     │   │
│  │  • Timing Metrics          • Context Size                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │                    ANALYTICS LAYER                               │   │
│  │                                                                │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐     │   │
│  │  │ Cost     │  │ Quality  │  │ Adoption │  │ ROI      │     │   │
│  │  │ Dashboard│  │ Dashboard│  │ Tracker  │  │ Calculator│    │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │                    GOVERNANCE LAYER                              │   │
│  │                                                                │   │
│  │  • Threshold Alerts          • Audit Trail                     │   │
│  │  • Policy Enforcement        • Leadership Reporting            │   │
│  │  • Approval Workflows        • Compliance Checks               │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 8.3 Why Agent Prism Matters for Embedded Engineering

| Concern | Agent Prism Solution |
|---------|---------------------|
| **Token Cost Visibility** | Track consumption per feature, per developer, per team |
| **Quality Measurement** | Compare AI output against specification compliance |
| **Failure Analysis** | Identify patterns in AI-generated code defects |
| **Adoption Tracking** | See which teams are using AI effectively |
| **ROI Demonstration** | Quantify time saved vs AI cost invested |
| **Compliance Audit** | Maintain complete trace of AI-assisted changes |

---

## 9. Pain Points in Embedded Software Delivery

### 9.1 Calibration Data: Current Pain Points (from Survey)

The calibration survey revealed specific, data-backed pain points across the cohort:

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CALIBRATION-BACKED PAIN POINTS                        │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PAIN POINT #1: FRAGMENTED CHANGE-IMPACT ANALYSIS              │   │
│  │                                                                │   │
│  │  Current methods are fragmented across manual techniques:      │   │
│  │  • Reading the code (4 respondents)                            │   │
│  │  • Tracing call hierarchy (4)                                  │   │
│  │  • Dependency analysis (3)                                     │   │
│  │  • Build/config analysis (2)                                   │   │
│  │  • Tests (2)                                                   │   │
│  │  • No set approach (2)                                         │   │
│  │                                                                │   │
│  │  → Directly justifies Module 5 repository-archaeology content │   │
│  │  → Justifies MCP-enabled repository analysis in Module 7       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PAIN POINT #2: WEAK AUTOMATED VALIDATION                      │   │
│  │                                                                │   │
│  │  Pipeline maturity:                                            │   │
│  │  • Build/compile only: 4 respondents (21%)                     │   │
│  │  • Very little automated: 4 respondents (21%)                  │   │
│  │  • Together: 42% have little more than compile check           │   │
│  │                                                                │   │
│  │  Only 4 respondents (21%) have mature pipeline                 │   │
│  │  (AI-assisted quality gates or full automated pipeline)        │   │
│  │                                                                │   │
│  │  → Most significant readiness gap in the cohort                │   │
│  │  → Validates Module 6 as highest-value for risk reduction      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PAIN POINT #3: AD-HOC CONTEXT (NOT STRUCTURED)                │   │
│  │                                                                │   │
│  │  Context supply method:                                        │   │
│  │  • Ad-hoc prompting: 10 respondents (53%)                      │   │
│  │  • Repo context: 4 (21%)                                       │   │
│  │  • Documentation/specs: 3 (16%)                                │   │
│  │  • Hand-picked files: 2 (11%)                                  │   │
│  │                                                                │   │
│  │  → Direct driver of token inefficiency and inconsistent output │   │
│  │  → Validates Module 3 (Context Engineering) as essential       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PAIN POINT #4: MANUAL REGRESSION DEBUGGING                    │   │
│  │                                                                │   │
│  │  Scenario: Diagnosing AI-introduced behavioural regression     │   │
│  │  → Great majority described identical manual workflow:         │   │
│  │    reproduce → diff → log/debug → isolate → fix → regression  │   │
│  │  → No one described using AI-native tooling (observability)    │   │
│  │                                                                │   │
│  │  → Exactly the gap Module 10 (Agent Prism) closes              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PAIN POINT #5: LOW MCP EXPOSURE DESPITE TOP PRIORITY          │   │
│  │                                                                │   │
│  │  • MCP ranked #1 training priority (68%)                       │   │
│  │  • Near-zero current MCP exposure                               │   │
│  │  • Several respondents: "not sure", "need to explore",         │   │
│  │    "hardly use, may be due to less awareness"                  │   │
│  │                                                                │   │
│  │  → Module 7 is single highest-leverage module                  │   │
│  │  → Must be protected from time compression                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PAIN POINT #6: KNOWLEDGE SILOS                                │   │
│  │                                                                │   │
│  │  Multiple open-text answers independently raised:              │   │
│  │  • Tribal knowledge spread across code, Jira, individuals     │   │
│  │  • Documentation scattered across systems                     │   │
│  │  • Bottleneck on few experienced individuals                  │   │
│  │                                                                │   │
│  │  → AI-powered documentation and architecture explanation      │   │
│  │    reduce dependency on specific individuals                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 9.2 Workshop: Identify Current Pain Points

**Duration:** 30 minutes  
**Format:** Group exercise using pain-point canvas

#### Pain Point Categories

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EMBEDDED ENGINEERING PAIN POINTS                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  FEATURE IMPLEMENTATION                                        │   │
│  │                                                                │   │
│  │  □ Manual analysis of C/C++ codebases                         │   │
│  │  □ Repetitive firmware change patterns                         │   │
│  │  □ Inconsistent code generation                                │   │
│  │  □ Time-consuming header/interface navigation                  │   │
│  │  □ No specification-to-code traceability                       │   │
│  │  □ Difficulty understanding HAL boundaries                     │   │
│  │  □ State machine implementation overhead                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  BUILD & TEST                                                  │   │
│  │                                                                │   │
│  │  □ Slow build/test cycles                                      │   │
│  │  □ Manual test case creation                                   │   │
│  │  □ Missing mocks for hardware interfaces                       │   │
│  │  □ Incomplete boundary testing                                 │   │
│  │  □ Regression test overhead                                    │   │
│  │  □ Static analysis noise                                       │   │
│  │  □ Build system complexity                                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CODE REVIEW & PR PROCESS                                      │   │
│  │                                                                │   │
│  │  □ Review latency (days)                                       │   │
│  │  □ Inconsistent review quality                                 │   │
│  │  □ Missing coding standards enforcement                        │   │
│  │  □ No automated quality checks                                 │   │
│  │  □ Manual regression risk assessment                           │   │
│  │  □ Documentation gaps                                          │   │
│  │  □ Knowledge silos across reviewers                            │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  AI USAGE (Current)                                            │   │
│  │                                                                │   │
│  │  □ Ad-hoc AI usage without governance                          │   │
│  │  □ No visibility into token consumption                        │   │
│  │  □ Untracked AI-assisted changes                               │   │
│  │  □ Quality inconsistency of AI output                          │   │
│  │  □ Cost leakage without measurement                            │   │
│  │  □ No team adoption metrics                                    │   │
│  │  □ Fear of AI-generated defects                                │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 9.2 Representative Use Cases

| Use Case | Greenfield/Brownfield | Key Challenge |
|----------|----------------------|---------------|
| New driver implementation | Greenfield | Interface design, HAL boundaries |
| State machine enhancement | Brownfield | Existing behavior preservation |
| Configuration update | Brownfield | Build system dependencies |
| Diagnostic feature addition | Greenfield | Testing without hardware |
| Protocol handler update | Brownfield | Interface contract maintenance |
| Memory optimization | Brownfield | Resource constraint compliance |

---

## 10. Success Metrics Framework

### 10.1 Metrics Categories

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    SUCCESS METRICS FRAMEWORK                             │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PRODUCTIVITY METRICS                                          │   │
│  │                                                                │   │
│  │  • Feature implementation cycle time                           │   │
│  │  • Code generation speed                                       │   │
│  │  • PR review turnaround time                                   │   │
│  │  • Test creation time                                          │   │
│  │  • Defect resolution time                                      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  QUALITY METRICS                                               │   │
│  │                                                                │   │
│  │  • Specification compliance rate                               │   │
│  │  • Coding standards adherence                                  │   │
│  │  • Test coverage (unit, integration)                           │   │
│  │  • Regression defect rate                                      │   │
│  │  • PR review pass rate                                         │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  COST METRICS                                                  │   │
│  │                                                                │   │
│  │  • Token consumption per feature                               │   │
│  │  • AI cost per accepted output                                 │   │
│  │  • Cost per PR review                                          │   │
│  │  • Cost per test suite                                         │   │
│  │  • Total AI spend vs budget                                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ADOPTION METRICS                                              │   │
│  │                                                                │   │
│  │  • Active AI users per team                                    │   │
│  │  • AI-assisted PRs percentage                                  │   │
│  │  • Reusable skill usage                                       │   │
│  │  • MCP tool integration rate                                   │   │
│  │  • Training completion rate                                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 10.2 Before/After Comparison Template

| Metric | Before AI Champions | After AI Champions | Target Improvement |
|--------|---------------------|-------------------|-------------------|
| Feature cycle time | ___ days | ___ days | 30-50% reduction |
| PR review time | ___ hours | ___ hours | 40-60% reduction |
| Test creation time | ___ hours | ___ hours | 50-70% reduction |
| Defect escape rate | ___% | ___% | 20-40% reduction |
| Token spend per feature | $___ | $___ | Optimized by 30%+ |

---

## 11. Architecture Diagrams and Visual Flow

### 11.1 Enterprise AI Adoption Architecture

```
┌─────────────────────────────────────────────────────────────────────────┐
│                ENTERPRISE AI ADOPTION ARCHITECTURE                       │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  LEADERSHIP & GOVERNANCE                                       │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐     │   │
│  │  │ Strategy │  │ Budget   │  │ Policy   │  │ Metrics  │     │   │
│  │  │ Alignment│  │ Approval │  │ Definition│  │ Review   │     │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  AI CHAMPION LAYER                                             │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐     │   │
│  │  │ Technical│  │ Process  │  │Governance│  │ Adoption │     │   │
│  │  │ Excellence│ │ Catalyst │  │ Guardian │  │ Driver   │     │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ENGINEERING TEAMS                                             │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐     │   │
│  │  │Developers│  │ Testers  │  │Architects│  │  DevOps  │     │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TOOL & PLATFORM LAYER                                         │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐     │   │
│  │  │ GitHub   │  │  MCP     │  │  Agent   │  │  CI/CD   │     │   │
│  │  │ Copilot  │  │  Tools   │  │  Prism   │  │ Pipeline │     │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 11.2 Context Engineering Flow for Embedded Systems

```
┌─────────────────────────────────────────────────────────────────────────┐
│                CONTEXT ENGINEERING FLOW                                   │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  1. TASK SCOPING                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ What is the specific embedded engineering task?         │  │   │
│  │  │ What are the constraints? (timing, memory, interface)  │  │   │
│  │  │ What is the expected output?                            │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  2. CONTEXT SELECTION                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Source files (C/C++)         Headers & interfaces       │  │   │
│  │  │ Build files (Make/CMake)     Configuration files        │  │   │
│  │  │ HAL boundaries               Design documents           │  │   │
│  │  │ Coding standards             Issue history              │  │   │
│  │  │ Existing tests              State machine definitions   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  3. CONTEXT LAYERING & COMPRESSION                              │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Layer 1: Core task context (essential)                   │  │   │
│  │  │ Layer 2: Related interfaces (important)                  │  │   │
│  │  │ Layer 3: Architecture context (helpful)                  │  │   │
│  │  │ Layer 4: Historical context (optional)                   │  │   │
│  │  │                                                         │  │   │
│  │  │ Compression: Token-aware selection to avoid inflation    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  4. CONTEXT BOUNDARIES                                         │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Do NOT include entire repository                       │  │   │
│  │  │ • Do NOT include unrelated modules                       │  │   │
│  │  │ • DO include relevant interfaces only                    │  │   │
│  │  │ • DO include build constraints                           │  │   │
│  │  │ • DO include coding standards                            │  │   │
│  │  │ • Monitor token usage continuously                       │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 11.3 Prompt-Only vs Spec-Driven Development Comparison

```
┌─────────────────────────────────────────────────────────────────────────┐
│           PROMPT-ONLY vs SPEC-DRIVEN DEVELOPMENT                         │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌────────────────────────────┐  ┌────────────────────────────┐       │
│  │  PROMPT-ONLY               │  │  SPEC-DRIVEN (SDD)         │       │
│  │                            │  │                             │       │
│  │  User → "Write a driver"   │  │  User → Specification      │       │
│  │         │                  │  │         │                  │       │
│  │         ▼                  │  │         ▼                  │       │
│  │  AI → Generic code         │  │  SDD → Structured Spec     │       │
│  │         │                  │  │         │                  │       │
│  │         ▼                  │  │         ▼                  │       │
│  │  User → "Add error        │  │  Plan → Tasks              │       │
│  │          handling"         │  │         │                  │       │
│  │         │                  │  │         ▼                  │       │
│  │         ▼                  │  │  AI → Spec-compliant code  │       │
│  │  AI → Partial fix          │  │         │                  │       │
│  │         │                  │  │         ▼                  │       │
│  │         ▼                  │  │  Tests → From spec         │       │
│  │  User → "Also handle      │  │         │                  │       │
│  │          timeout"          │  │         ▼                  │       │
│  │         │                  │  │  Validation → Against spec │       │
│  │         ▼                  │  │                             │       │
│  │  ... (many iterations)     │  │  Result: Traceable,        │       │
│  │                            │  │  complete, validated       │       │
│  │  Result: Iterative,        │  │                             │       │
│  │  incomplete, unvalidated   │  │                             │       │
│  └────────────────────────────┘  └────────────────────────────┘       │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  COMPARISON METRICS                                            │   │
│  │                                                                │   │
│  │  Metric              │ Prompt-Only │ Spec-Driven │ Improvement │   │
│  │  ────────────────────────────────────────────────────────────  │   │
│  │  Iterations          │   8-15      │   2-4       │  60-75%     │   │
│  │  Token Usage         │   High      │   Optimized │  30-50%     │   │
│  │  Output Quality      │   Variable  │   Consistent│  High       │   │
│  │  Spec Compliance     │   None      │   Full      │  100%       │   │
│  │  Test Coverage       │   Ad-hoc    │   From spec │  Complete   │   │
│  │  Review Effort       │   High      │   Low       │  50-70%     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 12. Workshop Canvas and Exercises

### 12.1 Current-State Workflow Canvas

**Exercise:** Map your team's current embedded software delivery workflow

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CURRENT-STATE WORKFLOW CANVAS                         │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 1: REQUIREMENTS                                          │   │
│  │  Current process: _________________________________________    │   │
│  │  Pain points: ____________________________________________    │   │
│  │  Time spent: ______________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 2: DESIGN                                                │   │
│  │  Current process: _________________________________________    │   │
│  │  Pain points: ____________________________________________    │   │
│  │  Time spent: ______________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 3: IMPLEMENTATION                                        │   │
│  │  Current process: _________________________________________    │   │
│  │  Pain points: ____________________________________________    │   │
│  │  Time spent: ______________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 4: TESTING                                               │   │
│  │  Current process: _________________________________________    │   │
│  │  Pain points: ____________________________________________    │   │
│  │  Time spent: ______________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 5: REVIEW & INTEGRATION                                  │   │
│  │  Current process: _________________________________________    │   │
│  │  Pain points: ____________________________________________    │   │
│  │  Time spent: ______________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 12.2 Target-State Workflow Canvas

**Exercise:** Design your ideal AI-enabled workflow

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TARGET-STATE WORKFLOW CANVAS                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 1: SPECIFICATION (SDD)                                   │   │
│  │  Target process: _________________________________________    │   │
│  │  AI role: ________________________________________________    │   │
│  │  Expected time: __________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 2: CONTEXT ENGINEERING                                   │   │
│  │  Target process: _________________________________________    │   │
│  │  AI role: ________________________________________________    │   │
│  │  Expected time: __________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 3: AI-ASSISTED IMPLEMENTATION                            │   │
│  │  Target process: _________________________________________    │   │
│  │  AI role: ________________________________________________    │   │
│  │  Expected time: __________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 4: AUTOMATED TESTING                                     │   │
│  │  Target process: _________________________________________    │   │
│  │  AI role: ________________________________________________    │   │
│  │  Expected time: __________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 5: LLM-as-JUDGE PR REVIEW                               │   │
│  │  Target process: _________________________________________    │   │
│  │  AI role: ________________________________________________    │   │
│  │  Expected time: __________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STEP 6: OBSERVABILITY & METRICS                               │   │
│  │  Agent Prism monitoring: _________________________________    │   │
│  │  Metrics tracked: ________________________________________    │   │
│  │  ROI measurement: ________________________________________    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 12.3 Success Metrics Worksheet

**Exercise:** Define measurable success criteria for your team

| Category | Metric | Current Baseline | 30-Day Target | 90-Day Target | Measurement Method |
|----------|--------|------------------|---------------|---------------|-------------------|
| **Productivity** | Feature cycle time | | | | |
| **Productivity** | PR review time | | | | |
| **Quality** | Spec compliance | | | | |
| **Quality** | Test coverage | | | | |
| **Cost** | Token spend/feature | | | | |
| **Cost** | AI cost/output | | | | |
| **Adoption** | Active AI users | | | | |
| **Adoption** | AI-assisted PRs % | | | | |

---

## 13. Reference Links and Resources

### 13.1 GitHub Copilot Enterprise

| Resource | URL | Description |
|----------|-----|-------------|
| GitHub Copilot Documentation | https://docs.github.com/en/copilot | Official Copilot documentation |
| Copilot Enterprise | https://docs.github.com/en/copilot/using-github-copilot/using-copilot-in-your-ide | Enterprise features and setup |
| Copilot Best Practices | https://docs.github.com/en/copilot/using-github-copilot/best-practices-for-using-copilot | Best practices guide |
| Copilot for Business | https://business.github.com/copilot | Enterprise plan details |

### 13.2 Specification-Driven Development (SDD)

| Resource | URL | Description |
|----------|-----|-------------|
| GitHub Spec Kit | https://github.com/github/spec-kit | Official SDD toolkit |
| OpenSpec Pattern | https://github.com/openspec-dev/openspec | Open specification pattern |
| SDD Documentation | https://docs.github.com/en/copilot/using-github-copilot/writing-better-prompts | Writing effective specs |

### 13.3 MCP (Model Context Protocol)

| Resource | URL | Description |
|----------|-----|-------------|
| MCP Specification | https://spec.modelcontextprotocol.io | Official MCP specification |
| MCP Documentation | https://modelcontextprotocol.io | MCP documentation and guides |
| MCP Servers | https://github.com/modelcontextprotocol/servers | Official MCP server implementations |
| MCP for GitHub Copilot | https://docs.github.com/en/copilot/using-mcp-servers | MCP integration with Copilot |

### 13.4 Agent Prism & Observability

| Resource | URL | Description |
|----------|-----|-------------|
| Agent Prism Documentation | https://agentprism.dev | Agent monitoring platform |
| OpenTelemetry | https://opentelemetry.io | Observability framework |
| LLM Observability | https://docs.smith.langchain.com | LangSmith for LLM monitoring |

### 13.5 Embedded Engineering

| Resource | URL | Description |
|----------|-----|-------------|
| MISRA C Guidelines | https://misra.org.uk | Embedded C coding standards |
| AUTOSAR | https://www.autosar.org | Automotive embedded standards |
| Embedded C Programming | https://www.embedded.com | Embedded systems resource |
| C/C++ Testing with Google Test | https://github.com/google/googletest | Unit testing framework |

### 13.6 LLM-as-Judge

| Resource | URL | Description |
|----------|-----|-------------|
| LLM-as-Judge Pattern | https://docs.smith.langchain.com/evaluation | Evaluation patterns |
| AI Code Review | https://github.com/features/copilot#code-review | Copilot code review features |

### 13.7 Atlassian Rovo Studio (Module 08)

| Resource | URL | Description |
|----------|-----|-------------|
| Atlassian Rovo Documentation | https://www.atlassian.com/software/rovo | Rovo Studio overview |
| Rovo Agents | https://support.atlassian.com/rovo/docs/ | Agent authoring and workflows |
| Jira Integration | https://www.atlassian.com/software/jira | Project tracking integration |
| Confluence Integration | https://www.atlassian.com/software/confluence | Documentation platform |

### 13.8 Honeywell Internal Resources

| Resource | Location | Description |
|----------|----------|-------------|
| AI Champions Programme | NIIT StackRoute Platform | Course materials and labs |
| Honeywell Training Sheet | Internal SharePoint | Training requirements and themes |
| Embedded Coding Standards | Internal Documentation | Honeywell-specific coding standards |
| Repository Access | GitHub Enterprise | Approved C/C++ repositories |
| Calibration Survey Results | NIIT Enterprise | 19 pre-programme responses |

### 13.9 Recommended Pre-Read / Self-Paced Foundation

| Topic | Resource | Duration |
|-------|----------|----------|
| AI Fundamentals | AI Fundamentals Bootcamp (NIIT) | 2 hours |
| Introduction to GenAI | GenAI Introduction Module | 1 hour |
| Introduction to Agents | Agent Architecture Overview | 1 hour |
| Responsible AI | Responsible AI Awareness Module | 1 hour |

---

## 14. Key Takeaways

### 14.1 Module 01 Summary

1. **AI Champions are essential** for Honeywell's embedded engineering teams to adopt AI responsibly and effectively
2. **The incremental journey** ensures each concept builds on the previous one — no shortcuts
3. **Enterprise context first** — understand WHY before learning HOW
4. **Role-based expectations** — different roles need different depths of AI capability
5. **Risks are real** — unmanaged AI usage can cause defects, cost overruns, and compliance violations
6. **Agent Prism provides visibility** — you can't improve what you can't measure
7. **Success metrics** must be defined before implementation, not after
8. **Two engineering flavors** — greenfield (SDD-driven) and brownfield (safe evolution)
9. **This cohort is senior and experienced** — 68% have 8+ years, 74% are Advanced/Expert in C/C++
10. **84% already use Copilot** — position as capability deepening, not first exposure
11. **MCP is the #1 training priority** (68%) with near-zero current exposure
12. **42% have weak automated validation** — biggest structural risk to safe AI adoption

### 14.2 Calibration-Driven Insights

| Insight | Implication |
|---------|-------------|
| 79% already work in spec-led patterns | SDD formalises existing instinct |
| Trust is conditional (58% confident with small changes) | Validate Module 9 PR quality gates alignment |
| Timing behaviour #1 review concern (14 mentions) | Anchor LLM-as-Judge rubric on this |
| Fragmented change-impact analysis | Module 5 repository archaeology is critical |
| Knowledge silos across teams | AI documentation reduces bottleneck |

### 14.3 Next Steps

- Complete the **Current-State Workflow Canvas** exercise
- Identify your **top 3 pain points** from the calibration-backed pain points
- Define **baseline metrics** for your team
- Review **Module 02: GitHub Copilot Enterprise Features** preview
- Consider **Module 7 (MCP)** as your highest-leverage learning opportunity

---

## Appendix A: Glossary

| Term | Definition |
|------|-----------|
| **AI Champion** | A team member who bridges AI tools and embedded engineering practices |
| **SDD** | Specification-Driven Development — structured approach to AI-assisted coding |
| **MCP** | Model Context Protocol — standard for connecting AI to tools |
| **Agent Prism** | Monitoring and observability platform for AI-assisted engineering |
| **LLM-as-Judge** | Using AI to evaluate AI-generated output quality |
| **Greenfield** | Building new features from specifications (no legacy constraints) |
| **Brownfield** | Enhancing existing code (requires understanding of current architecture) |
| **HAL** | Hardware Abstraction Layer — boundary between software and hardware |
| **Token** | Unit of text processed by AI models (input + output) |
| **Context Engineering** | Selecting and layering relevant information for AI tasks |

---

## Appendix B: Module 01 Workshop Checklist

- [ ] Complete role-mapping exercise
- [ ] Fill out current-state workflow canvas
- [ ] Identify top 3 pain points
- [ ] Define baseline metrics
- [ ] Review Agent Prism overview
- [ ] Discuss team-specific use cases
- [ ] Set 30-day and 90-day targets
- [ ] Prepare questions for Module 02

---

## Appendix C: Calibration-Driven Design Validation

### What the Data Validated (Keep As-Is)

| Design Element | Calibration Evidence |
|----------------|---------------------|
| Dual greenfield/brownfield tracks (Module 05) | 68% work roughly 50/50 brownfield vs greenfield |
| SDD-first structure (Module 04) | 79% already work in some specification-led pattern |
| Heavy MCP investment (Module 07) | 68% rank MCP as top training want |
| PR quality gates covering non-functional criteria (Module 09) | Near-unanimous scenario response on memory/design-pattern conformance |

### Suggested Emphasis Adjustments

| Adjustment | Rationale |
|------------|-----------|
| Protect Module 7 (MCP) pacing | Top stated want + lowest current exposure |
| Front-load Module 6 (test strategy) messaging | 42% have little automated validation |
| Use cohort's PR-approval consensus as Module 09 opening frame | Participants already hold the mental model |
| Consider Module 2 fast-path for ~84% already using Copilot | Free time for agent mode and reusable instructions |

### 30/60/90-Day Post-Programme Roadmap

| Horizon | Focus | Rationale |
|---------|-------|-----------|
| **30 days** | Consolidate context-engineering and MCP habits from Modules 3 & 7 | Top training want; lowest current exposure most likely to regress |
| **60 days** | Stand up shared automated validation baseline | 42% currently have little automated validation |
| **90 days** | Pilot one issue-to-validated-PR MCP workflow with Agent Prism | Directly mirrors cohort's preferred first MCP workflow |

---

*Module 01 of the AI Champions Programme for Honeywell Embedded Engineering Teams*  
*Total Programme Duration: 24 Hours (3 Full Days × 8 Hours)*  
*Delivered by NIIT StackRoute*  
*Calibration Data: 19 pre-programme survey responses*  
*Document Version: 2.0 (Synced with Revised Course Outline v3 & Calibration Report)*
