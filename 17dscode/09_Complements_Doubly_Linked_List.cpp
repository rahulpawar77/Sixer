// Problem Statement: Find the 1's and 2's complements of a binary number using a doubly linked list.
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int bit;
    Node *prev, *next;
};

Node* createList(string s, Node *&tail)
{
    Node *head = NULL;
    tail = NULL;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            cout << "Invalid Binary Number!";
            return NULL;
        }

        Node *p = new Node;
        p->bit = s[i] - '0';
        p->prev = tail;
        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            tail->next = p;

        tail = p;
    }

    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->bit;
        head = head->next;
    }
    cout << endl;
}

void onesComplement(Node *head)
{
    while (head != NULL)
    {
        head->bit = 1 - head->bit;
        head = head->next;
    }
}

void twosComplement(Node *tail)
{
    Node *p = tail;

    while (p != NULL)
    {
        if (p->bit == 0)
        {
            p->bit = 1;
            break;
        }
        else
        {
            p->bit = 0;
        }

        p = p->prev;
    }
}

int main()
{
    string binary;
    Node *head, *tail = NULL;

    cout << "Enter Binary Number: ";
    cin >> binary;

    head = createList(binary, tail);

    if (head == NULL)
        return 0;

    onesComplement(head);

    cout << "1's Complement: ";
    display(head);

    twosComplement(tail);

    cout << "2's Complement: ";
    display(head);

    while (head != NULL)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }

    return 0;
}
