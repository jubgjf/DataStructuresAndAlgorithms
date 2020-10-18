#include "header.h"

int main()
{
    max_heap* heap = init();
    insert(heap, 1);
    insert(heap, 3);
    insert(heap, 23);
    insert(heap, 4);
    insert(heap, 77);
    insert(heap, 23);
    insert(heap, 12);
    insert(heap, 3);
    insert(heap, 43);
    insert(heap, 45);
    insert(heap, 67);
    insert(heap, 78);

    delete_max(heap);
}
