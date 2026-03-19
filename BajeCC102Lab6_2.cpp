#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct book {
    string barcode;
    string title;
    int year;
    int rating;
};

string getCategory(int r) {
    if (r == 5) return "Excellent";
    if (r == 4) return "Very Good";
    if (r == 3) return "Good";
    if (r == 2) return "Fair";
    if (r == 1) return "Poor";
    return "No Rating";
}

int main() {
    char runAgain;

    do {
        int numBooks;
        cout << "Enter the number of books: ";
        cin >> numBooks;

        book* library = new book[numBooks];

        for (int i = 0; i < numBooks; i++) {
            cout << "\n--- Entry for Book " << (i + 1) << " ---" << endl;
            
            bool isUnique;
            do {
                isUnique = true;
                cout << "Enter Barcode: ";
                cin >> library[i].barcode;

                for (int j = 0; j < i; j++) {
                    if (library[i].barcode == library[j].barcode) {
                        cout << "Error: Barcode already exists! Please try again." << endl;
                        isUnique = false;
                        break;
                    }
                }
            } while (!isUnique);

            cin.ignore(); 
            cout << "Enter Title: ";
            getline(cin, library[i].title);

            cout << "Enter Year Published: ";
            cin >> library[i].year;

            cout << "Enter Rating (0-5): ";
            cin >> library[i].rating;
        }

        cout << "\n" << left << setw(15) << "Barcode" << setw(25) << "Title" 
             << setw(10) << "Year" << setw(10) << "Rating" << "Category" << endl;
        cout << string(70, '-') << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << left << setw(15) << library[i].barcode 
                 << setw(25) << library[i].title 
                 << setw(10) << library[i].year 
                 << setw(10) << library[i].rating 
                 << getCategory(library[i].rating) << endl;
        }

        delete[] library; 

        cout << "\nDo you want to run the program again? (Y/N): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
