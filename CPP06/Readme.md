# 📘 CPP06 – Casting, Parsing & RTTI (Concept Summary)

This document summarizes **all mandatory concepts used in CPP Module 06** at 42.
CPP06 focuses on **type conversion**, **safe casting**, **runtime type identification (RTTI)**, and **string parsing** using both C and C++ mechanisms.

---

## 1. Why CPP06 Exists

CPP06 teaches you **how C++ treats memory and types**.

You learn:

* How raw memory becomes a value
* How the compiler protects (or does not protect) you
* When conversions are safe, unsafe, or undefined
* Why C-style casts are dangerous

This module is about **control**, not convenience.

---

## 2. Parsing Strings into Numbers (ex00)

### 2.1 Two Worlds: C vs C++ Parsing

C++ offers multiple ways to convert strings into values:

| Method                     | Language | Safety  | Notes                          |
| -------------------------- | -------- | ------- | ------------------------------ |
| `atoi`, `strtod`, `strtof` | C        | ❌ Weak  | No exceptions, silent failures |
| `stringstream`             | C++      | ✅ Safer | Type-aware, controllable       |

CPP06 **forces you to understand both**.

---

### 2.2 C Conversion Functions

Used in **ex00**:

```cpp
int     i = atoi(str.c_str());
double  d = strtod(str.c_str(), NULL);
float   f = strtof(str.c_str(), NULL);
```

#### Characteristics:

* Read memory as raw characters
* Stop parsing on first invalid character
* Do **not throw exceptions**
* Overflow handling is inconsistent

This is why **manual validation is required** in CPP06.

---

### 2.3 std::stringstream Parsing

```cpp
std::stringstream ss(str);
ss >> value;
```

Advantages:

* Type-aware
* Detects leftover characters
* Integrates with C++ streams

In CPP06, stringstream is often used for **type detection**, not final conversion.

---

## 3. Scalar Conversion (ex00)

You detect the **literal type first**, then cast it.

Supported literals:

* `char`
* `int`
* `float`
* `double`
* pseudo-literals: `nan`, `inf`, `+inff`, etc.

### Important Rule

**Detection ≠ Conversion**

You must:

1. Detect the type from syntax
2. Convert once
3. Cast to all other types

This avoids inconsistent results.

---

## 4. C++ Cast Operators (Core of CPP06)

CPP06 introduces **four explicit C++ casts**.

### 4.1 static_cast

```cpp
int i = static_cast<int>(3.14);
```

* Compile-time cast
* No runtime checks
* Safe for numeric conversions
* Dangerous for unrelated pointers

Used heavily in **ex00**.

---

### 4.2 dynamic_cast (ex02 – RTTI)

```cpp
Base* b = new A;
A* a = dynamic_cast<A*>(b);
```

#### Key Properties:

* Runtime-checked cast
* Requires at least one **virtual function**
* Returns `NULL` (pointer)
* Throws `std::bad_cast` (reference)

Used to **safely identify derived classes**.

---

### dynamic_cast Failure Handling

Pointer version:

```cpp
if (dynamic_cast<A*>(p))
```

Reference version:

```cpp
try {
    dynamic_cast<A&>(p);
} catch (...) {}
```

This is mandatory in **ex02**.

---

### 4.3 const_cast

```cpp
const int* p;
int* q = const_cast<int*>(p);
```

* Removes constness
* ❌ Undefined behavior if object was originally const
* Rarely justified

Not used in CPP06, but important to recognize.

---

### 4.4 reinterpret_cast (ex01 – Serialization)

```cpp
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
Data* d = reinterpret_cast<Data*>(raw);
```

#### What reinterpret_cast REALLY Does

* Does **not** convert values
* Reinterprets **raw memory bits**
* Tells the CPU: *"Read this memory differently"*

No safety. No checks.

---

## 5. reinterpret_cast vs Other Casts

| Cast             | Safety | Runtime Check | Usage                      |
| ---------------- | ------ | ------------- | -------------------------- |
| static_cast      | Medium | ❌             | Numeric, up/down casts     |
| dynamic_cast     | High   | ✅             | Polymorphic hierarchies    |
| const_cast       | Low    | ❌             | Remove const               |
| reinterpret_cast | ❌❌❌    | ❌             | Bit-level reinterpretation |

`reinterpret_cast` is the **most dangerous cast in C++**.

CPP06 teaches **why it exists**, not when to abuse it.

---

## 6. Serialization (ex01)

### Goal

Convert a pointer to an integer and back **without loss**.

```cpp
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
```

Why `uintptr_t`?

* Guaranteed to hold pointer values
* Portable
* No truncation

This exercise teaches:

* Pointers are just numbers
* Types are a compiler abstraction

---

## 7. Runtime Type Identification (RTTI) – ex02

RTTI allows discovering the **real type of an object at runtime**.

Requirements:

* Base class must be polymorphic
* `dynamic_cast` relies on RTTI tables

```cpp
class Base { virtual ~Base(); };
```

Without virtual functions → RTTI disabled.

---

## 8. Why C-style Casts Are Forbidden

```cpp
(int)x; // ❌
```

C-style casts:

* Combine all cast types silently
* Hide dangerous conversions
* Break type safety

C++ casts force you to **state your intent**.

CPP06 exists to break this habit.

---

## 9. How the Compiler Sees Casts

* No runtime polymorphism for `static_cast`
* `dynamic_cast` generates RTTI tables
* `reinterpret_cast` is a no-op at runtime

In assembly:

* reinterpret_cast produces **zero instructions**
* dynamic_cast generates lookup code

---

## 10. Common 42 Grading Traps (CPP06)

❌ Using C-style casts
❌ Mixing detection and conversion
❌ Ignoring overflow
❌ Missing virtual destructor
❌ Using typeid (forbidden)
❌ Not handling reference dynamic_cast exceptions

---

## 11. Key Interview Takeaways

* Casting ≠ conversion
* reinterpret_cast does not change data
* dynamic_cast requires polymorphism
* RTTI is runtime, templates are compile-time
* Pointers are just addresses

---

## 12. CPP06 Core Concepts Checklist

✅ Scalar parsing
✅ C vs C++ conversion
✅ static_cast
✅ dynamic_cast
✅ reinterpret_cast
✅ RTTI
✅ Safe failure handling
✅ Serialization

---

**CPP06 teaches you how dangerous C++ can be — and how to control it.**
