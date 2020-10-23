#pragma once


/* set.cpp */

/**
 * \brief �洢��������Ԫ�ظ���
 */
#define MAX_ELEMENT_COUNT 100

/**
* \brief �����е�Ԫ����Ϣ
*/
struct Element
{
    int data;
    int parent;
};

/**
* \brief �洢������
*/
struct Pool
{
    struct Element element[MAX_ELEMENT_COUNT];
    int last_index;
};

/// <summary>
/// ��ʼ���洢�أ����½����ڵ�
/// </summary>
/// <param name="root_index">���ڵ�λ��</param>
/// <param name="root_data">���ڵ�����</param>
/// <returns>���ش洢��</returns>
Pool* init(int root_index, int root_data);

/// <summary>
/// ���Ϻϲ�
/// </summary>
/// <param name="pool">�洢��</param>
/// <param name="root1">��һ�����ϵĸ�</param>
/// <param name="root2">�ڶ������ϵĸ�</param>
void union_set(Pool* pool, int root1, int root2);

/// <summary>
/// ����Ԫ�����ڼ��ϵĸ�λ��
/// </summary>
/// <param name="pool">�洢��</param>
/// <param name="index">ָ��Ԫ��</param>
/// <returns>���ظ���λ��</returns>
int find_root(Pool* pool, int index);

/// <summary>
/// �����Ԫ��
/// </summary>
/// <param name="pool">�洢��</param>
/// <param name="parent">��Ԫ�صĸ��ڵ�λ��</param>
/// <param name="data">��Ԫ�ص�����</param>
void add(Pool* pool, int parent, int data);
