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

int ParentIndex(int index)
{
    return (index + 1) / 2 - 1;
}

int LeftChildIndex(int index)
{
    return 2 * index + 1;
}

int RightChildIndex(int index)
{
    return 2 * index + 2;
}

int SwapMax(int array[], int parentIndex, int leftChildIndex, int rightChildIndex)
{
}

void HeapSort(int array[], int startIndex, int endIndex)
{
    // 构建大顶堆


    // 将根调整到数组最后，从而由小到大排序
}

void InsertSort(int array[], int startIndex, int endIndex)
{
    for (int i = startIndex + 1; i < endIndex + 1; ++i)
    {
        for (int j = i; array[j] < array[j - 1]; --j)
        {
            Swap(array[j], array[j - 1]);
        }
    }
}

void ShellSort(int array[], int startIndex, int endIndex)
{
}
