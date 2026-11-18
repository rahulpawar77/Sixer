// Problem Statement: Maintain Pinnacle Club members using a singly linked list and delete members, president or secretary.
#include <iostream>
using namespace std;

struct Node
{
    int prn;
    string name;
    char role;
    Node *next;
};

Node *head = NULL;

void addPresident()
{
    Node *p = new Node;

    cout << "Enter PRN and Name: ";
    cin >> p->prn >> p->name;

    p->role = 'P';
    p->next = head;
    head = p;

    cout << "President Added Successfully!\n";
}

void addMember()
{
    Node *p = new Node;

    cout << "Enter PRN and Name: ";
    cin >> p->prn >> p->name;

    p->role = 'M';
    p->next = NULL;

    if (head == NULL)
        head = p;
    else
    {
        Node *t = head;

        while (t->next != NULL && t->next->role != 'S')
            t = t->next;

        p->next = t->next;
        t->next = p;
    }

    cout << "Member Added Successfully!\n";
}

void addSecretary()
{
    Node *p = new Node;

    cout << "Enter PRN and Name: ";
    cin >> p->prn >> p->name;

    p->role = 'S';
    p->next = NULL;

    if (head == NULL)
        head = p;
    else
    {
        Node *t = head;

        while (t->next != NULL)
            t = t->next;

        t->next = p;
    }

    cout << "Secretary Added Successfully!\n";
}

void deletePresident()
{
    if (head == NULL || head->role != 'P')
    {
        cout << "President Not Found!\n";
        return;
    }

    Node *t = head;
    head = head->next;
    delete t;

    cout << "President Deleted Successfully!\n";
}

void deleteMember()
{
    int prn;

    cout << "Enter Member PRN: ";
    cin >> prn;

    Node *t = head, *prev = NULL;

    while (t != NULL && !(t->role == 'M' && t->prn == prn))
    {
        prev = t;
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Member Not Found!\n";
        return;
    }

    prev->next = t->next;
    delete t;

    cout << "Member Deleted Successfully!\n";
}

void deleteSecretary()
{
    Node *t = head, *prev = NULL;

    while (t != NULL && t->role != 'S')
    {
        prev = t;
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "Secretary Not Found!\n";
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    delete t;

    cout << "Secretary Deleted Successfully!\n";
}

void display()
{
    Node *t = head;

    if (head == NULL)
    {
        cout << "Club List is Empty!\n";
        return;
    }

    cout << "\n===== PINNACLE CLUB =====\n";

    while (t != NULL)
    {
        if (t->role == 'P')
            cout << "President: ";
        else if (t->role == 'S')
            cout << "Secretary: ";
        else
            cout << "Member: ";

        cout << t->prn << " - " << t->name << endl;

        t = t->next;
    }
}

int main()
{
    int ch;

    do
    {
        cout << "\n===== PINNACLE CLUB =====\n";
        cout << "1. Add President\n";
        cout << "2. Add Member\n";
        cout << "3. Add Secretary\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Member\n";
        cout << "6. Delete Secretary\n";
        cout << "7. Display Members\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1: addPresident(); break;
            case 2: addMember(); break;
            case 3: addSecretary(); break;
            case 4: deletePresident(); break;
            case 5: deleteMember(); break;
            case 6: deleteSecretary(); break;
            case 7: display(); break;
            case 8: cout << "Program Ended!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (ch != 8);

    while (head != NULL)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }

    return 0;
}
