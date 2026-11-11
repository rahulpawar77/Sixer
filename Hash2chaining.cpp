/*
Hash Table Implementation for efficient Data Storage 
& retrieval using Chaining
*/
#include <iostream>  // Include header for standard console input/output
#include <string>    // Include header for string handling
using namespace std; // Avoid typing std:: before standard methods
const int SIZE = 10; // Define fixed size of the hash table array
// Node structure representing a single client record in the linked list
struct Node {
    string name;     // Stores client's name (key)
    string phone;    // Stores client's telephone number (value)
    Node* next;      // Pointer to the next client node in the chain
};
// Function to calculate primary hash index based on ASCII sum of the name
int hashFunc(string name) {
    int sum = 0; // Initialize ASCII accumulator variable
    for (size_t i = 0; i < name.length(); i++) { // Loop over characters (C++98 compatible)
        sum += name[i]; // Add character ASCII value to sum
    }
    return sum % SIZE; // Return hash index mapped within array bound [0, SIZE-1]
}
// Function to insert a client into the Hash Table using Chaining
void insertClient(Node* hashTable[], string name, string phone) {
    int index = hashFunc(name); // Compute hash index for client name
    Node* newNode = new Node(); // Dynamically allocate memory for new record node
    newNode->name = name;       // Store name in node
    newNode->phone = phone;     // Store phone number in node
    newNode->next = NULL;       // Set initial next pointer to NULL
    // Insert at the head of the chain at calculated index
    if (hashTable[index] == NULL) { 
        hashTable[index] = newNode; // Assign new node directly if chain is empty
    } else {
        newNode->next = hashTable[index]; // Attach existing chain to new node's next
        hashTable[index] = newNode;       // Update head of chain to new node
    }
    cout << "Inserted " << name << " into chain at Index " << index << endl;
}
// Function to search for a client's telephone number in the Hash Table
void searchClient(Node* hashTable[], string name) {
    int index = hashFunc(name); // Compute hash index for search key
    Node* temp = hashTable[index]; // Point temp pointer to head of list at index    
    // Traverse the linked list chain at this index
    while (temp != NULL) {
        if (temp->name == name) { // Match found
            cout << "Found! " << name << "'s Phone: " << temp->phone << endl;
            return; // Exit function after finding record
        }
        temp = temp->next; // Advance to next node in chain
    }
    cout << "Client " << name << " not found in database!\n"; // Match not found
}
// Function to display the contents of the Hash Table with linked list chains
void displayTable(Node* hashTable[]) {
    cout << "\n--- HASH TABLE (SEPARATE CHAINING) ---\n";
    for (int i = 0; i < SIZE; i++) { // Loop over all array indices
        cout << "Index " << i << ": ";
        Node* temp = hashTable[i]; // Get head node of chain    
        if (temp == NULL) {
            cout << "[ Empty ]";
        } else {
            while (temp != NULL) { // Traverse and print every node in the chain
                cout << "[" << temp->name << " : " << temp->phone << "]";
                if (temp->next != NULL) cout << " -> "; // Visual chain indicator
                temp = temp->next; // Move to next node
            }
        }
        cout << endl; // Newline for next index
    }
}
int main() {
    Node* hashTable[SIZE]; // Array of Node pointers (Hash Table)
   for (int i = 0; i < SIZE; i++) { // Initialize all table slots to NULL (Empty lists)
        hashTable[i] = NULL;
    }
    int choice, count; // Menu choice and client batch entry count
    string name, phone; // Temporary variables for record inputs
    do { // Interactive loop
        cout << "\n================ TELEPHONE DATABASE ================\n";
        cout << "1. Insert Clients (Separate Chaining)\n";
        cout << "2. Search Client\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice; // Read user selection
        if (choice == 1) { // Insert operation
            cout << "How many clients to add? ";
            cin >> count; // Read number of clients to insert at once
            for (int i = 0; i < count; i++) {
                cout << "Enter Name: "; cin >> name; // Read client name
                cout << "Enter Phone: "; cin >> phone; // Read phone number
                insertClient(hashTable, name, phone); // Insert record into table
            }
        } 
        else if (choice == 2) { // Search operation
            cout << "Enter Name to Search: "; 
            cin >> name; // Read search target
            searchClient(hashTable, name); // Call search function
        } 
        else if (choice == 3) { // Display operation
            displayTable(hashTable); // Display current table status
        } 
        else if (choice == 4) { // Exit program
            cout << "Exiting Telephone Database program...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n"; // Choice validation
        }
    } while (choice != 4); // Loop until user chooses option 4
    return 0; // Return zero indicating successful termination
}
