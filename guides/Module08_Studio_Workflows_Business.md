# Module 08: Studio-Style Workflows for Business and Engineering Collaboration

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
3. [Studio-Style Workflows Overview](#3-studio-style-workflows-overview)
4. [Atlassian Rovo Studio Fundamentals](#4-atlassian-rovo-studio-fundamentals)
5. [Agent Authoring for Business Roles](#5-agent-authoring-for-business-roles)
6. [Grounding Agents on Jira and Confluence](#6-grounding-agents-on-jira-and-confluence)
7. [Translating Business Intent to Agentic Execution](#7-translating-business-intent-to-agentic-execution)
8. [Triggers, Actions, and Connectors](#8-triggers-actions-and-connectors)
9. [Approval Flows and Human-in-the-Loop](#9-approval-flows-and-human-in-the-loop)
10. [Permission-Aware Access and Governance](#10-permission-aware-access-and-governance)
11. [Versioning and Ownership of Workflows](#11-versioning-and-ownership-of-workflows)
12. [Hands-On Workshop](#12-hands-on-workshop)
13. [Success Metrics and Measurement](#13-success-metrics-and-measurement)
14. [Architecture Diagrams and Visual Flow](#14-architecture-diagrams-and-visual-flow)
15. [Reference Links and Resources](#15-reference-links-and-resources)

---

## 1. Module Overview

**Duration:** 2 Hours  
**Format:** Instructor-led + Hands-on Lab  
**Primary Tools:** Atlassian Rovo Studio, Jira/Confluence Sandbox Tenant, Sample Project and Space, Workflow Canvas, Studio-Pattern Examples, Business-User Templates

### Module Objectives

By the end of this module, participants will:

- Understand how non-code or semi-technical users shape agent behavior through studio-style workflows
- Author agents for program and product roles in Atlassian Rovo Studio
- Ground agents on Jira issues, Confluence documentation, and connected engineering sources
- Translate business intent into agentic execution
- Configure triggers, automation rules, actions, and connectors
- Implement approval flows and human-in-the-loop checkpoints
- Manage permission-aware access to project data
- Version and own published workflows
- Collaborate with technical owners without bypassing governance

### Module 08 Context: Building on Modules 01-07

| Calibration Finding | Module 08 Implication |
|---------------------|------------------------|
| Programme includes program/product roles | Enable non-code participation |
| MCP workflows built in Module 07 | Studio workflows complement engineering workflows |
| Governance is critical | Permission-aware access, approval flows |
| Advanced end-states vision | Multi-agent coordination foundation |

---

## 2. Calibration-Driven Design Insights

### 2.1 Business/Program Role Needs

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    CALIBRATION: BUSINESS/PROGRAM ROLE NEEDS              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ROLE PARTICIPATION                                            │   │
│  │                                                                │   │
│  │  Programme includes:                                          │   │
│  │  • Architects (21%)                                           │   │
│  │  • Developers (42%)                                           │   │
│  │  • Testers (5%)                                               │   │
│  │  • Engineering Managers (5%)                                  │   │
│  │  • Technical Leads (5%)                                       │   │
│  │  • Selected Program/Product roles                             │   │
│  │                                                                │   │
│  │  → Studio workflows enable non-code participation            │   │
│  │  → Business users can shape agent behavior                    │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  WORKFLOW AUTOMATION NEEDS                                     │   │
│  │                                                                │   │
│  │  Current manual workflows:                                    │   │
│  │  • Program reporting                                          │   │
│  │  • Issue triage                                               │   │
│  │  • Release coordination                                       │   │
│  │  • Status tracking                                            │   │
│  │                                                                │   │
│  │  → Studio workflows automate these processes                  │   │
│  │  → Governance maintained through approval flows               │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  GOVERNANCE REQUIREMENTS                                       │   │
│  │                                                                │   │
│  │  • Permission-aware access                                    │   │
│  │  • Approval workflows                                         │   │
│  │  • Audit trails                                               │   │
│  │  • Version control                                            │   │
│  │                                                                │   │
│  │  → Studio provides enterprise governance controls             │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 2.2 Studio vs Engineering Workflows

| Aspect | Studio Workflows | Engineering Workflows |
|--------|------------------|----------------------|
| Audience | Business/program roles | Technical roles |
| Tools | Jira, Confluence | GitHub, Build, Test |
| Focus | Process automation | Code implementation |
| Governance | Business rules | Technical gates |
| Examples | Program reporting, triage | Code review, testing |

### 2.3 Design Implications

1. **Business-User Focus** — Design for non-technical users
2. **Governance First** — Permission-aware, approval flows
3. **Jira/Confluence Integration** — Ground on existing tools
4. **Handoff to Technical** — Clear boundary with engineering workflows

---

## 3. Studio-Style Workflows Overview

### 3.1 What are Studio-Style Workflows?

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    STUDIO-STYLE WORKFLOWS                                 │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  DEFINITION                                                    │   │
│  │                                                                │   │
│  │  Studio-style workflows allow non-code or semi-technical      │   │
│  │  users to shape agent behavior through visual, guided         │   │
│  │  configuration rather than writing code.                      │   │
│  │                                                                │   │
│  │  Key Characteristics:                                         │   │
│  │  • Visual workflow builder                                    │   │
│  │  • Pre-built connectors                                       │   │
│  │  • No-code/low-code approach                                  │   │
│  │  • Business-user friendly                                     │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  USE CASES FOR EMBEDDED ENGINEERING                            │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Program reporting and status tracking                 │  │   │
│  │  │ • Issue triage and assignment                           │  │   │
│  │  │ • Release coordination                                  │  │   │
│  │  │ • Sprint planning assistance                            │  │   │
│  │  │ • Documentation generation                              │  │   │
│  │  │ • Stakeholder communication                             │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  WORKFLOW LAYERS                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Studio Layer (Business) ──→ Engineering Layer (Technical)│  │   │
│  │  │                                                         │  │   │
│  │  │ • Business rules        →    • Code implementation      │  │   │
│  │  │ • Process automation    →    • Build/test execution     │  │   │
│  │  │ • Approval flows        →    • Technical gates          │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 3.2 Studio vs Code-Based Workflows

| Aspect | Studio Workflows | Code-Based Workflows |
|--------|------------------|---------------------|
| Authoring | Visual builder | Code/CLI |
| Skills required | Domain knowledge | Programming |
| Maintenance | Point-and-click | Code changes |
| Governance | Built-in | Manual |
| Collaboration | Business + Technical | Technical only |

### 3.3 Workflow Types

| Type | Description | Example |
|------|-------------|---------|
| Reporting | Generate reports from data | Sprint status report |
| Triage | Classify and route issues | Bug prioritization |
| Coordination | Orchestrate multi-team activities | Release coordination |
| Notification | Alert stakeholders | Build failure notification |
| Documentation | Auto-generate docs | API documentation |

---

## 4. Atlassian Rovo Studio Fundamentals

### 4.1 Rovo Studio Architecture

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    ROVO STUDIO ARCHITECTURE                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  BUSINESS USERS                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Program managers                                      │  │   │
│  │  │ • Product owners                                        │  │   │
│  │  │ • Scrum masters                                         │  │   │
│  │  │ • Business analysts                                     │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ROVO STUDIO LAYER                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Visual workflow builder                               │  │   │
│  │  │ • Agent authoring                                       │  │   │
│  │  │ • Trigger configuration                                 │  │   │
│  │  │ • Action definitions                                    │  │   │
│  │  │ • Approval flows                                        │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONNECTORS                                                    │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Jira (issues, projects, sprints)                      │  │   │
│  │  │ • Confluence (pages, spaces, content)                   │  │   │
│  │  │ • GitHub (repos, PRs, issues)                           │  │   │
│  │  │ • Custom APIs (engineering tools)                       │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ENGINEERING TOOLS                                              │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • GitHub repositories                                  │  │   │
│  │  │ • CI/CD pipelines                                       │  │   │
│  │  │ • Build systems                                         │  │   │
│  │  │ • Test frameworks                                       │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 4.2 Rovo Studio Components

| Component | Purpose | User Interaction |
|-----------|---------|------------------|
| Workflow Canvas | Visual workflow builder | Drag-and-drop |
| Agent Builder | Configure agent behavior | Forms and templates |
| Trigger Editor | Define workflow triggers | Event selection |
| Action Editor | Define workflow actions | Connector configuration |
| Approval Flow | Define approval steps | Step configuration |
| Version Control | Manage workflow versions | Publish/rollback |

### 4.3 Rovo Studio vs Code-Based Agents

| Aspect | Rovo Studio | Code-Based Agents |
|--------|-------------|-------------------|
| Authoring | Visual | Code |
| Maintenance | Point-and-click | Code changes |
| Testing | Visual testing | Unit tests |
| Deployment | Publish button | CI/CD pipeline |
| Governance | Built-in | Manual |

---

## 5. Agent Authoring for Business Roles

### 5.1 Agent Authoring Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    AGENT AUTHORING FRAMEWORK                             │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  1. DEFINE AGENT PURPOSE                                       │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • What problem does the agent solve?                    │  │   │
│  │  │ • Who is the target user?                               │  │   │
│  │  │ • What data does it need?                               │  │   │
│  │  │ • What actions does it perform?                         │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  2. CONFIGURE AGENT BEHAVIOR                                   │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Set agent persona and expertise                       │  │   │
│  │  │ • Define response format                                │  │   │
│  │  │ • Configure data sources                                │  │   │
│  │  │ • Set action permissions                                │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  3. TEST AND VALIDATE                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Test with sample data                                 │  │   │
│  │  │ • Verify output format                                  │  │   │
│  │  │ • Check permissions                                     │  │   │
│  │  │ • Validate governance                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  4. PUBLISH AND SHARE                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Publish to team                                       │  │   │
│  │  │ • Set access permissions                                │  │   │
│  │  │ • Document usage                                        │  │   │
│  │  │ • Provide training                                      │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 5.2 Business Role Agent Types

| Agent Type | Purpose | Example |
|------------|---------|---------|
| Program Reporter | Generate status reports | Sprint summary |
| Issue Triager | Classify and route issues | Bug prioritization |
| Release Coordinator | Orchestrate releases | Version management |
| Documentation Assistant | Generate documentation | API docs |
| Stakeholder Communicator | Update stakeholders | Progress reports |

### 5.3 Agent Configuration Template

```yaml
# Agent Configuration Template
agent:
  name: "Program Status Reporter"
  description: "Generates weekly program status reports"
  persona: "Program management assistant"
  
data_sources:
  - type: jira
    project: "EMBEDDED"
    fields: ["status", "priority", "assignee", "due_date"]
  - type: confluence
    space: "Program-Reports"
    pages: ["weekly-status", "milestones"]
  
actions:
  - type: generate_report
    format: "markdown"
    template: "weekly-status-template"
  - type: publish
    destination: "confluence"
    space: "Program-Reports"
  
permissions:
  read: ["program-managers", "scrum-masters"]
  write: ["program-managers"]
  
approval:
  required: false
  approvers: ["program-director"]
```

---

## 6. Grounding Agents on Jira and Confluence

### 6.1 Grounding Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    GROUNDING AGENTS ON JIRA AND CONFLUENCE               │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  JIRA GROUNDING                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Project structure                                     │  │   │
│  │  │ • Issue types and workflows                             │  │   │
│  │  │ • Sprint and release information                        │  │   │
│  │  │ • Custom fields and labels                              │  │   │
│  │  │ • Issue relationships                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONFLUENCE GROUNDING                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Space structure                                       │  │   │
│  │  │ • Page hierarchy                                        │  │   │
│  │  │ • Content types                                         │  │   │
│  │  │ • Templates                                             │  │   │
│  │  │ • Labels and metadata                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  DATA EXTRACTION                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Query JQL for issues                                  │  │   │
│  │  │ • Fetch page content                                    │  │   │
│  │  │ • Extract structured data                               │  │   │
│  │  │ • Handle permissions                                    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 6.2 Jira Integration Patterns

| Pattern | Use Case | Example |
|---------|----------|---------|
| Issue Query | Fetch issues by criteria | "Get all bugs in current sprint" |
| Issue Update | Modify issue fields | "Set priority to High" |
| Issue Creation | Create new issues | "Create bug from defect report" |
| Workflow Transition | Move issues through workflow | "Move to In Progress" |
| Comment Management | Add/update comments | "Add status update" |

### 6.3 Confluence Integration Patterns

| Pattern | Use Case | Example |
|---------|----------|---------|
| Page Read | Fetch page content | "Read architecture document" |
| Page Write | Create/update pages | "Update sprint status" |
| Page Search | Search page content | "Find design decisions" |
| Page Template | Use page templates | "Generate status report" |
| Page Comment | Add comments | "Add review feedback" |

---

## 7. Translating Business Intent to Agentic Execution

### 7.1 Translation Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    BUSINESS INTENT TO EXECUTION                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  1. BUSINESS INTENT                                            │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ "Generate weekly program status report"                 │  │   │
│  │  │                                                         │  │   │
│  │  │ Components:                                             │  │   │
│  │  │ • Goal: Status report                                   │  │   │
│  │  │ • Frequency: Weekly                                     │  │   │
│  │  │ • Audience: Program stakeholders                        │  │   │
│  │  │ • Data: Jira issues, Confluence pages                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  2. WORKFLOW DESIGN                                            │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Trigger: Schedule (every Monday 9 AM)                   │  │   │
│  │  │                                                         │  │   │
│  │  │ Actions:                                                │  │   │
│  │  │ 1. Query Jira for current sprint issues                 │  │   │
│  │  │ 2. Fetch Confluence status page                         │  │   │
│  │  │ 3. Aggregate data                                       │  │   │
│  │  │ 4. Generate report using template                       │  │   │
│  │  │ 5. Publish to Confluence                                │  │   │
│  │  │ 6. Notify stakeholders                                  │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  3. AGENTIC EXECUTION                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Agent executes workflow:                                │  │   │
│  │  │ • Calls Jira connector                                  │  │   │
│  │  │ • Calls Confluence connector                            │  │   │
│  │  │ • Processes data                                        │  │   │
│  │  │ • Generates output                                      │  │   │
│  │  │ • Publishes results                                     │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 7.2 Business Intent Patterns

| Pattern | Example | Agent Execution |
|---------|---------|-----------------|
| Report Generation | "Create sprint report" | Query data, format, publish |
| Issue Triage | "Prioritize incoming bugs" | Analyze, classify, assign |
| Status Update | "Update stakeholders" | Fetch status, compose, send |
| Documentation | "Document API changes" | Extract changes, generate docs |
| Coordination | "Coordinate release" | Orchestrate tasks, track progress |

### 7.3 Intent Translation Checklist

- [ ] Business goal clearly defined
- [ ] Data sources identified
- [ ] Output format specified
- [ ] Audience defined
- [ ] Frequency/schedule determined
- [ ] Approval requirements identified
- [ ] Permissions configured
- [ ] Error handling defined

---

## 8. Triggers, Actions, and Connectors

### 8.1 Trigger Types

| Trigger Type | Description | Example |
|--------------|-------------|---------|
| Schedule | Time-based trigger | Every Monday 9 AM |
| Event | Event-based trigger | Issue created |
| Manual | User-initiated | Click button |
| Webhook | External system trigger | GitHub push |
| Condition | State-based trigger | Sprint starts |

### 8.2 Action Types

| Action Type | Description | Example |
|-------------|-------------|---------|
| Query | Fetch data | Get Jira issues |
| Transform | Process data | Aggregate metrics |
| Generate | Create content | Generate report |
| Publish | Output results | Post to Confluence |
| Notify | Send notifications | Email stakeholders |
| Update | Modify data | Update issue status |

### 8.3 Connector Types

| Connector | Capabilities | Use Case |
|-----------|--------------|----------|
| Jira | Issues, projects, sprints | Issue management |
| Confluence | Pages, spaces, content | Documentation |
| GitHub | Repos, PRs, issues | Code integration |
| Email | Send, receive | Notifications |
| Slack | Messages, channels | Team communication |
| Custom | API integration | Specialized tools |

---

## 9. Approval Flows and Human-in-the-Loop

### 9.1 Approval Flow Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    APPROVAL FLOW FRAMEWORK                               │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  APPROVAL TYPES                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Auto-approve (no human needed)                        │  │   │
│  │  │ • Single approver                                       │  │   │
│  │  │ • Multiple approvers (any)                              │  │   │
│  │  │ • Multiple approvers (all)                              │  │   │
│  │  │ • Escalation                                            │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  APPROVAL WORKFLOW                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ 1. Agent prepares action                                │  │   │
│  │  │ 2. Agent submits for approval                           │  │   │
│  │  │ 3. Approver reviews                                     │  │   │
│  │  │ 4. Approver approves/rejects                            │  │   │
│  │  │ 5. Agent executes or aborts                             │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  HUMAN-IN-THE-LOOP PATTERNS                                    │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Review before publish                                 │  │   │
│  │  │ • Approve before execute                                │  │   │
│  │  │ • Confirm before send                                   │  │   │
│  │  │ • Validate before commit                                │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 9.2 Approval Configuration

| Setting | Options | Use Case |
|---------|---------|----------|
| Approval required | Yes/No | Critical vs routine actions |
| Approvers | Users, groups, roles | Who can approve |
| Timeout | Duration | Auto-escalation |
| Escalation | User, group | Timeout handler |
| Notification | Email, Slack | Approval requests |

### 9.3 Human-in-the-Loop Checkpoints

| Checkpoint | Description | When to Use |
|------------|-------------|-------------|
| Review | Human reviews output | Before publishing |
| Approve | Human approves action | Before execution |
| Confirm | Human confirms intent | Before sending |
| Validate | Human validates data | Before processing |
| Decide | Human makes decision | Ambiguous situations |

---

## 10. Permission-Aware Access and Governance

### 10.1 Permission Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    PERMISSION FRAMEWORK                                  │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PERMISSION LEVELS                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • None (no access)                                      │  │   │
│  │  │ • Read (view only)                                      │  │   │
│  │  │ • Write (create/modify)                                 │  │   │
│  │  │ • Admin (full control)                                  │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PERMISSION ASSIGNMENT                                         │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ By role:                                                 │  │   │
│  │  │ • Program Manager: Read Jira, Write Confluence          │  │   │
│  │  │ • Developer: Read/Write GitHub                          │  │   │
│  │  │ • Tester: Read GitHub, Write Test Results               │  │   │
│  │  │                                                         │  │   │
│  │  │ By workflow:                                             │  │   │
│  │  │ • Reporting workflow: Read Jira, Write Confluence       │  │   │
│  │  │ • Triage workflow: Read/Write Jira                      │  │   │
│  │  │ • Build workflow: Read GitHub, Execute Build            │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  GOVERNANCE CONTROLS                                           │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Audit logging (all actions)                           │  │   │
│  │  │ • Access review (periodic)                              │  │   │
│  │  │ • Permission expiration                                 │  │   │
│  │  │ • Exception handling                                    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 10.2 Governance Model

| Aspect | Description | Implementation |
|--------|-------------|----------------|
| Audit | Track all actions | Log every workflow execution |
| Review | Periodic access review | Quarterly permission audit |
| Compliance | Policy enforcement | Automated compliance checks |
| Reporting | Governance metrics | Dashboard and reports |

### 10.3 Permission Matrix Example

| Workflow | Jira | Confluence | GitHub | Email |
|----------|------|------------|--------|-------|
| Program Reporting | Read | Write | - | Send |
| Issue Triage | Read/Write | - | - | - |
| Release Coordination | Read | Read | Read | Send |
| Build Automation | - | - | Read/Execute | - |

---

## 11. Versioning and Ownership of Workflows

### 11.1 Versioning Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    VERSIONING FRAMEWORK                                  │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  VERSION SCHEME                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Major.Minor.Patch                                       │  │   │
│  │  │                                                         │  │   │
│  │  │ • Major: Breaking changes                               │  │   │
│  │  │ • Minor: New features                                   │  │   │
│  │  │ • Patch: Bug fixes                                      │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  VERSION LIFECYCLE                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ 1. Draft (work in progress)                             │  │   │
│  │  │ 2. Review (peer review)                                 │  │   │
│  │  │ 3. Approved (ready to publish)                          │  │   │
│  │  │ 4. Published (active)                                   │  │   │
│  │  │ 5. Deprecated (obsolete)                                │  │   │
│  │  │ 6. Archived (removed)                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  VERSION CONTROL                                               │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Change log                                            │  │   │
│  │  │ • Rollback capability                                   │  │   │
│  │  │ • Parallel versions                                     │  │   │
│  │  │ • Version comparison                                    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 11.2 Ownership Model

| Role | Responsibility | Permissions |
|------|----------------|-------------|
| Author | Create/maintain workflow | Full control |
| Reviewer | Review changes | Read, Comment |
| Approver | Approve for publication | Approve |
| Consumer | Use published workflow | Execute |
| Admin | Manage access and governance | Admin |

### 11.3 Workflow Documentation

| Document | Content | Location |
|----------|---------|----------|
| README | Overview and usage | Workflow root |
| CHANGELOG | Version history | Workflow root |
| CONFIGURATION | Setup instructions | Workflow root |
| TROUBLESHOOTING | Common issues | Workflow root |
| API REFERENCE | Connector details | Workflow root |

---

## 12. Hands-On Workshop

### 12.1 Workshop Structure

**Duration:** 1.5 hours  
**Format:** Hands-on lab with Atlassian Rovo Studio

### 12.2 Lab Exercise

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    WORKSHOP EXERCISE                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 1: WORKFLOW DESIGN (30 minutes)                          │   │
│  │                                                                │   │
│  │  Task: Design a studio workflow for business users            │   │
│  │                                                                │   │
│  │  Options:                                                     │   │
│  │  A. Program Status Reporting                                  │   │
│  │  B. Issue Triage and Assignment                               │   │
│  │  C. Release Coordination                                      │   │
│  │                                                                │   │
│  │  Activities:                                                  │   │
│  │  1. Define workflow purpose and audience                      │   │
│  │  2. Identify data sources (Jira, Confluence)                  │   │
│  │  3. Design workflow steps                                     │   │
│  │  4. Define approval requirements                             │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 2: WORKFLOW IMPLEMENTATION (40 minutes)                 │   │
│  │                                                                │   │
│  │  Task: Implement workflow in Rovo Studio                      │   │
│  │                                                                │   │
│  │  Activities:                                                  │   │
│  │  1. Create workflow in Rovo Studio                            │   │
│  │  2. Configure Jira connector                                  │   │
│  │  3. Configure Confluence connector                            │   │
│  │  4. Set up triggers and actions                               │   │
│  │  5. Configure approval flow                                   │   │
│  │  6. Set permissions                                           │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 3: TESTING AND VALIDATION (30 minutes)                  │   │
│  │                                                                │   │
│  │  Task: Test workflow with sample data                         │   │
│  │                                                                │   │
│  │  Activities:                                                  │   │
│  │  1. Test with sample Jira project                             │   │
│  │  2. Verify Confluence output                                  │   │
│  │  3. Test approval flow                                        │   │
│  │  4. Validate permissions                                      │   │
│  │  5. Document evidence                                         │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PHASE 4: HANDOFF TO TECHNICAL (20 minutes)                    │   │
│  │                                                                │   │
│  │  Task: Document workflow for technical handoff                │   │
│  │                                                                │   │
│  │  Activities:                                                  │   │
│  │  1. Document workflow purpose and usage                       │   │
│  │  2. Document permissions and governance                       │   │
│  │  3. Create handoff document                                   │   │
│  │  4. Review with technical owner                               │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 12.3 Measurement Worksheet

| Metric | Phase 1 | Phase 2 | Phase 3 | Phase 4 |
|--------|---------|---------|---------|---------|
| Time spent | __ min | __ min | __ min | __ min |
| Workflows designed | __ | __ | __ | __ |
| Connectors configured | __ | __ | __ | __ |
| Tests executed | __ | __ | __ | __ |
| Issues found | __ | __ | __ | __ |
| Handoff complete | __ | __ | __ | __% |

---

## 13. Success Metrics and Measurement

### 13.1 Module 08 Metrics Framework

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    MODULE 08 SUCCESS METRICS                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  WORKFLOW METRICS                                              │   │
│  │  • Workflows created                                          │   │
│  │  • Workflow completion rate                                   │   │
│  │  • Time to create workflow                                    │   │
│  │  • Workflow adoption                                          │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  GOVERNANCE METRICS                                            │   │
│  │  • Approval compliance                                        │   │
│  │  • Permission adherence                                       │   │
│  │  • Audit log completeness                                     │   │
│  │  • Version control compliance                                 │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  BUSINESS VALUE METRICS                                        │   │
│  │  • Time saved per workflow                                    │   │
│  │  • Manual effort reduced                                      │   │
│  │  • Error reduction                                            │   │
│  │  • Stakeholder satisfaction                                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 13.2 Baseline vs Target

| Metric | Before Module 08 | Target After Module 08 |
|--------|------------------|------------------------|
| Business user participation | Limited | Active workflow creation |
| Workflow automation | Manual | Studio-automated |
| Governance | Ad-hoc | Structured |
| Technical handoff | Informal | Documented process |

---

## 14. Architecture Diagrams and Visual Flow

### 14.1 Studio Workflow Architecture

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    STUDIO WORKFLOW ARCHITECTURE                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  BUSINESS USER                                                 │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ "Create weekly status report"                           │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  ROVO STUDIO WORKFLOW                                          │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Trigger: Schedule (Monday 9 AM)                         │  │   │
│  │  │                                                         │  │   │
│  │  │ Actions:                                                │  │   │
│  │  │ 1. Query Jira (current sprint issues)                   │  │   │
│  │  │ 2. Fetch Confluence (status page)                       │  │   │
│  │  │ 3. Generate report                                      │  │   │
│  │  │ 4. Publish to Confluence                                │  │   │
│  │  │ 5. Notify stakeholders                                  │  │   │
│  │  │                                                         │  │   │
│  │  │ Approval: Program Manager review                        │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  CONNECTORS                                                    │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ Jira ──→ Confluence ──→ Email                           │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  OUTPUT                                                        │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Status report published                               │  │   │
│  │  │ • Stakeholders notified                                 │  │   │
│  │  │ • Audit trail created                                   │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

### 14.2 Handoff Flow

```
┌─────────────────────────────────────────────────────────────────────────┐
│                    HANDOFF FLOW                                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  BUSINESS USER CREATES WORKFLOW                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Design in Rovo Studio                                 │  │   │
│  │  │ • Configure connectors                                  │  │   │
│  │  │ • Test with sample data                                 │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  DOCUMENTATION                                                 │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Workflow purpose                                      │  │   │
│  │  │ • Configuration details                                 │  │   │
│  │  │ • Permission requirements                               │  │   │
│  │  │ • Governance rules                                      │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  TECHNICAL HANDOFF                                             │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Technical owner reviews                               │  │   │
│  │  │ • Integration with engineering workflows                │  │   │
│  │  │ • Monitoring setup                                      │  │   │
│  │  │ • Support procedures                                    │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                              │                                          │
│                              ▼                                          │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │  PRODUCTION USE                                                │   │
│  │  ┌─────────────────────────────────────────────────────────┐  │   │
│  │  │ • Workflow runs on schedule                             │  │   │
│  │  │ • Business user monitors                                │  │   │
│  │  │ • Technical owner supports                              │  │   │
│  │  │ • Continuous improvement                                │  │   │
│  │  └─────────────────────────────────────────────────────────┘  │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 15. Reference Links and Resources

### 15.1 Atlassian Rovo Studio Resources

| Resource | URL | Description |
|----------|-----|-------------|
| Rovo Studio Docs | https://www.atlassian.com/software/rovo/studio | Official documentation |
| Rovo API | https://developer.atlassian.com/platform/rovo/ | API reference |
| Jira Automation | https://support.atlassian.com/jira-service-management-cloud/docs/ | Jira automation |
| Confluence API | https://developer.atlassian.com/cloud/confluence/rest/v2/ | Confluence API |

### 15.2 Workflow Design Resources

| Resource | URL | Description |
|----------|-----|-------------|
| Workflow Patterns | https://www.workflowpatterns.com/ | Design patterns |
| Business Process | https://www.bpm.com/ | BPM resources |
| Low-Code Platforms | https://www.outsystems.com/ | Low-code examples |

### 15.3 Honeywell Internal Resources

| Resource | Location | Description |
|----------|----------|-------------|
| AI Champions Programme | NIIT StackRoute Platform | Course materials |
| Honeywell Training Sheet | Internal SharePoint | Training requirements |
| Jira Projects | Internal Jira | Sample projects |
| Confluence Spaces | Internal Confluence | Sample spaces |

---

## Appendix A: Workflow Templates

### A.1 Program Status Report Template

```yaml
# Program Status Report Workflow
name: "Weekly Program Status Report"
description: "Generates and publishes weekly program status reports"

trigger:
  type: schedule
  schedule: "0 9 * * 1"  # Every Monday at 9 AM
  
data_sources:
  - type: jira
    query: "project = EMBEDDED AND sprint in openSprints()"
    fields: ["summary", "status", "priority", "assignee", "due_date"]
  - type: confluence
    page: "Program-Reports/Status-Template"
    
actions:
  - name: "Aggregate Data"
    type: transform
    script: "aggregate_sprint_data"
    
  - name: "Generate Report"
    type: generate
    template: "weekly-status"
    output: "Program-Reports/Weekly-Status-{date}"
    
  - name: "Notify Stakeholders"
    type: notify
    recipients: ["program-managers", "scrum-masters"]
    message: "Weekly status report published"
    
approval:
  required: true
  approvers: ["program-director"]
  timeout: "24h"
  escalation: "program-vp"
    
permissions:
  read: ["program-managers", "scrum-masters", "stakeholders"]
  write: ["program-managers"]
  admin: ["program-director"]
```

### A.2 Issue Triage Template

```yaml
# Issue Triage Workflow
name: "Automated Issue Triage"
description: "Classifies and routes incoming issues"

trigger:
  type: event
  event: "jira.issue_created"
  filter: "project = EMBEDDED AND issuetype = Bug"
    
data_sources:
  - type: jira
    issue: "{{event.issue_key}}"
    fields: ["summary", "description", "priority", "components"]
    
actions:
  - name: "Classify Issue"
    type: transform
    script: "classify_bug_severity"
    
  - name: "Assign to Team"
    type: update
    target: "jira"
    issue: "{{event.issue_key}}"
    fields:
      priority: "{{classification.priority}}"
      components: "{{classification.components}}"
      
  - name: "Notify Team"
    type: notify
    recipients: "{{classification.team}}"
    message: "New bug assigned: {{event.issue.summary}}"
    
approval:
  required: false
    
permissions:
  read: ["developers", "testers", "scrum-masters"]
  write: ["triage-team"]
  admin: ["engineering-managers"]
```

---

*Module 08 of the AI Champions Programme for Honeywell Embedded Engineering Teams*  
*Total Programme Duration: 24 Hours (3 Full Days × 8 Hours)*  
*Delivered by NIIT StackRoute*  
*Document Version: 1.0*
