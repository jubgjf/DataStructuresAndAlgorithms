#pragma once

#include <cstdlib>

struct node
{
    int coefficient; // ϵ��
    int exponent; // ָ��
    struct node* next;
};

/// <summary>
/// ��ʼ������ʽ����
/// </summary>
/// <returns>��������</returns>
node* InitList()
{
    node* list = (node*)malloc(sizeof(node));
    list->next = nullptr;

    return list;
}

/// <summary>
/// �ڶ���ʽָ��λ�ú�߲�������
/// </summary>
/// <param name="insertPosition">����λ��</param>
/// <param name="coef">ϵ��</param>
/// <param name="exp">ָ��</param>
void Insert(node* insertPosition, int coef, int exp)
{
}

/// <summary>
/// ɾ������ʽָ��λ�ú�ߵ���
/// </summary>
/// <param name="deletePosition">ɾ��λ��</param>
void Delete(node* deletePosition)
{
}
