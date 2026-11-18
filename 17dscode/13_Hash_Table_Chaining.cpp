// Problem Statement: Implement a hash table for efficient data storage and retrieval using chaining.
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node
{
    string name;
    long long phone;
    Node *next;
};

Node *table[SIZE] = {NULL};

// Hash Function
int hashFunction(string name)
{
    int sum = 0;

    for (int i = 0; i < name.length(); i++)
        sum += name[i];

    return sum % SIZE;
}

// Insert Record
void insertRecord()
{
    string name;
    long long phone;

    cout << "Enter Client Name: ";
    cin >> name;

    cout << "Enter Phone Number: ";
    cin >> phone;

    int index = hashFunction(name);

    Node *t = table[index];

    while (t != NULL)
    {
        if (t->name == name)
        {
            t->phone = phone;
            cout << "Record Updated Successfully!\n";
            return;
        }

        t = t->next;
    }

    Node *p = new Node;
    p->name = name;
    p->phone = phone;
    p->next = table[index];

    table[index] = p;

    cout << "Record Inserted at Index " << index << endl;
}

// Search Record
void searchRecord()
{
    string name;

    cout << "Enter Client Name: ";
    cin >> name;

    int index = hashFunction(name);

    Node *t = table[index];

    while (t != NULL)
    {
        if (t->name == name)
        {
            cout << "\nClient Name: " << t->name;
            cout << "\nPhone Number: " << t->phone << endl;
            return;
        }

        t = t->next;
    }

    cout << "Client Not Found!\n";
}

// Display Hash Table
void display()
{
    cout << "\n===== HASH TABLE =====\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> ";

        Node *t = table[i];

        while (t != NULL)
        {
            cout << "[" << t->name << ", " << t->phone << "] -> ";
            t = t->next;
        }

        cout << "NULL\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n===== TELEPHONE DIRECTORY =====\n";
        cout << "1. Insert Client\n";
        cout << "2. Search Client\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: insertRecord(); break;
            case 2: searchRecord(); break;
            case 3: display(); break;
            case 4: cout << "Program Ended!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    // Free Memory
    for (int i = 0; i < SIZE; i++)
    {
        while (table[i] != NULL)
        {
            Node *t = table[i];
            table[i] = table[i]->next;
            delete t;
        }
    }

    return 0;
}
