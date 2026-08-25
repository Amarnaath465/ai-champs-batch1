# Module 03: Prompt Engineering Recap and Context Engineering

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
3. [Prompt Engineering Fundamentals for Embedded Systems](#3-prompt-engineering-fundamentals-for-embedded-systems)
4. [Context Engineering for Embedded Repositories](#4-context-engineering-for-embedded-repositories)
5. [Context Selection and Layering](#5-context-selection-and-layering)
6. [Token-Aware Practices](#6-token-aware-practices)
7. [Context Compression Techniques](#7-context-compression-techniques)
8. [Task-Scoped Context Patterns](#8-task-scoped-context-patterns)
9. [Prompt-Only vs Context-Engineered Comparison](#9-prompt-only-vs-context-engineered-comparison)
10. [Hands-On Workshop](#10-hands-on-workshop)
11. [Success Metrics and Measurement](#11-success-metrics-and-measurement)
12. [Architecture Diagrams and Visual Flow](#12-architecture-diagrams-and-visual-flow)
13. [Reference Links and Resources](#13-reference-links-and-resources)

---

## 1. Module Overview

**Duration:** 2 Hours  
**Format:** Instructor-led + Hands-on Lab  
**Primary Tools:** Copilot, Prompt/Context Templates, C/C++ Repository Examples, Token Usage Worksheet

### Module Objectives

By the end of this module, participants will:

- Recap practical prompt engineering techniques for embedded software tasks
- Understand context engineering principles for embedded repositories
- Apply context selection, layering, and compression strategies
- Implement task-scoped context patterns
- Use token-aware practices to optimize AI interactions
- Compare prompt-only vs context-engineered approaches with measurable outcomes

### Module 03 Context: Building on Modules 01-02

| Calibration Finding | Module 03 Implication |
|---------------------|------------------------|
| 53% use ad-hoc prompting | Teach structured context engineering |
| Fragmented change-impact analysis | Show how context improves analysis |
| 42% have weak automated validation | Connect context to test generation |
| MCP is #1 priority (68%) | Preview context integration with MCP |

---

## 2. Calibration-Driven Design Insights

### 2.1 Current Context Supply Methods

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CALIBRATION: CONTEXT SUPPLY METHODS                   │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CURRENT CONTEXT METHODS                                        │   │
│  │                                                                │   │
│  │  Ad-hoc prompting            ████████████████████████  53%    │   │
│  │  Repository context          ████████████              21%    │   │
│  │  Documentation/specs         ████████                  16%    │   │
│  │  Hand-picked files           ██████                    11%    │   │
│  │                                                                │   │
│  │  → 53% use ad-hoc prompting (highest adoption)               │   │
│  │  → Structured context engineering is rare                     │   │
│  │  → Direct driver of token inefficiency                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONTEXT SCOPING CHALLENGES                                     │   │
│  │                                                                │   │
│  │  "Give the agent only the feature's requirements, directly     │   │
│  │   relevant source/header pairs, and minimal supporting context │   │
│  │   — not the entire repository."                                │   │
│  │                                                                │   │
│  │  → Strong consensus even before SDD training                  │   │
│  │  → Module 03 formalises this instinct                          │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.2 Token Inefficiency Patterns

| Pattern | Impact | Module 03 Response |
|---------|--------|-------------------|
| Large repository dumps | Token waste, diluted context | Teach task-scoped context |
| Unstructured prompts | Inconsistent output | Introduce prompt templates |
| No context boundaries | Hallucination risk | Define context boundaries |
| Missing design context | Poor code quality | Add design docs to context |

### 2.3 Design Implications

1. **Recap Before Advance** — Ensure solid prompt engineering foundation
2. **Context as First-Class Concern** — Treat context selection as engineering discipline
3. **Token Economics** — Connect context quality to cost and performance
4. **Repository Awareness** — Build on Module 02's repository-aware assistance

---

## 3. Prompt Engineering Fundamentals for Embedded Systems

### 3.1 The Prompt Engineering Pyramid

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    PROMPT ENGINEERING PYRAMID                             │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│                          ┌─────────┐                                    │
│                          │ VERITY  │                                    │
│                          │(Verify) │                                    │
│                         ┌┴─────────┴┐                                   │
│                         │ ITERATION │                                   │
│                         │ (Refine)  │                                   │
│                        ┌┴───────────┴┐                                  │
│                        │DECOMPOSITION│                                  │
│                        │ (Break Down)│                                  │
│                       ┌┴─────────────┴┐                                 │
│                       │  EXAMPLES     │                                 │
│                       │ (Show/Teach)  │                                 │
│                      ┌┴───────────────┴┐                                │
│                      │  CONSTRAINTS    │                                │
│                      │ (Boundaries)    │                                │
│                     ┌┴─────────────────┴┐                               │
│                     │  INSTRUCTIONS     │                               │
│                     │ (What to Do)      │                               │
│                    ┌┴───────────────────┴┐                              │
│                    │  TASK FRAMING       │                              │
│                    │ (Clear Objective)   │                              │
│                    └─────────────────────┘                              │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 3.2 Task Framing for Embedded Systems

| Component | Embedded Application | Example |
|-----------|---------------------|---------|
| Objective | What to implement | "Implement a UART driver for STM32" |
| Scope | Boundaries | "Only TX/RX, no flow control" |
| Constraints | Limits | "Must use HAL library, < 1KB RAM" |
| Output | Expected result | "C source + header + unit tests" |

### 3.3 Instructions That Work

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EFFECTIVE INSTRUCTION PATTERNS                         │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ROLE ASSIGNMENT                                                │   │
│  │  "You are an embedded software engineer specializing in        │   │
│  │   C/C++ firmware for safety-critical systems."                 │   │
│  │                                                                │   │
│  │  → Sets domain context immediately                            │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TASK SPECIFICATION                                             │   │
│  │  "Implement a circular buffer for UART receive with:"          │   │
│  │  • Thread-safe access (mutex protection)                       │   │
│  │  • Configurable size (compile-time define)                     │   │
│  │  • Overflow detection                                          │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONSTRAINT DEFINITION                                          │   │
│  │  "Follow these constraints:"                                    │   │
│  │  • No dynamic allocation (embedded requirement)                │   │
│  │  • MISRA-C compliant                                           │   │
│  │  • Maximum 512 bytes RAM                                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 3.4 Embedded-Specific Prompt Patterns

| Pattern | Use Case | Example Prompt |
|---------|----------|----------------|
| HAL-Aware | Driver generation | "Generate SPI driver using STM32 HAL" |
| State-Machine | Protocol implementation | "Implement Modbus state machine" |
| ISR-Safe | Interrupt handlers | "Create UART RX ISR with ring buffer" |
| Timing-Conscious | Real-time code | "Implement scheduler with 1ms tick" |
| Memory-Constrained | Resource-limited | "Optimize for 64KB Flash target" |

---

## 4. Context Engineering for Embedded Repositories

### 4.1 Context Engineering vs Prompt Engineering

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    PROMPT ENGINEERING vs CONTEXT ENGINEERING              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PROMPT ENGINEERING                                             │   │
│  │  • Focuses on HOW you ask                                      │   │
│  │  • Instruction wording and structure                           │   │
│  │  • Task decomposition                                          │   │
│  │  • Example selection                                           │   │
│  │  • Iterative refinement                                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONTEXT ENGINEERING                                            │   │
│  │  • Focuses on WHAT information you provide                     │   │
│  │  • Repository content selection                                │   │
│  │  • Design document inclusion                                   │   │
│  │  • Interface contract exposure                                 │   │
│  │  • Token budget management                                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  COMBINED EFFECT                                                │   │
│  │  • Clear instructions + Right context = Best output            │   │
│  │  • Poor context limits even the best prompts                   │   │
│  │  • Context engineering is the multiplier                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 4.2 Embedded Repository Context Types

| Context Type | Content | Value |
|--------------|---------|-------|
| Source Files | .c, .cpp implementations | Code patterns, logic |
| Headers | .h, .hpp interfaces | API contracts, types |
| Build Files | Makefile, CMakeLists.txt | Dependencies, toolchain |
| Configuration | .cfg, .json, .yaml | Runtime parameters |
| Design Docs | Architecture, diagrams | Design intent |
| Coding Standards | Style guides, rules | Compliance rules |
| Issue History | Bug reports, features | Change context |
| Tests | Unit, integration | Validation patterns |

### 4.3 HAL Boundaries and Interfaces

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    HAL BOUNDARY CONTEXT                                   │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  APPLICATION LAYER                                              │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │  Business Logic                                          │  │   │
│  │  │  • Feature implementation                                │  │   │
│  │  │  • State management                                      │  │   │
│  │  │  • Data processing                                       │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  HAL INTERFACE (Critical Context)                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │  Abstract Hardware Access                                │  │   │
│  │  │  • GPIO_ReadPin(), GPIO_WritePin()                       │  │   │
│  │  │  • UART_Send(), UART_Receive()                           │  │   │
│  │  │  • SPI_Transfer()                                        │  │   │
│  │  │  • Timer_Start(), Timer_Stop()                           │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  HARDWARE LAYER                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │  Peripheral Registers                                    │  │   │
│  │  │  • Memory-mapped I/O                                     │  │   │
│  │  │  • Interrupt vectors                                     │  │   │
│  │  │  • DMA channels                                          │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 4.4 State Machine Context

| Context Element | What to Include | Why It Matters |
|-----------------|-----------------|----------------|
| States | All possible states | Complete coverage |
| Transitions | Valid state changes | Prevent invalid paths |
| Events | Triggering conditions | Correct behavior |
| Actions | Entry/exit behaviors | Implementation detail |
| Guards | Transition conditions | Business rules |

---

## 5. Context Selection and Layering

### 5.1 Context Selection Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CONTEXT SELECTION FRAMEWORK                            │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  1. TASK ANALYSIS                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ What is the engineering task?                           │  │   │
│  │  │ What files are directly relevant?                       │  │   │
│  │  │ What interfaces are involved?                           │  │   │
│  │  │ What constraints apply?                                 │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  2. CONTEXT GATHERING                                           │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Primary: Direct task files (source + headers)           │  │   │
│  │  │ Secondary: Related interfaces (HAL, contracts)          │  │   │
│  │  │ Tertiary: Supporting docs (design, standards)           │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  3. TOKEN BUDGET ALLOCATION                                     │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Total budget: ~8K tokens (typical)                      │  │   │
│  │  │ Primary files: 60% (4.8K)                               │  │   │
│  │  │ Secondary files: 25% (2K)                               │  │   │
│  │  │ Tertiary docs: 15% (1.2K)                               │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 5.2 Context Layering Strategy

| Layer | Content | When to Include |
|-------|---------|-----------------|
| **Layer 1: Core** | Task file + immediate dependencies | Always |
| **Layer 2: Interface** | HAL boundaries, contracts | When modifying interfaces |
| **Layer 3: Design** | Architecture docs, diagrams | When changing structure |
| **Layer 4: Standards** | Coding rules, style guides | Always for compliance |
| **Layer 5: History** | Issue context, past changes | When debugging/regression |

### 5.3 Context Boundary Patterns

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CONTEXT BOUNDARY PATTERNS                             │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  FUNCTION-LEVEL BOUNDARY                                        │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Input: Function signature + docstring                   │  │   │
│  │  │ Context: Implementation file + direct includes          │  │   │
│  │  │ Output: Function body                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  MODULE-LEVEL BOUNDARY                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Input: Module header + interface contracts              │  │   │
│  │  │ Context: Related modules + HAL boundaries               │  │   │
│  │  │ Output: Module implementation                           │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  FEATURE-LEVEL BOUNDARY                                        │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Input: Feature specification + acceptance criteria      │  │   │
│  │  │ Context: Affected modules + build configuration         │  │   │
│  │  │ Output: Complete feature implementation                 │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 6. Token-Aware Practices

### 6.1 Token Budget Management

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    TOKEN BUDGET MANAGEMENT                                │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TOKEN BUDGET BREAKDOWN                                         │   │
│  │                                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │  TOTAL CONTEXT WINDOW: ~8,000 tokens                    │  │   │
│  │  │                                                         │  │   │
│  │  │  ┌───────────────────────────────────────────────────┐ │  │   │
│  │  │  │ Task Description        ████         10% (800)   │ │  │   │
│  │  │  │ Primary Files           ████████████ 40% (3,200) │ │  │   │
│  │  │  │ Supporting Files        ██████████   25% (2,000) │ │  │   │
│  │  │  │ Design/Standards        ████████     15% (1,200) │ │  │   │
│  │  │  │ Response Buffer         ████████     10% (800)   │ │  │   │
│  │  │  └───────────────────────────────────────────────────┘ │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 6.2 Token Optimization Strategies

| Strategy | Technique | Token Savings |
|----------|-----------|---------------|
| File Selection | Only include relevant files | 30-50% |
| Code Summarization | Summarize non-critical sections | 20-30% |
| Interface Extraction | Extract only API contracts | 40-60% |
| Snippet Inclusion | Include relevant snippets only | 50-70% |
| Reference Links | Link to docs instead of including | 60-80% |

### 6.3 Avoiding Context Inflation

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    AVOIDING CONTEXT INFLATION                             │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ANTI-PATTERNS (Don't Do This)                                  │   │
│  │                                                                │   │
│  │  ✗ Paste entire repository                                     │   │
│  │  ✗ Include all header files                                     │   │
│  │  ✗ Add unrelated test files                                    │   │
│  │  ✗ Include full build logs                                      │   │
│  │  ✗ Paste complete configuration files                          │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  BEST PRACTICES (Do This Instead)                               │   │
│  │                                                                │   │
│  │  ✓ Select specific files relevant to task                     │   │
│  │  ✓ Include only affected interfaces                           │   │
│  │  ✓ Reference design docs by path, not content                 │   │
│  │  ✓ Summarize build configuration                              │   │
│  │  ✓ Include only relevant code snippets                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 7. Context Compression Techniques

### 7.1 Source/Header Compression

| Technique | Before | After | Savings |
|-----------|--------|-------|---------|
| Full File | 500 lines | 500 lines | 0% |
| Function Signatures | 500 lines | 50 lines | 90% |
| Interface Only | 500 lines | 20 lines | 96% |
| API Summary | 500 lines | 10 lines | 98% |

### 7.2 Design Document Compression

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    DESIGN DOCUMENT COMPRESSION                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  FULL DOCUMENT (10,000 tokens)                                  │   │
│  │  • Complete architecture document                              │   │
│  │  • All diagrams and descriptions                               │   │
│  │  • Full requirements traceability                              │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  COMPRESSED (2,000 tokens)                                      │   │
│  │  • Key architectural decisions                                 │   │
│  │  • Affected module descriptions                                │   │
│  │  • Relevant interface contracts                                │   │
│  │  • Critical constraints                                        │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  MINIMAL (500 tokens)                                           │   │
│  │  • Module responsibility summary                               │   │
│  │  • Key interface signatures                                    │   │
│  │  • Critical constraints only                                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 7.3 Build Configuration Compression

| Element | Full Content | Compressed Representation |
|---------|--------------|---------------------------|
| Makefile | 200 lines | "Uses GCC ARM, -O2 optimization, -Wall warnings" |
| CMakeLists | 150 lines | "CMake project, targets STM32F4, includes HAL" |
| linker.ld | 100 lines | "64KB Flash, 8KB RAM, sections: .text, .data, .bss" |

---

## 8. Task-Scoped Context Patterns

### 8.1 Pattern: New Feature Implementation

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    NEW FEATURE CONTEXT PATTERN                            │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONTEXT STRUCTURE                                              │   │
│  │                                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ 1. FEATURE SPECIFICATION                                │  │   │
│  │  │    • Requirements                                        │  │   │
│  │  │    • Acceptance criteria                                 │  │   │
│  │  │    • Constraints                                         │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ 2. AFFECTED INTERFACES                                  │  │   │
│  │  │    • Header files (API contracts)                       │  │   │
│  │  │    • HAL boundaries                                     │  │   │
│  │  │    • Data structures                                    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ 3. EXISTING PATTERNS                                    │  │   │
│  │  │    • Similar implementations                            │  │   │
│  │  │    • Coding conventions                                 │  │   │
│  │  │    • Test patterns                                      │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 8.2 Pattern: Bug Fix / Regression

| Context Element | Content | Purpose |
|-----------------|---------|---------|
| Error Description | Symptom + reproduction steps | Understand the problem |
| Affected Code | Function with bug | Locate the issue |
| Related Tests | Existing test cases | Validate the fix |
| History | Recent changes | Identify regression source |
| Constraints | Timing, memory | Ensure fix doesn't break |

### 8.3 Pattern: Refactoring

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    REFACTORING CONTEXT PATTERN                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  REFACTORING CONTEXT STRUCTURE                                  │   │
│  │                                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ CURRENT STATE                                           │  │   │
│  │  │ • Function/file to refactor                             │  │   │
│  │  │ • Current behavior description                          │  │   │
│  │  │ • Known issues                                          │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ TARGET STATE                                             │  │   │
│  │  │ • Desired behavior                                      │  │   │
│  │  │ • Quality goals (readability, performance)              │  │   │
│  │  │ • Constraints (backward compatibility)                  │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ SAFETY BOUNDARIES                                        │  │   │
│  │  │ • Interface contracts to preserve                       │  │   │
│  │  │ • Test cases to maintain                                │  │   │
│  │  │ • Performance requirements                              │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 9. Prompt-Only vs Context-Engineered Comparison

### 9.1 Side-by-Side Comparison

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    PROMPT-ONLY vs CONTEXT-ENGINEERED                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌──────────────────────────────────┐  ┌──────────────────────────────┐│
│  │  PROMPT-ONLY                     │  │  CONTEXT-ENGINEERED          ││
│  │                                  │  │                              ││
│  │  "Write a UART driver"          │  │  "Write a UART driver"       ││
│  │                                  │  │                              ││
│  │  No context provided:           │  │  Context provided:           ││
│  │  • No repository structure      │  │  • uart.h (interface)        ││
│  │  • No HAL boundaries            │  │  • hal.h (HAL API)           ││
│  │  • No coding standards          │  │  • coding_standards.md       ││
│  │  • No existing patterns         │  │  • similar_driver.c (example)││
│  │                                  │  │                              ││
│  │  Result: Generic, may not       │  │  Result: Targeted, follows   ││
│  │  match project conventions      │  │  project conventions         ││
│  └──────────────────────────────────┘  └──────────────────────────────┘│
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 9.2 Measurable Differences

| Metric | Prompt-Only | Context-Engineered | Improvement |
|--------|-------------|-------------------|-------------|
| Code quality | 6/10 | 8.5/10 | +42% |
| Iterations to complete | 5-7 | 2-3 | -57% |
| Token usage | 12,000 | 6,000 | -50% |
| Time to completion | 45 min | 20 min | -56% |
| Coding standard compliance | 40% | 95% | +138% |
| Test coverage | 30% | 80% | +167% |

### 9.3 Example: UART Driver

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    EXAMPLE: UART DRIVER IMPLEMENTATION                    │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PROMPT-ONLY OUTPUT                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ // Generic UART driver - no project context             │  │   │
│  │  void uart_init(void) {                                    │  │   │
│  │      // Implementation without HAL awareness              │  │   │
│  │      // May not match existing patterns                   │  │   │
│  │      // No error handling                                 │  │   │
│  │      // No test coverage                                  │  │   │
│  │  }                                                         │  │   │
│  │  // Missing: HAL calls, error codes, configuration        │  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONTEXT-ENGINEERED OUTPUT                                     │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ // UART driver matching project conventions             │  │   │
│  │  │ #include "hal_uart.h"                                   │  │   │
│  │  │ #include "error_codes.h"                                │  │   │
│  │  │                                                         │  │   │
│  │  │ // Uses HAL API as defined in hal.h                     │  │   │
│  │  │ // Follows error handling pattern from similar_driver.c │  │   │
│  │  │ // Includes configuration structure                     │  │   │
│  │  │ // Includes unit tests                                  │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 10. Hands-On Workshop

### 10.1 Workshop Structure

**Duration:** 1.5 hours  
**Format:** Hands-on lab with C/C++ embedded codebase

### 10.2 Lab Exercise

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    WORKSHOP EXERCISE                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 1: PROMPT-ONLY ATTEMPT (20 minutes)                     │   │
│  │                                                                │   │
│  │  Task: Implement a circular buffer for UART receive            │   │
│  │                                                                │   │
│  │  Approach: Use only a basic prompt, no context                │   │
│  │  Prompt: "Write a circular buffer for UART receive in C"      │   │
│  │                                                                │   │
│  │  Measure:                                                     │   │
│  │  • Time to completion                                         │   │
│  │  • Number of iterations                                       │   │
│  │  • Token usage                                                │   │
│  │  • Code quality assessment                                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 2: CONTEXT-ENGINEERED ATTEMPT (30 minutes)              │   │
│  │                                                                │   │
│  │  Task: Same implementation with structured context            │   │
│  │                                                                │   │
│  │  Context to provide:                                          │   │
│  │  • uart.h (interface contract)                                │   │
│  │  • hal.h (HAL API)                                            │   │
│  │  • existing_buffer.c (similar pattern)                        │   │
│  │  • coding_standards.md (project rules)                        │   │
│  │  • buffer_requirements.txt (specification)                    │   │
│  │                                                                │   │
│  │  Measure: Same metrics as Phase 1                             │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 3: COMPARISON AND ANALYSIS (20 minutes)                 │   │
│  │                                                                │   │
│  │  Activities:                                                  │   │
│  │  1. Compare outputs side-by-side                              │   │
│  │  2. Measure token usage difference                            │   │
│  │  3. Assess code quality and standard compliance               │   │
│  │  4. Document lessons learned                                  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 10.3 Measurement Worksheet

| Metric | Phase 1 (Prompt-Only) | Phase 2 (Context-Engineered) | Delta |
|--------|----------------------|------------------------------|-------|
| Time to completion | __ min | __ min | __% |
| Iterations | __ | __ | __% |
| Token usage | __ | __ | __% |
| Code quality (1-10) | __ | __ | __% |
| Standard compliance | __% | __% | __% |
| Test coverage | __% | __% | __% |

---

## 11. Success Metrics and Measurement

### 11.1 Module 03 Metrics Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    MODULE 03 SUCCESS METRICS                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONTEXT QUALITY METRICS                                        │   │
│  │  • Token usage per task                                         │   │
│  │  • Context relevance score                                      │   │
│  │  • Iteration count reduction                                    │   │
│  │  • Output quality improvement                                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PRODUCTIVITY METRICS                                           │   │
│  │  • Time to completion                                          │   │
│  │  • First-pass success rate                                     │   │
│  │  • Rework frequency                                            │   │
│  │  • Code review pass rate                                       │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  COST METRICS                                                   │   │
│  │  • Token consumption per feature                               │   │
│  │  • API call frequency                                          │   │
│  │  • Cost per task completion                                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 11.2 Baseline vs Target

| Metric | Before Module 03 | Target After Module 03 |
|--------|------------------|------------------------|
| Token usage per task | 12,000 | 6,000 |
| Iterations to complete | 5-7 | 2-3 |
| Context supply method | 53% ad-hoc | 80% structured |
| Code quality score | 6/10 | 8.5/10 |

---

## 12. Architecture Diagrams and Visual Flow

### 12.1 Context Engineering Flow

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CONTEXT ENGINEERING FLOW                               │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  1. TASK ANALYSIS                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ What is the engineering task?                           │  │   │
│  │  │ What are the constraints?                               │  │   │
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
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  3. CONTEXT COMPRESSION                                        │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Apply compression techniques                            │  │   │
│  │  │ Allocate token budget                                   │  │   │
│  │  │ Remove irrelevant content                               │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  4. CONTEXT INJECTION                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Structure prompt with task + context                    │  │   │
│  │  │ Set clear boundaries                                    │  │   │
│  │  │ Define expected output format                           │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  5. ITERATION & VERIFICATION                                   │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Generate output                                          │  │   │
│  │  │ Verify against requirements                             │  │   │
│  │  │ Refine context if needed                                │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 12.2 Context Layering Diagram

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CONTEXT LAYERING DIAGRAM                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│                    ┌─────────────────────────────┐                      │
│                    │      LAYER 5: HISTORY       │                      │
│                    │  (Issue context, changes)   │                      │
│                    └─────────────────────────────┘                      │
│                              │                                          │
│                    ┌─────────────────────────────┐                      │
│                    │     LAYER 4: STANDARDS      │                      │
│                    │  (Coding rules, style)      │                      │
│                    └─────────────────────────────┘                      │
│                              │                                          │
│                    ┌─────────────────────────────┐                      │
│                    │     LAYER 3: DESIGN         │                      │
│                    │  (Architecture, diagrams)   │                      │
│                    └─────────────────────────────┘                      │
│                              │                                          │
│                    ┌─────────────────────────────┐                      │
│                    │     LAYER 2: INTERFACE      │                      │
│                    │  (HAL, contracts)           │                      │
│                    └─────────────────────────────┘                      │
│                              │                                          │
│                    ┌─────────────────────────────┐                      │
│                    │     LAYER 1: CORE           │                      │
│                    │  (Task file + dependencies) │                      │
│                    └─────────────────────────────┘                      │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 13. Reference Links and Resources

### 13.1 Prompt Engineering Resources

| Resource | URL | Description |
|----------|-----|-------------|
| GitHub Copilot Docs | https://docs.github.com/copilot | Official Copilot documentation |
| Prompt Engineering Guide | https://www.promptingguide.ai | Comprehensive prompt engineering |
| OpenAI Prompt Best Practices | https://platform.openai.com/docs/guides/prompt-engineering | Best practices guide |
| Anthropic Prompt Library | https://docs.anthropic.com/claude/docs/prompt-library | Claude prompt examples |

### 13.2 Context Engineering Resources

| Resource | URL | Description |
|----------|-----|-------------|
| LangChain Context | https://python.langchain.com/docs/concepts/context | Context engineering concepts |
| RAG Patterns | https://docs.llamaindex.ai/en/stable/understanding/rag/ | Retrieval-augmented generation |
| Token Optimization | https://help.openai.com/en/articles/4936856-what-are-tokens-and-how-to-count-them | Token counting guide |

### 13.3 Embedded Engineering Resources

| Resource | URL | Description |
|----------|-----|-------------|
| C/C++ Best Practices | https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines | C++ guidelines |
| Embedded C Guidelines | https://github.com/ProgrammingGuidelines | Embedded C best practices |
| MISRA C | https://www.misra.org.uk | Automotive C standard |

### 13.4 Honeywell Internal Resources

| Resource | Location | Description |
|----------|----------|-------------|
| AI Champions Programme | NIIT StackRoute Platform | Course materials and labs |
| Honeywell Training Sheet | Internal SharePoint | Training requirements |
| Embedded Coding Standards | Internal Documentation | Honeywell-specific standards |
| Repository Access | GitHub Enterprise | Approved C/C++ repositories |

---

## Appendix A: Context Engineering Checklist

### Pre-Task Context Checklist

- [ ] Task clearly defined with objectives
- [ ] Relevant source files identified
- [ ] Header files / interfaces included
- [ ] HAL boundaries understood
- [ ] Build configuration referenced
- [ ] Coding standards included
- [ ] Design docs referenced (not full content)
- [ ] Token budget allocated
- [ ] Context boundaries defined
- [ ] Expected output format specified

### Context Quality Scorecard

| Criterion | Score (1-5) | Notes |
|-----------|-------------|-------|
| Task clarity | | |
| File relevance | | |
| Interface coverage | | |
| Constraint documentation | | |
| Token efficiency | | |
| Output quality | | |

---

*Module 03 of the AI Champions Programme for Honeywell Embedded Engineering Teams*  
*Total Programme Duration: 24 Hours (3 Full Days × 8 Hours)*  
*Delivered by NIIT StackRoute*  
*Document Version: 1.0*
