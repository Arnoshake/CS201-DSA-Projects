# Movie Sorting Program (Revisited)

Author: **Zachary West**  
Email: [zwest2563@gmail.com](mailto:zwest2563@gmail.com)  
Course Section: **Spring 2025 CS 201-002**  

---

## Overview

This C++ program builds on the program created for Homework0. Please refer to that project's relevant README and code.

This program builds off of Homework0 by changing the sorting condition to instead return the list of movies an actor is in or the list of actors in a movie.

If a movie is the argument, then that movie's list of actors is returned.
If an actor is the argument, then every movie that actor has been in is returned.

The program outputs directly to terminal.
    
Upon execution, the program prints the following performance metrics to the terminal (in microseconds):
- Total program execution time
- Time taken to load and parse the input file into the maps
- Time to search and return each query

---

## Compilation Instructions

To compile the program, use:

```bash
g++ -std=c++20 movieQuery.cpp
```

---

## Execution Instructions

To execute the program:

```bash
./a.out [inputFileName].txt [queryFileName].txt
```

---

## Input File Format

Each line of the input file should be structured as follows:

```
MovieName (Year)/lastName1, firstName1/lastName2, firstName2/.../lastNameN, firstNameN

The Matrix (1999)/Reeves, Keanu/Fishburne, Laurence/Moss, Carrie-Anne/...
```
Each line of the query file should be structured as follows:

```
The Matrix (1999)
Reeves, Keanu
Fishburne, Laurence
```
---

## Output

For each argument in the query file, it will print the query (surrounded by asterisks for viewability) followed by the list for that query. Each result (including the query) is printed on a a new line.

```
*****Sayle, Alexei*****
Bride, The (1985,I)
Curacao (1993)
Gorky Park (1983)
Indiana Jones and the Last Crusade (1989)
Reckless Kelly (1993)
Swing (1999)
Whoops Apocalypse (1986)
```


---
## License

This project was created for academic purposes as part of coursework for CS 201 at the University of Alabama. Redistribution should follow academic integrity guidelines.


