#pragma once

/**
 * \brief 并查集存储池中最多的元素个数
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
* \brief 并查集存储池类型
*/
struct Pool
{
    struct Element element[MAX_ELEMENT_COUNT];
    int lastIndex;
};

/**
 * \brief 初始化并查集存储池，并新建根节点
 * \param rootIndex 根节点位置
 * \param rootData 根节点数据
 * \return 返回存储池
 */
Pool* InitUnionSetPool(int rootIndex, int rootData);

/**
 * \brief 集合合并
 * \param pool 存储池
 * \param root1Index 第一个集合的根
 * \param root2Index 第二个集合的根
 */
void UnionSets(Pool* pool, int root1Index, int root2Index);

/**
 * \brief 查找元素所在集合的根位置
 * \param pool 存储池
 * \param index 指定元素
 * \return 返回根的位置
 */
int FindRoot(Pool* pool, int index);

/**
 * \brief 集合添加新元素
 * \param pool 存储池
 * \param parent 新元素的父节点位置
 * \param data 新元素的数据
 */
void AddElement(Pool* pool, int parent, int data);
