/*
Name: Sam Carter
Class: CPSC 122 spring 2023
Date: February 1, 2023
Programming assignment: PA1
Description: This program converts English characters to morse code 
or vice versa, depending on what the user chooses.
Notes: NA
*/
#include "morseEnglish.h"

int main(){
    //variables
    string conversion, inputFileName, outputFile = "";
    string morseConversions[91] = {" "};
    bool conversionType = 0;
    ifstream inFile;
    ofstream outFile;
    //Below is the ASCII conversions to morse code.
    morseConversions[48] = "-----", morseConversions[49] = ".----", morseConversions[50] = "..---";
    morseConversions[51] = "...--", morseConversions[52] = "....-", morseConversions[53] = ".....";
    morseConversions[54] = "-....", morseConversions[55] = "--...", morseConversions[56] = "---..";
    morseConversions[57] = "----.";
    morseConversions[32] = " ", morseConversions[65] = ".-", morseConversions[66] = "-...";
    morseConversions[67] = "-.-.", morseConversions[68] = "-..", morseConversions[69] = ".";
    morseConversions[70] = "..-.", morseConversions[71] = "--.", morseConversions[72] = "....";
    morseConversions[73] = "..", morseConversions[74] = ".---", morseConversions[75] = "-.-";
    morseConversions[76] = ".-..", morseConversions[77] = "--", morseConversions[78] = "-.";
    morseConversions[79] = "---", morseConversions[80] = ".--.", morseConversions[81] = "--.-";
    morseConversions[82] = ".-.", morseConversions[83] = "...", morseConversions[84] = "-";
    morseConversions[85] = "..-", morseConversions[86] = "...-", morseConversions[87] = ".--";
    morseConversions[88] = "-..-", morseConversions[89] = "-.--", morseConversions[90] = "--..";

//ask user which files to open as input ot output and what conversion
promptUser(conversion, inputFileName, outputFile, conversionType);
//open the files
openFiles(inFile, inputFileName, outFile, outputFile);
//conversionType determines morse to english or vice versa
if(conversionType == 1){
processFileM(inFile, outFile, morseConversions);}
else{processFileT(inFile, outFile, morseConversions);}
//close files
inFile.close();
outFile.close();
    return 0;
}
