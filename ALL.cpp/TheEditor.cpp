#include <iostream>
#include <cstdlib>

using namespace std;
struct Node
{
    Node *prev;
    int indexNumber;
    int data;
    Node *next;
}; struct Node *start = NULL;
struct Node *cursor = start;

void cursorMov()
{
    cout << "The cursor is at: " << cursor->indexNumber << "\n";
    char toMove = 0;
    int movRL = 0;
    cout << "If you want to move right enter 'R', if you want to move left enter 'L': ";
    cin >> toMove;
    if (toMove != 'R' && toMove != 'L')
    {
        cout << "INVALID INPUT\n";
        cout << "If you want to move right enter 'R', if you want to move left enter 'L': ";
        cin >> toMove;
    }
    cout << "How many steps do you want to move: ";
    cin >> movRL;

    if (toMove == 'R') {
        while (movRL != 0 && cursor->next != NULL)
        {
            cursor = cursor->next;
            movRL--;
        }
        if (movRL != 0)
        {
            cout << "INVALID INPUT. LIST OUT OF BOUNDS\n";
        }
        cout << "The cursor is at: " << cursor->indexNumber << "\n";
    } 
    else if (toMove == 'L') 
    {
        while (movRL != 0 && cursor->prev != NULL)
        {
            cursor = cursor->prev;
            movRL--;
        }
        if (movRL != 0)
        {
            cout << "INVALID INPUT. LIST OUT OF BOUNDS\n";
        }
        cout << "The cursor is at: " << cursor->indexNumber << "\n";
    } 
}

void insertAtNum()
{
    int newIndex;
    cout << "Enter index: ";
    cin >> newIndex;

    if (newIndex < 0)
    {
        cout << "Invalid index.\n";
        return;
    }

    Node *curr = start;
    while (curr != NULL)
    {
        if (curr->indexNumber == newIndex)
        {
            cout << "Index already exists in the list.\n";
            return;
        }
        curr = curr->next;
    }

    Node *newNode = new Node;
    newNode->indexNumber = newIndex;
    
    if (newIndex == 0) // Inserting at the beginning
    {
        cout << "Enter data: ";
        cin >> newNode->data;
        newNode->prev = NULL;
        newNode->next = start;
        if (start != NULL)
            start->prev = newNode;
        start = newNode;
        cursor = start;
    }
    else // Inserting at a non-zero index
    {
        int newData;
        cout << "Enter data: ";
        cin >> newData;
        newNode->data = newData;
        
        curr = start;
        while (curr != NULL && curr->indexNumber != newIndex - 1)
            curr = curr->next;
        
        if (curr == NULL)
        {
            cout << "Index out of bounds.\n";
            delete newNode;
            return;
        }
        
        newNode->next = curr->next;
        if (curr->next != NULL)
            curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }
}


void insertion()
{
    int newID;
    cout << "Enter ID: ";
    cin >> newID;
    
    Node *curr = start;
    while (curr != NULL)
    {
        if (curr->indexNumber == 0)
        {
            cout << "It is an invalid ID.\n";
        }
        if (curr->indexNumber == newID)
        {
            cout << "Following ID already exists in the list.\n";
            return;
        }
        curr = curr->next;
    }

    Node *temp = new Node; 
    temp->indexNumber = newID;
    cout << "Enter data: ";
    cin >> temp->data;
    temp->next = NULL;
    
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
        cursor = start;
    }
    else
    {
        curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr; 
    }
}

