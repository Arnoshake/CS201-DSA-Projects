# CS201-DSA Homework 2

## Author
**Zachary West**  
📧 Email: [zwest2563@gmail.com](mailto:zwest2563@gmail.com)  
📘 Course: CS 201 (Spring 2025)  
📄 Homework #: 1  

---
## Project Overview

The goal of the assignment is to implement a custom symbol table structure using Red-Black Trees (RBT). The provided files cover the basic infrastructure. The symbol table utilizes a RBT and is implimented in `ST.hpp` and applied in `main.cpp`.


## Files Provided

The following files were provided for this assignment:
- `RBT.hpp`: Contains the Red-Black Tree class implementation.
- `RBTNode.hpp`: Defines the Red-Black Tree Node structure.
- `RBTPrint.hpp`: Provides functions to visualize and print the tree.

The following files were written by me:
- `ST.hpp`: This is the header file for the symbol table structure, utilizing Red-Black Trees for storage and retrieval operations.
- `STmain.cpp`: The main program that demonstrates the functionality of the symbol table.

---

## Input File Format

A text file that includes words is all that is necessary. It can be excerpts of books, magazines, etc. 

---
## Compilation

To compile the code, use the following command:
```bash
g++ -std=c++11 main.cpp
```
 `main.cpp` imports the symbol table, so compilation of `ST.hpp` isnt necessary.

## Execution

To execute the program, simply run the compiled executable:
```bash
./a.out < input.txt
```

With this implementation, these words are all unique: "the", "The", ". The", and "the."
Cleaning or normalization of the data would help with this but it was outside the scope of the project.
## License

This project was created for academic purposes as part of coursework for CS 201 at the University of Alabama. Redistribution should follow academic integrity guidelines.

