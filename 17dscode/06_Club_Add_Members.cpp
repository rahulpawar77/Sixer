// Problem Statement: Maintain Pinnacle Club members using a singly linked list and add members, president and secretary.
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int prn;
    char name[30];
    Node *next;
};

Node *head = NULL;

void addPresident()
{
    Node *p = new Node;

    cout << "Enter President PRN: ";
    cin >> p->prn;

    cout << "Enter President Name: ";
    cin >> p->name;

    p->next = head;
    head = p;

    cout << "\nPresident added successfully!\n";
}

void addMember()
{
    Node *p = new Node;

    cout << "Enter Member PRN: ";
    cin >> p->prn;

    cout << "Enter Member Name: ";
    cin >> p->name;

    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }

    cout << "\nMember added successfully!\n";
}

void addSecretary()
{
    Node *p = new Node;

    cout << "Enter Secretary PRN: ";
    cin >> p->prn;

    cout << "Enter Secretary Name: ";
    cin >> p->name;

    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }

    cout << "\nSecretary added successfully!\n";
}

void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        cout << "\nClub list is empty!\n";
        return;
    }

    cout << "\n===== PINNACLE CLUB MEMBERS =====\n";

    while (temp != NULL)
    {
        cout << "PRN  : " << temp->prn << endl;
        cout << "Name : " << temp->name << endl;
        cout << "-------------------------\n";

        temp = temp->next;
    }
}

void countMembers()
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "\nTotal Club Members: " << count << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== PINNACLE CLUB ==========\n";
        cout << "1. Add President\n";
        cout << "2. Add Member\n";
        cout << "3. Add Secretary\n";
        cout << "4. Display Members\n";
        cout << "5. Count Members\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPresident();
                break;

            case 2:
                addMember();
                break;

            case 3:
                addSecretary();
                break;

            case 4:
                display();
                break;

            case 5:
                countMembers();
                break;

            case 6:
                cout << "\nThank you for using Pinnacle Club!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
