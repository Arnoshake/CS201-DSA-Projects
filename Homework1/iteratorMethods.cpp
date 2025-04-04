/*
 Name: Zachary West
 Email: zjwest1@crimson.ua.edu
 Course Section: Spring 2025 CS 201-002
 Homework #: 1
 Instructions to Compile:
    Compilation was done within the "functest.cpp" and "perftest.cpp" documents. Simply add #include "iteratorMethods.cpp" and the sorting methods will become available
 Instructions to Execute:
    ""./a.out" will execute the code and print the test results to the terminal.
    the two methods to replace std::sort with in either "functest.cpp" or "perftest.cpp" are: 
        1. "heapSort (RandomIt first, RandomIt last)"
        2. "quickSort(RandomIt first, RandomIt last)"
*/

#include <stdlib.h>
#include <algorithm> // included for iter swap
#include <vector>

//HEAPSORT
template< class RandomIt>
void heapify (RandomIt first, RandomIt last, RandomIt iterator){
    //establish iterator values for the parent (maximum) and the two children
    auto maximum = iterator;
    auto leftChild = iterator + 2 * (iterator - first) + 1;
    auto rightChild = iterator + 2 * (iterator - first) + 2;

    //compare the parent to each of its children (checks to maintain proper bounds)
    if (leftChild < last && *leftChild > *maximum){
        maximum = leftChild;
    }
    if(rightChild < last && *rightChild > *maximum){
        maximum = rightChild;
    }
    //If the maximum value has been found to be one of the children, swap these two values and then call heapify on the swapped parent
    if (maximum != iterator){
        std::iter_swap(iterator, maximum);
        heapify(first,last,maximum);
    }

    /*
    INDEX PSEUDOCODE
    max = i
    leftchild = 2i + 1
    rightchild = 2i + 2
    if (leftchild <= n) and (A[i] < A[leftchild])
        max = leftchild
    else 
        max = i
    if (rightchild <= n) and (A[max]  > A[rightchild])
        max = rightchild
    if (max != i)
        swap(A[i], A[max])
        Heapify(A, n, max)
    */
}
template< class RandomIt>
void buildHeap (RandomIt first, RandomIt last){
    auto iterator = first + (last - first)/2 - 1;
    while (iterator >= first){
        heapify(first,last, iterator);
        iterator--;
        /*
            Originally used a for loop, but while loop seemed easier to impliment, understand, and debug if necessary
        */
    }
    //calls heapify
}
template< class RandomIt >
void heapSort (RandomIt first, RandomIt last){
    buildHeap(first,last);
    for (auto iterator = last - 1 ; iterator > first ; --iterator){
        std::iter_swap(first,iterator);
        heapify(first,iterator,first);

        /*

        */
    }
    /*
    n = length(A)
   for i = n/2 downto 1   
     Heapify(A, n ,i)
   
   for i = n downto 2
     exchange A[1] with A[i]
     A.heapsize = A.heapsize - 1
     Heapify(A, i, 0)
    */
}
template void heapSort<int*>(int*, int*); //included because this case wasnt covered by the template for some reason. Kept gaving errors without


template< class RandomIt >
RandomIt medianFinder(RandomIt low,RandomIt mid, RandomIt high){
    //high = last - 1
    if (*low > *mid ){
        std::iter_swap(low,mid);
    }
    if (*low > *high ){
        std::iter_swap(low,high);
    }
    if (*mid > *high ){
        std::iter_swap(mid,high);
    }
    return mid;

}
template< class RandomIt >
auto partition(RandomIt first, RandomIt last){
    // RandomIt pivot = first + std::rand() % (last - first); // random pivot value to avoid worst case runtime
    auto mid = first + (last - first) / 2;
    auto pivot = medianFinder(first,mid, last-1);
    std::iter_swap(pivot,last-1);
    pivot = last - 1; //dereferencing here so that not dereferencing in every for loop 
    RandomIt i = first;

    for (auto j = first; j < last - 1  ; ++j){
        if (*j < *pivot){
            std::iter_swap(i,j);
            i = i + 1;
        }
    }
    std::iter_swap(i,last - 1);
    return i;
}
template< class RandomIt >
void quickSort(RandomIt first, RandomIt last){
    
    if (first < last ){
        RandomIt pivot = partition(first, last);
        quickSort(first, pivot );
        quickSort(pivot + 1, last);
    }
}
