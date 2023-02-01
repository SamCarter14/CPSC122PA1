/*
Function: promptUser()
Date Created: 1/27/23
Date last modified: 1/27/23
Description: Prompts user for conversion type and input/output files
Input: cin statement
Returns: input/output files, convserion type
Pre: Nothing happens before this function
Post: The user is prompted to give input/output files and conversion type,
they are given by user and returned
*/
#include "morseEnglish.h"

void promptUser(string& conversion, string& inputFileName, string& outputFile, bool& conversionType){
    cout << "USER CMD: ";
    cin >> conversion >> inputFileName >> outputFile;
    while(conversion != "-m" && conversion != "-t"){
    cout << "ERROR. TRY AGAIN." << endl;
    cout << "USER CMD: ";
    cin >> conversion >> inputFileName >> outputFile;}
    if(conversion == "-m"){
        conversionType = 1;
    }
    else{
        conversionType = 0;
    }}

/*
Function: openFiles()
Date created: 1/27/23
Last modified: 1/27/23
Description: Opens the files given by user
Input parameters: input and output file names
Returns: attempts to open files, returns if opened correctly or not
Pre: User must put in input output file names.
post: The input and output files are opened
*/
void openFiles(ifstream& inFile, string fileNameIn, ofstream& outFile, string fileNameOut){
    inFile.open(fileNameIn);
    if(inFile.is_open()){
    cout << "Input File opened correctly" << endl;
    }
    else{
        cout << "Error opening input file" << endl;
        exit(-1);
    }
     outFile.open(fileNameOut);
    if(outFile.is_open()){
    cout << "Output File opened correctly" << endl;
    }
    else{
        cout << "Error opening output file" << endl;
        exit(-1);
    }
}
/*
Function:processFileM
Date created: 1/29/23
Date last modified: 1/29/23
Description: Converts from english into morse code, gives character conversion count
input: morseConversions, input file 
returns: returns morse characters to output file, returns total character conversion count
Pre: User must have given input file and output file, and chose -m (to morse) conversion type 
Post: Morse characters are written to output file.
*/
void processFileM(ifstream& inFile, ofstream& outFile, string morseConversions[]){

string line = "";
int count = 0;

while(!inFile.eof()){
if(line != ""){
    outFile << endl;
    count += 1;
}
getline(inFile, line);
    for (int i = 0; i < line.length(); i++){
    if(line[i] > 91){
        line[i] -= 32;
    }
    if(line[i] == 32){
    outFile << morseConversions[line[i]];
    }
else {outFile << morseConversions[line[i]] << " ";}
count += 1;
} 
}
cout << "Total Characters converted succesfully into morse (including whitespace): " << count << endl;
}
/*
Function:processFileT
Date created: 1/29/23
Date last modified: 1/30/23
Description: Converts from morse into English, gives character conversion count
input: morseConversions, input file 
returns: returns uppercase English characters to output file, returns total character conversion count
Pre: User must have given input file and output file, and chose -t (to English text) conversion type 
Post: English characters are written to output file
*/
void processFileT(ifstream& inFile, ofstream& outFile, string morseConversions[]){
 string morseLetter = "";
 string line;
 char character;
 int count = 0;
 morseConversions[32] = "";
 
 while(!inFile.eof()){
    if(line != ""){
        outFile << endl;
        count += 1;}
    line = "";
getline(inFile, line);
for(int i = 0; i < line.size(); i++){
    if(isspace(line.at(i))){
     for(int i = 32; i < 91; i++){
        if(morseLetter == morseConversions[i]){
            character = i;
            outFile << character;
            count += 1;
            break;
        }
 }  
    morseLetter = "";
}
else{
    character = line.at(i);
    morseLetter.push_back(character);
}}}
cout << "Total characters converted successfully into English (including whitespace): " << count << endl;
}
