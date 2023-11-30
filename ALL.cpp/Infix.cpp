#include <iostream>
#include <string>
using namespace std;

struct Stack {
    char ID;
    Stack* next;
};

Stack* top = nullptr;

void push(char ID) {
    Stack* temp = new Stack;
    temp->ID = ID;
    temp->next = top;
    top = temp;
}


void pop() {
    Stack* temp;
    if (top == nullptr) {
        cout << "Stack underflow.";
    } else {
        cout << top->ID;
        temp = top;
        top = top->next;
        delete temp;
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '&':
        case '|':
            return 4;
        case '<':
        case '>':
        case '=':
        case '!':
            return 5;
    }
    return 0;
}

bool stackempty() {
    return top == NULL;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
        c == '&' || c == '|' || c == '<' || c == '>' || c == '=' || c == '!')
        return true;
    return false;
}

string infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        //if (infix[i] == ' ') {
            //continue;}
        if (isalnum(infix[i])) {
            postfix += infix[i];
        } else if (isOperator(infix[i])) {
            while (!stackempty() && precedence(top->ID) >= precedence(infix[i])) {
                postfix += top->ID;
                pop();
            }
            push(infix[i]);
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!stackempty() && top->ID != '(') {
                postfix += top->ID;
                pop();
            }
            pop(); // Remove the '('
        }
    }

    while (!stackempty()) {
        postfix += top->ID;
        pop();
    }

    return postfix;
}


int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "POSTFIX EXPRESSION IS: " << postfix << endl;
    return 0;
}