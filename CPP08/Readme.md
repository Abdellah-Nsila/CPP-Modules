# 📘 C++ Module 08 – STL, Containers, Iterators & Algorithms

---

# 🧠 Overview

Module 08 introduces one of the most powerful parts of C++: the **Standard Template Library (STL)**.

This module is not about syntax. It is about understanding:

* Generic programming
* Template-based design
* Containers
* Iterators
* Algorithms
* Container adaptors
* Complexity awareness
* STL architecture philosophy

After this module, you should understand *how modern C++ is engineered*.

---

# 1️⃣ What Is the STL?

The **Standard Template Library (STL)** is a generic library composed of:

* **Containers** → store data
* **Iterators** → access data
* **Algorithms** → operate on ranges
* **Functors** → customize behavior

## 🔥 Core Principle

> Algorithms operate on iterators, not containers.

This separation makes STL flexible, reusable, and extremely powerful.

---

# 2️⃣ Containers

A **container** is a data structure that stores objects.

Containers manage:

* Memory
* Element lifetime
* Insertion/removal
* Size tracking

---

## 🔹 A) Sequence Containers

Elements are stored in insertion order.

| Container     | Memory Model       | Notes                      |
| ------------- | ------------------ | -------------------------- |
| `std::vector` | Contiguous array   | Fast random access         |
| `std::deque`  | Segmented memory   | Fast push front/back       |
| `std::list`   | Doubly linked list | Fast insert/erase anywhere |

### Vector

* Contiguous memory
* Cache-friendly
* Random access O(1)
* Insert in middle O(n)

### Deque

* Not contiguous
* Fast push_front + push_back
* Random access O(1)

### List

* Node-based
* No random access
* Insert/erase O(1) if iterator known

---

## 🔹 B) Associative Containers

Sorted containers implemented using **balanced binary trees (usually Red-Black Trees)**.

| Container       | Key Properties         |
| --------------- | ---------------------- |
| `std::set`      | Unique sorted keys     |
| `std::map`      | Key-value pairs        |
| `std::multiset` | Duplicate keys allowed |
| `std::multimap` | Duplicate keys allowed |

Operations:

* Insert → O(log n)
* Search → O(log n)
* Always sorted

---

## 🔹 C) Container Adaptors

Adaptors wrap another container and restrict its interface.

| Adaptor               | Behavior   |
| --------------------- | ---------- |
| `std::stack`          | LIFO       |
| `std::queue`          | FIFO       |
| `std::priority_queue` | Heap-based |

They do NOT expose iterators.

Example internal structure of `std::stack`:

```cpp
template <class T, class Container = std::deque<T>>
class stack {
protected:
    Container c;
};
```

They enforce behavior restrictions intentionally.

---

# 3️⃣ Iterators

An **iterator** is an abstraction over a pointer.

It allows traversal of container elements without exposing internal structure.

Example:

```cpp
std::vector<int>::iterator it;
```

Basic operations:

```cpp
*it
++it
--it
```

---

# 4️⃣ Iterator Categories

Iterators are categorized by capability.

| Category      | Capabilities       |
| ------------- | ------------------ |
| Input         | Read forward       |
| Output        | Write forward      |
| Forward       | Read/write forward |
| Bidirectional | Forward + backward |
| Random Access | Jump anywhere      |

Examples:

* `vector` → Random Access
* `deque` → Random Access
* `list` → Bidirectional
* `set/map` → Bidirectional

---

# 5️⃣ Why Algorithms Exist

Instead of writing loops manually:

```cpp
for (...) { ... }
```

We use:

```cpp
std::sort(begin, end);
std::find(begin, end, value);
std::min_element(begin, end);
```

## Why?

* Reusable
* Generic
* Optimized
* Safer
* Work with any container that provides iterators

Algorithms do not care about container type.

They only require iterator ranges:

```cpp
[begin, end)
```

---

# 6️⃣ The Range Concept

STL uses half-open intervals:

```cpp
[begin, end)
```

Advantages:

* Works for empty ranges
* Easy size calculation
* Prevents off-by-one errors

---

# 7️⃣ Why Templates Are Powerful

Templates allow writing generic code:

```cpp
template <typename T>
class Array;
```

Instead of duplicating code for every type.

Benefits:

* Type safety
* No runtime overhead
* Compile-time resolution
* Code reuse

STL is entirely template-based.

---

# 8️⃣ Separation of Responsibilities

| Component | Responsibility    |
| --------- | ----------------- |
| Container | Store data        |
| Iterator  | Traverse data     |
| Algorithm | Process data      |
| Adaptor   | Restrict behavior |

Each part does one job.

This is clean architecture design.

---

# 9️⃣ Time Complexity Awareness

Choosing the right container matters.

| Operation | Vector     | Set           |
| --------- | ---------- | ------------- |
| Insert    | O(1)*      | O(log n)      |
| Search    | O(n)       | O(log n)      |
| Sort      | O(n log n) | Always sorted |

(*amortized)

Performance decisions define good design.

---

# 🔟 Why Stack Has No Iterators

Stack enforces LIFO abstraction.

Allowing iteration would:

* Break strict stack discipline
* Allow access to middle elements

That is why `std::stack` hides iterators.

MutantStack exposes them by accessing protected member `c`.

---

# 1️⃣1️⃣ Design Philosophy of STL

STL follows:

* Generic programming
* Compile-time polymorphism
* Zero-cost abstraction
* Separation of concerns
* Performance predictability

It avoids:

* Virtual functions
* Runtime overhead
* Hidden complexity

Everything is explicit and deterministic.

---

# 1️⃣2️⃣ What Module 08 Teaches

By completing CPP08, you understand:

* How containers manage memory
* How iterators abstract traversal
* How algorithms operate generically
* How adaptors restrict interfaces
* How templates enable reuse
* How to reason about complexity

You move from writing loops to using powerful abstractions correctly.

---

# 🎯 Final Understanding

C++ STL is built on this formula:

```
Containers + Iterators + Algorithms + Templates = Powerful Generic System
```

CPP08 is the moment where C++ stops being "just syntax" and becomes a real engineering tool.

Mastering this module means you understand the architecture behind modern C++.

---

# 🚀 End of README

You are no longer just coding.

You are understanding system design.
