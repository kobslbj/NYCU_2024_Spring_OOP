#include <iostream>

char *deleteRepeats(char *letters, int &size) {
    bool exists[256] = {false};
    int current = 0;

    for (int i = 0; i < size; ++i) {
        if (!exists[letters[i]]) { 
            exists[letters[i]] = true;
            letters[current++] = letters[i];
        }
    }


    size = current; 
    char *newArray = new char[size]; 

    for (int i = 0; i < size; ++i) {
        newArray[i] = letters[i]; 
    }

    return newArray; 
}

int main() {
    int size;
    std::cout << "Please enter the size of string: ";
    std::cin >> size;

    char *letters = new char[size]; 
    std::cout << "Please enter string: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> letters[i]; 
    }

    char *noRepeats = deleteRepeats(letters, size); 

    std::cout << "The new size of string is " << size << std::endl;
    std::cout << "The string after deleteRepeats is ";
    for (int i = 0; i < size; ++i) {
        std::cout << noRepeats[i]; 
    }

    delete[] letters;
    delete[] noRepeats; 

    return 0;
}
