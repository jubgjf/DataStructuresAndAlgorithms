#pragma once

#include <cstdlib>

struct node
{
    int coefficient; // 系数
    int exponent; // 指数
    struct node* next;
};

/// <summary>
/// 初始化多项式链表
/// </summary>
/// <returns>返回链表</returns>
node* InitList()
{
    node* list = (node*)malloc(sizeof(node));
    list->next = nullptr;

    return list;
}

/// <summary>
/// 在多项式指定位置后边插入新项
/// </summary>
/// <param name="insertPosition">插入位置</param>
/// <param name="coef">系数</param>
/// <param name="exp">指数</param>
void Insert(node* insertPosition, int coef, int exp)
{
}

/// <summary>
/// 删除多项式指定位置后边的项
/// </summary>
/// <param name="deletePosition">删除位置</param>
void Delete(node* deletePosition)
{
}
