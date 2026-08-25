# Module 04: Spec-Driven Development for Embedded Software

## Honeywell Embedded Engineering Teams — Comprehensive Guide

---

## Document Revision

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 25 Aug 2026 | Initial comprehensive guide |

---

## Table of Contents

1. [Module Overview](#1-module-overview)
2. [Calibration-Driven Design Insights](#2-calibration-driven-design-insights)
3. [SDD Fundamentals for Embedded Engineering](#3-sdd-fundamentals-for-embedded-engineering)
4. [Requirements and Constraints](#4-requirements-and-constraints)
5. [Interfaces and Contracts](#5-interfaces-and-contracts)
6. [Acceptance Criteria and Specification Quality](#6-acceptance-criteria-and-specification-quality)
7. [The SDD Workflow: Spec → Plan → Tasks → Implementation](#7-the-sdd-workflow-spec--plan--tasks--implementation)
8. [GitHub Spec Kit / OpenSpec Patterns](#8-github-spec-kit--openspec-patterns)
9. [Traceability and Change Control](#9-traceability-and-change-control)
10. [Prompt-Only vs Spec-Driven Development](#10-prompt-only-vs-spec-driven-development)
11. [Hands-On Workshop](#11-hands-on-workshop)
12. [Success Metrics and Measurement](#12-success-metrics-and-measurement)
13. [Architecture Diagrams and Visual Flow](#13-architecture-diagrams-and-visual-flow)
14. [Reference Links and Resources](#14-reference-links-and-resources)

---

## 1. Module Overview

**Duration:** 2 Hours  
**Format:** Instructor-led + Hands-on Lab  
**Primary Tools:** GitHub Copilot, GitHub Spec Kit / OpenSpec, Specification Templates, Acceptance-Criteria Checklist

### Module Objectives

By the end of this module, participants will:

- Understand SDD fundamentals and their application to embedded engineering
- Define requirements, functional/non-functional constraints, and timing/resource constraints
- Create clear interface contracts and acceptance criteria
- Follow the complete SDD workflow: Spec → Plan → Tasks → Implementation
- Use GitHub Spec Kit / OpenSpec patterns for specification management
- Implement traceability from requirements through implementation
- Apply change control processes for specification modifications
- Compare prompt-only vs spec-driven development approaches

### Module 04 Context: Building on Modules 01-03

| Calibration Finding | Module 04 Implication |
|---------------------|------------------------|
| 79% already work spec-led | Formalises existing instinct, adds rigor |
| 53% use ad-hoc prompting | Shows how SDD improves consistency |
| Fragmented change-impact analysis | SDD provides traceability |
| Trust is conditional (58%) | SDD enables validation-driven confidence |

---

## 2. Calibration-Driven Design Insights

### 2.1 Current Specification Patterns

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CALIBRATION: REQUIREMENT-TO-CODE FLOW                 │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CURRENT SPECIFICATION METHODS                                  │   │
│  │                                                                │   │
│  │  User stories/tickets        ████████████████████████  42%    │   │
│  │  Formal requirement docs     ████████████████          26%    │   │
│  │  Verbal/discussion           ████████████              21%    │   │
│  │  No formal spec              ████████                  11%    │   │
│  │                                                                │   │
│  │  → 79% already work in some specification-led pattern        │   │
│  │  → SDD formalises and tools this instinct                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  SPECIFICATION QUALITY GAPS                                     │   │
│  │                                                                │   │
│  │  • Missing acceptance criteria                                 │   │
│  │  • Incomplete interface contracts                              │   │
│  │  • No timing/resource constraints documented                  │   │
│  │  • Traceability gaps between spec and code                    │   │
│  │  • Change control inconsistencies                              │   │
│  │                                                                │   │
│  │  → Module 04 addresses these gaps systematically              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.2 Context Scoping Consensus

| Finding | Implication |
|---------|-------------|
| Strong consensus on task-scoped context | "Give the agent only the feature's requirements, directly relevant source/header pairs, and minimal supporting context" |
| Even without SDD training | Participants already understand the principle |
| Module 04 adds tooling | Formalises this instinct with structured workflow |

### 2.3 Design Implications

1. **Formalise, Don't Replace** — Build on existing spec-led patterns
2. **Add Rigor** — Introduce acceptance criteria, traceability, change control
3. **Tool the Workflow** — Use GitHub Spec Kit / OpenSpec for consistency
4. **Enable Validation** — Connect SDD to testing in Module 06

---

## 3. SDD Fundamentals for Embedded Engineering

### 3.1 What is Spec-Driven Development?

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    SPEC-DRIVEN DEVELOPMENT OVERVIEW                       │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TRADITIONAL APPROACH                                           │   │
│  │                                                                │   │
│  │  Requirements → [Manual Interpretation] → Code → [Ad-hoc Test]│   │
│  │                                                                │   │
│  │  Problems:                                                    │   │
│  │  • Inconsistent interpretation                                │   │
│  │  • Missing acceptance criteria                                │   │
│  │  • Poor traceability                                          │   │
│  │  • Rework cycles                                              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  SDD APPROACH                                                  │   │
│  │                                                                │   │
│  │  Spec → Plan → Tasks → Implementation → Validation            │   │
│  │                                                                │   │
│  │  Benefits:                                                    │   │
│  │  • Clear requirements                                         │   │
│  │  • Traceable implementation                                   │   │
│  │  • Testable acceptance criteria                               │   │
│  │  • Change-controlled modifications                            │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 3.2 SDD vs Traditional Development

| Aspect | Traditional | SDD | Embedded Impact |
|--------|-------------|-----|-----------------|
| Requirements | Verbal/tickets | Formal specification | Clear constraints |
| Planning | Ad-hoc | Spec-driven plan | Resource allocation |
| Implementation | Code-first | Spec-first | Architecture alignment |
| Testing | After implementation | Derived from spec | Validation coverage |
| Traceability | Manual | Automated | Compliance audit |
| Change Control | Informal | Spec-controlled | Risk management |

### 3.3 SDD for Embedded Systems

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EMBEDDED SDD CONSIDERATIONS                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  FUNCTIONAL REQUIREMENTS                                        │   │
│  │  • Feature behavior description                                │   │
│  │  • Input/output specifications                                 │   │
│  │  • State machine definitions                                   │   │
│  │  • Protocol compliance                                         │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  NON-FUNCTIONAL REQUIREMENTS                                   │   │
│  │  • Timing constraints (deadlines, latency)                    │   │
│  │  • Memory constraints (RAM, Flash)                             │   │
│  │  • Power consumption                                           │   │
│  │  • Reliability requirements (MTBF)                             │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  INTERFACE REQUIREMENTS                                        │   │
│  │  • HAL boundary contracts                                      │   │
│  │  • Communication protocols                                     │   │
│  │  • Data formats and structures                                 │   │
│  │  • Error handling contracts                                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 4. Requirements and Constraints

### 4.1 Functional Requirements Structure

| Component | Description | Example |
|-----------|-------------|---------|
| **Purpose** | What the feature does | "Implement UART receive driver" |
| **Scope** | Boundaries of implementation | "RX only, no flow control" |
| **Behavior** | Detailed functionality | "Support 9600-115200 baud rates" |
| **Inputs** | External inputs | "UART RX pin, configuration parameters" |
| **Outputs** | Generated outputs | "Received data buffer, status flags" |
| **State Changes** | State transitions | "IDLE → RECEIVING → COMPLETE" |

### 4.2 Non-Functional Constraints

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EMBEDDED CONSTRAINTS MATRIX                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TIMING CONSTRAINTS                                             │   │
│  │                                                                │   │
│  │  • Maximum latency: < 10ms response time                      │   │
│  │  • Interrupt response: < 1μs                                   │   │
│  │  • Task period: 10ms deterministic                             │   │
│  │  • Watchdog timeout: 500ms                                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  MEMORY CONSTRAINTS                                            │   │
│  │                                                                │   │
│  │  • RAM usage: < 2KB per module                                │   │
│  │  • Flash usage: < 16KB per feature                            │   │
│  │  • No dynamic allocation                                       │   │
│  │  • Stack size: < 512 bytes                                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  RELIABILITY CONSTRAINTS                                        │   │
│  │                                                                │   │
│  │  • MTBF: > 10,000 hours                                       │   │
│  │  • Error recovery: Graceful degradation                        │   │
│  │  • Watchdog compliance                                         │   │
│  │  • Fault tolerance requirements                                │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 4.3 Timing Constraints Documentation

| Constraint | Value | Justification | Validation Method |
|------------|-------|---------------|-------------------|
| ISR latency | < 1μs | Real-time requirement | Oscilloscope measurement |
| Task period | 10ms | Control loop timing | RTOS scheduler analysis |
| Response time | < 10ms | User experience | End-to-end timing test |
| Watchdog | 500ms | System recovery | Timeout injection test |

---

## 5. Interfaces and Contracts

### 5.1 Interface Contract Structure

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    INTERFACE CONTRACT TEMPLATE                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  MODULE: [Module Name]                                          │   │
│  │                                                                │   │
│  │  RESPONSIBILITY: [What this module does]                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PUBLIC INTERFACE                                               │   │
│  │                                                                │   │
│  │  Functions:                                                    │   │
│  │  • [function_name](params) → return_type                      │   │
│  │    Pre-conditions: [what must be true before]                 │   │
│  │    Post-conditions: [what will be true after]                 │   │
│  │    Error codes: [possible error returns]                      │   │
│  │                                                                │   │
│  │  Data Structures:                                              │   │
│  │  • [struct_name] { fields, types, ranges }                    │   │
│  │                                                                │   │
│  │  Constants:                                                    │   │
│  │  • [CONSTANT_NAME] = value  // description                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  DEPENDENCIES                                                   │   │
│  │                                                                │   │
│  │  Required interfaces: [list of dependencies]                  │   │
│  │  HAL requirements: [hardware dependencies]                    │   │
│  │  Build requirements: [toolchain, libraries]                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 5.2 HAL Boundary Contracts

| Interface | Function | Parameters | Return | Error Codes |
|-----------|----------|------------|--------|-------------|
| `hal_gpio` | `hal_gpio_read_pin(port, pin)` | GPIO_Port, GPIO_Pin | GPIO_State | HAL_OK, HAL_ERROR |
| `hal_gpio` | `hal_gpio_write_pin(port, pin, state)` | GPIO_Port, GPIO_Pin, GPIO_State | HAL_Status | HAL_OK, HAL_ERROR |
| `hal_uart` | `hal_uart_send(data, length)` | uint8_t*, size_t | HAL_Status | HAL_OK, HAL_BUSY |
| `hal_uart` | `hal_uart_receive(buffer, length)` | uint8_t*, size_t | HAL_Status | HAL_OK, HAL_TIMEOUT |

### 5.3 State Machine Contracts

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    STATE MACHINE CONTRACT                                │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  STATES                                                         │   │
│  │                                                                │   │
│  │  • IDLE: No activity, waiting for trigger                     │   │
│  │  • INITIALIZING: Setting up resources                         │   │
│  │  • RUNNING: Active operation                                   │   │
│  │  • ERROR: Fault condition detected                             │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TRANSITIONS                                                    │   │
│  │                                                                │   │
│  │  IDLE → INITIALIZING: on start_command                        │   │
│  │  INITIALIZING → RUNNING: on init_complete                     │   │
│  │  RUNNING → ERROR: on fault_detected                           │   │
│  │  ERROR → IDLE: on reset_command                               │   │
│  │                                                                │   │
│  │  Guards:                                                       │   │
│  │  • init_complete: all resources allocated                     │   │
│  │  • fault_detected: error flag set                             │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 6. Acceptance Criteria and Specification Quality

### 6.1 Acceptance Criteria Template

| Criterion | Description | Verification Method |
|-----------|-------------|---------------------|
| **Functional** | Feature works as specified | Unit test, integration test |
| **Performance** | Meets timing constraints | Timing measurement |
| **Memory** | Stays within resource limits | Memory analysis |
| **Reliability** | Handles errors gracefully | Fault injection |
| **Compliance** | Follows coding standards | Static analysis |
| **Traceability** | Links to requirements | Spec-to-code mapping |

### 6.2 Specification Quality Checklist

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    SPECIFICATION QUALITY CHECKLIST                       │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  COMPLETENESS                                                   │   │
│  │  □ All functional requirements documented                      │   │
│  │  □ All non-functional constraints specified                    │   │
│  │  □ Interface contracts defined                                 │   │
│  │  □ Error handling specified                                    │   │
│  │  □ State machine fully defined                                 │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CLARITY                                                        │   │
│  │  □ No ambiguous language                                       │   │
│  │  □ Quantitative criteria (not "fast", use "< 10ms")           │   │
│  │  □ Testable acceptance criteria                                │   │
│  │  □ Clear scope boundaries                                      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONSISTENCY                                                    │   │
│  │  □ No contradicting requirements                               │   │
│  │  □ Aligned with architecture                                   │   │
│  │  □ Compatible with existing interfaces                         │   │
│  │  □ Follows naming conventions                                  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TRACEABILITY                                                   │   │
│  │  □ Unique requirement IDs                                      │   │
│  │  □ Links to design decisions                                   │   │
│  │  □ Links to test cases                                         │   │
│  │  □ Change history documented                                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 6.3 Good vs Bad Acceptance Criteria

| Criterion | Bad Example | Good Example |
|-----------|-------------|--------------|
| Performance | "Should be fast" | "Response time < 10ms under max load" |
| Memory | "Use little memory" | "RAM usage < 2KB, Flash < 16KB" |
| Reliability | "Handle errors" | "On UART timeout, return HAL_TIMEOUT within 100ms" |
| Testing | "Test it well" | "All boundary conditions covered, > 80% branch coverage" |

---

## 7. The SDD Workflow: Spec → Plan → Tasks → Implementation

### 7.1 Complete SDD Workflow

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    SDD WORKFLOW: SPEC → PLAN → TASKS → IMPLEMENTATION    │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  1. SPECIFICATION                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Define requirements (functional + non-functional)     │  │   │
│  │  │ • Document constraints (timing, memory, power)          │  │   │
│  │  │ • Specify interfaces (HAL, APIs, data structures)       │  │   │
│  │  │ • Write acceptance criteria                              │  │   │
│  │  │ • Review and approve specification                       │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  2. PLAN                                                        │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Break specification into modules                      │  │   │
│  │  │ • Identify dependencies                                  │  │   │
│  │  │ • Estimate effort and resources                         │  │   │
│  │  │ • Define implementation order                            │  │   │
│  │  │ • Plan validation approach                               │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  3. TASKS                                                       │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Create implementation tasks                           │  │   │
│  │  │ • Define task-level acceptance criteria                 │  │   │
│  │  │ • Assign dependencies                                   │  │   │
│  │  │ • Set milestones                                         │  │   │
│  │  │ • Define Definition of Done per task                    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  4. IMPLEMENTATION                                              │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Implement tasks in defined order                      │  │   │
│  │  │ • Follow coding standards                               │  │   │
│  │  │ • Write unit tests                                      │  │   │
│  │  │ • Validate against acceptance criteria                  │  │   │
│  │  │ • Update traceability                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 7.2 Specification to Implementation Mapping

| Spec Element | Implementation | Validation |
|--------------|----------------|------------|
| Requirement ID | Function/module | Test case ID |
| Acceptance criterion | Test assertion | Test result |
| Interface contract | API implementation | Integration test |
| Timing constraint | Code optimization | Timing measurement |
| Memory constraint | Resource allocation | Memory analysis |

### 7.3 Task Breakdown Example

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TASK BREAKDOWN: UART RECEIVE DRIVER                   │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TASK 1: Define Interface Contract                              │   │
│  │  • Create uart_receive.h header                                │   │
│  │  • Define function signatures                                  │   │
│  │  • Document error codes                                        │   │
│  │  • Acceptance: Header compiles, API documented                 │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TASK 2: Implement Configuration                               │   │
│  │  • Create configuration structure                              │   │
│  │  • Define baud rate, buffer size parameters                    │   │
│  │  • Acceptance: Config structure matches spec                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TASK 3: Implement Core Logic                                  │   │
│  │  • Implement ring buffer                                       │   │
│  │  • Implement receive state machine                             │   │
│  │  • Acceptance: Logic matches state diagram                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TASK 4: Write Unit Tests                                      │   │
│  │  • Test normal operation                                       │   │
│  │  • Test boundary conditions                                    │   │
│  │  • Test error handling                                         │   │
│  │  • Acceptance: All tests pass, coverage > 80%                  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 8. GitHub Spec Kit / OpenSpec Patterns

### 8.1 GitHub Spec Kit Structure

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    GITHUB SPEC KIT STRUCTURE                             │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  repository/                                                    │   │
│  │  ├── .spec/                                                     │   │
│  │  │   ├── specifications/                                        │   │
│  │  │   │   ├── 001-uart-receive/                                  │   │
│  │  │   │   │   ├── spec.md           (Specification)             │   │
│  │  │   │   │   ├── interfaces.md     (Interface contracts)       │   │
│  │  │   │   │   ├── acceptance.md     (Acceptance criteria)       │   │
│  │  │   │   │   └── traceability.md   (Req-to-code mapping)      │   │
│  │  │   │   └── 002-spi-driver/                                    │   │
│  │  │   ├── templates/                                             │   │
│  │  │   │   ├── spec-template.md                                   │   │
│  │  │   │   └── acceptance-template.md                             │   │
│  │  │   └── checklists/                                            │   │
│  │  │       └── quality-checklist.md                               │   │
│  │  └── src/                                                       │   │
│  │      └── (implementation files)                                 │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 8.2 OpenSpec Pattern

| Component | Purpose | Location |
|-----------|---------|----------|
| Specification | Core requirements | `.spec/specifications/<id>/spec.md` |
| Interfaces | API contracts | `.spec/specifications/<id>/interfaces.md` |
| Acceptance | Test criteria | `.spec/specifications/<id>/acceptance.md` |
| Traceability | Requirement links | `.spec/specifications/<id>/traceability.md` |
| Templates | Reusable formats | `.spec/templates/` |
| Checklists | Quality gates | `.spec/checklists/` |

### 8.3 Specification Template

```markdown
# Specification: [Feature Name]

## Requirement ID
REQ-[XXX]-[NNN]

## Purpose
[What this feature does]

## Scope
[Boundaries of implementation]

## Functional Requirements
1. [Requirement 1]
2. [Requirement 2]

## Non-Functional Constraints
- Timing: [constraints]
- Memory: [constraints]
- Power: [constraints]

## Interfaces
- Input: [interface]
- Output: [interface]

## Acceptance Criteria
- [ ] Criterion 1
- [ ] Criterion 2

## Dependencies
- [Dependent modules]

## Traceability
- Design: [link]
- Tests: [link]
```

---

## 9. Traceability and Change Control

### 9.1 Traceability Matrix

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TRACEABILITY MATRIX                                   │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  REQUIREMENT → DESIGN → CODE → TEST                            │   │
│  │                                                                │   │
│  │  REQ-001-001  ──→  design-001  ──→  uart_receive.c  ──→  TC-001│   │
│  │  REQ-001-002  ──→  design-001  ──→  uart_receive.c  ──→  TC-002│   │
│  │  REQ-001-003  ──→  design-002  ──→  ring_buffer.c   ──→  TC-003│   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  Benefits:                                                             │
│  • Impact analysis: Which code is affected by requirement change?      │
│  • Coverage analysis: Which requirements have tests?                   │
│  • Regression analysis: Which tests to run for code change?           │
│  • Compliance audit: Prove requirements are implemented and tested     │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 9.2 Change Control Process

| Step | Action | Output |
|------|--------|--------|
| 1 | Submit change request | Change request document |
| 2 | Impact analysis | Affected requirements, code, tests |
| 3 | Review and approve | Approval/rejection |
| 4 | Update specification | Revised spec with version |
| 5 | Update implementation | Code changes |
| 6 | Update tests | Test updates |
| 7 | Verify traceability | Updated matrix |
| 8 | Close change request | Change complete |

### 9.3 Change Impact Analysis

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CHANGE IMPACT ANALYSIS                                │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CHANGE REQUESTED                                               │   │
│  │  "Modify UART receive to support DMA mode"                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  IMPACT ANALYSIS                                                │   │
│  │                                                                │   │
│  │  Affected Requirements:                                        │   │
│  │  • REQ-001-001 (receive function)                              │   │
│  │  • REQ-001-003 (timing constraints)                            │   │
│  │                                                                │   │
│  │  Affected Code:                                                │   │
│  │  • uart_receive.c                                             │   │
│  │  • dma_config.c                                               │   │
│  │                                                                │   │
│  │  Affected Tests:                                               │   │
│  │  • TC-001 (normal receive)                                     │   │
│  │  • TC-003 (timing test)                                        │   │
│  │                                                                │   │
│  │  Risk Assessment:                                              │   │
│  │  • High: Timing changes may affect real-time behavior         │   │
│  │  • Medium: DMA configuration complexity                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  IMPLEMENTATION PLAN                                            │   │
│  │                                                                │   │
│  │  1. Update specification (REQ-001-001, REQ-001-003)           │   │
│  │  2. Modify uart_receive.c for DMA support                     │   │
│  │  3. Update dma_config.c                                       │   │
│  │  4. Update TC-001, TC-003                                     │   │
│  │  5. Verify traceability                                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 10. Prompt-Only vs Spec-Driven Development

### 10.1 Side-by-Side Comparison

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    PROMPT-ONLY vs SPEC-DRIVEN                            │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌──────────────────────────────────┐  ┌──────────────────────────────┐│
│  │  PROMPT-ONLY                     │  │  SPEC-DRIVEN                 ││
│  │                                  │  │                              ││
│  │  "Implement UART receive"        │  │  "Implement UART receive"    ││
│  │                                  │  │                              ││
│  │  No specification:              │  │  Specification:              ││
│  │  • Ambiguous requirements       │  │  • Clear requirements        ││
│  │  • No acceptance criteria       │  │  • Defined acceptance criteria││
│  │  • No interface contracts       │  │  • Interface contracts       ││
│  │  • No traceability              │  │  • Full traceability         ││
│  │                                  │  │                              ││
│  │  Result: Inconsistent,          │  │  Result: Consistent,         ││
│  │  hard to validate, rework       │  │  testable, traceable         ││
│  └──────────────────────────────────┘  └──────────────────────────────┘│
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 10.2 Measurable Differences

| Metric | Prompt-Only | Spec-Driven | Improvement |
|--------|-------------|-------------|-------------|
| Requirements clarity | 4/10 | 9/10 | +125% |
| First-pass success | 30% | 85% | +183% |
| Rework cycles | 5-7 | 1-2 | -71% |
| Test coverage | 40% | 90% | +125% |
| Traceability | 0% | 100% | ∞ |
| Change impact analysis | Manual | Automated | -80% effort |

### 10.3 Example: UART Receive Driver

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EXAMPLE: UART RECEIVE DRIVER                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PROMPT-ONLY OUTPUT                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ void uart_receive(uint8_t *buf, int len) {             │  │   │
│  │  │     // No error handling                                │  │   │
│  │  │     // No timing constraints                            │  │   │
│  │  │     // No DMA support                                   │  │   │
│  │  │     // No state management                              │  │   │
│  │  │     // No test cases                                    │  │   │
│  │  │ }                                                       │  │   │
│  │  │ // Missing: acceptance criteria, interface contracts    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  SPEC-DRIVEN OUTPUT                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ // REQ-001-001: UART Receive Driver                     │  │   │
│  │  │ // Acceptance: < 10ms latency, DMA support, error codes │  │   │
│  │  │                                                         │  │   │
│  │  │ HAL_Status uart_receive(uart_config_t *cfg,            │  │   │
│  │  │                         uint8_t *buf, size_t len,      │  │   │
│  │  │                         size_t *actual_len) {          │  │   │
│  │  │     // Pre-conditions validated                        │  │   │
│  │  │     // State machine transitions documented            │  │   │
│  │  │     // Error codes defined (HAL_OK, HAL_TIMEOUT)       │  │   │
│  │  │     // Timing: < 10ms per spec                         │  │   │
│  │  │     // Unit tests: TC-001, TC-002, TC-003              │  │   │
│  │  │ }                                                       │  │   │
│  │  │ // Traceability: REQ-001-001 → uart_receive.c → TC-001 │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 11. Hands-On Workshop

### 11.1 Workshop Structure

**Duration:** 1.5 hours  
**Format:** Hands-on lab with C/C++ embedded codebase

### 11.2 Lab Exercise

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    WORKSHOP EXERCISE                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 1: CREATE SPECIFICATION (30 minutes)                     │   │
│  │                                                                │   │
│  │  Task: Create a specification for an embedded software feature │   │
│  │                                                                │   │
│  │  Deliverables:                                                │   │
│  │  1. Requirements document with REQ IDs                        │   │
│  │  2. Interface contracts (header files)                        │   │
│  │  3. Acceptance criteria checklist                             │   │
│  │  4. Timing/memory constraints                                 │   │
│  │                                                                │   │
│  │  Tool: Use Spec Kit template                                  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 2: GENERATE PLAN AND TASKS (20 minutes)                 │   │
│  │                                                                │   │
│  │  Task: Break specification into implementation plan           │   │
│  │                                                                │   │
│  │  Deliverables:                                                │   │
│  │  1. Module breakdown                                          │   │
│  │  2. Task list with dependencies                               │   │
│  │  3. Task-level acceptance criteria                            │   │
│  │  4. Implementation order                                      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 3: IMPLEMENT AND VALIDATE (40 minutes)                  │   │
│  │                                                                │   │
│  │  Task: Implement against specification                        │   │
│  │                                                                │   │
│  │  Deliverables:                                                │   │
│  │  1. Implementation matching spec                              │   │
│  │  2. Unit tests derived from acceptance criteria               │   │
│  │  3. Traceability matrix                                       │   │
│  │  4. Validation evidence                                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 4: VALIDATE TRACEABILITY (20 minutes)                   │   │
│  │                                                                │   │
│  │  Task: Verify complete traceability                           │   │
│  │                                                                │   │
│  │  Activities:                                                  │   │
│  │  1. Map requirements to code                                  │   │
│  │  2. Map requirements to tests                                 │   │
│  │  3. Verify acceptance criteria met                            │   │
│  │  4. Document lessons learned                                  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 11.3 Measurement Worksheet

| Metric | Phase 1 | Phase 2 | Phase 3 | Phase 4 |
|--------|---------|---------|---------|---------|
| Time spent | __ min | __ min | __ min | __ min |
| Requirements defined | __ | __ | __ | __ |
| Tasks created | __ | __ | __ | __ |
| Code written | __ | __ | __ | __ |
| Tests written | __ | __ | __ | __ |
| Traceability links | __ | __ | __ | __ |

---

## 12. Success Metrics and Measurement

### 12.1 Module 04 Metrics Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    MODULE 04 SUCCESS METRICS                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  SPECIFICATION QUALITY METRICS                                  │   │
│  │  • Requirements completeness                                   │   │
│  │  • Acceptance criteria clarity                                 │   │
│  │  • Interface contract coverage                                 │   │
│  │  • Constraint documentation                                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TRACEABILITY METRICS                                           │   │
│  │  • Requirement-to-code links                                   │   │
│  │  • Requirement-to-test links                                   │   │
│  │  • Coverage percentage                                         │   │
│  │  • Gap identification                                          │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PRODUCTIVITY METRICS                                           │   │
│  │  • First-pass success rate                                     │   │
│  │  • Rework reduction                                            │   │
│  │  • Time to completion                                          │   │
│  │  • Change impact analysis speed                                │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 12.2 Baseline vs Target

| Metric | Before Module 04 | Target After Module 04 |
|--------|------------------|------------------------|
| Specification-led patterns | 79% | 100% |
| Acceptance criteria coverage | 40% | 90% |
| Traceability completeness | 20% | 80% |
| First-pass success | 30% | 70% |

---

## 13. Architecture Diagrams and Visual Flow

### 13.1 SDD Architecture

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    SDD ARCHITECTURE                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  SPECIFICATION LAYER                                            │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐      │   │
│  │  │Requirements│ │Interfaces│ │Acceptance│ │Constraints│      │   │
│  │  │          │  │          │  │ Criteria │  │          │      │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PLAN LAYER                                                     │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐      │   │
│  │  │ Module   │  │Dependency│  │  Effort  │  │  Order   │      │   │
│  │  │ Breakdown│  │  Map     │  │ Estimate │  │          │      │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TASK LAYER                                                     │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐      │   │
│  │  │  Tasks   │  │  Task    │  │Milestones│  │   DoD    │      │   │
│  │  │          │  │ Accept.  │  │          │  │          │      │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  IMPLEMENTATION LAYER                                           │   │
│  │  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐      │   │
│  │  │  Code    │  │  Tests   │  │  Docs    │  │  Trace   │      │   │
│  │  │          │  │          │  │          │  │  Matrix  │      │   │
│  │  └──────────┘  └──────────┘  └──────────┘  └──────────┘      │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 13.2 Traceability Flow

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TRACEABILITY FLOW                                     │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────┐                                                       │
│  │ Requirement │                                                       │
│  │ REQ-001-001 │                                                       │
│  └──────┬──────┘                                                       │
│         │                                                               │
│         ▼                                                               │
│  ┌─────────────┐                                                       │
│  │   Design    │                                                       │
│  │ design-001  │                                                       │
│  └──────┬──────┘                                                       │
│         │                                                               │
│         ▼                                                               │
│  ┌─────────────┐                                                       │
│  │    Code     │                                                       │
│  │ uart_recv.c │                                                       │
│  └──────┬──────┘                                                       │
│         │                                                               │
│         ▼                                                               │
│  ┌─────────────┐                                                       │
│  │    Test     │                                                       │
│  │   TC-001    │                                                       │
│  └─────────────┘                                                       │
│                                                                         │
│  Bidirectional:                                                        │
│  • Forward: Requirement → Test (coverage)                              │
│  • Backward: Code → Requirement (impact analysis)                      │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 14. Reference Links and Resources

### 14.1 SDD Resources

| Resource | URL | Description |
|----------|-----|-------------|
| GitHub Spec Kit | https://github.com/github/spec-kit | Official Spec Kit |
| OpenSpec | https://github.com/openspec | Open specification format |
| Behavior-Driven Development | https://cucumber.io/docs/bdd/ | BDD principles |
| ATDD by Example | https://atddbyexample.com/ | Acceptance test-driven development |

### 14.2 Embedded Engineering Resources

| Resource | URL | Description |
|----------|-----|-------------|
| MISRA C Guidelines | https://www.misra.org.uk | Automotive C standard |
| AUTOSAR | https://www.autosar.org | Automotive software standard |
| Embedded C Guidelines | https://github.com/ProgrammingGuidelines | Best practices |

### 14.3 Honeywell Internal Resources

| Resource | Location | Description |
|----------|----------|-------------|
| AI Champions Programme | NIIT StackRoute Platform | Course materials |
| Honeywell Training Sheet | Internal SharePoint | Training requirements |
| Embedded Coding Standards | Internal Documentation | Honeywell-specific standards |
| Repository Access | GitHub Enterprise | Approved C/C++ repositories |

---

## Appendix A: Specification Templates

### A.1 Feature Specification Template

```markdown
# Feature Specification: [Feature Name]

## Metadata
- Requirement ID: REQ-[XXX]-[NNN]
- Version: 1.0
- Author: [Name]
- Date: [Date]
- Status: [Draft/Reviewed/Approved]

## Purpose
[What this feature does and why]

## Scope
[Boundaries of implementation]

## Functional Requirements
1. [Requirement 1 with acceptance criteria]
2. [Requirement 2 with acceptance criteria]

## Non-Functional Constraints
- Timing: [constraints]
- Memory: [constraints]
- Power: [constraints]
- Reliability: [constraints]

## Interfaces
### Input Interface
- [Interface 1]
- [Interface 2]

### Output Interface
- [Interface 1]
- [Interface 2]

## Acceptance Criteria
- [ ] Criterion 1
- [ ] Criterion 2
- [ ] Criterion 3

## Dependencies
- [Dependent module 1]
- [Dependent module 2]

## Design Notes
[Architecture decisions, patterns used]

## Traceability
- Design Document: [link]
- Test Plan: [link]
- Implementation: [link]
```

### A.2 Acceptance Criteria Template

```markdown
# Acceptance Criteria: [Feature Name]

## Functional Criteria
| ID | Criterion | Test Case | Status |
|----|-----------|-----------|--------|
| AC-001 | [Criterion 1] | TC-001 | [ ] |
| AC-002 | [Criterion 2] | TC-002 | [ ] |

## Performance Criteria
| ID | Criterion | Target | Measurement | Status |
|----|-----------|--------|-------------|--------|
| PC-001 | Latency | < 10ms | Timing test | [ ] |
| PC-002 | Memory | < 2KB | Memory analysis | [ ] |

## Reliability Criteria
| ID | Criterion | Test Method | Status |
|----|-----------|-------------|--------|
| RC-001 | Error handling | Fault injection | [ ] |
| RC-002 | Recovery | Recovery test | [ ] |
```

---

*Module 04 of the AI Champions Programme for Honeywell Embedded Engineering Teams*  
*Total Programme Duration: 24 Hours (3 Full Days × 8 Hours)*  
*Delivered by NIIT StackRoute*  
*Document Version: 1.0*
