#include "header.h"

int main()
{
    Queue* queue = Init();

    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);

    Dequeue(queue);
    Dequeue(queue);
}
