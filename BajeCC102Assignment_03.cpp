#include <iostream>
#include <string>
using namespace std;

void input(struct Book books[], int n);
void display(struct Book books[], int n);
string getCategory(int rating);
bool isDuplicate(struct Book books[], int size, string code);

struct Book {
        string barcode;
        string title;
        int year;
        int rating;
    };
int main() {

    
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book books[n]; 

    input(books, n);
    display(books, n);

    return 0;
}

void input(struct Book books[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << endl;

        string code;
        do {
            cout << "Enter Barcode: ";
            cin >> code;

            if(isDuplicate(books, i, code)) {
                cout << "Barcode already exists! Try again.\n";
            }
        } while(isDuplicate(books, i, code));

        books[i].barcode = code;

        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, books[i].title);

        cout << "Enter Year Published: ";
        cin >> books[i].year;

        do {
            cout << "Enter Rating (0-5): ";
            cin >> books[i].rating;

            if(books[i].rating < 0 || books[i].rating > 5) {
                cout << "Invalid rating! Must be 0 to 5.\n";
            }
        } while(books[i].rating < 0 || books[i].rating > 5);
    }
}

void display(struct Book books[], int n) {
    cout << "\n\n===== BOOK LIST =====\n";
    cout << "Barcode\tTitle\tYear\tRating\tCategory\n";

    for(int i = 0; i < n; i++) {
        cout << books[i].barcode << "\t"
             << books[i].title << "\t"
             << books[i].year << "\t"
             << books[i].rating << "\t"
             << getCategory(books[i].rating) << endl;
    }
}

string getCategory(int rating) {
    switch(rating) {
        case 5: return "Excellent";
        case 4: return "Very Good";
        case 3: return "Good";
        case 2: return "Fair";
        case 1: return "Poor";
        default: return "No Rating";
    }
}

bool isDuplicate(struct Book books[], int size, string code) {
    for(int i = 0; i < size; i++) {
        if(books[i].barcode == code) {
            return true;
        }
    }
    return false;
}