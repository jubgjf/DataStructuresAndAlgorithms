#include <iostream>
#include "header.h"

void PrintArray(int array[], int startIndex, int endIndex)
{
    for (int i = startIndex; i < endIndex; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int array[], int startIndex, int endIndex)
{
    for (int i = startIndex; i < endIndex + 1; ++i)
    {
        bool exchanged = false;

        for (int j = endIndex; j > i; --j)
        {
            if (array[j - 1] > array[j])
            {
                Swap(array[j - 1], array[j]);
                exchanged = true;
            }
        }

        if (!exchanged) { break; }
    }
}

void QuickSort(int array[], int startIndex, int endIndex)
{
    if (startIndex > endIndex) { return; }

    int pivot = array[startIndex];
    int i = startIndex, j = endIndex;

    while (i != j)
    {
        while (array[j] >= pivot && j > i) { --j; }
        while (array[i] <= pivot && i < j) { ++i; }

        if (i < j) { Swap(array[i], array[j]); }
    }

    array[startIndex] = array[i];
    array[i] = pivot;

    QuickSort(array, i + 1, endIndex);
    QuickSort(array, startIndex, i - 1);
}

void SelectSort(int array[], int startIndex, int endIndex)
{
    for (int i = startIndex; i < endIndex; ++i)
    {
        int minIndex = i;

        for (int j = i; j < endIndex + 1; ++j)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        Swap(array[i], array[minIndex]);
    }
}

void HeapInsert(int heap[], int& lastIndex, int insertData)
{
    heap[lastIndex + 1] = insertData;
    lastIndex++;
    int currentIndex = lastIndex;

    while (heap[currentIndex] < heap[currentIndex / 2] && currentIndex != 1)
    {
        Swap(heap[currentIndex], heap[currentIndex / 2]);
        currentIndex /= 2;
    }
}

int LeftChildIndex(int index, int lastIndex)
{
    return index * 2 > lastIndex ? -1 : index * 2;
}

int RightChildIndex(int index, int lastIndex)
{
    return index * 2 + 1 > lastIndex ? -1 : index * 2 + 1;
}

int HeapPop(int heap[], int& lastIndex)
{
    Swap(heap[1], heap[lastIndex]);
    lastIndex--;

    int currentIndex = 1;
    while (true)
    {
        if (LeftChildIndex(currentIndex, lastIndex) == -1) // 没有左孩子
        {
            break;
        }
        else if (RightChildIndex(currentIndex, lastIndex) == -1) // 有左孩子，没有右孩子
        {
            if (heap[currentIndex] > heap[LeftChildIndex(currentIndex, lastIndex)])
            {
                Swap(heap[currentIndex], heap[LeftChildIndex(currentIndex, lastIndex)]);
                currentIndex = currentIndex * 2;
            }
            else
            {
                break;
            }
        }
        else // 有左孩子、右孩子
        {
            if (heap[currentIndex] < heap[LeftChildIndex(currentIndex, lastIndex)] &&
                heap[currentIndex] < heap[RightChildIndex(currentIndex, lastIndex)])
            {
                break;
            }
            else if (heap[LeftChildIndex(currentIndex, lastIndex)] <
                heap[RightChildIndex(currentIndex, lastIndex)])
            {
                Swap(heap[currentIndex], heap[LeftChildIndex(currentIndex, lastIndex)]);
                currentIndex = currentIndex * 2;
            }
            else if (heap[LeftChildIndex(currentIndex, lastIndex)] >=
                heap[RightChildIndex(currentIndex, lastIndex)])
            {
                Swap(heap[currentIndex], heap[RightChildIndex(currentIndex, lastIndex)]);
                currentIndex = currentIndex * 2 + 1;
            }
        }
    }

    return heap[lastIndex + 1];
}

void HeapSort(int array[], int startIndex, int endIndex)
{
    // 构建小顶堆
    int heap[1000];
    int heapLastIndex = 0;
    for (int i = startIndex; i < endIndex; ++i)
    {
        HeapInsert(heap, heapLastIndex, array[i]);
    }

    for (int i = 0; heapLastIndex >= 1; ++i)
    {
        array[i] = HeapPop(heap, heapLastIndex);
    }
}

void InsertSort(int array[], int startIndex, int endIndex)
{
    for (int i = startIndex + 1; i < endIndex + 1; ++i)
    {
        for (int j = i; j - 1 >= 0 && array[j] < array[j - 1]; --j)
        {
            Swap(array[j], array[j - 1]);
        }
    }
}

void ShellSort(int array[], int startIndex, int endIndex)
{
    for (int gap = (endIndex + 1 - startIndex) / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < endIndex + 1; ++i)
        {
            for (int j = i; j - gap >= 0 && array[j] < array[j - gap]; j -= gap)
            {
                Swap(array[j], array[j - gap]);
            }
        }
    }
}
