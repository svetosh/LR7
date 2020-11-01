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
    int value = stack.endNode->value;
    Node* popNode = stack.endNode;
    stack.endNode = popNode->nextNode;
    delete popNode;
    --stack.sizeStack;
    return value;
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
    Stack Jopa;
    constructor(Jopa);
    for (int i = 0; i < 10; i++)
    {
        push(Jopa, i);
    }
    for (int i = 0; i < 3; i++)
    {
        pop(Jopa);
    }
    destructor(Jopa);
}
