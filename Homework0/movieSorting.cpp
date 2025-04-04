/*
 Name: Zachary West
 Email: zwest2563@gmail.com
 Course Section: Spring 2025 CS 201-002
 Homework #: 0
 Instructions to Compile:
    I used the following statement to compile my code: "g++ -std=c++11 -o movieSorting movieSorting.cpp."
 Instructions to Execute:
    To execute the code properly, use the following format: 
        "./movieSorting [fileName].txt " OR "./a.out [fileName].txt"
    
    The results will populate within the corresponding [fileName]ByYear.txt and [fileName]ByName.txt 
        and the times for execution (used in report) will print to the terminal
*/



#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector> //data storage
#include <sstream> //file reading
#include <string> //file reading
#include <algorithm> // std::sort

#include <chrono> //timing
using namespace std;

class Movie{  
    public:
        string nameOfMovie, yearReleased;
        vector <string> actors;

        Movie(string name, string year, vector <string> cast){
            nameOfMovie = name;
            yearReleased = year;
            actors = cast;
        }
        /*void printMovie(){
            cout << nameOfMovie << "(" << yearReleased << ")/";
            for (int i = 0; i < actors.size() - 1; i++){
                cout << actors.at(i) << "/";
            }
            cout << actors.at(actors.size()-1) << endl;
        }

        void printYear(){
            cout << yearReleased << endl;
        }
        */
};

//write to File function just maintains the format of the input file but calls upon the created Movie class elements to do so
void writeToFile(ofstream &file, vector < Movie > sortedData){
    for (int movieIndex = 0; movieIndex < sortedData.size();movieIndex++){
        file << sortedData.at(movieIndex).nameOfMovie << "(" << sortedData.at(movieIndex).yearReleased << ")/"; //writes name and year
        for (int actorIndex = 0; actorIndex < sortedData.at(movieIndex).actors.size(); actorIndex++){
                file << sortedData.at(movieIndex).actors.at(actorIndex); //add actor
                if (actorIndex != sortedData[movieIndex].actors.size() - 1) file << "/"; //add divider for all but last actor
            }
        file << endl;
    }
}

int main(int argc, char* argv[]){

    auto startTimeOfProgram = std::chrono::high_resolution_clock::now();
    //validation of command line and properly opened file
    if (argc > 2){
        cout << "Usage: ./a.out [filename].txt \n";
        return -1;
    }

    string inputFileName = argv[1];
    ifstream inputFile(inputFileName);
    
    if (!inputFile){
        cout << "ERROR: File failed to open! \n";
        return -1;
    }

    //reading of input file into database
    string line;

    
    auto startTimeCollections = std::chrono::high_resolution_clock::now();
    vector < Movie > database; // will store each line of the input file
    while (getline(inputFile,line)){
        stringstream ss(line);
        string element;
        int index = line.find('(');
        // have to get rid of the first element of each line as it contains name and year. The first getline gets the name, second the year, and third finishes off the line for the while loop to start with first actor.
        vector <string> cast;
        getline(ss,element,'(');
        string movieName = element;
        getline(ss,element,')');
        string movieYear = element;
        getline(ss,element,'/');

        while (getline(ss,element,'/')){ // O(N^2)...
            cast.push_back(element); //the actors are never actually called upon or required for sorting, it would be faster to store it as a string but I thought to keep it as a vector as its more versatile for further improvement/implenentation. For example, if we wanted to sort movie my the name of the x actor or to return a movie by searching for actor
        }
        Movie filmElement(movieName,movieYear,cast);
    
        database.push_back(filmElement);
        
    }
    inputFile.close();

    auto endTimeCollections = std::chrono::high_resolution_clock::now();
    int charIndex = inputFileName.find('.');


    string outputFile1Name = inputFileName.substr(0,charIndex) + "ByName.txt";
    string outputFile2Name = inputFileName.substr(0,charIndex) + "ByYear.txt";
    
    /*
    LAMBDA EXPLANATION (for my understanding):
    [ captures ] ( parameters ) -> return_type { body }
    captures = what the alg is applied to
    parameters = normal function stuff
    */

   auto startTimeNameFile = std::chrono::high_resolution_clock::now();
   ofstream nameFile(outputFile1Name);
   if (!nameFile) {
    cout << "ERROR!" << endl;
    return -1;
    }
    //Sort algorithm uses a lambda function. The sort function references database by the begin and end pointers. The lambda funct, through sort, implicitly references the vector for its execution
    sort(database.begin(),database.end(),[]( const Movie& movie1,  const Movie& movie2) { //constant 2 comparison
        if (movie1.nameOfMovie != movie2.nameOfMovie) return movie1.nameOfMovie < movie2.nameOfMovie; // Sort by age in ascending order
        else{ //same name...
            return movie1.yearReleased < movie2.yearReleased;
        }
    });
    writeToFile(nameFile, database);
    nameFile.close();
    auto EndTimeNameFile = std::chrono::high_resolution_clock::now();
    auto startTimeYearFile = std::chrono::high_resolution_clock::now();
    ofstream yearFile(outputFile2Name);
    if (!nameFile) {
    cout << "ERROR!" << endl;
    return -1;
    }
    sort(database.begin(),database.end(),[](const Movie& movie1, const Movie& movie2) {
        if (movie1.yearReleased != movie2.yearReleased) return movie1.yearReleased < movie2.yearReleased; // Sort by age in ascending order
        else{ //same year...
            return movie1.nameOfMovie < movie2.nameOfMovie;
        }
    });
    writeToFile(yearFile, database);
    yearFile.close();
    auto endTimeYearFile = std::chrono::high_resolution_clock::now();

    //taking the established time checkpoints and casting them into the unit of miliseconds
    auto totalTimeProgram = std::chrono::duration_cast<std::chrono::microseconds>(endTimeYearFile - startTimeOfProgram);
    auto totalTimeCollection = std::chrono::duration_cast<std::chrono::microseconds>(endTimeCollections - startTimeCollections);
    auto totalTimeName = std::chrono::duration_cast<std::chrono::microseconds>(EndTimeNameFile - startTimeNameFile);
    auto totalTimeYear = std::chrono::duration_cast<std::chrono::microseconds>(endTimeYearFile - startTimeYearFile);

    std::cout << "TIME ANALYSIS \nTOTAL PROGRAM TIME: " << totalTimeProgram.count() << " Microseconds\nTOTAL COLLECTION TIME: " << totalTimeCollection.count() << " Microseconds\nTOTAL NAME FILE TIME: " << totalTimeName.count() << " Microseconds\nTOTAL YEAR FILE TIME: " << totalTimeYear.count() << " Microseconds\n";
    return 1;
}


