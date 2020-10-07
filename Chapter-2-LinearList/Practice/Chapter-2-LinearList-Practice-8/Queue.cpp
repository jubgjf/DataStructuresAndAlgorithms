#include "header.h"

Queue* Init()
{
    Node* node = new Node;
    node->next = nullptr;

    Queue* queue = new Queue;
    queue->head = node;
    queue->rear = node;

    return queue;
}

void Enqueue(Queue* queue, elementType data)
{
    Node* node = new Node;
    node->data = data;

    queue->rear->next = node;
    queue->rear = node;
}

Node* Dequeue(Queue* queue)
{
    Node* dequeueNode = queue->head->next;
    queue->head->next = dequeueNode->next;

    return dequeueNode;
}
