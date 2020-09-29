#pragma once

#include "Maze.h"

/// <summary>
/// 栈的节点
/// </summary>
struct node
{
    struct Position position;
    struct node* next;
};

/// <summary>
/// 生成空栈
/// </summary>
/// <returns>返回栈</returns>
node* InitStack()
{
    node* top = (node*)malloc(sizeof(node));
    top->next = nullptr;

    return top;
}

/// <summary>
/// 将数据压栈
/// </summary>
/// <param name="stack">栈</param>
/// <param name="position">坐标</param>
void Push(node* stack, Position position)
{
    node* pushNode = (node*)malloc(sizeof(node));
    pushNode->position = position;
    pushNode->next = stack->next;
    stack->next = pushNode;
}

/// <summary>
/// 弹栈
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回弹出的数据。若无数据，则返回-1</returns>
Position Pop(node* stack)
{
    node* popNode = stack->next;

    if (popNode == nullptr)
    {
        return Position{-1, -1};
    }

    stack->next = popNode->next;
    Position popData = popNode->position;
    free(popNode);

    return popData;
}

/// <summary>
/// 查询栈顶数据
/// </summary>
/// <param name="stack">栈</param>
/// <returns>返回栈顶数据。若无数据，则返回-1</returns>
Position Top(node* stack)
{
    if (stack->next == nullptr)
    {
        return Position{-1, -1};
    }
    return stack->next->position;
}

/// <summary>
/// 清空栈
/// </summary>
/// <param name="stack">栈</param>
void Clear(node* stack)
{
    // TODO 节点未释放空间

    stack->next = nullptr;
}

/// <summary>
/// 打印栈中所有数据
/// </summary>
/// <param name="stack">栈</param>
void Travel(node* stack)
{
    node* pointer = stack->next;
    while (pointer != nullptr)
    {
        std::cout << pointer->position.x << " " << pointer->position.y << std::endl;
        pointer = pointer->next;
    }
}
