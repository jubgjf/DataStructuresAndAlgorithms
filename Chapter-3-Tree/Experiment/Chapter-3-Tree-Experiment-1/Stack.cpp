#include "header.h"

Stack* InitStack()
{
    Stack* stack = new Stack;
    stack->topIndex = -1;

    return stack;
}

bool IsEmpty(Stack* stack)
{
    return stack->topIndex < 0;
}

void Push(Stack* stack, Node* data)
{
    if (stack->topIndex >= MAX_STACK_SIZE - 1) { return; }

    stack->storePool[stack->topIndex + 1] = data;
    stack->topIndex++;
}

Node* Pop(Stack* stack)
{
    if (IsEmpty(stack)) { return nullptr; }

    Node* popData = Top(stack);
    stack->topIndex--;

    return popData;
}

Node* Top(Stack* stack)
{
    if (IsEmpty(stack)) { return nullptr; }

    return stack->storePool[stack->topIndex];
}

Stack* Reverse(Stack* stack)
{
    Stack* reverseStack = InitStack();

    while (!IsEmpty(stack))
    {
        Push(reverseStack, Pop(stack));
    }
    delete stack;

    return reverseStack;
}
