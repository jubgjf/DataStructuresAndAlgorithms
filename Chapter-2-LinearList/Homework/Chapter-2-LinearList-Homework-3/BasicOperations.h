#pragma once

#include "Maze.h"

/// <summary>
/// ջ�Ľڵ�
/// </summary>
struct node
{
    struct Position position;
    struct node* next;
};

/// <summary>
/// ���ɿ�ջ
/// </summary>
/// <returns>����ջ</returns>
node* InitStack()
{
    node* top = (node*)malloc(sizeof(node));
    top->next = nullptr;

    return top;
}

/// <summary>
/// ������ѹջ
/// </summary>
/// <param name="stack">ջ</param>
/// <param name="position">����</param>
void Push(node* stack, Position position)
{
    node* pushNode = (node*)malloc(sizeof(node));
    pushNode->position = position;
    pushNode->next = stack->next;
    stack->next = pushNode;
}

/// <summary>
/// ��ջ
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>���ص��������ݡ��������ݣ��򷵻�-1</returns>
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
/// ��ѯջ������
/// </summary>
/// <param name="stack">ջ</param>
/// <returns>����ջ�����ݡ��������ݣ��򷵻�-1</returns>
Position Top(node* stack)
{
    if (stack->next == nullptr)
    {
        return Position{-1, -1};
    }
    return stack->next->position;
}

/// <summary>
/// ���ջ
/// </summary>
/// <param name="stack">ջ</param>
void Clear(node* stack)
{
    // TODO �ڵ�δ�ͷſռ�

    stack->next = nullptr;
}

/// <summary>
/// ��ӡջ����������
/// </summary>
/// <param name="stack">ջ</param>
void Travel(node* stack)
{
    node* pointer = stack->next;
    while (pointer != nullptr)
    {
        std::cout << pointer->position.x << " " << pointer->position.y << std::endl;
        pointer = pointer->next;
    }
}
