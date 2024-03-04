#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Cannot open file." << endl;
        return 1;
    }

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

    inFile.clear(); // Clear EOF flag
    inFile.seekg(0, ios::beg); // Move to the beginning of the file

    char c;
    while (inFile.get(c)) {
        charCount++;
        if (isspace(c) && c != ' ') nonSpaceCharCount++; // Counting '\n' as non-space character
    }

    cout << "Word count: " << wordCount << endl;
    cout << "Total number of characters: " << charCount << endl;
    cout << "Total number of non-whitespace characters: " << nonSpaceCharCount << endl;
    cout << "Total number of letters: " << letterCount << endl;

    ofstream outFile("output.txt");
    outFile << "Word count: " << wordCount << endl;
    outFile << "Total number of characters: " << charCount << endl;
    outFile << "Total number of non-whitespace characters: " << nonSpaceCharCount << endl;
    outFile << "Total number of letters: " << letterCount << endl;

    inFile.close();
    outFile.close();

    return 0;
}
