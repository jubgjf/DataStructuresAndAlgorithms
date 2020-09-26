#pragma once

#include <string>

/// <summary>
/// 链表的一个节点中的数据
/// </summary>
struct Data
{
    std::string name;
    std::string brand;
    double price;
    int count;
};

/// <summary>
/// 链表的一个节点
/// </summary>
struct Cell
{
    struct Data data;
    struct Cell* next;
};

/// <summary>
/// 生成一个空链表
/// </summary>
/// <returns>返回链表头节点</returns>
inline Cell* InitList()
{
    Cell* head = new Cell;

    head->data.name = "";
    head->data.brand = "";
    head->data.price = 0;
    head->data.count = 0;
    head->next = nullptr;

    return head;
}

/// <summary>
/// 在链表指定位置的后边插入一个节点
/// </summary>
/// <param name="insertPosition">待插入节点的位置</param>
/// <param name="insertData">待插入的数据</param>
/// <returns>返回被插入的节点</returns>
inline Cell* Insert(Cell* insertPosition, Data insertData)
{
    Cell* insertCell = new Cell;

    insertCell->data = insertData;
    insertCell->next = insertPosition->next;
    insertPosition->next = insertCell;

    return insertCell;
}

/// <summary>
/// 在链表指定位置的后边删除一个节点
/// </summary>
/// <param name="deletePosition">待删除节点的位置</param>
/// <returns>返回被删除节点前边的节点</returns>
inline Cell* Delete(Cell* deletePosition)
{
    if (deletePosition->next != nullptr)
    {
        Cell* tempCell = deletePosition->next;
        deletePosition->next = tempCell->next;
        free(tempCell);

        return deletePosition;
    }
    return nullptr;
}

/// <summary>
/// 更新链表指定位置的数据
/// </summary>
/// <param name="updatePosition">待更新数据的节点位置</param>
/// <param name="updateData">待更新的数据</param>
/// <returns>返回被更新的节点</returns>
inline void Update(Cell* updatePosition, Data updateData)
{
    // TODO 完成Update

    return;
}

/// <summary>
/// 查询信息的方式
/// </summary>
enum RETRIEVE_TYPE
{
    RETRIEVE_NAME,
    RETRIEVE_BRAND
};

/// <summary>
/// 查询链表中信息，可以选择按名称查找或品牌查找
/// </summary>
/// <param name="strToFind">查找的字符串</param>
/// <param name="retrieveType">查找信息的方式
/// <para>若为RETRIEVE_NAME，则按照商品名称查找
/// <para>若为RETRIEVE_BRAND，则按照商品品牌查找
/// </param>
/// <returns>返回查找到的第一个商品所在节点</returns>
inline Cell* Retrieve(std::string strToFind, enum RETRIEVE_TYPE retrieveType)
{
    // TODO 完成Retrieve，用vector等返回多个值

    switch (retrieveType)
    {
    case RETRIEVE_NAME:
        break;
    case RETRIEVE_BRAND:
        break;
    }
    return nullptr;
}
