#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int countPrimesInFile(string filename) {
    ifstream inputFile(filename);
    int count = 0;
    int number;

    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return -1; 
    }

    while (inputFile >> number) {
        if (isPrime(number)) {
            count++;
        }
    }
    inputFile.close();
    return count;
}
int main() {
    string filename = "NUM.TXT";
    int primeCount = countPrimesInFile(filename);

    if (primeCount != -1) {
        cout << "Total prime numbers in " << filename << ": " << primeCount << endl;
    }

    return 0;
}
