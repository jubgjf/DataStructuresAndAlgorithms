#pragma once

/**
 * \brief �����������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void PrintArray(int array[], int startIndex, int endIndex);

/**
 * \brief ����������
 * \param a ��һ����
 * \param b �ڶ�����
 */
void Swap(int& a, int& b);

/**
 * \brief ð������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void BubbleSort(int array[], int startIndex, int endIndex);

/**
 * \brief ð������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void QuickSort(int array[], int startIndex, int endIndex);

/**
 * \brief ð������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void SelectSort(int array[], int startIndex, int endIndex);

/**
 * \brief ��С�����в���Ԫ��
 * \param heap С����
 * \param lastIndex ����������һ��Ԫ�ص��±�
 * \param insertData �������Ԫ��
 */
void HeapInsert(int heap[], int& lastIndex, int insertData);

/**
 * \brief ��ȡ�����±�
 * \param index ��ǰ�±�
 * \param lastIndex �ѵ����һ��Ԫ�ص��±�
 * \return ��ȡ�����±꣬û�������򷵻�-1
 */
int LeftChildIndex(int index, int lastIndex);

/**
 * \brief ��ȡ�Һ����±�
 * \param index ��ǰ�±�
 * \param lastIndex �ѵ����һ��Ԫ�ص��±�
 * \return ��ȡ�Һ����±꣬û���Һ����򷵻�-1
 */
int RightChildIndex(int index, int lastIndex);

/**
 * \brief ��С�����е�����
 * \param heap С����
 * \param lastIndex ����������һ��Ԫ�ص��±�
 * \return ������Ԫ��
 */
int HeapPop(int heap[], int& lastIndex);

/**
 * \brief ð������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void HeapSort(int array[], int startIndex, int endIndex);

/**
 * \brief ð������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void InsertSort(int array[], int startIndex, int endIndex);

/**
 * \brief ð������
 * \param array ����
 * \param startIndex ����ʼ�±�
 * \param endIndex ��������±�
 */
void ShellSort(int array[], int startIndex, int endIndex);
