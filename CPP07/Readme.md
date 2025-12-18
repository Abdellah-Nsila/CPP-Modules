# 📘 CPP07 – Templates (Concept Summary)

This document summarizes **all mandatory template concepts** required for **CPP07 (42 School)**, with emphasis on **how the compiler works**, **why design constraints exist**, and **what interviewers expect you to understand**.

---

## 1. What is a Template?

A **template** is a **compile-time mechanism** that allows writing **generic code**.
Instead of duplicating logic for multiple types (`int`, `float`, `std::string`, etc.), templates let the **compiler generate type-specific code automatically**.

⚠️ Templates are **not real code** until the compiler **instantiates** them.

```cpp
template <typename T>
T add(T a, T b)
{
    return a + b;
}
```

This single definition can generate:

* `int add(int, int)`
* `float add(float, float)`
* `std::string add(std::string, std::string)`

---

## 2. Template Types

### 2.1 Function Templates

Used when **behavior is identical** for multiple types.

```cpp
template <typename T>
void print(T value)
{
    std::cout << value << std::endl;
}
```

Instantiation happens when called:

```cpp
print<int>(42);
print("Hello"); // type deduction
```

---

### 2.2 Class Templates

Used to build **generic data structures**.

```cpp
template <typename T>
class Array
{
    T* data;
};
```

Each type creates a **completely different class**:

* `Array<int>`
* `Array<std::string>`

They are **separate types** in memory, symbols, and ABI.

---

### 2.3 Template Parameters

| Kind               | Example      |
| ------------------ | ------------ |
| Type parameter     | `typename T` |
| Non-type parameter | `int N`      |
| Function parameter | `typename F` |

```cpp
template <typename T, unsigned int N>
void foo(T (&arr)[N]);
```

---

## 3. Compilation Stages & Templates

### 3.1 Normal Compilation

1. Preprocessing
2. Compilation → object file
3. Linking

---

### 3.2 Template Compilation (Important!)

Templates **do not generate code when compiled**.

They generate code **only when**:

* A **concrete type is used**
* The compiler **sees the full definition**

❌ This fails:

```cpp
template <typename T>
void foo(T x); // declaration only
```

✔ This works:

```cpp
template <typename T>
void foo(T x) { /* implementation */ }
```

📌 This is why **templates must be header-only** (`.hpp` / `.tpp`).

---

## 4. Template Instantiation (How the Compiler Generates Code)

```cpp
Array<int> a;
Array<std::string> b;
```

The compiler generates:

```cpp
class Array_int { ... };
class Array_string { ... };
```

At assembly level:

* One symbol per instantiated type
* No runtime polymorphism
* No vtable unless `virtual` is used

➡️ Templates provide **compile-time polymorphism**.

---

## 5. Template Type Deduction

The compiler deduces template parameters from arguments:

```cpp
template <typename T>
void print(T);

print(42);    // T = int
print(3.14);  // T = double
```

Explicit instantiation:

```cpp
print<int>(42);
```

Used when deduction is **ambiguous or impossible**.

---

## 6. Const vs Non-Const in Templates

Templates enforce **strict const-correctness**.

```cpp
template <typename T>
void foo(T& x);          // non-const

template <typename T>
void bar(const T& x);    // const
```

| Call             | Valid |
| ---------------- | ----- |
| `foo(const int)` | ❌     |
| `bar(const int)` | ✔     |
| `foo(int)`       | ✔     |

This is why CPP07 requires:

```cpp
T& operator[](unsigned int);
const T& operator[](unsigned int) const;
```

The compiler treats these as **two separate functions**.

---

## 7. Default Initialization vs Value Initialization

### 7.1 Default Initialization

```cpp
int* a = new int;
```

* Memory allocated
* Value is **uninitialized** (undefined)

---

### 7.2 Value Initialization

```cpp
int* b = new int();
```

* Memory allocated
* Value initialized to **0**

---

### 7.3 Arrays

```cpp
new int[n];     // undefined values
new int[n]();   // zero-initialized
```

📌 In CPP07:

> **Array elements must be default-initialized**

Correct form:

```cpp
new T[n]();
```

---

## 8. Const Arrays & Template Behavior

```cpp
template <typename T>
void print(const Array<T>& arr);
```

Requires:

* `size()` to be `const`
* `operator[] const`

Why?
Because **const objects cannot call non-const functions**.

---

## 9. Exception Safety in Templates

Your `Array` must guarantee:

* No memory leaks
* Deep copy semantics
* Safe assignment

Correct pattern:

```cpp
T* tmp = new T[n];
delete[] old;
old = tmp;
```

This provides **strong exception safety**.

---

## 10. Why Preventive Allocation Is Forbidden

```cpp
Array<T> arr(1000); // but only 3 used
```

Why forbidden:

* Wastes memory
* Hides bugs
* Breaks exception guarantees
* Violates strict ownership

CPP07 forces **precise memory control**.

---

## 11. Why Array<T> Is Harder Than It Looks

Because it combines:

* Templates
* Memory ownership
* Copy semantics
* Const correctness
* Exception safety
* Header-only compilation

This is why **`std::vector` exists**.

---

## 12. Why std::vector Exists

Your `Array<T>`:

* Fixed size
* Manual memory handling
* Error-prone

`std::vector`:

* Dynamic growth
* Allocators
* Strong exception safety
* Optimized
* ABI-stable

CPP07 makes you **earn** `std::vector`.

---

## 13. When to Use Templates

✅ Use when:

* Behavior identical across types
* Performance matters
* Compile-time polymorphism

❌ Avoid when:

* Runtime type switching required
* ABI stability matters
* Binary size must be small

---

## 14. Key Interview Takeaways

* Templates are compile-time
* Templates must be fully visible
* Each type generates separate code
* Const correctness is mandatory
* Templates ≠ inheritance
* STL is template-based

---

## 15. CPP07 Core Concepts Checklist

✅ Function templates
✅ Class templates
✅ Template instantiation
✅ Const vs non-const overloads
✅ Default vs value initialization
✅ Header-only design
✅ Deep copy semantics
✅ Exception safety
✅ Compile-time polymorphism

---

📌 **If you understand everything in this README, you fully understand CPP07.**
