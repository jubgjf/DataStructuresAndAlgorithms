//
// @brief: 静态链表练习
//

#include <iostream>


/// <summary>
/// 静态链表最大长度
/// </summary>
constexpr int maxLength = 10;

/// <summary>
/// 链表中的数据类型
/// </summary>
typedef int elementType;

/// <summary>
/// 静态链表的一个节点
/// </summary>
struct StaticList
{
    elementType data;
    int next;
};

/// <summary>
/// 初始化存储池
/// </summary>
/// <param name="avail">可用位置序号</param>
/// <returns>返回存储池</returns>
StaticList* InitSpace(int* avail)
{
    *avail = 0;

    StaticList space[maxLength];

    for (int i = 0; i < maxLength - 1; ++i)
    {
        space[i].next = i + 1;
    }
    space[maxLength - 1].next = -1;

    return space;
}

/// <summary>
/// 从存储池生成新静态链表
/// </summary>
/// <param name="space">存储池</param>
/// <param name="avail">可用位置序号</param>
/// <returns>返回链表头节点序号</returns>
int NewList(StaticList* space, int* avail)
{
    // TODO 测试NewList

    int listHead = *avail;
    *avail = space[listHead].next;
    space[listHead].next = -1;

    return listHead;
}

/// <summary>
/// 向静态链表指定位置后边插入节点
/// </summary>
/// <param name="space">存储池</param>
/// <param name="avail">可用位置序号</param>
/// <param name="insertPosition">插入新节点的位置</param>
/// <param name="data">新节点数据</param>
/// <returns>返回新节点对应序号</returns>
int Insert(StaticList* space, int* avail, int insertPosition, elementType data)
{
    // TODO 测试Insert

    int insertIndex = *avail;

    space[insertIndex].data = data;
    *avail = space[insertIndex].next;
    space[insertIndex].next = space[insertPosition].next;
    space[insertPosition].next = insertIndex;

    return insertIndex;
}

/// <summary>
/// 删除静态链表指定节点后边的节点
/// </summary>
/// <param name="space">存储池</param>
/// <param name="avail">可用位置序号</param>
/// <param name="deletePosition">删除节点的位置</param>
void Delete(StaticList* space, int* avail, int deletePosition)
{
    // TODO 测试Delete

    int deleteIndex = space[deletePosition].next;

    space[deletePosition].next = space[deleteIndex].next;
    space[deleteIndex].next = *avail;
    *avail = deleteIndex;
}

/// <summary>
/// 输出静态链表所有元素信息
/// </summary>
/// <param name="space">存储池</param>
/// <param name="listHead">链表头节点序号</param>
void Travel(StaticList* space, int listHead)
{
    // TODO 测试Travel

    StaticList node = space[listHead];

    while (node.next != -1)
    {
        std::cout << node.data << std::endl;
    }
    std::cout << node.data << std::endl;
}

int main()
{
    int avail;
    StaticList* space = InitSpace(&avail);

    int listHead = NewList(space, &avail);

    Insert(space, &avail, listHead, 9);
}
