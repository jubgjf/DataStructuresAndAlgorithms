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
 * \brief 获取在以0为开始的数组形成的堆中，某个节点的父节点下标
 * \param index 节点下标
 * \return 返回父节点下标
 */
int ParentIndex(int index);

/**
 * \brief 获取在以0为开始的数组形成的堆中，某个节点的左孩子下标
 * \param index 节点下标
 * \return 返回左孩子下标
 */
int LeftChildIndex(int index);

/**
 * \brief 获取在以0为开始的数组形成的堆中，某个节点的右孩子下标
 * \param index 节点下标
 * \return 返回右孩子下标
 */
int RightChildIndex(int index);

/**
 * \brief 检查父节点和两个儿子节点，将最大的数放在父节点
 * \param array 数组
 * \param parentIndex 父节点下标
 * \param leftChildIndex 左孩子下标
 * \param rightChildIndex 右孩子下标，-1代表没有右孩子
 * \return 返回被交换的孩子的下标
 */
int SwapMax(int array[], int parentIndex, int leftChildIndex, int rightChildIndex);

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
