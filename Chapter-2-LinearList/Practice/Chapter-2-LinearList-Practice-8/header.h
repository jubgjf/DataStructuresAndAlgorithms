#pragma once


/* Queue.cpp */

/// <summary>
/// �ڵ���������
/// </summary>
typedef int elementType;

/// <summary>
/// ���нڵ�
/// </summary>
struct Node
{
    elementType data;
    struct Node* next;
};

/// <summary>
/// ��������
/// </summary>
struct Queue
{
    Node* head;
    Node* rear;
};

/// <summary>
/// ���ɿն���
/// </summary>
/// <returns>���ؿն���</returns>
Queue* Init();

/// <summary>
/// ���
/// </summary>
/// <param name="queue">����</param>
/// <param name="data">�������</param>
void Enqueue(Queue* queue, elementType data);

/// <summary>
/// ����
/// </summary>
/// <param name="queue">����</param>
/// <returns>���ӽڵ�</returns>
Node* Dequeue(Queue* queue);
