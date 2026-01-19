
# Coding Challenge

This repository contains a small C++ command-line program written as part of the
coding challenge for **“Creating an Execution-Driven Version of Olympia”**
(RISC-V Mentorship).

The goal of the challenge is to demonstrate object-oriented design,
encapsulation, and extensibility.

---

## Problem Summary

The program prints information about an object specified on the command line.
Depending on the object and provided parameters, it computes basic properties
such as area, perimeter, or circumference.

Supported objects:

- **circle**
- **square**
- **rect** (rectangle)

Examples:
```bash
describe_object circle 5
describe_object square 4
describe_object rect 4 6
````

---

## Design Constraints

* The `main` function has no knowledge of concrete object types
* Objects are created via a common interface
* Adding a new object does not require modifying existing code

---

## Build Instructions

Requirements:

* CMake ≥ 3.16
* C++17 compiler

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```

---

## Running (Windows / MSVC)

```bat
Debug\describe_object.exe circle 5
Debug\describe_object.exe square 4
Debug\describe_object.exe rect 4 6
```

---

## Notes

* Objects self-register and are instantiated at runtime
* The structure is intentionally minimal and focused on extensibility
* No external dependencies beyond the standard library

