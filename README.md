# CPP - C++ Programming Modules

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![C++98](https://img.shields.io/badge/Standard-C++98-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

> A comprehensive collection of C++ programming exercises covering fundamental to advanced concepts in C++98 standard.

## 📑 Table of Contents

- [📖 About](#-about)
- [📚 Modules](#-modules)
- [🛠️ Compilation](#️-compilation)
- [🚀 Usage](#-usage)
- [📂 Project Structure](#-project-structure)
- [✨ Features](#-features)
- [🎯 Concepts Covered](#-concepts-covered)
- [🧪 Testing](#-testing)
- [📚 Resources](#-resources)

## 📖 About

This repository contains a series of C++ modules designed to progressively teach core C++ concepts following the **C++98 standard**. Each module builds upon previous concepts, introducing new features and advanced programming techniques.

### Learning Objectives

- **Object-Oriented Programming**: Classes, inheritance, polymorphism
- **Memory Management**: Dynamic allocation, RAII principles
- **Operator Overloading**: Custom operators for user-defined types
- **Exception Handling**: Try-catch blocks, custom exceptions
- **Advanced Concepts**: Abstract classes, interfaces, templates, STL containers

## 📚 Modules

### CPP Module 00 - Basics
Introduction to C++ basics, namespaces, classes, and member functions.

**Exercises:**
- **ex00**: `megaphone` - String manipulation and character conversion
- **ex01**: `PhoneBook` - Contact management system with classes
- **ex02**: `Account` - Bank account simulation with timestamps

**Key Concepts:** Classes, constructors/destructors, member functions, static members

---

### CPP Module 01 - Memory & Pointers
Working with memory allocation, references, and pointers.

**Exercises:**
- **ex00**: `newZombie` - Dynamic memory allocation
- **ex01**: `zombieHorde` - Array allocation
- **ex03**: `Weapon` - References vs pointers
- **ex05**: `Harl` - Function pointers and switch statements

**Key Concepts:** `new`/`delete`, references, pointers, member function pointers

---

### CPP Module 02 - Fixed Point Numbers
Understanding Orthodox Canonical Form and operator overloading.

**Exercises:**
- **ex00**: `Fixed` - Basic fixed-point class
- **ex01**: `Fixed` - Type conversions (int/float)
- **ex02**: `Fixed` - Arithmetic and comparison operators

**Key Concepts:** Operator overloading, const correctness, static members

---

### CPP Module 03 - Inheritance
Object-oriented programming with inheritance hierarchies.

**Exercises:**
- **ex00**: `ClapTrap` - Base character class
- **ex01**: `ScavTrap` - Single inheritance
- **ex02**: `FragTrap` - Multiple derived classes
- **ex03**: `DiamondTrap` - Diamond inheritance problem

**Key Concepts:** Inheritance, virtual functions, protected members, diamond problem

---

### CPP Module 04 - Polymorphism
Advanced polymorphism and abstract classes.

**Exercises:**
- **ex00**: `Animal` - Basic polymorphism
- **ex01**: `Brain` - Deep copy and memory management
- **ex02**: `AAnimal` - Abstract base classes

**Key Concepts:** Virtual functions, abstract classes, pure virtual functions, deep copying

---

### CPP Module 05 - Exceptions
Exception handling and bureaucratic forms.

**Exercises:**
- **ex00**: `Bureaucrat` - Custom exceptions
- **ex01**: `Form` - Form signing system
- **ex02**: `AForm` - Abstract forms with execution
- **ex03**: `Intern` - Factory pattern

**Key Concepts:** Exception handling, try-catch, custom exceptions, factory pattern

---

### CPP Module 06 - C++ Casts
Understanding different types of C++ type casting.

**Exercises:**
- **ex00**: `ScalarConverter` - Convert and display scalar types
- **ex01**: `Serialization` - Serialize and deserialize data
- **ex02**: `Identify` - Type identification without dynamic_cast

**Key Concepts:** static_cast, dynamic_cast, reinterpret_cast, const_cast, type conversion

---

### CPP Module 07 - Templates
Introduction to C++ templates and generic programming.

**Exercises:**
- **ex00**: `Templates` - Function templates (swap, min, max)
- **ex01**: `iter` - Template function for arrays
- **ex02**: `Array` - Template class for dynamic arrays

**Key Concepts:** Function templates, class templates, template specialization, generic programming

---

### CPP Module 08 - STL Containers
Working with Standard Template Library containers and algorithms.

**Exercises:**
- **ex00**: `easyfind` - Finding elements in containers
- **ex01**: `Span` - Container for storing and analyzing numbers
- **ex02**: `MutantStack` - Stack with iterator support

**Key Concepts:** STL containers, iterators, algorithms, container adapters

---

### CPP Module 09 - Real-World Applications
Practical applications combining advanced C++ concepts with algorithmic challenges.

**Exercises:**
- **ex00**: `BitcoinExchange` - Parse CSV and compute Bitcoin exchange rates
- **ex01**: `RPN` - Reverse Polish Notation calculator
- **ex02**: `PmergeMe` - Ford-Johnson merge-insertion sort algorithm

**Key Concepts:** File parsing, algorithm implementation, STL container selection, performance optimization

## 🛠️ Compilation

Each module includes a **Makefile** for easy compilation. All projects are compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

### Compile a Module

Navigate to any exercise directory and run:

```bash
make        # Compile
make clean  # Remove object files
make fclean # Remove executables
make re     # Recompile
```

### Compile All Modules

From the root directory:

```bash
./make_all.sh
```

## 🚀 Usage

After compilation, run the executables:

```bash
# Module 00 - ex00
cd cpp00/ex00
make
./megaphone "shhhhh... I think the students are asleep..."

# Module 00 - ex01
cd cpp00/ex01
make
./phonebook

# Module 03 - ex03
cd cpp03/ex03
make
./diamondtrap

# Module 07 - ex02
cd cpp07/ex02
make
./array

# Module 08 - ex02
cd cpp08/ex02
make
./mutantstack
```

## 📂 Project Structure

```
CPP/
├── 📂 cpp00/          # Basics
│   ├── ex00/          # Megaphone
│   ├── ex01/          # PhoneBook
│   └── ex02/          # Account
├── 📂 cpp01/          # Memory & Pointers
│   ├── ex00/          # newZombie
│   ├── ex01/          # zombieHorde
│   ├── ex03/          # Weapon
│   └── ex05/          # Harl
├── 📂 cpp02/          # Fixed Point
│   ├── ex00/          # Fixed basic
│   ├── ex01/          # Fixed conversions
│   └── ex02/          # Fixed operators
├── 📂 cpp03/          # Inheritance
│   ├── ex00/          # ClapTrap
│   ├── ex01/          # ScavTrap
│   ├── ex02/          # FragTrap
│   └── ex03/          # DiamondTrap
├── 📂 cpp04/          # Polymorphism
│   ├── ex00/          # Animal
│   ├── ex01/          # Brain
│   └── ex02/          # AAnimal
├── 📂 cpp05/          # Exceptions
│   ├── ex00/          # Bureaucrat
│   ├── ex01/          # Form
│   ├── ex02/          # AForm
│   └── ex03/          # Intern
├── 📂 cpp06/          # C++ Casts
│   ├── ex00/          # ScalarConverter
│   ├── ex01/          # Serialization
│   └── ex02/          # Identify
├── 📂 cpp07/          # Templates
│   ├── ex00/          # Templates
│   ├── ex01/          # iter
│   └── ex02/          # Array
├── 📂 cpp08/          # STL Containers
│   ├── ex00/          # easyfind
│   ├── ex01/          # Span
│   └── ex02/          # MutantStack
├── 📂 cpp09/          # Real-World Applications
│   ├── ex00/          # BitcoinExchange
│   ├── ex01/          # RPN Calculator
│   └── ex02/          # PmergeMe
├── Makefile           # Root makefile
└── make_all.sh        # Compilation script
```

## ✨ Features

### 💻 Code Quality
- ✅ Follows **C++98 standard**
- ✅ **Orthodox Canonical Form** (4 essential member functions)
- ✅ **RAII** principles for resource management
- ✅ **Const correctness** throughout
- ✅ **No memory leaks** (verified with valgrind)

### ⚙️ Compilation Flags
- `-Wall -Wextra -Werror`: Strict warning enforcement
- `-std=c++98`: C++98 standard compliance
- `-g`: Debug symbols for development


## 🎯 Concepts Covered

| Module | Core Concepts |
|--------|---------------|
| **00** | 🔹 Classes, Constructors, Destructors, Static members |
| **01** | 🔹 Memory allocation, References, Pointers, Function pointers |
| **02** | 🔹 Operator overloading, Fixed-point arithmetic, Canonical form |
| **03** | 🔹 Inheritance, Virtual functions, Diamond problem |
| **04** | 🔹 Polymorphism, Abstract classes, Deep copying |
| **05** | 🔹 Exceptions, Custom exception classes, Factory pattern |
| **06** | 🔹 Type casting, static_cast, dynamic_cast, reinterpret_cast |
| **07** | 🔹 Function templates, Class templates, Generic programming |
| **08** | 🔹 STL containers, Iterators, Algorithms, Container adapters |
| **09** | 🔹 File parsing, Algorithmic implementations, Sorting algorithms |

## 🧪 Testing

Each module includes a `main.cpp` with comprehensive tests. Example outputs demonstrate:
- ✅ Constructor/destructor calls
- ✅ Memory management correctness
- ✅ Operator overloading behavior
- ✅ Exception handling
- ✅ Polymorphic behavior
- ✅ Template instantiation
- ✅ STL container operations

## 📚 Resources

- [C++ Reference](https://en.cppreference.com/)
- [Learn C++](https://www.learncpp.com/)
- [C++98 Standard](https://www.iso.org/standard/25845.html)
- [STL Documentation](https://www.cplusplus.com/reference/stl/)
- [Ford-Johnson Algorithm Explanation](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91)
