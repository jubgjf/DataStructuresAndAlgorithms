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
 * \brief ��ȡ����0Ϊ��ʼ�������γɵĶ��У�ĳ���ڵ�ĸ��ڵ��±�
 * \param index �ڵ��±�
 * \return ���ظ��ڵ��±�
 */
int ParentIndex(int index);

/**
 * \brief ��ȡ����0Ϊ��ʼ�������γɵĶ��У�ĳ���ڵ�������±�
 * \param index �ڵ��±�
 * \return ���������±�
 */
int LeftChildIndex(int index);

/**
 * \brief ��ȡ����0Ϊ��ʼ�������γɵĶ��У�ĳ���ڵ���Һ����±�
 * \param index �ڵ��±�
 * \return �����Һ����±�
 */
int RightChildIndex(int index);

/**
 * \brief ��鸸�ڵ���������ӽڵ㣬�����������ڸ��ڵ�
 * \param array ����
 * \param parentIndex ���ڵ��±�
 * \param leftChildIndex �����±�
 * \param rightChildIndex �Һ����±꣬-1����û���Һ���
 * \return ���ر������ĺ��ӵ��±�
 */
int SwapMax(int array[], int parentIndex, int leftChildIndex, int rightChildIndex);

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
