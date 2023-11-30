#include <iostream>
#include <cstdlib>
#include <fstream>
         
using namespace std;
struct Node
{
    Node *prev;
    int data;
    Node *next;
}; struct Node *start = NULL;
struct Node *cursor = start;

Node* createNode(int newData) {
    Node *temp = new Node;
    temp->data = newData;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* insertNode(int num) {
    Node *temp = createNode(num);
    if (start == NULL) 
    {
        start = temp;
        cursor = start;
    } else {
        Node *curr = start;
        while (curr->next != NULL) 
        {
            curr = curr->next;
        }
        temp->prev = curr;
        curr->next = temp; 
    }
}

void cursorRight(int toMove)
{
    while (toMove != 0)
    {
        cursor = cursor->next;
        toMove--;
    }
}

void cursorLeft(int toMove)
{
    while (toMove != 0)
    {
        cursor = cursor->prev;
        toMove--;
    }
}

void insertionAtCursor(int newData) {
    Node* temp = createNode(newData);
    Node* curr = start;

    if (cursor == NULL) {
        // List is empty, so make 'temp' the new start.
        temp->next = start;
        if (start != NULL) {
            start->prev = temp;
        }
        start = temp;
    } else {
        // Insert 'temp' after the cursor.
        temp->next = cursor->next;
        temp->prev = cursor;
        if (cursor->next != NULL) {
            cursor->next->prev = temp;
        }
        cursor->next = temp;
    }
}


void toPrint()
{
    cout << cursor->data << " ";
    return;
}

// void print() {
//     Node* curr = start;
//     if (curr == NULL) {
//         cout << "List is empty.\n";
//     }
//     cout << "\t\t The list is: \n";
//     while (curr != NULL) {
//         cout << "Data: " << curr->data << endl;
//         curr = curr->next;
//     }
//     return;
// }

void deletion(int toDelete) {

    struct Node *curr = start;
    struct Node *temp = NULL;

    while (toDelete != 0) 
    {
        temp = curr;
        curr = curr->next;
        toDelete--;
    }
    if (temp == NULL) 
    {
        start = curr->next;
        cursor = curr->next;
        if (start != NULL) 
        {
            start->prev = NULL;
        }
    } 
    else 
    {
        temp->next = curr->next;
        if (curr->next != NULL) 
        {
            curr->next->prev = temp;
        }
    }
    delete curr;
    return;       
}

void deleteAtEnd() {
    if (start == NULL) {
        // List is empty, nothing to delete.
        return;
    }
    
    struct Node *curr = start;
    
    if (curr->next == NULL) {
        // If there's only one node in the list.
        delete curr;
        start = NULL;
        return;
    }
    
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // Now curr points to the last node.
    curr->prev->next = NULL;
    delete curr;
}


void update(int toUpdate, int upddata)
{
    
    struct Node *curr = start;

    while (toUpdate != 0) 
    {
        curr = curr->next;
        toUpdate--;
    }
    curr->data = upddata;
    return;
}

void updateCursor(int upddata)
{
    Node *curr = cursor;
    curr->data = upddata;
}

void insertAtNum(int newIndex, int newData)
{
    Node* temp = createNode(newData);
    Node *curr = start;
    int currentIndex;
    while (curr != nullptr && currentIndex < newIndex - 1) {
        curr = curr->next;
        currentIndex++;
    }
    
    
    // if (start->next == NULL) // Inserting at the beginning
    // {
    //     temp->data = newData;
    //     temp->prev = NULL;
    //     temp->next = start;
    //     if (start != NULL)
    //     {
    //         start->prev = temp;
    //     }
    //     start = temp;
    //     cursor = start;
    // }
    // else // Inserting at a non-zero index
    // {
    //    temp->data = newData;
    temp->prev = curr->prev;  
    temp->next = curr;
    if (curr->prev != NULL)
        curr->prev->next = temp;
    curr->prev = temp; 
}

void shift(int toShift)
{
    struct Node *curr = cursor;
    // if (curr == NULL)
    // {
    //     cout << "List is empty\n";
    //     return;
    // }    
    while (curr != NULL)
    {
        if (curr->data == toShift)
        {
            struct Node *temp = new Node; 
            temp->data = curr->data; 
            curr->data = cursor->data; 
            cursor->data = temp->data;  
            delete temp;  
            return;  
        }
        curr = curr->next;
    }
    //cout << "Following ID does not exist";
}

void deleteCursor()
{
    if (cursor == NULL)
    {
        // Handle the case where cursor is NULL (optional).
        return;
    }

    struct Node *curr = cursor;
    struct Node *temp = curr->prev;

    if (cursor == start) 
    {
        if (temp == NULL) 
        {
            if (start->next != NULL)
            {
                start = curr->next;
                cursor = curr->next;
                if (start != NULL) {
                    start->prev = NULL;
                }
            }
            else
            {
                // If start->next is NULL, there are no more nodes in the list.
                start = NULL;
                cursor = NULL;
            }
        }
    } 
    else
    {
        temp->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = temp;
        }
        cursor = cursor->prev;
    } 

    // Only delete if the node was dynamically allocated.
    delete curr;
}


int main() 
{
    ifstream inputFile("uTest.txt");

    string command;
    while (inputFile >> command) 
    {
        cout << "COMMANDS: " << command << "\n"; 
        if (command == "Add") {
            int num1;
            int check;
            inputFile >> num1;
            check = inputFile.get();
            if (check == 10)
            {
                insertNode(num1);
                continue;
            }
            else
            {
                int num2;
                insertAtNum(num1, num2);
            }
        }
        else if (command == "AddImmediate"){
            int num;
            inputFile >> num;
            insertionAtCursor(num);
        } else if (command == "Delete"){
                int toDelete;
                inputFile >> toDelete;
                cout << toDelete;
                if (toDelete == 0)
                {
                    deleteAtEnd();
                    continue;
                }
                else
                {
                    deletion(toDelete);
                }
                cout << "DONE";
        }else if (command == "DeleteImmediate"){
            cout << "LOL";
            deleteCursor();
        }else if (command == "Shift"){
             int toShift;
             inputFile >> toShift;
             shift(toShift);
        } else if (command == "Print") {
            toPrint();
        } else if (command == "MoveForward"){
            int cursor;
            inputFile >> cursor;
            cursorRight(cursor);
        } else if (command == "MoveBackward"){
            int cursor;
            inputFile >> cursor;
            cursorLeft(cursor);    
        } else if (command == "Update"){
            int toUpdate;
            int upddata;
            inputFile >> toUpdate;
            inputFile >> upddata;
            update(toUpdate, upddata);
        } else if (command == "UpdateImmediate"){
            int upddata;
            inputFile >> upddata;
            updateCursor(upddata);
        
        } else if (command == "END") {
            break;
        }
    }   

    // Free memory for the linked list
    Node* curr = start;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    return 0;
}