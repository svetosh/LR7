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

void push(Stack& stack, int value)
{
    Node* pushNode = new Node{ stack.endNode, value };
    stack.endNode = pushNode;
    stack.sizeStack++;
}

int pop(Stack& stack)
{
    if (stack.sizeStack == 0)
    {
        return 0;
    }
    else
    {
        int value = stack.endNode->value;
        Node* popNode = stack.endNode;
        stack.endNode = popNode->nextNode;
        delete popNode;
        stack.sizeStack--;
        return value;
    }
}

int size(Stack& stack)
{
    return stack.sizeStack;
}

void print(const Stack& stack)
{
    Node* node = stack.endNode;
    if (node != nullptr)
    {
        while (node != nullptr)
        {
            std::cout << node->value << " ";
            node = node->nextNode;
        }
    }
    std::cout << std::endl;
}

void destructor(Stack& stack)
{
    Node* node = stack.endNode;
    if (node != nullptr) 
    {
        while (stack.endNode != nullptr) 
        {
            stack.endNode = stack.endNode->nextNode;
            delete node;
            node = stack.endNode;
        }
        delete node;
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
    print(Joja);
    for (int i = 0; i < 3; i++)
    {
        pop(Joja);
    }
    print(Joja);
    destructor(Joja);
}
