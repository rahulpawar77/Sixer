// Problem Statement: Build a BST, insert a node, find the longest root path and find the minimum value.
#include <iostream>
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

// Find Longest Path
int height(Node *root)
{
    if (root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

// Find Minimum Value
int minimum(Node *root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
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
    int n, x, ch;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    cout << "Enter Values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    do
    {
        cout << "\n===== BINARY SEARCH TREE =====\n";
        cout << "1. Insert New Node\n";
        cout << "2. Find Longest Path\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Display Inorder\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter Value: ";
                cin >> x;
                root = insert(root, x);
                cout << "Node Inserted Successfully!\n";
                break;

            case 2:
                cout << "Longest Path (Height) = "
                     << height(root) << endl;
                break;

            case 3:
                if (root == NULL)
                    cout << "Tree is Empty!\n";
                else
                    cout << "Minimum Value = "
                         << minimum(root) << endl;
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

    } while (ch != 5);

    freeTree(root);

    return 0;
}
