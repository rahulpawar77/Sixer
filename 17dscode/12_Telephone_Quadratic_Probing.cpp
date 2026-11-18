// Problem Statement: Store client telephone records in a hash table and search them using quadratic probing.
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 16;

struct Record
{
    string name;
    long long phone;
    bool occupied;
};

Record table[SIZE];

int hashFunction(string name)
{
    int sum = 0;

    for (int i = 0; i < name.length(); i++)
        sum += name[i];

    return sum % SIZE;
}

int probeIndex(int h, int i)
{
    return (h + i * (i + 1) / 2) % SIZE;
}

void insertRecord()
{
    string name;
    long long phone;

    cout << "Enter Client Name: ";
    cin >> name;

    cout << "Enter Phone Number: ";
    cin >> phone;

    int h = hashFunction(name);

    for (int i = 0; i < SIZE; i++)
    {
        int pos = probeIndex(h, i);

        if (table[pos].occupied && table[pos].name == name)
        {
            table[pos].phone = phone;
            cout << "Record Updated Successfully!\n";
            return;
        }

        if (!table[pos].occupied)
        {
            table[pos].name = name;
            table[pos].phone = phone;
            table[pos].occupied = true;

            cout << "Record Inserted at Index " << pos << endl;
            return;
        }
    }

    cout << "Hash Table is Full!\n";
}

void searchRecord()
{
    string name;

    cout << "Enter Client Name: ";
    cin >> name;

    int h = hashFunction(name);

    for (int i = 0; i < SIZE; i++)
    {
        int pos = probeIndex(h, i);

        if (!table[pos].occupied)
            break;

        if (table[pos].name == name)
        {
            cout << "\nClient Name: " << table[pos].name;
            cout << "\nPhone Number: " << table[pos].phone << endl;
            return;
        }
    }

    cout << "Client Not Found!\n";
}

void display()
{
    cout << "\n===== TELEPHONE DIRECTORY =====\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : ";

        if (table[i].occupied)
            cout << table[i].name << " - " << table[i].phone;
        else
            cout << "Empty";

        cout << endl;
    }
}

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

    return 0;
}
