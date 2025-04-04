/*
 Name: Zachary West
 Email: zjwest1@crimson.ua.edu
 Course Section: Spring 2025 CS 201-002
 Homework #: 0
 Instructions to Compile:
    I used the following statement to compile my code: "g++ -std=c++20 movieQuery.cpp "
 Instructions to Execute:
    To execute the code properly, use the following format: 
        "./a.out [fileName].txt query.txt"
    
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

#include <map>

#include <chrono> //timing
using namespace std;

class Movie{  
    public:
        string nameOfMovie, yearReleased;
        string actors;

        Movie(string name, string year, string cast){
            nameOfMovie = name;
            yearReleased = year;
            actors = cast;
        }
};
bool printMap(std::map<std::string,std::vector<std::string> > mapOfInterest, std::string key){
    if (mapOfInterest.find(key) == mapOfInterest.end()){ //key, val pair DNE
        return false; 
    }
    else{
        std::cout << "*****" << key <<"*****" << std::endl;
        for (int i = 0; i < mapOfInterest[key].size();i++){
        std::cout << (mapOfInterest[key]).at(i) <<std::endl;
        }
        return true;
    }
}
int main(int argc, char* argv[]){
    auto startTimeOfProgram = std::chrono::high_resolution_clock::now();

    if (argc > 3){
        cout << "Usage: ./a.out [filename].txt \n";
        return -1;
    }
    string inputFileName = argv[1];
    ifstream inputFile(inputFileName);
    if (!inputFile){
        cout << "ERROR: File failed to open! \n";
        return -1;
    }

    map<std::string,std::vector<std::string> > queryActor; // (actor, movies)
    map<std::string,std::vector<std::string> > queryMovie; // (movie, vector of actors)
    
    auto startTimeDataStructureCreation = std::chrono::high_resolution_clock::now();

    vector < Movie > database; // will store each line of the input file
    string line;
    while (getline(inputFile,line)){
        stringstream ss(line);
        string element;
        int index = line.find('(');
        // have to get rid of the first element of each line as it contains name and year. The first getline gets the name, second the year, and third finishes off the line for the while loop to start with first actor.
        
        getline(ss,element,'(');
        string movieName = element;
        getline(ss,element,')');
        string movieYear = element;
        getline(ss,element,'/');
        string actorString = element;
        
        vector <string> cast;
        while (getline(ss,element,'/')){ cast.push_back(element);}
            
        Movie filmElement(movieName,movieYear,actorString); //Is not used for this project but stores each line of input files at an object... good for future projects
    
        database.push_back(filmElement);
        string fullMovieName = movieName + '(' + movieYear + ')';
        queryMovie.insert(std::make_pair(fullMovieName,cast)); // map[ movie (year) ] = {actor1/actor2/.../actorX}
        for (int i = 0; i <cast.size(); i++){
            //for each actor, append the movie to that actors list of movies
            queryActor[cast.at(i)].push_back(fullMovieName);
        }
    }
    inputFile.close();
    auto endTimeDataStructureCreation = std::chrono::high_resolution_clock::now();
    std::string name;
    std::ifstream queryfile(argv[2]);
	if (!queryfile.is_open()) {
	   std::cout << "Unable to open file: " << argv[2] << std::endl;
	   std::exit(-1);
	}

	std::cout << "***Reading query file " << argv[2] << "***" << std::endl;
    std::vector<std::string> queryCommands;
	while (std::getline(queryfile, name)) {
	   std::cout << "Query value:" << name << std::endl;
       queryCommands.push_back(name);
	}
	queryfile.close();
	std::cout << "***Done reading query file " << argv[2] << "***" << std::endl;

    for (int i = 0; i < queryCommands.size(); i++){
        //check each map for a matching value, done so that the if statement does not exit early
        bool actorCheckPair = !printMap(queryActor, queryCommands.at(i));
        bool movieCheckPair = !printMap(queryMovie, queryCommands.at(i));

        if (actorCheckPair && movieCheckPair) {
            std::cout << "This query (" << queryCommands.at(i) << ") returns no matches." << std::endl;
        }
    }
    
    auto endTimeOfProgram = std::chrono::high_resolution_clock::now();


    //taking the established time checkpoints and casting them into the unit of miliseconds
    auto totalTimeProgram = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeOfProgram - startTimeOfProgram);
    auto totalDataStructureCreation = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeDataStructureCreation - startTimeDataStructureCreation);
    auto totalSearch = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeOfProgram - endTimeDataStructureCreation);
    std::cout << "*****\nTIME ANALYSIS (seconds) \nDS CREATION: " << double(totalDataStructureCreation.count()/1000.0) << "\nSEARCH: " <<double(totalSearch.count()/1000.0) << "\nPROGRAM : " << double(totalTimeProgram.count()/1000.0) << std::endl;
    return 1;
}



