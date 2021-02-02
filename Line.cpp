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

void push(Line& line, int value)
{
    Node* pushNode = new Node { nullptr, value };
    if (line.endNode != nullptr)
    {
        line.endNode->nextNode = pushNode;
        line.endNode = pushNode;
    }
    else if (line.begNode == nullptr)
    {
        line.begNode = pushNode;
        line.endNode = pushNode;
    }
    ++line.sizeLine;
}

int pop(Line& line)
{
    if (line.sizeLine == 0)
    {
        return 0;
    }
    else
    {
        int value = line.begNode->value;
        Node* popNode = line.begNode;
        line.begNode = popNode->nextNode;
        delete popNode;
        --line.sizeLine;
        return value;
    }
}

int size(Line& line)
{
    return line.sizeLine;
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
    Line Joja;
    constructor(Joja);
    for (int i = 1; i < 11; i++)
    {
        push(Joja, i);
    }
    for (int i = 0; i < 3; i++)
    {
        pop(Joja);
    }
    destructor(Joja);
}
