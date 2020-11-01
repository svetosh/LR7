#include <iostream>

struct Node
{
    Node* nextNode;
    int value;
};

struct Line
{
    Node* endNode;
    Node* begNode;
    int sizeLine;
};

void constructor(Line& line)
{
    line.endNode = nullptr;
    line.begNode = nullptr;
    line.sizeLine = 0;
}

int pop(Line& line)
{
    int value = line.begNode->value;
    Node* popNode = line.begNode;
    line.begNode = popNode->nextNode;
    delete popNode;
    --line.sizeLine;
    return value;
}

void push(Line& line, int value)
{
    Node* pushNode;
    
    pushNode = new Node{ nullptr, value };
    if (line.endNode != nullptr)
    {
        line.endNode->nextNode = pushNode;
    }
    line.endNode = pushNode;
    if (line.begNode == nullptr)
    {
        line.begNode = line.endNode;
    }
    ++line.sizeLine;
}

void destructor(Line& line)
{
    while (line.begNode != nullptr)
    {
        std::cout << pop(line) << " ";
    }
}

int main()
{
    Line Jopa;
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