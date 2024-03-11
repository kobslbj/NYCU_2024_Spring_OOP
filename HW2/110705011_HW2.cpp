#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int jumpIt(int* board, int index, int n) {
    if (index >= n - 1) return board[index];
    int oneStep = jumpIt(board, index + 1, n);
    int twoSteps = INT_MAX;
    if (index + 2 < n) twoSteps = jumpIt(board, index + 2, n);
    return board[index] + min(oneStep, twoSteps);
}

int main() {
    string filename;
    cout << "Please enter the filename: ";
    cin >> filename;
    ifstream inFile(filename.c_str());
    if (!inFile) {
        cerr << "Unable to open file: " << filename << endl;
        return 1;
    }

    int n;
    inFile >> n;
    int* board = new int[n]; 

    for (int i = 0; i < n; ++i) {
        inFile >> board[i];
    }

    int minCost = jumpIt(board, 0, n);
    cout << "The lowest cost is " << minCost << endl;

    delete[] board; // Free掉
    inFile.close();

    return 0;
}
