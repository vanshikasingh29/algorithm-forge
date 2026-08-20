<div align="center">

# Algorithm Forge

### Production-Oriented Algorithms & Data Structures in C

A systems-level algorithm library built from first principles, exploring
complexity analysis, recursion, dynamic programming, graph algorithms,
search, sorting, and balanced trees.


![Language](https://img.shields.io/badge/Language-C-blue)
![Standard](https://img.shields.io/badge/Standard-C17-blue)
![Testing](https://img.shields.io/badge/Testing-Automated-success)
![Algorithms](https://img.shields.io/badge/Algorithms-From%20First%20Principles-purple)
![Status](https://img.shields.io/badge/Status-Complete-success)

</div>

---

# Project Overview

Algorithm Forge is an algorithm engineering platform built from first principles.

The project implements multiple algorithmic strategies for solving common
computational problems and evaluates them using both:

- mathematical complexity analysis
- empirical performance measurements


# Objectives

The project demonstrates:

- algorithmic problem solving
- asymptotic analysis
- recursion
- dynamic programming
- searching
- sorting
- graph algorithms
- shortest-path algorithms
- balanced search trees
- memory-aware C programming
- automated testing
- performance analysis
  
The objective is not simply to implement algorithms.

The objective is to understand **why one algorithm performs better than
another and under which conditions.**

---

# Architecture

```
Algorithm Forge
│
├── include/
│   └── Public algorithm interfaces
│
├── src/
│   └── Algorithm implementations
│
├── tests/
│   └── Automated correctness tests
│
├── benchmarks/
│   └── Performance experiments
│
├── docs/
│   └── Complexity and algorithm documentation
│
└── Makefile
```
---

# Core Philosophy

```
Problem
   ↓
Algorithm
   ↓
Data Structure
   ↓
Complexity Analysis
   ↓
Implementation
   ↓
Benchmark
   ↓
Engineering Decision
```
# Project  Coverage

> The project consolidates the concepts studied throughout Phase 3 of CS From First Principles.

#### Topic 11 — Asymptotic Analysis

Implemented and analysed:

- Big-O
- Big-Theta
- Big-Omega
- time complexity
- space complexity
- empirical performance

#### Topic 12 — Dynamic Programming

Algorithms include:

- Fibonacci
- 0/1 Knapsack
- Longest Common Subsequence

Concepts demonstrated:

- overlapping subproblems
- optimal substructure
- memorisation
- tabulation
  
#### Topic 13 — Greedy Algorithms

Algorithms include:

- Activity Selection
- Fractional Knapsack

Concepts demonstrated:

- greedy choice property
- local optimisation
- proof of correctness
- comparison with dynamic programming

#### Topic 14 — Graph Algorithms

Implemented algorithms include:

- Breadth-First Search
- Depth-First Search
- Dijkstra
- Bellman-Ford
- A*
- Floyd-Warshall

Applications include:

- route optimisation
- network analysis
- dependency exploration

#### Topic 15 — Balanced Trees

Implemented:

- AVL Trees
- rotations
- insertion
- search
- deletion

The implementation demonstrates how balancing maintains logarithmic
search complexity.

# Engineering Goals

The project focuses on:

- correctness
- asymptotic efficiency
- memory usage
- modular architecture
- testability
- benchmarking
- algorithm comparison
- maintainability

# Why This Project Exists

Many implementations demonstrate that an algorithm works.

Algorithm Forge asks a more important engineering question:

> How does the algorithm behave as the problem grows?

For example:
```
Linear Search


O(n)


        vs


Binary Search


O(log n)
```

Both solve a search problem.

Their engineering characteristics are fundamentally different.

## Benchmarking

Algorithm Forge includes a benchmarking layer.

Algorithms are evaluated against increasing input sizes.

Example:
```
Input Size


100
1000
10000
100000
```
Measurements can then be compared against theoretical complexity.

This allows:
```
Mathematical Prediction


        vs


Observed Runtime
```

Complexity Analysis

Each implementation documents its expected complexity.

Example:
```
| Algorithm     | Time             | Space          |
| ------------- | ---------------- | -------------- |
| Linear Search | O(n)             | O(1)           |
| Binary Search | O(log n)         | O(1)           |
| BFS           | O(V + E)         | O(V)           |
| Dijkstra      | O((V + E) log V) | O(V)           |
| AVL Search    | O(log n)         | O(1) auxiliary |
```

The purpose is to connect implementation directly to mathematical
analysis.

# Software Engineering

The project uses a modular C architecture:
```
Headers
   ↓
Implementation
   ↓
Tests
   ↓
Benchmarks
   ↓
Analysis
```
Components are separated so that algorithms can be independently tested
and benchmarked.

# Technologies
###### Language
- C17

###### Tooling
- GCC
- Make
- Git
- GDB
- Engineering Practices
- modular design
- automated testing
- complexity analysis
- benchmarking
- defensive programming
- documentation
  
# Connection To CS From First Principles

Algorithm Forge represents the third stage of the learning journey.
```
Phase 1
Mathematical Foundations
        ↓
Logic Query Engine


Phase 2
Systems Architecture
        ↓
Systems Engineering Project


Phase 3
Algorithms & Data Structures
        ↓
Algorithm Forge
```

The progression is deliberate:
```
Mathematics
    ↓
Machines
    ↓
Algorithms
    ↓
Systems
Future Development
```

Planned extensions include:

- Red-Black Trees
- B-Trees
- A* heuristics
- priority queues
- advanced graph representations
- parallel benchmarking
- memory profiling
- cache-aware algorithms
- visualisation of algorithm behaviour
- automated complexity reports
- Engineering Philosophy

Algorithms are not just code.

They are mathematical models implemented on physical machines.

Understanding both sides is essential.
```
Mathematical Model
        +
Data Structure
        +
Implementation
        +
Hardware Behaviour
        =
Algorithm Engineering
```

# Author
Computer Science student developing deeper understanding of:

- algorithms
- data structures
- systems engineering
- mathematical foundations
- performance engineering

Algorithm Forge is part of the CS From First Principles learning journey.
