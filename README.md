# Symbol Table in C++

🇮🇷 [نسخه فارسی (Persian version)](README.fa.md)

A simple symbol table built on a **hash table with chaining** (a linked list per bucket).
Made as a data structures practice project.

## Features
- Insert a symbol (name + type); duplicates are rejected
- Lookup, delete, and display the whole table
- Handles invalid input; frees all memory on exit

## How it works
- The table size is 3 on purpose, so collisions are easy to see.
- Hash function: `name.length() % 3`
- Each bucket is a linked list of `node { name, type, next }`

## Build & run
```bash
g++ -std=c++17 -o symboltable src/main.cpp
./symboltable        # on Windows: symboltable.exe
```

## Example
```
Bucket 0: pencil (int) -> animal (string)
Bucket 1: x (int)
Bucket 2: Empty
```

## Docs
- [Project report](docs/project_report.pdf)
- [Flowcharts](docs/flowchart.pdf)
- [Demo results](docs/demo_results.pdf)

## Possible improvements
- A better hash function and dynamic resizing
- Wrap the code in a `SymbolTable` class
- Add scope support (nested symbol tables)
