#include <iostream>

struct Node
{
    Node* nextNode;
    int value;
};

struct Stack
{
    Node* endNode;
    int sizeStack;
};

void constructor(Stack& stack)
{
    stack.endNode = nullptr;
    stack.sizeStack = 0;
}

int pop(Stack& stack)
{
    if (stk.stack_size == 0)
    {
        return 0;
    }
    else
    {
    int value = stack.endNode->value;
    Node* popNode = stack.endNode;
    stack.endNode = popNode->nextNode;
    delete popNode;
    --stack.sizeStack;
    return value;
    }
}

int size(Stack& stack)
{
    return stack.stacksize;
}

void push(Stack& stack, int value)
{
    Node* pushNode;
    Node* endAdd = stack.endNode;
    pushNode = new Node{ endAdd, value };
    stack.endNode = pushNode;
    ++stack.sizeStack;
}

void destructor(Stack& stack)
{
    while (stack.endNode != nullptr)
    {
        std::cout << pop(stack) << " ";
    } 
}

int main()
{
    Stack Joja;
    constructor(Joja);
    for (int i = 0; i < 10; i++)
    {
        push(Joja, i);
    }
    for (int i = 0; i < 3; i++)
    {
        pop(Joja);
    }
    destructor(Joja);
}
