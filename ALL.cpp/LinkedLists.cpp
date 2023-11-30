#include <iostream>
#include <cstdlib>
         
using namespace std;
struct Node
{
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
        if (curr->ID == newID)
        {
            cout << " Following ID already exists in the list.\n";
            return;
        }
        curr = curr->next;
    }

    struct Node * temp = (struct Node *) malloc (sizeof(struct Node));
    temp -> ID = newID;
    
    cout << "Enter marks of the student: ";
    cin >> temp -> marks;
    temp -> next = NULL;

    if (start == NULL)
    {
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
        curr = curr -> next;
    }
}

void deletion()
{
    int toDelete;
    cout << "Enter ID of the student to delete: ";
    cin >> toDelete;
    struct Node * curr = start;
    struct Node * prev = NULL;

    while (curr != NULL)
    {
        if (curr->ID == toDelete)
        {
            if (prev == NULL)
            {
                start = curr->next; 
            }
            else
            {
                prev->next = curr->next; 
            }
            free(curr); 
            cout << "ID " << toDelete << " is deleted.\n";
            return;
        }
        prev = curr;
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
        free(temp);
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

 
int main()
{
    int opt;
    cout << "\t 1: Insert an ID. \n";
    cout << "\t 2: Search an ID. \n";
    cout << "\t 3: Delete an ID. \n";
    cout << "\t 4: Print the whole list. \n";
    cout << "\t 5: Exit. \n";
    cin >> opt;
    
    while (opt != 5)
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
                deletion();
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
        
        cout << "\t 1: Insert an ID. \n";
        cout << "\t 2: Search an ID. \n";
        cout << "\t 3: Delete an ID. \n";
        cout << "\t 4: Print the whole list. \n";
        cout << "\t 5: Exit. \n";
        cin >> opt;
    }
    
    return 0;
}
