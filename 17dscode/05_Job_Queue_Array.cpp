// Problem Statement: Simulate a first-come, first-served job queue using an array with add and delete operations.
#include <iostream>
using namespace std;
 
const int MAX = 100;
int queueArr[MAX], frontIndex = -1, rearIndex = -1, capacity;
 
void addJob(int job) {
    if ((rearIndex + 1) % capacity == frontIndex) {
        cout << "Job Queue is Full\n";
        return;
    }
    if (frontIndex == -1) frontIndex = rearIndex = 0;
    else rearIndex = (rearIndex + 1) % capacity;
    queueArr[rearIndex] = job;
    cout << "Job added successfully\n";
}
 
void deleteJob() {
    if (frontIndex == -1) {
        cout << "Job Queue is Empty\n";
        return;
    }
    cout << "Processed Job: " << queueArr[frontIndex] << endl;
    if (frontIndex == rearIndex) frontIndex = rearIndex = -1;
    else frontIndex = (frontIndex + 1) % capacity;
}
 
void display() {
    if (frontIndex == -1) {
        cout << "Job Queue is Empty\n";
        return;
    }
    cout << "Jobs in queue: ";
    int i = frontIndex;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rearIndex) break;
        i = (i + 1) % capacity;
    }
    cout << endl;
}
 
int main() {
    int choice, job;
    cout << "Enter maximum queue size (1-100): ";
    cin >> capacity;
    if (capacity < 1 || capacity > MAX) return 0;
 
    do {
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter Job ID: "; cin >> job; addJob(job); break;
            case 2: deleteJob(); break;
            case 3: display(); break;
            case 4: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}
