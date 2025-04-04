

/*
 Name: Zachary West
 Email: zwest2563@gmail.com
 Course Section: Spring 2025 CS 201-002
 Homework #: 2

 To compile: g++ -std=c++11 main.cpp
 To run: ./a.out < input.txt
*/
#include <iostream>
#include <vector>
#include <regex>
#include <chrono>
#include "ST.hpp"
#include "RBTPrint.hpp"

int main() {
   //Provided by instructor
   std::string text;
   const auto start1{std::chrono::steady_clock::now()};
   const std::regex delim("\\s+"); 
   ST<std::string, int> symbolTable;
   while (std::cin >> text) {
      auto begin = std::sregex_token_iterator(text.begin(), text.end(), delim, -1);
      auto end = std::sregex_token_iterator();
      for (std::sregex_token_iterator word = begin; word != end; word++) {
         if (!symbolTable.count(*word)){ //if the word isnt in it
            symbolTable[*word] = 1;
         }
         else{
            symbolTable[*word]++; // it exists but increase
         }
      }
   }
   std::vector< std::pair<std::string, int> > symbolVector = symbolTable.toVector(); //initially sorted alphabtical
   //CALL SORT WITH LAMBDA for greatest to lowest key->value
   //Sort algorithm uses a lambda function. The sort function references database by the begin and end pointers. The lambda funct, through sort, implicitly references the vector for its execution
   sort(symbolVector.begin(),symbolVector.end(),[]( const std::pair<std::string, int>& symbol1,  const  std::pair<std::string, int>& symbol2) { //constant 2 comparison
         if (symbol1.second != symbol2.second){ //they are different values...
            return symbol1.second > symbol2.second; //compare values
         }
         else{
            return symbol1.first < symbol2.first; //compare the key
         }
  });
  const auto end1{std::chrono::steady_clock::now()};
   auto totalTimeProgram = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    
  //print the vector in sorted order
   for(const auto & str : symbolVector)
      std::cout << str.first << ": " << str.second << std::endl;
   //end of provided
  std::cout <<"Time elapsed (mS): " << totalTimeProgram.count() << std::endl;
   std::cout << "Unique Words: " << symbolTable.size() << std::endl;




   return 0;
}