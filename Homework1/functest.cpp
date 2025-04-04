/* 
   Sample program to test std::sort with different containers.
   To Compile: g++ -std=c++17 functest.cpp
   To Run: ./a.out
*/

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "quicksort2.hpp"
#include "quicksort2.hpp"
template< class RandomIt >
void print(RandomIt start, RandomIt end) {
	while (start != end) {
		std::cout << *start << " ";
		++start;
	}
	std::cout << std::endl;
}


int main(int argc, char *argv[]) {
	/*
	int a0[] = {56, 23, 11, 64, 43};
	std::array<int, 5> a1 = {5, 4, 3, 2, 1};
	std::array<std::string, 5> a2 = {"lion", "dog", "cat", "fox", "pig"};
	std::vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9};
	std::cout << "HEAPSORT \n";
	heapSort(a0, a0+5);
	print(a0, a0+5);
	std::cout << std::endl;
	heapSort(&a0[0], &a0[5]);
	print(&a0[0], &a0[5]);
	std::cout << std::endl;
	heapSort(a1.begin(), a1.end());
	print(a1.begin(), a1.end());
	std::cout << std::endl;
	heapSort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());
	std::cout << std::endl;
	std::reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());
	std::cout << std::endl;
	heapSort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());
	std::cout << std::endl;
	heapSort(v.begin(), v.end());
	print(v.begin(), v.end());
	*/
	int a0[] = {56, 23, 11, 64, 43};
	std::array<int, 5> a1 = {5, 4, 3, 2, 1};
	std::array<std::string, 5> a2 = {"lion", "dog", "cat", "fox", "pig"};
	std::vector<double> v = {4.2, 3.1, 5.6, 2.8, 1.9};
	std::cout << "QUICKSORT \n";
	quickSort(a0, a0+5);
	print(a0, a0+5);
	std::cout << std::endl;
	quickSort(&a0[0], &a0[5]);
	print(&a0[0], &a0[5]);
	std::cout << std::endl;

	quickSort(a1.begin(), a1.end());
	print(a1.begin(), a1.end());
	std::cout << std::endl;

	quickSort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());
	std::cout << std::endl;

	std::reverse(a2.begin(), a2.end());
	print(a2.begin(), a2.end());
	std::cout << std::endl;

	quickSort(a2.begin(), a2.end());
	print(a2.begin(), a2.end());
	std::cout << std::endl;

	quickSort(v.begin(), v.end());
	print(v.begin(), v.end());
	
	return 0;
}

