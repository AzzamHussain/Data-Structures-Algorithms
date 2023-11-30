#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    Node *prev;
    int indexNumber;
    int data;
    Node *next;
}; struct Node *start = NULL;

Node* createNode(int newData, int newIndex) {
    Node *temp = new Node;
    temp->data = newData;
    temp->indexNumber = newIndex;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* insertNode(Node *start, int newData, int newIndex) {
    Node *temp = createNode(newData, newIndex); // Pass newData and newIndex
    if (start == NULL) 
    {
        start = temp;
    } else {
        Node *curr= start;
        while (curr->next != NULL) 
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    return start;
}

void toPrint()
{
    Node * curr = start;
    if (curr == NULL)
    {
        cout << "List is empty.\n";

    }
    cout << "\t\t The list is: \n";
    while (curr != NULL)
    {
        cout << "ID: " << curr ->indexNumber << endl;
        cout << "Data: " << curr ->data << endl;
       // cout << "Previous: " << curr ->prev << endl;
       // cout << "Next: " << curr ->next << endl;
        curr = curr -> next;
    }
}

int main()
{
    ifstream inputFile("Input_Editor.txt");

    int newIndex, newData;

    while (inputFile >> newIndex >> newData) {
        start = insertNode(start, newData, newIndex); // Pass newData and newIndex
    }

    inputFile.close();

    toPrint();

    return 0;
}

// void countingSortLinkedList() {
//     if (start == NULL) {
//         cout << "List is empty.";
//         return; // Empty list
//     }

//     const int maxData = 100; // Assuming maximum data value is 100
//     int count[maxData + 1] = {0}; // Initialize the array with zeros

//     // Find the maximum data value in the linked list
//     Node *curr = start;
//     while (curr != NULL) {
//         count[curr->data]++;
//         curr = curr->next;
//     }
//     //Sorting.
//     curr = start;
//     int dataIndex = 0;
//     while (dataIndex <= maxData) {
//         if (count[dataIndex] > 0) {
//             curr->data = dataIndex;
//             curr = curr->next;
//             count[dataIndex]--;
//         } else {
//             dataIndex++;
//         }
//     }
// }
  


