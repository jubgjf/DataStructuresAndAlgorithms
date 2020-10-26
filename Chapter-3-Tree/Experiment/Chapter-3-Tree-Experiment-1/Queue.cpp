#include "header.h"

Queue* InitQueue()
{
    Queue* queue = new Queue;
    queue->enqueueStack = InitStack();
    queue->dequeueStack = InitStack();

    return queue;
}

bool IsEmpty(Queue* queue)
{
    return IsEmpty(queue->enqueueStack) && IsEmpty(queue->dequeueStack);
}

void Enqueue(Queue* queue, Node* data)
{
    Push(queue->enqueueStack, data);
}

struct Node* Dequeue(Queue* queue)
{
    if (IsEmpty(queue)) { return nullptr; }

    if (!IsEmpty(queue->dequeueStack)) { return Pop(queue->dequeueStack); }

    while (!IsEmpty(queue->enqueueStack))
    {
        Push(queue->dequeueStack, Pop(queue->enqueueStack));
    }
    return Pop(queue->dequeueStack);
}
