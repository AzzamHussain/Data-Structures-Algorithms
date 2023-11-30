#include <iostream>
#include <cstdlib>

using namespace std;

struct BST
{
    int data;
    BST *right = nullptr;
    BST *left = nullptr;
    int height = 1; // Initialize the height to 1
};

int height(BST *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int heightDifference(BST *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void updateHeight(BST *node)
{
    if (node != nullptr)
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
        {
            node->height = 1 + leftHeight;
        }
        if (rightHeight > leftHeight)
        {
            node->height = 1 + rightHeight;
        }
    }
}

BST *shiftLeft(BST *node)
{
    BST *nNode = node->right;
    node->right = nNode->left;
    nNode->left = node;

    // Update heights
    updateHeight(node);
    updateHeight(nNode);

    return nNode;
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

    // Update height of the current node
    updateHeight(node);

    // Check and perform rotations
    int balance = heightDifference(node);



    if (balance < -1 && value > node->right->data)
    {
        // Right-Right case, perform left rotation
        return shiftLeft(node);
    }

    return node;
}

void preorder(BST *node)
{
    if (node != nullptr)
    {
        cout << node->data << endl;
        preorder(node->left);
        preorder(node->right);
    }
}


int main()
{
    BST *root = nullptr;
    int n;
    cout << "Enter number of Nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int insert;
        cout << "Enter value to be inserted: ";
        cin >> insert;
        root = insertion(root, insert);
        cout << "Preorder: " << endl;
        preorder(root);
    }
    
    return 0;
}



    // if (balance > 1 && value < node->left->data)
    // {
    //     // Left-Left case, perform a right rotation
    //     return shiftRight(node);
    // }

    // if (balance > 1 && value > node->left->data)
    // {
    //     // Left-Right case, perform left-right rotation
    //     node->left = shiftLeft(node->left);
    //     return shiftRight(node);
    // }

    //   if (balance < -1 && value < node->right->data)
    // {
    //     // Right-Left case, perform right-left rotation
    //     node->right = shiftRight(node->right);
    //     return shiftLeft(node);
    // }

//     BST *shiftRight(BST *node)
// {
//     BST *nNode = node->left;
//     node->left = nNode->right;
//     nNode->right = node;

//     // Update heights
//     updateHeight(node);
//     updateHeight(nNode);

//     return nNode;
// }
