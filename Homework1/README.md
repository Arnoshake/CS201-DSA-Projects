# Sorting Algorithms Implementation in C++

## Author
**Zachary West**  
📧 Email: [zwest2563@gmail.com](mailto:zwest2563@gmail.com)  
📘 Course: CS 201 (Spring 2025)  
📄 Homework #: 1  

---

## Project Overview

This project implements two popular sorting algorithms in C++ using templates and iterators as a learning experience for C++ syntax, use cases for iterator, and the purpose of templates.

- `heapSort(RandomIt first, RandomIt last)`
- `quickSort(RandomIt first, RandomIt last)`

These methods are designed to work with **random-access iterators** and can be used as drop-in replacements for `std::sort()` in standard C++ containers like `std::vector`.

---

## Compilation Instructions

You do **not** need to compile this file directly. Instead, include it within your test files as follows:

```cpp
#include "iteratorMethods.cpp"
```

Recommended test files:
- `functest.cpp`
- `perftest.cpp`

Then compile using a standard g++ command:

```bash
g++ functest.cpp -o functest
# or
g++ perftest.cpp -o perftest
```

---

## Execution Instructions

To run the compiled program:

```bash
./functest
# or
./perftest
```

These test files will:
- Execute the sorting algorithms.
- Compare results and performance against `std::sort`.

To use the custom sorting functions in place of `std::sort`, simply replace with:

```cpp
heapSort(vec.begin(), vec.end());
quickSort(vec.begin(), vec.end());
```

---

## Key Functions

### `heapSort(RandomIt first, RandomIt last)`
Implements a **heap sort** algorithm with the help of:

- `heapify()`: Ensures max-heap properties.
- `buildHeap()`: Builds a valid heap from the range.

### `quickSort(RandomIt first, RandomIt last)`
Implements a **median-of-three quicksort**, with:

- `partition()`: Lomuto-style partitioning with pivot chosen via:
- `medianFinder()`: Finds the median of the first, middle, and last elements to reduce worst-case performance.

---

## Notes

- `heapify()` uses manual child index calculations to simulate a heap structure.
- `quickSort()` uses a smart pivot selection strategy to avoid degraded performance on sorted or reverse-sorted inputs.

---

## Example Usage

```cpp
#include <vector>
#include "iteratorMethods.cpp"

int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    
    quickSort(data.begin(), data.end());
    // or
    heapSort(data.begin(), data.end());

    return 0;
}
```

## License

This project was created for academic purposes as part of coursework for CS 201 at the University of Alabama. Redistribution should follow academic integrity guidelines.


