#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
    TreeNode() {
        delete left;
        delete right;
    }
};

struct Stack {
    TreeNode* Node;
    Stack* next;
};Stack *top = NULL;

struct infixStack {
    char ID;
    infixStack* infixNext;
};

infixStack* infixTop = nullptr;

void infixPush(char ID) {
    infixStack* temp = new infixStack;
    temp->ID = ID;
    temp->infixNext = infixTop;
    infixTop = temp;
}

void infixPop() {
    infixStack* temp;
    if (infixTop == nullptr) {
        cout << "Stack underflow.";
    } else {
        cout << infixTop->ID;
        temp = infixTop;
        infixTop = infixTop->infixNext;
        delete temp;
    }
}

void push(TreeNode *Node) {
    Stack* temp = new Stack;
    temp->Node = Node;
    temp->next = top;
    top = temp;
}

void pop() {
    Stack* temp;
    temp = top;
    top = top->next;
    delete temp;
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

string infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        //if (infix[i] == ' ') {
            //continue;}
        if (isalnum(infix[i])) {
            postfix += infix[i];
        } else if (isOperator(infix[i])) {
            while (!stackempty() && precedence(infixTop->ID) >= precedence(infix[i])) {
                postfix += infixTop->ID;
                pop();
            }
            infixPush(infix[i]);
        } else if (infix[i] == '(') {
            infixPush(infix[i]);
        } else if (infix[i] == ')') {
            while (!stackempty() && infixTop->ID != '(') {
                postfix += infixTop->ID;
                infixPop();
            }
            infixPop(); // Remove the '('
        }
    }

    while (!stackempty()) {
        postfix += infixTop->ID;
        pop();
    }

    return postfix;
}

TreeNode* treeTop = NULL;

TreeNode* buildExpressionTree(string& postfix) {
    for (char c : postfix) {
        if (isalnum(c)) {
            TreeNode* operandNode = new TreeNode(c);
            push(operandNode);
        } else if (isOperator(c)) {
            TreeNode* rightOperand = top->Node;
            pop(); 
            TreeNode* leftOperand = top->Node;
            pop();
            TreeNode* operatorNode = new TreeNode(c);
            operatorNode->right = rightOperand;
            operatorNode->left = leftOperand;
            push(operatorNode);
        }
    }
    return top->Node;
}


void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << "";
        inorder(root->right);
    }
}

int main()
{
    int option;
    cout << "1: Enter Infix expression: " << endl;
    cout << "2: Enter Postfix expression: " << endl;
    cout << "3: Exit" << endl;
    while (true) 
    {
        cin >> option;
        switch (option) 
        {
            case 1:
            {
            string infixExp;
            cout << "Enter the infix expression: ";
            getline(cin, infixExp);
            string postfix = infixToPostfix(infixExp);
            TreeNode* root = buildExpressionTree(postfix);
            cout << "INORDER TREE: " << endl;
            inorder(root);
            delete root;
            return 0;
            }
        
            case 2:
            {
            string postfix;
            cout << "Enter the postfix expression: ";
            getline(cin, postfix);
            TreeNode* root = buildExpressionTree(postfix);
            cout << "INORDER TREE: " << endl;
            inorder(root);
            delete root; // Deallocate memory
            return 0;
            }
        }   
    }
}