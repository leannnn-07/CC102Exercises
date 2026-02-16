#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        double sales[5][4] = {0};
        int salesperson, product;
        double amount;
        char more;

        // Input sales records
        do {
            cout << "\nEnter Salesperson number (1-4): ";
            cin >> salesperson;

            cout << "Enter Product number (1-5): ";
            cin >> product;

            cout << "Enter Amount sold: ";
            cin >> amount;

            if (salesperson >= 1 && salesperson <= 4 &&
                product >= 1 && product <= 5) {
                sales[product - 1][salesperson - 1] += amount;
            } else {
                cout << "Invalid input. Try again.\n";
            }

            cout << "Enter another record? (y/n): ";
            cin >> more;

        } while (more == 'y' || more == 'Y');

        cout << "\n---------------------------------------------\n";
        cout << "\t\tSalesperson\n";
        cout << "---------------------------------------------\n";
        cout << "Product\t1\t2\t3\t4\tTotal\n";
        cout << "---------------------------------------------\n";

        double grandTotal = 0;

        // Display table with row totals
        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "---------------------------------------------\n";

        // Column totals
        cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            double columnTotal = 0;
            for (int i = 0; i < 5; i++) {
                columnTotal += sales[i][j];
            }
            cout << columnTotal << "\t";
        }

        cout << grandTotal << endl;
        cout << "---------------------------------------------\n";

        cout << "\nDo you want to run the program again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
