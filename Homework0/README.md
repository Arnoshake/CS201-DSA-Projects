# Movie Sorting Program

Author: **Zachary West**  
Email: [zwest2563@gmail.com](mailto:zwest2563@gmail.com)  
Course Section: **Spring 2025 CS 201-002**  

---

## Overview

This C++ program reads a text file containing movie data (titles, release years, and actors), stores it in a structured format, and generates two sorted output files:

- One sorted **by movie name**
- One sorted **by year of release**

The program outputs two new files:
- `[fileName]ByName.txt`
- `[fileName]ByYear.txt`
    
Upon execution, the program prints the following performance metrics to the terminal (in microseconds):
- Total program execution time
- Time taken to load and parse the input file
- Time to generate the sorted name file
- Time to generate the sorted year file

---

## Compilation Instructions

To compile the program, use:

```bash
g++ -std=c++11 -o movieSorting movieSorting.cpp
```

---

## Execution Instructions

To execute the program:

```bash
./movieSorting [inputFileName].txt
```
**OR**
```bash
./a.out [inputFileName].txt
```

---

## Input File Format

Each line of the input file should be structured as follows:

```
MovieName(Year)/lastName1, firstName1/lastName2, firstName2/.../lastNameN, firstNameN

The Matrix(1999)/Reeves, Keanu/Fishburne, Laurence/Moss, Carrie-Anne/...
```

---

## Output Files

Two output files will be generated:

1. `[fileName]ByName.txt` – Movies sorted alphabetically by title (then by year if titles are identical).
2. `[fileName]ByYear.txt` – Movies sorted chronologically by year (then by title if years are identical).

Each line maintains the original format.

---


## Notes

- The program uses `std::chrono` for precise timing.
- Lambda functions are used in `std::sort()` for custom sorting logic.
- Input validation is handled for command-line arguments and file opening.
