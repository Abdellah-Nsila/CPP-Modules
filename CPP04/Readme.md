# 📘 CPP04 – Subtype Polymorphism, Abstract Classes & Interfaces

## Overview

**CPP04** is the module where C++ stops being “just classes” and starts being **object‑oriented design**.

This module focuses on:

* Runtime (subtype) polymorphism
* Virtual functions and destructors
* Abstract classes
* Interfaces (pure abstract classes)
* Architecture through inheritance and composition

This module is not about syntax.
It is about **designing extensible and safe systems**.

---

## 1. Subtype Polymorphism

### Definition

Subtype polymorphism allows a **base class pointer or reference** to point to a **derived class object**, while calling the **correct overridden function at runtime**.

This requires:

* Inheritance
* `virtual` functions
* Calls through base class pointers or references

### Example

```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};
```

```cpp
Animal* a = new Dog();
a->makeSound(); // Woof!
```

The function call is resolved **at runtime**, not at compile time.

---

## 2. Exercise 00 – Polymorphism

### Purpose

Introduce runtime polymorphism and show why `virtual` is mandatory.

### Key Concepts

#### Virtual Functions

Without `virtual`, function calls are resolved statically:

```cpp
Animal* a = new Dog();
a->makeSound(); // Animal sound ❌
```

With `virtual`, dynamic dispatch is enabled.

#### Virtual Destructors (Critical)

```cpp
virtual ~Animal();
```

Why?

```cpp
Animal* a = new Dog();
delete a;
```

Without a virtual destructor:

* Derived destructor is not called
* Resources leak

This is a **mandatory rule** in polymorphic base classes.

---

## 3. Exercise 01 – I Don’t Want to Set the World on Fire

### Purpose

Introduce **deep copy** and **resource ownership** in polymorphic hierarchies.

### Key Concepts

#### Composition

```cpp
class Dog : public Animal {
    Brain* brain;
};
```

* `Brain` is owned
* Must be dynamically allocated
* Requires deep copy

#### Deep Copy

```cpp
Dog a;
Dog b = a;
```

After copying:

* `a.brain` and `b.brain` must be different pointers
* Data must be identical

This enforces the **Rule of Three**:

* Destructor
* Copy constructor
* Copy assignment operator

---

## 4. Exercise 02 – Abstract Class

### What Is an Abstract Class?

An abstract class cannot be instantiated.
It contains at least one **pure virtual function**.

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;
};
```

```cpp
Animal a; // ❌ Compilation error
```

### Purpose

Abstract classes define **contracts**, not implementations.
They describe **what a class must do**, not how.

---

## 5. Exercise 03 – Interface & Recap

### Interfaces in C++

C++ does not have a dedicated `interface` keyword.

An interface is implemented as a **pure abstract class**:

```cpp
class ICharacter {
public:
    virtual void attack() = 0;
    virtual ~ICharacter() {}
};
```

Characteristics:

* Only pure virtual functions
* No data members
* Virtual destructor

---

## 6. Architecture Goal (Exercise 03)

This exercise focuses on **system design**, not features.

Key goals:

* Decoupling logic using interfaces
* Programming to abstractions
* Runtime behavior substitution

Example:

```cpp
class Game {
    ICharacter* character;
};
```

This enables:

* Easy extension
* Safe substitution
* Clean architecture

---

## 7. Interfaces + Inheritance = Scalable Design

### Example

```cpp
class AMateria {
public:
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
    virtual ~AMateria() {}
};
```

Concrete implementations:

```cpp
class Ice : public AMateria { ... };
class Cure : public AMateria { ... };
```

This design uses:

* Prototype pattern (`clone()`)
* Strategy pattern (`use()`)

---

## 8. Manual Resource Management

CPP04 teaches explicit ownership:

* Who allocates
* Who deletes
* When deletion occurs

This prepares you for:

* RAII
* Smart pointers
* Engine‑level memory management

---

## 9. Common 42 Traps

❌ Missing virtual destructor
❌ Shallow copy of owned resources
❌ Instantiating abstract classes
❌ Missing `const` on virtual methods
❌ Deleting through base pointer without virtual destructor
❌ Using concrete types instead of interfaces

---

## 10. Why CPP04 Matters

CPP04 teaches:

* Runtime polymorphism
* API and system design
* Clean inheritance hierarchies
* Decoupling via interfaces

This is the foundation of:

* Game engines
* Frameworks
* Large‑scale systems

---

## 11. Final Summary

* Polymorphism enables runtime behavior selection
* `virtual` enables dynamic dispatch
* Destructors must be virtual in polymorphic bases
* Abstract classes define contracts
* Interfaces decouple implementation from usage
* Deep copy is mandatory for owned resources

CPP04 is about **architecture, not syntax**.

---

## ✅ CPP04 Checklist

* Virtual functions
* Virtual destructors
* Runtime polymorphism
* Abstract classes
* Interfaces (pure abstract classes)
* Deep copy & Rule of Three
* Clean ownership design

---

**CPP04 is where you stop writing student code and start writing software architecture.**
