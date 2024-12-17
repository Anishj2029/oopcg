/// Write a function template for selection sort that inputs, sorts and outputs an integer array and 
// a float array.

#include <iostream>
using namespace std;

#define SIZE 10

// Function template for selection sort
template <typename T>
void sel(T a[], int n) {
    int i, j, minIndex;
    T temp;

    // Selection sort logic
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[minIndex] > a[j]) {
                minIndex = j;
            }
        }
        // Swap the elements
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    // Display the sorted array
    cout << "Sorted array: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[SIZE];
    float b[SIZE];
    int n;
    int i;
    int ch;

    while (true) {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Sort Integer Array\n";
        cout << "2. Sort Float Array\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                // Input for integer array
                cout << "Enter the total number of integers (max " << SIZE << "): ";
                cin >> n;
                if (n > SIZE || n <= 0) {
                    cout << "Invalid size! Please enter a size between 1 and " << SIZE << "." << endl;
                    break;
                }
                cout << "Enter the integer elements:\n";
                for (i = 0; i < n; i++) {
                    cin >> a[i];
                }
                sel(a, n); // Call selection sort for integers
                break;
            }

            case 2: {
                // Input for float array
                cout << "Enter the total number of floats (max " << SIZE << "): ";
                cin >> n;
                if (n > SIZE || n <= 0) {
                    cout << "Invalid size! Please enter a size between 1 and " << SIZE << "." << endl;
                    break;
                }
                cout << "Enter the float elements:\n";
                for (i = 0; i < n; i++) {
                    cin >> b[i];
                }
                sel(b, n); // Call selection sort for floats
                break;
            }

            case 3: {
                // Exit the program
                cout << "Exiting the program. Goodbye!" << endl;
                exit(0);
            }

            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }

    return 0;
}

