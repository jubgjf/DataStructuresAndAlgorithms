#include <iostream>
#include <cstdlib>

/// <summary>
/// 链表节点中数据的类型
/// </summary>
typedef int elementType;

/// <summary>
/// 链表的一个节点
/// </summary>
struct cell
{
    elementType data;
    struct cell* next;
};

/// <summary>
/// 生成一个空链表
/// </summary>
/// <returns>返回头节点</returns>
inline cell* InitList()
{
    cell* head = (cell*)malloc(sizeof(cell));
    head->data = 0; // 头节点中的数据设置为0
    head->next = nullptr;
    return head;
}

/// <summary>
/// 插入节点类别
/// </summary>
enum INSERT_TYPE
{
    INSERT_FRONT,
    INSERT_BACK
};

/// <summary>
/// 在链表中指定位置插入一个节点
/// </summary>
/// <param name="insertPosition">待插入的位置</param>
/// <param name="insertData">待插入的数据</param>
/// <param name="insertType">
/// <para>若为INSERT_FRONT，则在链表的insertPosition节点前，插入一个数据为data的节点
/// <para>若为INSERT_BACK，则在链表的insertPosition节点后，插入一个数据为data的节点（默认）
/// </param>
/// <returns>插入成功则返回被插入的节点，否则返回nullptr</returns>
inline cell* Insert(cell* insertPosition, elementType insertData, enum INSERT_TYPE insertType = INSERT_BACK)
{
    cell* insertCell = (cell*)malloc(sizeof(cell));
    if (insertCell == nullptr) { return nullptr; }

    insertCell->data = insertData;

    switch (insertType)
    {
    case INSERT_FRONT:
        // TODO 未完成 INSERT_FRONT
        break;
    case INSERT_BACK:
        insertCell->next = insertPosition->next;
        insertPosition->next = insertCell;
        break;
    }

    return insertCell;
}

/// <summary>
/// 删除节点类别
/// </summary>
enum DELETE_TYPE
{
    DELETE_FRONT,
    DELETE_HERE,
    DELETE_BACK
};

/// <summary>
/// 在链表中指定位置删除节点
/// </summary>
/// <param name="deletePosition">待删除的位置</param>
/// <param name="deleteType">
/// <para>若为DELETE_FRONT，则删除deletePosition节点前边的节点
/// <para>若为DELETE_HERE，则删除deletePosition节点（默认）
/// <para>若为DELETE_BACK，则删除deletePosition节点后边的节点
/// </param>
/// <returns>删除成功则返回被删除节点前边的节点，否则返回nullptr</returns>
inline cell* Delete(cell* deletePosition, enum DELETE_TYPE deleteType = DELETE_HERE)
{
    switch (deleteType)
    {
    case DELETE_FRONT:
        // TODO 未完成 DELETE_FRONT
        break;
    case DELETE_HERE:
        // TODO 未完成 DELETE_HERE
        break;
    case DELETE_BACK:
        if (deletePosition->next != nullptr)
        {
            cell* tempCell = deletePosition->next;
            deletePosition->next = tempCell->next;
            free(tempCell);

            return deletePosition;
        }
        return nullptr;
    }

    return nullptr;
}

/// <summary>
/// 在链表中，寻找某个第一次出现的位置
/// </summary>
/// <param name="list">待查找的链表</param>
/// <param name="dataToFind">待查找的数据</param>
/// <returns>若找到则返回第一次出现所在的节点，否则返回nullptr</returns>
inline cell* Locate(cell* list, elementType dataToFind)
{
    cell* pointer = list->next;
    while (pointer != nullptr)
    {
        if (pointer->data == dataToFind)
        {
            return pointer;
        }
        else
        {
            pointer = pointer->next;
        }
    }

    return nullptr;
}

/// <summary>
/// 遍历链表，并依次输出节点数据
/// </summary>
/// <param name="list">待遍历的链表</param>
inline void Travel(cell* list)
{
    cell* pointer = list->next;

    while (pointer != nullptr)
    {
        std::cout << pointer->data << " ";
        pointer = pointer->next;
    }
    std::cout << std::endl;
}
