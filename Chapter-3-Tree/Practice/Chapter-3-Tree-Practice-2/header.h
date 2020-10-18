#pragma once

/**
 * \brief 堆最大元素个数
 */
#define HEAP_MAX_SIZE 100

/**
 * \brief 大顶堆结构
 */
struct max_heap
{
    int data[HEAP_MAX_SIZE];
    int last_index;
};

/**
 * \brief 创建空堆
 * \return 返回空堆
 */
max_heap* init();

/**
 * \brief 交换两个整数
 * \param a 第一个数
 * \param b 第二个数
 */
void swap(int& a, int& b);

/**
 * \brief 向堆中插入元素
 * \param heap 大顶堆
 * \param data 插入的数据
 */
void insert(max_heap* heap, int data);

/**
 * \brief 删除最大元素
 * \param heap 最大堆
 */
void delete_max(max_heap* heap);
