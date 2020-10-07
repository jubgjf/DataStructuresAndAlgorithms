#pragma once


/* Queue.cpp */

/// <summary>
/// 节点数据类型
/// </summary>
typedef int elementType;

/// <summary>
/// 队列节点
/// </summary>
struct Node
{
    elementType data;
    struct Node* next;
};

/// <summary>
/// 队列类型
/// </summary>
struct Queue
{
    Node* head;
    Node* rear;
};

/// <summary>
/// 生成空队列
/// </summary>
/// <returns>返回空队列</returns>
Queue* Init();

/// <summary>
/// 入队
/// </summary>
/// <param name="queue">队列</param>
/// <param name="data">入队数据</param>
void Enqueue(Queue* queue, elementType data);

/// <summary>
/// 出队
/// </summary>
/// <param name="queue">队列</param>
/// <returns>出队节点</returns>
Node* Dequeue(Queue* queue);
