#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string name;
    string phone;
    Node* next;
    Node(string n, string p)
    {
        name = n;
        phone = p;
        next = NULL;
    }
};
class HashTable
{
    Node** table;
    int size;
public:
    HashTable(int s)
    {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }
    int hashFunction(string name)
    {
        int sum = 0;
        for (char ch : name)
            sum += ch;
        return sum % size;
    }
    void insert(string name, string phone)
    {
        int index = hashFunction(name);
        Node* newNode = new Node(name, phone);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            Node* temp = table[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Contact inserted at index "
             << index << endl;
    }
    void display()
    {
        cout << "\n===== TELEPHONE BOOK =====\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " : ";
            Node* temp = table[i];
            if (temp == NULL)
            {
                cout << "NULL";
            }
            else
            {
                while (temp != NULL)
                {
                    cout << "[" << temp->name
                         << " : " << temp->phone << "]";
                    if (temp->next != NULL)
                        cout << " -> ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
    void search(string name)
    {
        int index = hashFunction(name);
        Node* temp = table[index];
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "Contact Found!" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Phone: " << temp->phone << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Contact Not Found!" << endl;
    }
};
int main()
{
    cout<<" ========= STUDENT NAME : OM SAHANE =========\n";
    cout<<" =========      Roll No.: 229         =========\n";
    int size, n;
    string name, phone;
    cout << "Enter hash table size: ";
    cin >> size;
    HashTable h(size);
    cout << "Enter number of contacts: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phone;
        h.insert(name, phone);
    }
    h.display();
    cout << "\nEnter name to search: ";
    cin >> name;
    h.search(name);
    return 0;
}
