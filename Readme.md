gcc code/main.c code/tree.c code/primes.c code/solver.c -o main -Wall -Wextra -O2
./main

# CSPC32 - Binary Tree Communication Problem

This project is part of my **Data Structures** coursework (Assignment 7–11).  
It mainly deals with **binary trees**, **prime number generation**, and **bitwise operations (XOR)** — applying DS concepts to a real-world-style problem.

---

## Problem Overview

We are given the *level order traversal* of a family tree where each member is represented as a node in a **binary tree**.

### Task 1: Minimum Phones (Tree + DFS)
We need to find the **minimum number of phones** that should be distributed among family members such that:
- Every member can communicate with at least one person.
- A person with a phone can share it with their **parent** or **children**.
- If a member doesn’t have a phone, they can only receive communication (not share further).

This is solved using a **binary tree traversal (DFS)** approach that decides whether a node:
- Has a phone,
- Is covered by another’s phone, or
- Still needs coverage.

### Task 2: Out-of-Range Pairs (Primes + XOR)
Once we know the minimum phones `m`, we assign **prime numbers** to each phone.  
The “communication distance” between two phones is the **XOR** of their prime values.

We then count how many phone pairs have XOR distances **outside** a given range `[l, r]`.

---

## Data Structures Used

| Data Structure | Purpose | Operations |
|----------------|----------|-------------|
| **Binary Tree** | Represents the family hierarchy | Construction from level order, DFS traversal |
| **Queue (array-based)** | Used while building the tree from level order | Insert, delete (O(1)) |
| **Array** | Stores level order data, prime numbers, XOR results | Sequential access (O(1)) |
| **Dynamic Memory Allocation (malloc/free)** | For flexible node and array creation | O(1) allocation per object |

---

## Algorithmic Approach

### 1 Build Tree
- Uses an **array-based queue** to connect child nodes while traversing the level order input.
- Time Complexity: **O(n)**  
- Space Complexity: **O(n)**  

### 2 Minimum Phones (DFS on Binary Tree)
- Each node returns one of three states:  
  `0` → needs phone, `1` → has phone, `2` → covered.  
- Phones are placed greedily from bottom-up.
- Time Complexity: **O(n)**  
- Space Complexity: **O(h)** (recursion stack, where h is tree height)

### 3 Prime Generation (Sieve of Eratosthenes)
- Finds the first `m` prime numbers efficiently using a sieve.
- Time Complexity: **O(N log log N)**, where N ≈ m·log(m)
- Space Complexity: **O(N)**  

### 4 Pair Counting (Nested Loops + XOR)
- Computes XOR for every pair of primes and checks range `[l, r]`.
- Time Complexity: **O(m²)**  
- Space Complexity: **O(m)**  

 ### to compile without makefile -
 - gcc code/main.c code/tree.c code/primes.c code/solver.c -o main -Wall -Wextra -O2


