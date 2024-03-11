#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string inputFilename, outputFilename;
    cout << "Please enter the filename: ";
    cin >> inputFilename;

    ifstream inFile(inputFilename);
    if (!inFile) {
    cout << "File '" << inputFilename << "' does not exist." << endl;
    return 1;
    }

    cout << "Please enter the output filename: ";
    cin >> outputFilename;

    string word;
    int wordCount = 0; 
    int charCount = 0; 
    int nonSpaceCharCount = 0; 
    int letterCount = 0;

   
    while (inFile >> word) {
        wordCount++; 
        for (char &c : word) {
            if (isalpha(c)) letterCount++;
            nonSpaceCharCount++;
        }
    }

    inFile.clear(); 
    inFile.seekg(0, ios::beg); 

    char c;
    
    while (inFile.get(c)) {
        charCount++; 
    }
    cout << "Total number of words: " << wordCount << endl;
    cout << "Total number of characters: " << charCount << endl;
    cout << "Total number of non-whitespace characters: " << nonSpaceCharCount << endl;
    cout << "Total number of letters: " << letterCount << endl << endl;
    
    ofstream outFile(outputFilename);
    if (!outFile) {
        cout << "Cannot create output file." << endl;
        return 2;
    }

    outFile << "Total number of words: " << wordCount << endl;
    outFile << "Total number of characters: " << charCount << endl;
    outFile << "Total number of non-whitespace characters: " << nonSpaceCharCount << endl;
    outFile << "Total number of letters: " << letterCount << endl;

    inFile.close(); 
    outFile.close();

    return 0;
}

