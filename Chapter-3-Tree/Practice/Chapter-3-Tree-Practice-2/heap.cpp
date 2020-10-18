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
    // �������ݲ�������������丸�ڵ�Ƚϣ������򽻻�

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
    // �����ڵ������һ�����ݽ������¸��ڵ������뺢�ӽڵ�Ƚϣ�С���򽻻�

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
