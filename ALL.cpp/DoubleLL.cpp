#include <iostream>
#include <cstdlib>
         
using namespace std;
struct Node
{
    Node *prev;
    int ID;
    int marks;
    Node *next;
}; struct Node *start = NULL;

void insertion()
{
    int newID;
    cout << "Enter ID of the student: ";
    cin >> newID;
    
    Node *curr = start;
    while (curr != NULL)
    {
        if (curr->ID == 0)
        {
            cout << "It is an invalid ID.\n";
            return;
        }
        if (curr->ID == newID)
        {
            cout << "Following ID already exists in the list.\n";
            return;
        }
        curr = curr->next;
    }

    Node *temp = new Node; 
    temp->ID = newID;
    cout << "Enter marks of the student: ";
    cin >> temp->marks;
    temp->next = NULL;
    
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
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



void toPrint()
{
    cout << "\t\t The list of students is: \n";
    Node * curr = start;
    if (curr == NULL)
    {
        cout << "List is empty.\n";

    }
    while (curr != NULL)
    {
        cout << "ID: " << curr ->ID << endl;
        cout << "Marks: " << curr ->marks << endl;
       // cout << "Previous: " << curr ->prev << endl;
       // cout << "Next: " << curr ->next << endl;
        curr = curr -> next;
    }
}

void deleteAtEnd() {
    int toDelete;
    cout << "Enter ID of the student to delete: ";
    cin >> toDelete;
    struct Node *curr = start;
    struct Node *temp = NULL;

    while (curr != NULL) {
        if (curr->ID == toDelete) {
            if (temp == NULL) {
                start = curr->next;
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
        cout << "Enter ID of the student to search: ";
        cin >> toSearch;
        struct Node *curr = start;

        while (curr != NULL)
            {
            if (curr->ID == toSearch)
            {
                cout << "Marks of the following ID are: " << curr->marks << "\n";
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
int updMarks;
int updID;
if (start == NULL)
    {
        cout << "The list is empty. \n";
        return;
    }
    else
    {
        cout << "\tEnter ID of the student to update: " << "\n";
        cin >> toUpdate;
        cout << "\tEnter new marks: ";
        cin >> updMarks;
        cout << "\tEnter new ID: ";
        cin >> updID;
        struct Node *curr = start;

        while (curr != NULL)
            {
            if (curr->ID == toUpdate)
            {
                curr->ID = updID;
                curr->marks = updMarks;
                return;
            }
        curr = curr->next;
            }
    }
    
    cout << "Following ID does not exist.\n";
}

 
int main()
{
    int opt;
    cout << "\t 1: Insert an ID. \n";
    // cout << "\t 2: Search an ID. \n";
    // cout << "\t 3: Delete an ID. \n";
    // cout << "\t 4: Print the whole list. \n";
    // cout << "\t 5: Update an ID. \n"
    // cout << "\t 6: Sort the list using Counting Sort. \n";
    cout << "\t 6: Exit. \n";
    cin >> opt;
    
    while (opt != 6)
    {
        if (opt == 1)
        {
            int optInsert = 1;
            while (optInsert == 1)
            {
                insertion();
                cout << "\t If you want to add another ID enter 1, if you want to exit enter 0: ";
                cin >> optInsert;
                if (optInsert != 1)
                    opt = 0;  
            }
        }
        else if (opt == 2)
        {
            search();
        }
        else if (opt == 3)
        {
            int optdel;
            cout << "\t\t Enter 1 if you want to delete one element: \n";
            cout << "\t\t Enter 0 if you want to delete the whole list: ";
            cin >> optdel;
            if (optdel == 1)
            {
                deleteAtEnd();
            }
            else 
            {
                deleteAll();
            }
        }
        else if (opt == 4)
        {
            toPrint();
        }
        else if(opt == 5)
        {
            update();
        }
        // else if (opt == 6) 
        // {
        //     countingSortLinkedList();
        //     cout << "List sorted using Counting Sort.\n";
        // }
        else
        {
            cout << "\t\t\tINVALID INPUT\n";
        }
        
        cout << "\t 1: Insert an ID. \n";
        cout << "\t 2: Search an ID. \n";
        cout << "\t 3: Delete an ID. \n";
        cout << "\t 4: Print the whole list. \n";
        cout << "\t 5: Update an ID. \n";
      //  cout << "\t 6: Sort the list using Counting Sort. \n";
        cout << "\t 6: Exit. \n";
        cin >> opt;
    }
    
    return 0;
}