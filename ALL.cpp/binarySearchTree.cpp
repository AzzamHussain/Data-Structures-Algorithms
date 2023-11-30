#include <iostream>
#include <cstdlib>

using namespace std;

struct BST
{
    int data;
    BST *right = nullptr;
    BST *left = nullptr;
};

BST *insertion(BST *node, int value)
{
    if (node == nullptr)
    {
        BST *newNode = new BST;
        newNode->data = value;
        return newNode;
    }
    if (value > node->data)
    {
        node->right = insertion(node->right, value);
    }
    else if (value < node->data)
    {
        node->left = insertion(node->left, value);
    }
    return node;
}

void inorder(BST *node)
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void preorder(BST *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(BST *node)
{
    if (node != nullptr)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

BST *search(BST *node, int value)
{
    if (node == nullptr)
    {
        cerr << "VALUE NOT FOUND!" << endl;
        return nullptr; // Return nullptr to indicate the value was not found
    }
    if (value == node->data)
    {
        return node;
    }
    else if (value > node->data)
    {
        return search(node->right, value);
    }
    else
    {
        return search(node->left, value);
    }
}

BST *minValueNode(BST *node)
{
    BST *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

BST *deletion(BST *node, int value)
{
    if (node == nullptr)
    {
        cerr << "ERROR 404" << endl;
        return node;
    }

    if (value < node->data)
    {
        node->left = deletion(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = deletion(node->right, value);
    }
    else
    {
        if (node->left == nullptr)
        {
            BST *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            BST *temp = node->left;
            delete node;
            return temp;
        }

        BST *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deletion(node->right, temp->data);
    }

    return node;
}

int main()
{
    BST *root = nullptr;
    int opt;
    
    while (true)
    {
        cout << "\t 1: Insert an ID. \n";
        cout << "\t 2: Search an ID. \n";
        cout << "\t 3: Delete an ID. \n";
        cout << "\t 4: Traverse the tree. \n";
        cout << "\t 5: Exit. \n";
        cin >> opt;

        if (opt == 1)
        {
            int optInsert = 1;
            while (optInsert == 1)
            {
                int insert;
                cout << "Enter value to be inserted: ";
                cin >> insert;
                root = insertion(root, insert);
                cout << "\t If you want to add another ID enter 1, if you want to exit enter 0: ";
                cin >> optInsert;
                if (optInsert != 1)
                {
                    break;
                }
            }
        }
        else if (opt == 2)
        {
            int tosearch;
            cout << "Enter value to be searched: ";
            cin >> tosearch;
            root = search(root, tosearch);
        }
        else if (opt == 3)
        {
            int todelete;
            cout << "Enter value to be deleted: ";
            cin >> todelete;
            root = deletion(root, todelete);
        }
        else if (opt == 4)
        {
            int opt2;
            cout << "\t\t Enter 1 for inorder: \n";
            cout << "\t\t Enter 2 for preorder: \n";
            cout << "\t\t Enter 3 for postorder: \n";
            cin >> opt2;
            if (opt2 == 1)
            {
                cout << "Inorder: " << endl;
                inorder(root);
            }
            else if (opt2 == 2)
            {
                cout << "Preorder: " << endl;
                preorder(root);
            }
            else if (opt2 == 3)
            {
                cout << "Postorder; " << endl;
                postorder(root);
            }
            cout << endl; // Add a newline to separate the output from the menu
        }
        else if (opt == 5)
        {
            break;
        }
        else
        {
            cout << "INVALID INPUT" << endl;
        }
    }

    return 0;
}