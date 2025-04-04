/*
 Name: Zachary West & Chase Berkey
 Email: zwest2563@gmail.com & ccBerkey@crimson.ua.edu
 Course Section: Spring 2025 CS 201-002
 Homework #: 0
 Instructions to Compile:
    I used the following statement to compile my code: "g++ -std=c++11 -O3 -o movieSortingSonic2 movieSortingSonic2.cpp"
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
        string nameOfMovie, yearReleased, actors;

        Movie(string name, string year,string cast){
            nameOfMovie = name;
            yearReleased = year;
            actors = cast;
        }
};

//write to File function just maintains the format of the input file but calls upon the created Movie class elements to do so
void writeToFile(ofstream &file, vector < Movie > sortedData){
    string masterString;
    for (int movieIndex = 0; movieIndex < sortedData.size();movieIndex++){
        masterString += sortedData.at(movieIndex).nameOfMovie + "(" +sortedData.at(movieIndex).yearReleased + ")" + sortedData.at(movieIndex).actors + "\n";
    }
    file << masterString;
}
//chatGPT generated functions below
std::string readFileToString(const std::string& filename) { 
    // Open the file in binary mode
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return "";
    }
    
    // Move the file pointer to the end to get the size
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();  // Get the size of the file
    file.seekg(0, std::ios::beg);         // Move the pointer back to the beginning
    
    // Read the file into a string
    std::string content(size, '\0');  // Create a string of the file's size
    file.read(&content[0], size);    // Read the file content into the string
    
    return content;  // Return the file content as a string
}
void readMovie(const std::string& entry, std::string& movieName, std::string& movieYear, std::string& actors) {
    size_t openParen = entry.find_last_of('(');
    size_t closeParen = entry.find_last_of(')');

    if (openParen == std::string::npos || closeParen == std::string::npos || closeParen <= openParen) {
        std::cerr << "Error: Malformed entry: " << entry << "\n";
        return;
    }

    try {
        // Extract movie name
        if (openParen > 0) {
            movieName = entry.substr(0, openParen - 1); // Exclude the space before '('
        } else {
            movieName = "";
        }

        // Extract movie year
        movieYear = entry.substr(openParen + 1, closeParen - openParen - 1);

        // Extract actors
        if (closeParen + 2 < entry.size()) {
            actors = entry.substr(closeParen + 2);
        } else {
            actors = ""; // No actors present
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error while processing: " << entry << " - " << e.what() << "\n";
    }
}

void readMasterString(const std::string& fileContent, std::vector<Movie>& database) {
    size_t start = 0;
    size_t end;

    while ((end = fileContent.find('\n', start)) != std::string::npos) {
        std::string line = fileContent.substr(start, end - start);
        start = end + 1;

        if (line.empty()) continue;

        std::string movieName, movieYear, actors;
        readMovie(line, movieName, movieYear, actors);
        database.emplace_back(movieName, movieYear, actors);
    }

    if (start < fileContent.size()) {
        std::string line = fileContent.substr(start);
        std::string movieName, movieYear, actors;
        readMovie(line, movieName, movieYear, actors);
        database.emplace_back(movieName, movieYear, actors);
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
    //reading of input file into database

    vector < Movie > database; // will store each line of the input file
    auto startTimeCollections = std::chrono::high_resolution_clock::now();
    int index;
    string name;
    string year;
    string actors;
    //cout << "test" << endl;

    string masterString = readFileToString(argv[1]);
    readMasterString(masterString,database);

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

    sort(database.begin(),database.end(),[]( const Movie& movie1,  const Movie& movie2) {
        return movie1.nameOfMovie < movie2.nameOfMovie; // Sort by name in ascending
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


