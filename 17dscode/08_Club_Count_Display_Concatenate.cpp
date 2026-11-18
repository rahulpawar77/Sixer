// Problem Statement: Count and display club members, and concatenate the linked lists of two divisions.
#include <iostream>
#include <string>
using namespace std;
 
struct Node { int prn; string name; Node* next; };
 
void add(Node*& head) {
    Node* p = new Node;
    cout << "Enter PRN and name: "; cin >> p->prn >> p->name;
    p->next = NULL;
    if (!head) head = p;
    else { Node* t = head; while (t->next) t = t->next; t->next = p; }
}
 
void display(Node* head) {
    if (!head) cout << "List is empty\n";
    int i = 1;
    while (head) {
        cout << i++ << ". PRN: " << head->prn << " Name: " << head->name << endl;
        head = head->next;
    }
}
 
int count(Node* head) {
    int n = 0; while (head) { n++; head = head->next; } return n;
}
 
void concatenate(Node*& first, Node*& second) {
    if (!first) first = second;
    else { Node* t = first; while (t->next) t = t->next; t->next = second; }
    second = NULL;
    cout << "Division lists concatenated\n";
}
 
int main() {
    Node *division1 = NULL, *division2 = NULL;
    int ch, div;
    do {
        cout << "\n1. Add Member\n2. Display Division\n3. Count Division Members\n4. Concatenate Divisions\n5. Display Combined List\n6. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1 || ch == 2 || ch == 3) {
            cout << "Select division (1 or 2): "; cin >> div;
            if (div != 1 && div != 2) { cout << "Invalid division\n"; continue; }
            Node*& h = (div == 1) ? division1 : division2;
            if (ch == 1) add(h);
            else if (ch == 2) display(h);
            else cout << "Total Members = " << count(h) << endl;
        } else if (ch == 4) concatenate(division1, division2);
        else if (ch == 5) display(division1);
        else if (ch != 6) cout << "Invalid choice\n";
    } while (ch != 6);
    while (division1) { Node* t = division1; division1 = division1->next; delete t; }
    while (division2) { Node* t = division2; division2 = division2->next; delete t; }
    return 0;
}
 
