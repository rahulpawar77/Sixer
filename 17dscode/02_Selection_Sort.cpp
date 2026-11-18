// Problem Statement: Sort student percentages in ascending order using Selection Sort and display the top five scores.
#include <iostream>
using namespace std;
 
void selectionSort(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIndex]) minIndex = j;
        swap(a[i], a[minIndex]);
    }
}
 
int main() {
    float a[100];
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    if (n < 1 || n > 100) return 0;
 
    cout << "Enter first-year percentages: ";
    for (int i = 0; i < n; i++) cin >> a[i];
 
    selectionSort(a, n);
    cout << "Percentages in ascending order: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
 
    cout << "\nTop five scores (highest first): ";
    for (int i = n - 1; i >= (n > 5 ? n - 5 : 0); i--) cout << a[i] << " ";
    cout << endl;
    return 0;
}
 
