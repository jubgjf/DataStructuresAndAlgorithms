#pragma once

/**
 * \brief 依次输出数组
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void PrintArray(int array[], int startIndex, int endIndex);

/**
 * \brief 交换两个数
 * \param a 第一个数
 * \param b 第二个数
 */
void Swap(int& a, int& b);

/**
 * \brief 冒泡排序
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void BubbleSort(int array[], int startIndex, int endIndex);

/**
 * \brief 冒泡排序
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void QuickSort(int array[], int startIndex, int endIndex);

/**
 * \brief 冒泡排序
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void SelectSort(int array[], int startIndex, int endIndex);

/**
 * \brief 向小顶堆中插入元素
 * \param heap 小顶堆
 * \param lastIndex 堆数组的最后一个元素的下标
 * \param insertData 待插入的元素
 */
void HeapInsert(int heap[], int& lastIndex, int insertData);

/**
 * \brief 获取左孩子下标
 * \param index 当前下标
 * \param lastIndex 堆的最后一个元素的下标
 * \return 获取左孩子下标，没有左孩子则返回-1
 */
int LeftChildIndex(int index, int lastIndex);

/**
 * \brief 获取右孩子下标
 * \param index 当前下标
 * \param lastIndex 堆的最后一个元素的下标
 * \return 获取右孩子下标，没有右孩子则返回-1
 */
int RightChildIndex(int index, int lastIndex);

/**
 * \brief 从小顶堆中弹出根
 * \param heap 小顶堆
 * \param lastIndex 堆数组的最后一个元素的下标
 * \return 弹出的元素
 */
int HeapPop(int heap[], int& lastIndex);

/**
 * \brief 冒泡排序
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void HeapSort(int array[], int startIndex, int endIndex);

/**
 * \brief 冒泡排序
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void InsertSort(int array[], int startIndex, int endIndex);

/**
 * \brief 冒泡排序
 * \param array 数组
 * \param startIndex 排序开始下标
 * \param endIndex 排序结束下标
 */
void ShellSort(int array[], int startIndex, int endIndex);
