// Problem Statement: Search student roll numbers using Linear and Binary Search and count comparisons.
#include <iostream>
#include <algorithm>
using namespace std;
 
int linearSearch(int a[], int n, int key) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (a[i] == key) {
            cout << "Found at position " << i + 1 << endl;
            cout << "Comparisons = " << comparisons << endl;
            return 1;
        }
    }
    cout << "Not Found\nComparisons = " << comparisons << endl;
    return 0;
}
 
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, comparisons = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (a[mid] == key) {
            cout << "Found at position " << mid + 1 << endl;
            cout << "Comparisons = " << comparisons << endl;
            return 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Not Found\nComparisons = " << comparisons << endl;
    return 0;
}
 
int main() {
    int a[100], n, key, choice;
    cout << "Enter number of students: ";
    cin >> n;
    if (n < 1 || n > 100) return 0;
 
    cout << "Enter roll numbers in random order: ";
    for (int i = 0; i < n; i++) cin >> a[i];
 
    do {
        cout << "\n1. Linear Search\n2. Binary Search\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            cout << "Enter roll number to search: ";
            cin >> key;
            if (choice == 1) linearSearch(a, n, key);
            else {
                int b[100];
                copy(a, a + n, b);
                sort(b, b + n);
                cout << "Sorted roll numbers: ";
                for (int i = 0; i < n; i++) cout << b[i] << " ";
                cout << endl;
                binarySearch(b, n, key);
            }
        } else if (choice != 3) cout << "Invalid choice\n";
    } while (choice != 3);
    return 0;
}
 
