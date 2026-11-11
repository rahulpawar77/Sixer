#include<iostream>
#include<string>
using namespace std;
struct Node
{
    int prn;
    string name;
    Node* next;
};
// Function to create a node
Node* createNode()
{
    Node* newNode = new Node();
    cout << "Enter PRN : ";
    cin >> newNode->prn;
    cout << "Enter Name : ";
    cin >> newNode->name;
    newNode->next = NULL;
    return newNode;
}
// a) Add Members (President, Secretary and Regular Member)
void addPresident(Node*& head)
{
    Node* newNode = createNode();
    newNode->next = head;
    head = newNode;
}

void addSecretary(Node*& head)
{
    Node* newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void addMember(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "Add President and Secretary first!\n";
        return;
    }
    Node* newNode = createNode();
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

// b) Delete Members (President, Secretary and Regular Member by PRN)
void deletePresident(Node*& head)
{
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteSecretary(Node*& head)
{
    if (head == NULL) return;
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}
void deleteMember(Node*& head)
{
    int prn;
    cout << "Enter PRN to delete : ";
    cin >> prn;
    if (head == NULL) return;
    if (head->prn == prn) { deletePresident(head); return; }
    Node* temp = head, *prev = NULL;
    while (temp != NULL && temp->prn != prn)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {cout << "PRN not found!\n"; return; }
    prev->next = temp->next;
    delete temp;
}
// c) Compute total number of members
int countMembers(Node* head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
// d) Display members
void display(Node* head)
{
    if (head == NULL) { cout << "List is empty!\n"; return;}
    cout << "\nPRN\tName\tRole\n";
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->prn << "\t" << temp->name;
        if (temp == head) cout << "\t(President)\n";
        else if (temp->next == NULL) cout << "\t(Secretary)\n";
        else cout << "t(Member)\n";
        temp = temp->next;
    }
}
// e) Concatenate two lists
Node* concatenate(Node* head1, Node* head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    Node* temp = head1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head2;
    return head1;
}
int main()
{ 
    cout << "Name : Sanit Salve" << endl << "Roll No. : 230";
    Node* divA = NULL;
    Node* divB = NULL;
    int choice;
    do
    {
        cout << "\n=====PINNACLE CLUB=====\n";
        cout << "1. Add President\n2. Add Secretary\n3. Add Member\n";
        cout << "4. Delete President\n5. Delete Secretary\n6. Delete Member\n";
        cout << "7. Count Member\n8. Display Members\n9. Concatenate Div B into Div A\n10. Exit\n";
        cout << "Choice : ";
        cin >> choice;
        if (choice == 1) addPresident(divA);
        else if (choice == 2) addSecretary(divA);
        else if (choice == 3) addMember(divA);
        else if (choice == 4) deletePresident(divA);
        else if (choice == 5) deleteSecretary(divA);
        else if (choice == 6) deleteMember(divA);
        else if (choice == 7) cout << "Total : " << countMembers(divA) << endl;
        else if (choice == 8) display(divA);
        else if (choice == 9)
        {
            cout << "\n[Enter details for division B]\n";
            addPresident(divB);
            addSecretary(divB);
            divA = concatenate(divA, divB);
            cout << "Lists Concatenated!\n";
        }
    } while (choice != 10);
    return 0;
}