void insertionAtCursor()
{
    
    int newID;
    cout << "Enter ID: ";
    cin >> newID;
    
    Node *curr = start;
    while (curr != NULL)
    {
        if (curr->indexNumber == 0)
        {
            cout << "It is an invalid ID.\n";
        }
        if (curr->indexNumber == newID)
        {
            cout << "Following ID already exists in the list.\n";
            return;
        }
        curr = curr->next;
    }

    Node *temp = new Node;
    temp->indexNumber = newID;
    cout << "Enter data: ";
    cin >> temp->data;
    temp->next = NULL;

    if (cursor == NULL) {
        // If cursor is NULL, insert at the end of the list
        Node *curr = start;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    } else {
        if (cursor->next != NULL) {
            cursor->next->prev = temp;
        }
        temp->next = cursor->next;
        temp->prev = cursor;
        cursor->next = temp;
    }
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

void deleteCursor()
{
    struct Node *curr = start;
    struct Node *temp = NULL;

    while (curr != NULL) {
        if (curr->indexNumber == cursor->indexNumber) {
            if (temp == NULL) {
                start = curr->next;
                cursor = curr->next;
                if (start != NULL) {
                    start->prev = NULL;
                }
            } else {
                temp->next = curr->next;
                if (curr->next != NULL) {
                    curr->next->prev = temp;
                }
            }
            cursor = cursor->prev; 
            delete curr;
            cout << "ID the cursor was at is deleted.\n";
            return;
        }
        temp = curr;
        curr = curr->next;
    }
}

void deletion() {
    int toDelete;
    cout << "Enter ID to delete: ";
    cin >> toDelete;
    struct Node *curr = start;
    struct Node *temp = NULL;

    while (curr != NULL) {
        if (curr->indexNumber == toDelete) {
            if (temp == NULL) {
                start = curr->next;
                cursor = curr->next;
                if (start != NULL) {
                    start->prev = NULL;
                }
            } else {
                temp->next = curr->next;
                if (curr->next != NULL) {
                    curr->next->prev = temp;
                }
            }
            delete curr;
            cout << "ID " << toDelete << " is deleted.\n";
            return;
        }
        temp = curr;
        curr = curr->next;
    }

    cout << "The ID is not in the list.\n";
}


void deleteAll()
{
    struct Node * curr = start;
    while (curr != NULL)
    {
        struct Node * temp = curr;
        curr = curr->next;
        delete temp;
    }
    start = NULL;
}

void search()
{
    int toSearch;
    if (start == NULL)
    {
        cout << "The list is empty. \n";
        return;
    }
    else
    {
        cout << "Enter ID to search: ";
        cin >> toSearch;
        struct Node *curr = start;

        while (curr != NULL)
            {
            if (curr->indexNumber == toSearch)
            {
                cout << "Data of the following ID is: " << curr->data << "\n";
                return;
            }
        curr = curr->next;
            }
    }
    
    cout << "Following ID does not exist.\n";
}

void update()
{
    int toUpdate;
    int upddata;
    int updID;

    if (start == NULL)
    {
        cout << "The list is empty. \n";
        return;
    }

    cout << "\tEnter ID to update: " << "\n";
    cin >> toUpdate;

    struct Node *curr = start;
    bool idFound = false;

    while (curr != NULL)
    {
        if (curr->indexNumber == toUpdate)
        {
            idFound = true;
            break;
        }
        curr = curr->next;
    }

    if (idFound == false)
    {
        cout << "Following ID does not exist.\n";
        return;
    }

    cout << "\tEnter new ID: ";
    cin >> updID;

    curr = start;

    while (curr != NULL)
    {
        if (curr->indexNumber == updID)
        {
            cout << "This ID already exists: \n";
            return;
        }
        curr = curr->next;
    }

    cout << "\tEnter new data: ";
    cin >> upddata;

    curr = start;

    while (curr != NULL)
    {
        if (curr->indexNumber == toUpdate)
        {
            curr->indexNumber = updID;
            curr->data = upddata;
            return;
        }
        curr = curr->next;
    }
}

void updateCursor()
{
    int upddata;
    int updID;

    if (start == NULL)
    {
        cout << "The list is empty. \n";
        return;
    }
    else
    {
        cout << "\tEnter new ID: ";
        cin >> updID;

        struct Node *curr = start;

        while (curr != NULL)
        {
            if (curr->indexNumber == updID)
            {
                cout << "This ID already exists: \n";
                return;
            }
            curr = curr->next;
        }
    }
    
    cout << "\tEnter new data: ";
    cin >> upddata;

    struct Node *curr = start;

    while (curr != NULL)
    {
        if (curr->indexNumber == cursor->indexNumber)
        {
            curr->indexNumber = updID;
            curr->data = upddata;
            return;
        }
        curr = curr->next;
    }

    cout << "Following ID does not exist.\n";
}

void shift()
{
    int toShift;
    cout << "Enter ID you want to shift: ";
    cin >> toShift;
    struct Node *curr = start;
    if (curr == NULL)
    {
        cout << "List is empty\n";
        return;
    }    
    while (curr != NULL)
    {
        if (curr->indexNumber == toShift)
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
    cout << "Following ID does not exist";
}


int main()
{
    int opt;
    cout << "\t 1: Insert an ID. \n";
    cout << "\t 8: Exit. \n";
    cin >> opt;
    
    while (opt != 8)
    {
        if (opt == 1)
        {
            int optInsert = 1;
            int optInsert2 = 0;
            while (optInsert == 1)
            {
               cout << "\t********************************************\n";
               cout << "\t If you want to Insert at End. Enter 1: \n";
               cout << "\t If you want to Insert at Cursor position. Enter 2: \n";
               cout << "\t If you want to Insert at a given Index. Enter 3: \n";
               cin >> optInsert2;

               if (optInsert2 == 1)
               {
                   insertion();
               }
               else if (optInsert2 == 2)
               {
                   insertionAtCursor();
               }
               else if (optInsert2 == 3)
               {
                   insertAtNum();
               }
               else
               {
                   cout << "INVALID INPUT.\n";
               }

               cout << "\t If you want to add another ID enter 1, if you want to exit enter 0: ";
               cin >> optInsert;
               if (optInsert == 0)
                   break;
            }
  
        }
        else if (opt == 2)
        {
            cursorMov();
        }
        else if (opt == 3)
        {
            int optdel;
            cout << "\t\t***********************************************\n";
            cout << "\t\t Enter 1 if you want to delete one element: \n";
            cout << "\t\t Enter 2 if you want to delete ID of the cursor: \n";
            cout << "\t\t Enter 0 if you want to delete the whole list: \n";
            cin >> optdel;
            if (optdel == 1)
            {
                deletion();
            }
            else if (optdel ==2)
            {
                deleteCursor();
            }
            else if (optdel == 0)
            {
                deleteAll();
            }
            else 
            {
                cout << "INVALID INPUT\n";
            }
        }
        else if (opt == 4)
        {
            int optPrint;
            cout << "\t\t***********************************************\n";
            cout << "\t\t Enter 1 if you want to print the cursor: \n";
            cout << "\t\t Enter 2 if you want to print the whole list: \n";
            cin >> optPrint;
            if (optPrint == 1)
            {
                cout << "The data of the cursor's node is: " << cursor->data << "\n";
            }
            else if (optPrint == 2)
            {
                toPrint();
            }
            else 
            {
                cout << "INVALID INPUT\n";
            }
        }
        else if(opt == 5)
        {
            int optUpdate;
            cout << "\t\t***********************************************\n";
            cout << "\t\t Enter 1 if you want to update at a specific ID: \n";
            cout << "\t\t Enter 2 if you want to update the cursor: \n";
            cin >> optUpdate;
            if (optUpdate == 1)
            {
                update();
            }
            else if (optUpdate == 2)
            {
                updateCursor();
            }
            else 
            {
                cout << "INVALID INPUT\n";
            }
        }
        else if (opt == 6)
        {
            search();
        }
        else if (opt == 7)
        {
            shift();
        }

        else
        {
            cout << "\t\t\tINVALID INPUT\n";
        }
        
        cout << "\t 1: Insert an ID. \n";
        cout << "\t 2: Move the cursor. \n";
        cout << "\t 3: Delete. \n";
        cout << "\t 4: Print. \n";
        cout << "\t 5: Update an ID. \n";
        cout << "\t 6: Search an ID. \n";
        cout << "\t 7: Shift an ID with the cursor. \n";
        cout << "\t 8: Exit. \n";
        cin >> opt;
    }
    
    return 0;
}