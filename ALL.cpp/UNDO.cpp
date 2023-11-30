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
struct Node *cursor = NULL;
struct stack_value *top_value = NULL;
struct stack_command *top_command = NULL;

struct stack_command
{
    string command;
    stack_command *next;
}; 

struct stack_value
{
    int data;
    stack_value *next;
}; 



Node* createNode(int newData) {
    Node *temp = new Node;
    temp->data = newData;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* insertNode(Node *start, int num) {
    Node *temp = createNode(num);
    if (start == NULL) 
    {
        start = temp;
        cursor = start;
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

void push_command(string command)
{
    // stack_command *curr = top_command;
    struct stack_command *temp = new stack_command;
    temp->command = command;
    temp->next = NULL;
    if (top_command == NULL)
    {
        top_command = temp;
    }
    else
    {
        temp->next = top_command;
        top_command = temp;   
    }
}

string pop_command()
{
    stack_command *temp = top_command;
    if (top_command == NULL)
    {
        cout << "Stack underflow.";
    }
    else
    {
        stack_command *temp = top_command;
        string poppedCommand = temp->command;
        top_command = top_command->next; // Update top_value before deleting the node.
        delete temp;
        return poppedCommand;
    }
}

void printStack_Command() {
    stack_command* current = top_command;

    if (current == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack contents:" << endl;
    while (current != NULL) {
        cout << current->command << endl;
        current = current->next;
    }
}

void printStack_Value() {
    stack_value* current = top_value;

    if (current == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack contents:" << endl;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}

void push_value(int data)
{
    stack_value *curr = top_value;
    stack_value *temp = new stack_value;
    temp->data = data;
    temp->next = NULL;
    if (top_value == NULL)
    {
        top_value = temp;
    }
    else
    {
        temp->next = top_value;
        top_value = temp;   
    }
}

int pop_value()
{
    stack_value *temp = top_value;
    if (top_value == NULL)
    {
        cout << "Stack underflow.";
    }
    else
    {
        stack_value *temp = top_value;
        int poppedData = temp->data;
        top_value = top_value->next; // Update top_value before deleting the node.
        delete temp;
        return poppedData;
    }
}

void cursorRight(int toMove)
{
    if (cursor->next != NULL)
    {
        while (toMove != 0)
        {
            cursor = cursor->next;
            toMove--;
        }
    }
}

void cursorLeft(int toMove)
{
    if (cursor->prev != NULL)
    {
        while (toMove != 0)
        {
            cursor = cursor->prev;
            toMove--;
        }
    }
}

void insertionAtCursor(int newData) {
    Node* temp = createNode(newData);
    
    // Check if cursor is NULL
    if (cursor == NULL) {
        // Handle this case (e.g., return an error or do nothing)
        return;
    }
    
    // Initialize start if it's not already done
    if (start == NULL) {
        start = temp;
        return;
    }

    temp->next = cursor->next;
    temp->prev = cursor;
    cursor->next = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = temp;
    }
}



void toPrint()
{
    cout << cursor->data << "\n";
    return;
}

void print() {
    Node* curr = start;
    if (curr == NULL) {
        cout << "List is empty.\n";
    }
    cout << "\t\t The list is: \n";
    while (curr != NULL) {
        cout << "Data: " << curr->data << endl;
        curr = curr->next;
    }
    return;
}

void deletion(int toDelete) {
    struct Node *curr = start;
    struct Node *temp = NULL;

    while (toDelete != 0 && curr != NULL) {
        temp = curr;
        curr = curr->next;
        toDelete--;
    }

    if (curr == cursor) {
        if (cursor->next != NULL)
        {
            cursor = cursor->next;
        }
        else 
        {
            cursor = cursor->prev;
        }
    }

    if (temp == NULL) {
        start = curr->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        push_value(curr->data);
        free(curr); // Deallocate memory
    } else if (curr != NULL) {
        temp->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = temp;
        }
        push_value(curr->data);
        free(curr); // Deallocate memory
    }
}


void deleteAtEnd() {
    struct Node *curr = start;
    struct Node *temp = NULL;

    while (curr->next != NULL) {
        temp = curr;
        curr = curr->next;
    }
    if (temp == NULL)
    {
        push_value(curr->data);
        delete curr;
    }
    else
    {
        temp->next = NULL;
        push_value(curr->data);
        delete curr;
    } 
}
void update(int toUpdate, int upddata)
{
    
    struct Node *curr = start;

    while (toUpdate != 0) 
    {
        curr = curr->next;
        toUpdate--;
    }
    push_value(curr->data);
    curr->data = upddata;
    return;
}

void updateCursor(int upddata)
{
    Node *curr = cursor;
    push_value(curr->data);
    curr->data = upddata;
}

void insertAtNum(int newIndex, int newData)
{
    Node *temp = createNode(newData);
    Node *curr = start;
    while (curr != NULL && newIndex != 0) {
        curr = curr->next;
        newIndex--;
    }
    
    
    temp->prev = curr->prev;  
    temp->next = curr;
    if (curr->prev != NULL)
        curr->prev->next = temp;
    curr->prev = temp;   
}

void shift(int toShift)
{

    struct Node *curr = start;
    int temp;
    while (curr != NULL && toShift != 0) {
        curr = curr->next;
        toShift--;
    }
    push_value(curr->data);
    push_value(cursor->data);
    if (curr != NULL)
    {
        temp = cursor->data;
        cursor->data = curr->data;
        curr->data = temp;     
    }
}

void reShift(int toShift, int cursor_Data, int current_Data)
{

    struct Node *curr = start;
    int temp;
    while (curr != NULL && toShift != 0) {
        curr = curr->next;
        toShift--;
    }
    if (curr != NULL)
    {
        cursor->data = cursor_Data;
        curr->data = current_Data;     
    }
}

void deleteCursor() {
    if (cursor == NULL) {
        // Check if cursor is NULL before attempting to delete.
        return;
    }

    struct Node *curr = cursor;

    if (curr == start) {
        // If cursor is at the beginning of the list.
        start = start->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        cursor = start;
    } else {
        struct Node *prevNode = curr->prev;
        prevNode->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = prevNode;
        }
        cursor = prevNode;
    }

    // Free the memory associated with the deleted node.
    push_value(curr->data);
    free(curr);
}

void undo()
{
    string command;
    command = pop_command();
    if (command == "Add") {
        deleteAtEnd();
    } else if (command == "AddImmediate"){
        deleteCursor();
    }
    else if (command == "Delete") {
        int value;
        value = pop_value();
        insertNode(start, value);
    }else if (command == "DeleteImmediate"){
        int value;
        value = pop_value();
        insertionAtCursor(value);
    }else if (command == "Shift"){
        int cursor_Data = pop_value();
        int current = pop_value();
        int toShift = pop_value();
        reShift(cursor_Data, current, toShift);
    } else if (command == "MoveForward"){
        int value;
        value = pop_value();
        cursorLeft(value);
    } else if (command == "MoveBackward"){
        int value;
        value = pop_value();
        cursorRight(value);    
    } else if (command == "Update"){
        int data;
        int index;
        data = pop_value();
        index = pop_value();
        update(index, data);
    } else if (command == "UpdateImmediate"){
        int value = pop_value();
        updateCursor(value);
     }else if (command == "addWithIndex"){
        int index = pop_value();
        deletion(index);
    } else if (command == "deleteWithIndex") {
        //printStack_Value();
        int data = pop_value();
        cout << "POP: " << data << endl;
        int index = pop_value();
        cout << "POP2: " << index << endl;
        insertAtNum(index, data);
    }
}

int main() 
{
    ifstream inputFile("editor.txt");
    
    string command;
    while (inputFile >> command) 
    {
        if (command == "Add") {
            int num1;
            inputFile.get();
            inputFile >> num1;
            int check = inputFile.get();
            if (check == 10 || check == -1)
            {
                push_command(command);
                start = insertNode(start, num1);
            }
            else 
            {   
                int num2;
                inputFile >> num2;
                push_command("addWithIndex");
                push_value(num1);
                insertAtNum(num1, num2);
            }
            
        } else if (command == "AddImmediate"){
            push_command(command);
            int num;
            inputFile >> num;
            insertionAtCursor(num);
        }
        else if (command == "Delete") {
            int check;
			check = inputFile.get();
			if (check == 10 || check== -1) {
                push_command(command);
			    deleteAtEnd();
			    continue;
			}
			else {
                push_command("deleteWithIndex");
                int index;
				inputFile >> index;
                push_value(index);
				deletion(index);
                cout << "LOL" << endl;
			}
		
        }else if (command == "DeleteImmediate"){
            push_command(command);
            deleteCursor();
        }else if (command == "Shift"){
            push_command(command);
            int toShift;
            inputFile >> toShift;
            push_value(toShift);
            shift(toShift);
        } else if (command == "Print") {
            toPrint(); 
            print();
        } else if (command == "MoveForward"){
            push_command(command);
            int cursor_value;
            inputFile >> cursor_value;
            push_value(cursor_value);
            cursorRight(cursor_value);
        } else if (command == "MoveBackward"){
            push_command(command);
            int cursor_value;
            inputFile >> cursor_value;
            push_value(cursor_value);
            cursorLeft(cursor_value);    
        } else if (command == "Update"){
            push_command(command);
            int toUpdate;
            int upddata;
            inputFile >> toUpdate;
            push_value(toUpdate);
            inputFile >> upddata;
            update(toUpdate, upddata);
        } else if (command == "UpdateImmediate"){
            push_command(command);
            int upddata;
            inputFile >> upddata;
            updateCursor(upddata);
        
        } else if (command == "Undo"){
            undo();
        }            
    }

    Node* curr = start;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    return 0;
}