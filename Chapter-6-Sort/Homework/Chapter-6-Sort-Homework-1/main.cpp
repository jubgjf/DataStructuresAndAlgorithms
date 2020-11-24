#include <ctime>
#include <iostream>
#include "header.h"

int main(int argc, char* argv[])
{
    // TODO 用文件读取数据

    clock_t begin, end;
    int array[1000] = {0};
    for (int i = 0; i < argc - 1; ++i) { array[i] = atoi(argv[i + 1]); }

    begin = clock();
    // BubbleSort(array, 0, argc-1);
    // QuickSort(array, 0, argc-1);
    // SelectSort(array, 0, argc-1);
    // HeapSort(array, 0, argc-1);
    // InsertSort(array, 0, argc-1);
    // ShellSort(array, 0, argc-1);
    end = clock();

    PrintArray(array, 0, argc - 1);
    double cost = (static_cast<double>(end) - begin) / CLOCKS_PER_SEC;
    printf("Time cost:%lf", cost);
}
