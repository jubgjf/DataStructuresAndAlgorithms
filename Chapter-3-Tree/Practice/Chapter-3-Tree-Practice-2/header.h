#pragma once

/**
 * \brief �����Ԫ�ظ���
 */
#define HEAP_MAX_SIZE 100

/**
 * \brief �󶥶ѽṹ
 */
struct max_heap
{
    int data[HEAP_MAX_SIZE];
    int last_index;
};

/**
 * \brief �����ն�
 * \return ���ؿն�
 */
max_heap* init();

/**
 * \brief ������������
 * \param a ��һ����
 * \param b �ڶ�����
 */
void swap(int& a, int& b);

/**
 * \brief ����в���Ԫ��
 * \param heap �󶥶�
 * \param data ���������
 */
void insert(max_heap* heap, int data);

/**
 * \brief ɾ�����Ԫ��
 * \param heap ����
 */
void delete_max(max_heap* heap);
