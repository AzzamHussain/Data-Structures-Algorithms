#include <iostream>
#include <cstdlib>
         
using namespace std;
struct stack
{
    int ID;
    stack *next;
}; struct stack *top = NULL;

void push()
{
    int ID;
    stack *curr = top;
    struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
    cout << "Enter data: ";
    cin >> ID;
    temp->ID = ID;
    temp->next = top;
    top = temp;
}

void pop()
{
    stack *temp;
    if (top == NULL)
    {
        cout << "Stack underflow.";
    }
    else 
    {
        cout << "Value at top of stack: " << top->ID << endl;
        temp = top;
        top = top->next;
        free(temp);
    }

}
bool stackempty()
{
    if (top == NULL)
    {
        cout << "Stack is empty!!" << endl;
        return true;
    }
    else{
        return false;
    }
} 

int main()
{
    //int optpop = 0;
    //push();
    int opt = 1;
    cout << "\t\tEnter 1 to push data: " << endl;
    cout << "\t\tEnter 2 to pop data:  " << endl;
    cout << "\t\tEnter 3 to check whether the stack is empty: " << endl;
    cout << "\t\tEnter 0 to exit: " << endl; 
    cin >> opt;
    while (opt != 0)
    {
        if (opt == 1)
        {
            int optPush = 1;
            while (optPush == 1)
            {
                push();
                cout << "\t If you want to push data enter 1, if you want to exit enter 0: ";
                cin >> optPush;
                if (optPush != 1)
                    opt = 0;  
            }
        }
       else  if (opt == 2)
        {
            int optPop = 1;
            while (optPop == 1)
            {
                pop();
                cout << "\t If you want to pop data enter 1, if you want to exit enter 0: ";
                cin >> optPop;
                if (optPop != 1)
                    opt = 0;  
            }
        }
        else if (opt == 3)
        {
            stackempty();
        }
        else{
            cout << "INVALID INPUT!!!";
        }
        cout << "Enter 1 to push data: " << endl;
        cout << "Enter 2 to pop data:  " << endl;
        cout << "Enter 3 to check whether the stack is empty: " << endl;
        cout << "Enter 0 to exit: " << endl;
        cin >> opt;
    }
}