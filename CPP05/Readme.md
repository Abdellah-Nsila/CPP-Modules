# 📘 CPP05 – Exceptions (Concept Summary)

## 1. What Are Exceptions?

An **exception** is a runtime error handling mechanism in C++.
Instead of returning error codes and manually checking them everywhere, exceptions allow **separating normal logic from error-handling logic**.

Exceptions are designed for:

* Invalid states
* Contract violations
* Impossible or forbidden operations

Example:

```cpp
if (grade < 1)
    throw GradeTooHighException();
```

---

## 2. Keywords: `try`, `throw`, `catch`

### 2.1 `throw`

`throw` is used to **signal an error**.

```cpp
throw std::exception();
throw GradeTooHighException();
```

Effects:

* Immediately stops normal execution
* Starts **stack unwinding**
* Transfers control to the nearest matching `catch`

---

### 2.2 `try`

Wraps code that **might fail**.

```cpp
try
{
    Bureaucrat b("Bob", 0);
}
```

---

### 2.3 `catch`

Handles the thrown exception.

```cpp
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

Key rules:

* Exceptions are matched **by type**
* Always catch by **reference** to avoid slicing
* Catch base classes (`std::exception`) **last**

---

## 3. `std::exception` (The Base Class)

Defined in:

```cpp
#include <exception>
```

It provides:

```cpp
virtual const char* what() const throw();
```

This enables **polymorphic error messages**.

---

## 4. Custom Exceptions (CPP05 Core Pattern)

### 4.1 The Syntax Explained

```cpp
class GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};
```

Meaning:

* `GradeTooHighException` **IS A** `std::exception`
* It overrides `what()`
* It can be caught as:

  * `GradeTooHighException`
  * `std::exception`

---

### 4.2 Why Nested Classes?

In CPP05, exceptions are often **nested inside the class that throws them**:

```cpp
class Bureaucrat
{
    class GradeTooHighException : public std::exception { ... };
};
```

Reasons:

* Logical ownership
* Clear semantic scope
* Avoids global name pollution

---

## 5. The `what()` Function

### 5.1 Definition

```cpp
const char* what() const throw();
```

Meaning:

* `const char*` → C-style error message
* `const` → does not modify the exception
* `throw()` → guarantees it will NOT throw

---

### 5.2 Implementation with Scope Resolution

```cpp
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is Too High";
}
```

Breakdown:

* `Bureaucrat::` → enclosing class scope
* `GradeTooHighException::` → nested exception
* `what()` → virtual override

This is **normal C++ scope resolution**, not template-related.

---

## 6. What Is `throw()` After a Function?

```cpp
const char* what() const throw();
```

This is an **exception specification** in **C++98**.

Meaning:

> "This function guarantees it will not throw any exceptions."

If it does:

* `std::unexpected()` is called
* Program terminates

⚠️ In modern C++, this is replaced by `noexcept`,
but **CPP05 uses C++98**, so `throw()` is mandatory.

---

## 7. Why `what()` Must Never Throw

Because:

* It is called **during error handling**
* Throwing from `what()` causes a **double exception**
* This results in `std::terminate()`

Rule:

```text
what() must be noexcept (throw())
```

---

## 8. Exception Flow (Step-by-Step)

```cpp
try
{
    Bureaucrat b("Alice", 151);
}
catch (const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

Execution order:

1. Constructor validates grade
2. `throw GradeTooLowException()`
3. Stack unwinding begins
4. Destructors of fully constructed objects are called
5. Matching `catch` is found
6. `what()` message is printed

---

## 9. Exception Safety Rules (Important for CPP05)

### 9.1 Constructors

If a constructor throws:

* Object is **not created**
* Destructor is **not called**
* Resources must already be safe

Best practices:

* Validate arguments early
* Avoid raw `new` before checks

---

### 9.2 Do NOT Catch Inside the Class

❌ Bad practice:

```cpp
try { ... } catch (...) { }
```

Why?

* Hides errors
* Breaks class contracts
* Makes debugging harder

CPP05 expects:

> **Throw in the class, catch in `main()`**

---

## 10. Catching by Reference (Critical)

Always:

```cpp
catch (const std::exception& e)
```

Never:

```cpp
catch (std::exception e) // object slicing
```

Why?

* Preserves polymorphism
* Keeps correct `what()` message

---

## 11. Multiple Exceptions

```cpp
class GradeTooHighException;
class GradeTooLowException;
```

Each represents:

* A specific contract violation
* A distinct semantic error

Better than using one generic exception.

---

## 12. Common 42 Traps (CPP05)

❌ Forgetting `const` on `what()`
❌ Forgetting `throw()` in C++98
❌ Catching by value
❌ Using `std::string` inside `what()`
❌ Printing inside exception instead of returning message
❌ Using `exit()` instead of throwing

---

## 13. Why Exceptions Instead of Return Codes?

Return codes:

* Easy to ignore
* Hard to propagate
* Pollute normal logic

Exceptions:

* Force handling
* Clean control flow
* Clear responsibility boundaries

CPP05 teaches **robust API design**.

---

## 14. Key Interview Takeaways

* Exceptions are runtime error handling
* `throw` transfers control
* `try` protects risky code
* `catch` handles specific types
* `std::exception` is the base class
* `what()` must never throw
* Nested exceptions express ownership
* Always catch by reference

---

## 15. CPP05 Checklist

✅ `try / catch / throw`
✅ Custom exceptions
✅ Inheritance from `std::exception`
✅ `what()` override
✅ C++98 `throw()` specification
✅ Proper error propagation
✅ Clean `main()` handling

---

## Final Thought

> **CPP05 is not about syntax.**
>
> It is about **defining and enforcing class invariants**.
>
> If your class cannot exist in a certain state — **throw**.
