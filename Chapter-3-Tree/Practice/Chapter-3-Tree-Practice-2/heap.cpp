#include "header.h"

max_heap* init()
{
    max_heap* heap = new max_heap;
    heap->last_index = 0;
    return heap;
}

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void insert(max_heap* heap, int data)
{
    // 将新数据插在最后，依次与其父节点比较，大于则交换

    heap->data[heap->last_index + 1] = data;
    heap->last_index++;
    int data_index = heap->last_index;

    while (heap->data[data_index / 2] < data && data_index / 2 > 0)
    {
        swap(heap->data[data_index / 2], heap->data[data_index]);
        data_index /= 2;
    }
}

void delete_max(max_heap* heap)
{
    // 将根节点与最后一个数据交换，新根节点依次与孩子节点比较，小于则交换

    swap(heap->data[1], heap->data[heap->last_index]);
    heap->last_index--;
    int data_index = 1;

    while (data_index * 2 <= heap->last_index)
    {
        if (heap->data[data_index] > heap->data[data_index * 2] &&
            heap->data[data_index] > heap->data[data_index * 2 + 1])
        {
            break;
        }

        if (heap->data[data_index * 2] > heap->data[data_index * 2 + 1])
        {
            swap(heap->data[data_index * 2], heap->data[data_index]);
            data_index = data_index * 2;
        }
        else if (heap->data[data_index * 2] < heap->data[data_index * 2 + 1])
        {
            swap(heap->data[data_index * 2 + 1], heap->data[data_index]);
            data_index = data_index * 2 + 1;
        }
    }
}
