#pragma once

typedef int elementType;

struct node
{
    elementType data;
    struct node* next;
};

/// <summary>
/// 初始化环形链表
/// </summary>
/// <returns>返回链表尾节点</returns>
node* InitList()
{
}

/// <summary>
/// 在链表指定位置的后边插入新节点
/// </summary>
/// <param name="list">链表</param>
/// <param name="insertPosition">插入位置</param>
/// <param name="data">新数据</param>
void Insert(node* list, node* insertPosition, elementType data)
{
}

/// <summary>
/// 在链表头节点前方插入新节点
/// </summary>
/// <param name="list">链表</param>
/// <param name="data">数据</param>
void LeftInsert(node* list, elementType data)
{
}

/// <summary>
/// 在链表尾节点后方插入新节点
/// </summary>
/// <param name="list">链表</param>
/// <param name="data">数据</param>
void RightInsert(node* list, elementType data)
{
}

/// <summary>
/// 删除链表指定位置后边的节点
/// </summary>
/// <param name="list">链表</param>
/// <param name="deletePosition">删除位置</param>
void Delete(node* list, node* deletePosition)
{
}
