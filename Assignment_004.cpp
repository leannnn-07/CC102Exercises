#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("color.txt");

    if (!outFile) {
        cerr << "Error: Unable to create color.txt" << endl;
        return 1;
    }

    outFile << "Red" << endl;
    outFile << "Orange" << endl;
    outFile << "Yellow" << endl;
    outFile << "Green" << endl;
    outFile << "Blue" << endl;

    outFile.close();

    ifstream inFile("color.txt");

    if (!inFile) {
        cerr << "Error: Unable to open color.txt for reading" << endl;
        return 1;
    }

    ofstream copyFile("color_copy.txt");

    if (!copyFile) {
        cerr << "Error: Unable to create color_copy.txt" << endl;
        inFile.close();
        return 1;
    }

    string line;

    while (getline(inFile, line)) {
        copyFile << line << endl;
    }

    inFile.close();
    copyFile.close();

    cout << "File copied successfully from color.txt to color_copy.txt." << endl;

    return 0;
}