#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10;
struct Contact {
    string name;
    string phone;
    bool occupied;
    Contact() {
        name = "";
        phone = "";
        occupied = false;
    }
};
// ================= LINEAR PROBING =================
class LinearHashTable {
    Contact table[SIZE];
    int hashFunction(string name) {
        int sum = 0;
        for (char c : name)
            sum += c;
        return sum % SIZE;
    }
public:
    void insert(string name, string phone) {
        int index = hashFunction(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;
            if (!table[pos].occupied) {
                table[pos].name = name;
                table[pos].phone = phone;
                table[pos].occupied = true;
                cout << "Contact inserted successfully.\n";
                return;
            }
        }
        cout << "Hash table is full.\n";
    }
    void search(string name) {
        int index = hashFunction(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;
            if (!table[pos].occupied)
                break;
            if (table[pos].name == name) {
                cout << "Name  : " << table[pos].name << endl;
                cout << "Phone : " << table[pos].phone << endl;
                return;
            }
        }
        cout << "Contact not found.\n";
    }
    void display() {
        cout << "\n--- Linear Probing Hash Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            if (table[i].occupied)
                cout << table[i].name << " - " << table[i].phone;
            else
                cout << "Empty";
            cout << endl;
        }
    }
};
// ================= QUADRATIC PROBING =================
class QuadraticHashTable {
    Contact table[SIZE];
    int hashFunction(string name) {
        int sum = 0;
        for (char c : name)
            sum += c;
        return sum % SIZE;
    }
public:
    void insert(string name, string phone) {
        int index = hashFunction(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i * i) % SIZE;
            if (!table[pos].occupied) {
                table[pos].name = name;
                table[pos].phone = phone;
                table[pos].occupied = true;
                cout << "Contact inserted successfully.\n";
                return;
            }
        }
        cout << "Hash table is full.\n";
    }
    void search(string name) {
        int index = hashFunction(name);
        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i * i) % SIZE;
            if (!table[pos].occupied)
                break;
            if (table[pos].name == name) {
                cout << "Name  : " << table[pos].name << endl;
                cout << "Phone : " << table[pos].phone << endl;
                return;
            }
        }
        cout << "Contact not found.\n";
    }
    void display() {
        cout << "\n--- Quadratic Probing Hash Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";
            if (table[i].occupied)
                cout << table[i].name << " - " << table[i].phone;
            else
                cout << "Empty";
            cout << endl;
        }
    }
};
// ================= MAIN FUNCTION =================
int main() {
    cout<<" ========= STUDENT NAME : OM SONAWANE =========\n";
    cout<<" =========      Roll No.: 244         =========\n";
    LinearHashTable linear;
    QuadraticHashTable quadratic;
    int choice;
    string name, phone;
    do {
        cout << "\n========== TELEPHONE BOOK ==========\n";
        cout << "1. Insert using Linear Probing\n";
        cout << "2. Search using Linear Probing\n";
        cout << "3. Display Linear Hash Table\n";
        cout << "4. Insert using Quadratic Probing\n";
        cout << "5. Search using Quadratic Probing\n";
        cout << "6. Display Quadratic Hash Table\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            linear.insert(name, phone);
            break;
        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            linear.search(name);
            break;
        case 3:
            linear.display();
            break;
        case 4:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;
            quadratic.insert(name, phone);
            break;
        case 5:
            cout << "Enter name to search: ";
            cin >> name;
            quadratic.search(name);
            break;
        case 6:
            quadratic.display();
            break;
        case 7:
            cout << "Program terminated.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);
    return 0;
}
