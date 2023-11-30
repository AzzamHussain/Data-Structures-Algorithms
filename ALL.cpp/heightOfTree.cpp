#include <iostream>
#include <cstdlib>

using namespace std;

struct BST
{
    int data;
    BST *right = nullptr;
    BST *left = nullptr;
};


int height(BST *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        int left_height = height(node->left);
        int right_height = height(node->right);
        
        int node_height = (left_height > right_height) ? left_height : right_height;
        node_height = node_height + 1;
        
        cout << "Node " << node->data << ": Height = " << node_height - 1 << endl;
        
        return node_height;
    }
}


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
    if (node == nullptr || node->data == value)
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
        cout << "\t 5: Calculate Height. \n";
        cout << "\t 6: Exit. \n";
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
            BST *result = search(root, tosearch);
            if (result)
            {
                cout << "Value found: " << result->data << endl;
            }
            else
            {
                cout << "Value not found!" << endl;
            }
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
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
            }
            else if (opt2 == 2)
            {
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
            }
            else if (opt2 == 3)
            {
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
            }
        }
        else if (opt == 5)
        {
            int treeHeight = height(root);
            cout << "Height of the tree is: " << treeHeight << endl;
        }
        else if (opt == 6)
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
