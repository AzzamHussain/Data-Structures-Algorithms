#include <iostream>
#include <cstdlib>
#include <fstream>
         
using namespace std;
struct stack
{
    int ID;
    stack *next;
}; struct stack *top = NULL;

void push(int num)
{
    stack *curr = top;
    struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
    temp->ID = num;
    temp->next = NULL;
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;   
    }
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
        cout << "Value at top of stack: " << top->ID << "\n";
        temp = top;
        top = top->next;
        free(temp);
    }

}

int main()
{
    ifstream my_File("stack.txt");
    int num;
    while (my_File >> num)
    {
        push(num);
    }
    while (top)
    {
        pop();
    }  
}