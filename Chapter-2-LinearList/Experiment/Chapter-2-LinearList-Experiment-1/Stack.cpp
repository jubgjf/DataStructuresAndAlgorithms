#include "headers.h"

node* InitStack()
{
    node* stack = new node;
    stack->next = nullptr;

    return stack;
}

void Push(node* stack, char c)
{
    node* newNode = new node;
    newNode->data.op = c;
    newNode->next = stack->next;

    stack->next = newNode;
}

void Push(node* stack, double num)
{
    node* newNode = new node;
    newNode->data.num = num;
    newNode->next = stack->next;

    stack->next = newNode;
}

node* Pop(node* stack)
{
    node* popNode = stack->next;
    if (popNode == nullptr) { return nullptr; }

    stack->next = popNode->next;

    return popNode;
}

node* Top(node* stack)
{
    return stack->next;
}

bool IsEmpty(node* stack)
{
    return stack->next == nullptr;
}

void Travel(node* stack, TravelType travelType)
{
    node* pointer = stack->next;
    while (pointer != nullptr)
    {
        switch (travelType)
        {
        case TravelNumber:
            cout << pointer->data.num;
            break;
        case TravelOperator:
            cout << pointer->data.op;
            break;
        }

        pointer = pointer->next;
    }
}

string Travel(node* stack)
{
    node* pointer = stack->next;
    string str;

    while (pointer != nullptr)
    {
        str += pointer->data.op;
        pointer = pointer->next;
    }

    return str;
}
