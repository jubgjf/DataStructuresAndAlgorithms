#pragma once

typedef int elementType;

struct node
{
    elementType data;
    struct node* next;
};

/// <summary>
/// ��ʼ����������
/// </summary>
/// <returns>��������β�ڵ�</returns>
node* InitList()
{
}

/// <summary>
/// ������ָ��λ�õĺ�߲����½ڵ�
/// </summary>
/// <param name="list">����</param>
/// <param name="insertPosition">����λ��</param>
/// <param name="data">������</param>
void Insert(node* list, node* insertPosition, elementType data)
{
}

/// <summary>
/// ������ͷ�ڵ�ǰ�������½ڵ�
/// </summary>
/// <param name="list">����</param>
/// <param name="data">����</param>
void LeftInsert(node* list, elementType data)
{
}

/// <summary>
/// ������β�ڵ�󷽲����½ڵ�
/// </summary>
/// <param name="list">����</param>
/// <param name="data">����</param>
void RightInsert(node* list, elementType data)
{
}

/// <summary>
/// ɾ������ָ��λ�ú�ߵĽڵ�
/// </summary>
/// <param name="list">����</param>
/// <param name="deletePosition">ɾ��λ��</param>
void Delete(node* list, node* deletePosition)
{
}