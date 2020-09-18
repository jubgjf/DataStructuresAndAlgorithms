#include <cstdarg>

/// <summary>
/// 在链表中，查找倒数第k个节点中的数据
/// </summary>
/// <param name="list">待查找的链表</param>
/// <param name="index">倒数第index个节点（从0开始计算）</param>
/// <returns>查找成功则返回该节点，否则返回nullptr</returns>
inline cell* RetrieveByReverse(cell* list, int index)
{
    cell* frontCell = list->next;
    cell* backCell = list->next;

    if (backCell == nullptr) { return nullptr; }

    for (int i = 0; i < index; i++)
    {
        if (backCell->next != nullptr)
        {
            backCell = backCell->next;
        }
        else
        {
            return nullptr;
        }
    }
    while (backCell->next != nullptr)
    {
        frontCell = frontCell->next;
        backCell = backCell->next;
    }

    return frontCell;
}

/// <summary>
/// 查找链表中间节点的类型
/// </summary>
enum MIDDLE_TYPE
{
    MIDDLE_FRONT,
    MIDDLE_BACK
};

/// <summary>
/// 在链表中，查找中间节点
/// </summary>
/// <param name="list">待查找的链表</param>
/// <param name="middleType">遇到偶数个节点的处理方式</param>
/// <returns>
/// <para>若有奇数个节点，则返回正中间的节点；
/// <para>若有偶数个节点，且MIDDLE_TYPE为MIDDLE_FRONT，则返回中间两个的前一个节点（默认）
/// <para>若有偶数个节点，且MIDDLE_TYPE为MIDDLE_BACK，则返回中间两个的后一个节点
/// <para>若为空链表，则返回nullptr
/// </returns>
inline cell* RetrieveMiddle(cell* list, enum MIDDLE_TYPE middleType = MIDDLE_FRONT)
{
    cell* frontCell = list->next;
    cell* backCell = list->next;

    if (backCell == nullptr) { return nullptr; }

    switch (middleType)
    {
    case MIDDLE_FRONT:
        while (backCell->next != nullptr && backCell->next->next != nullptr)
        {
            frontCell = frontCell->next;
            backCell = backCell->next->next;
        }
        break;
    case MIDDLE_BACK:
        while (backCell != nullptr && backCell->next != nullptr)
        {
            frontCell = frontCell->next;
            backCell = backCell->next->next;
        }
        break;
    }

    return frontCell;
}

/// <summary>
/// <para>测试作业1.1.1：“求单链表倒数第k个元素”
/// <para>输出倒数第k个节点的数据，若不存在该节点，则输出"index k not found"
/// </summary>
/// <param name="count">链表节点个数</param>
/// <param name="k">需要求的链表倒数第几个节点</param>
/// <param name="...">链表的各个节点的数据</param>
inline void TestHomework1_1_1(int count, int k, ...)
{
    va_list paraList;
    cell* list = InitList();
    cell* pointer = list;

    va_start(paraList, k);
    for (int i = 0; i < count; ++i)
    {
        pointer = Insert(pointer, va_arg(paraList, elementType));
    }
    va_end(paraList);

    cell* resultCell = RetrieveByReverse(list, k);

    if (resultCell == nullptr) { std::cout << "index k not found" << std::endl; }
    else { std::cout << resultCell->data << std::endl; }
}

/// <summary>
/// <para>测试作业1.1.2：“求单链表中点元素”
/// <para>输出中间节点的数据，若不存在该节点，则输出"empty list"
/// </summary>
/// <param name="count">链表节点个数</param>
/// <param name="middleType">当链表有偶数个节点时，选取哪一种取中点方式</param>
/// <param name="...">链表的各个节点的数据</param>
inline void TestHomework1_1_2(int count, enum MIDDLE_TYPE middleType, ...)
{
    va_list paraList;
    cell* list = InitList();
    cell* pointer = list;

    va_start(paraList, middleType);
    for (int i = 0; i < count; ++i)
    {
        pointer = Insert(pointer, va_arg(paraList, elementType));
    }
    va_end(paraList);

    cell* resultCell = RetrieveMiddle(list, middleType);

    if (resultCell == nullptr) { std::cout << "empty list" << std::endl; }
    else { std::cout << resultCell->data << std::endl; }
}
