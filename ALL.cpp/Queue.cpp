#include <iostream>
#include <cstdlib>
         
using namespace std;
struct queue
{
    int ID;
    queue *next;
};struct queue *front = NULL;
struct queue *rear = NULL;

void Enqueue()
{
    int ID;
    queue *curr = front;
    queue *ref = rear;
    struct queue *temp = (struct queue*)malloc(sizeof(struct queue));
    cout << "Enter data: ";
    cin >> ID;
    temp->ID = ID;
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
        rear = front;
        return;
    }
    else
    {
        rear->next = temp;
        rear = rear->next;   
        return;
    }
}

void Dequeue()
{
    queue *temp;
    if (front == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }
    else 
    {
        cout << "Value at the front of the queue: " << front->ID << "\n";
        temp = front;
        front = front->next;
        free(temp);
    }
}

int main()
{
    int optdequeue = 0;
    int opt = 1;

    while (opt != 0)
    {
        if (opt == 1)
        {
            int optInsert = 1;
            while (optInsert == 1)
            {
                Enqueue();
                cout << "\t If you want to add another ID enter 1, if you want to exit enter 0: ";
                cin >> optInsert;
                if (optInsert != 1)
                    opt = 0;  
            }
        }
    }
    cout << "Do you want to dequeue the data at the front: ";
    cin >> optdequeue;
    while (optdequeue == 1)
    {
    if (optdequeue == 1)
    {
        Dequeue();
        cout << "Do you want to dequeue the data at the front: ";
        cin >> optdequeue;
    }
    }
}