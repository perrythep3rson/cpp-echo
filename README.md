# Echo-like C++ Utility

A single-file command-line program that mimics common behaviors of Unix `echo` with simple escape-sequence interpretation and three flags: **-e**, **-E**, and **-n**. This project is a compact example of argument parsing and string replacement in modern C++.

---

## Features


- Prints command-line arguments separated by spaces  
- Flags:
  - **-e** — enable interpretation of escape sequences
  - **-E** — disable interpretation of escape sequences (default)
  - **-n** — do not print a trailing newline
- Supported escape sequences: `\n`, `\t`, `\r`, `\v`, `\b` (inserts a backspace control character)
- Special behavior: `\c` truncates output at that point and the program exits without printing a trailing newline

---

## Requirements

- C++ compiler with C++11 or later support (g++, clang++, MSVC)

---

## Build

Save the source as `echo.cpp` and compile with one of these commands:

- g++
```bash
g++ -std=c++11 -O2 -Wall -Wextra -o echo_cpp echo.cpp
```

---

## Usage

```bash
./echo_cpp [flags] [strings...]
```

### Examples:

```bash

# Print text with trailing newline (default)
./echo_cpp Hello world

# Interpret escape sequences (newline and tab)
./echo_cpp -e "Line1\nLine2" "Col1\tCol2"

# Do not print trailing newline
./echo_cpp -n "no newline at end"

# Explicitly disable escape processing (prints literal \n)
./echo_cpp -E "literal \\n sequence"

# Stop output at \c (no trailing newline)
./echo_cpp -e "hello\cworld"

# Combine flags and arguments
./echo_cpp -n -e "a\tb\nc"

```

### Behavior notes:

- Flags are recognized only while scanning leading arguments; scanning stops at the first non-flag argument.

- If both -e and -E appear, the last one encountered during the scan determines whether escape processing is active.

- \b is replaced with a backspace control character; it does not delete previously printed characters in the current implementation.