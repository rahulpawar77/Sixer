// Problem Statement: Build a BST, insert a node, find the minimum value and mirror the tree.
#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Insert Node
Node* insert(Node *root, int x)
{
    if (root == NULL)
    {
        Node *p = new Node;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Find Minimum Value
int minimum(Node *root)
{
    if (root == NULL)
        return INT_MAX;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Mirror Tree
void mirror(Node *root)
{
    if (root == NULL)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Delete Tree
void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Main Function
int main()
{
    Node *root = NULL;
    int n, x, choice;
    bool mirrored = false;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    do
    {
        cout << "\n===== BINARY SEARCH TREE =====\n";
        cout << "1. Insert New Node\n";
        cout << "2. Find Minimum Value\n";
        cout << "3. Mirror Tree\n";
        cout << "4. Display Inorder\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (mirrored)
                    cout << "Cannot insert after mirroring!\n";
                else
                {
                    cout << "Enter value: ";
                    cin >> x;
                    root = insert(root, x);
                    cout << "Node Inserted!\n";
                }
                break;

            case 2:
                if (root == NULL)
                    cout << "Tree is Empty!\n";
                else
                    cout << "Minimum Value = " << minimum(root) << endl;
                break;

            case 3:
                mirror(root);
                mirrored = !mirrored;
                cout << "Tree Mirrored Successfully!\n";
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Program Ended!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    freeTree(root);

    return 0;
}
