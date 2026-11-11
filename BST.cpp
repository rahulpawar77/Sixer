#include <iostream>
#include <algorithm>
using namespace std;
// Task 1: Create a node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
// Task 3: Implement a function to insert a new node into the BST
Node* insert(Node* root, int val) {
    // If the tree/subtree is empty, create and return the new node
    if (root == nullptr) {
        return new Node(val);
    }
    // Otherwise, recur down the tree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root; // Return the unchanged node pointer
}
// Task 8: Display tree contents using Inorder Traversal (Sorted order)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Task 4: Implement a function to calculate the height (longest path from root in terms of nodes)
int longestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);
    return max(leftHeight, rightHeight) + 1;
}
// Task 5: Implement a function to find the minimum value in the BST
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left; // Minimum is always at the leftmost node
    }
    return current->data;
}
// Task 6: Implement a function to mirror the BST (swap left and right pointers at every node)
void mirrorTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Swap the left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // Recurse for subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}
// Task 7: Implement a search function to locate a given value in the BST
bool searchBST(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key > root->data) {
        return searchBST(root->left, key);
    } else {
        return searchBST(root->right, key);
    }
}
int main() {
    Node* root = nullptr;
    // Task 2: Construct a BST by inserting values in the specified order
    int initialValues[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : initialValues) {
        root = insert(root, val);
    }
    cout << "=== BST Operations & Exemplar Verification ==-\n\n";
    // Display initial tree (Inorder)
    cout << "1. Initial BST Inorder Traversal: ";
    inorder(root);
    cout << "\n\n";
    // i. Insert new node (25)
    cout << "i. Inserting 25 into the BST...\n";
    root = insert(root, 25);
    cout << "   Updated BST Inorder Traversal: ";
    inorder(root);
    cout << "\n\n";
    // ii. Find number of nodes in longest path from root
    int pathLength = longestPath(root);
    cout << "ii. Longest path from root (Height in nodes): " << pathLength << " nodes\n\n";
    // iii. Minimum data value found in the tree
    int minValue = findMin(root);
    cout << "iii. Minimum data value in BST: " << minValue << "\n\n";
    // iv. Mirror the tree
    cout << "iv. Mirroring the tree (swapping left and right pointers at every node)...\n";
    mirrorTree(root);
    cout << "    Inorder Traversal after Mirroring: ";
    inorder(root);
    cout << "\n\n";
    // v. Search values (60 and 90)
    cout << "v. Searching values:\n";
    int searchKeys[] = {60, 90};
    for (int key : searchKeys) {
        if (searchBST(root, key)) {
            cout << "   Search " << key << " -> Found\n";
        } else {
            cout << "   Search " << key << " -> Not Found\n";
        }
    }
    return 0;
}
