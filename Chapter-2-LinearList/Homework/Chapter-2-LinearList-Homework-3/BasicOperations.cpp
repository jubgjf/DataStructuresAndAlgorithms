#include <cstdlib>
#include <iostream>
#include "header.h"

node* InitStack()
{
    node* top = (node*)malloc(sizeof(node));
    top->next = nullptr;

    return top;
}

void Push(node* stack, Position position)
{
    node* pushNode = (node*)malloc(sizeof(node));
    pushNode->position = position;
    pushNode->next = stack->next;
    stack->next = pushNode;
}

Position Pop(node* stack)
{
    node* popNode = stack->next;

    if (popNode == nullptr)
    {
        return Position{-1, -1};
    }

    stack->next = popNode->next;
    Position popData = popNode->position;
    free(popNode);

    return popData;
}

Position Top(node* stack)
{
    if (stack->next == nullptr)
    {
        return Position{-1, -1};
    }
    return stack->next->position;
}

void Clear(node* stack)
{
    // TODO 节点未释放空间

    stack->next = nullptr;
}

void Travel(node* stack)
{
    node* pointer = stack->next;
    while (pointer != nullptr)
    {
        std::cout << pointer->position.x << " " << pointer->position.y << std::endl;
        pointer = pointer->next;
    }
}
