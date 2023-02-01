#ifndef MORSE_ENGLISH_H
#define MORSE_ENGLISH_H
//libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//functions
void promptUser(string& conversion, string& inputFileName, string& outputFile, bool& conversionType);
void openFiles(ifstream& inFile, string fileNameIn, ofstream& outFile, string fileNameOut);
void processFileM(ifstream&, ofstream& outFile, string morseConversions[]);
void processFileT(ifstream&, ofstream& outFile, string morseConversions[]);

#endif