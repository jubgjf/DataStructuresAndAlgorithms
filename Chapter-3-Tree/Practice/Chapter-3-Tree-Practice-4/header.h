#pragma once


/* set.cpp */

/**
 * \brief 存储池中最多的元素个数
 */
#define MAX_ELEMENT_COUNT 100

/**
* \brief 集合中的元素信息
*/
struct Element
{
    int data;
    int parent;
};

/**
* \brief 存储池类型
*/
struct Pool
{
    struct Element element[MAX_ELEMENT_COUNT];
    int last_index;
};

/// <summary>
/// 初始化存储池，并新建根节点
/// </summary>
/// <param name="root_index">根节点位置</param>
/// <param name="root_data">根节点数据</param>
/// <returns>返回存储池</returns>
Pool* init(int root_index, int root_data);

/// <summary>
/// 集合合并
/// </summary>
/// <param name="pool">存储池</param>
/// <param name="root1">第一个集合的根</param>
/// <param name="root2">第二个集合的根</param>
void union_set(Pool* pool, int root1, int root2);

/// <summary>
/// 查找元素所在集合的根位置
/// </summary>
/// <param name="pool">存储池</param>
/// <param name="index">指定元素</param>
/// <returns>返回根的位置</returns>
int find_root(Pool* pool, int index);

/// <summary>
/// 添加新元素
/// </summary>
/// <param name="pool">存储池</param>
/// <param name="parent">新元素的父节点位置</param>
/// <param name="data">新元素的数据</param>
void add(Pool* pool, int parent, int data);
