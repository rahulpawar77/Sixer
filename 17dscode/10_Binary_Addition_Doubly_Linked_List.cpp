// Problem Statement: Add binary numbers using a doubly linked list.
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
            return NULL;

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

string addBinary(Node *a, Node *b)
{
    string result = "";
    int carry = 0;

    while (a != NULL || b != NULL || carry != 0)
    {
        int sum = carry;

        if (a != NULL)
        {
            sum += a->bit;
            a = a->prev;
        }

        if (b != NULL)
        {
            sum += b->bit;
            b = b->prev;
        }

        result = char('0' + sum % 2) + result;
        carry = sum / 2;
    }

    return result;
}

void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
}

int main()
{
    string s1, s2;
    Node *tail1 = NULL, *tail2 = NULL;

    cout << "Enter First Binary Number: ";
    cin >> s1;

    cout << "Enter Second Binary Number: ";
    cin >> s2;

    Node *h1 = createList(s1, tail1);
    Node *h2 = createList(s2, tail2);

    if (h1 == NULL || h2 == NULL)
    {
        cout << "Invalid Binary Number!";
        freeList(h1);
        freeList(h2);
        return 0;
    }

    cout << "Binary Addition = " << addBinary(tail1, tail2);

    freeList(h1);
    freeList(h2);

    return 0;
}
