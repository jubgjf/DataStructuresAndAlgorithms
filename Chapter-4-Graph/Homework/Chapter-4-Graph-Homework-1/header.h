#pragma once


/* Homework.cpp */

/**
 * \brief ������ҵ��Ŀ
 */
void TestHomework1();


/* Graph.cpp */

/**
 * \brief ͼ�����ڵ�����
 */
#define MAX_NODE_COUNT 100

/**
 * \brief ͼ�ṹ
 */
struct Graph
{
    int matrix[MAX_NODE_COUNT][MAX_NODE_COUNT];
    int nodeCount;
};

/**
 * \brief ��ʼ��ͼ
 * \param matrix ͼ���ڽӾ���
 * \param nodeCount ͼ�Ľڵ�����
 * \return ����ͼ
 */
Graph* InitGraph(int matrix[10][10], int nodeCount);

/**
 * \brief Dijkstra�㷨Ѱ�����·��
 * \param graph ͼ
 * \param startNode ��ʼ�ڵ��±�
 * \param endNode ��ֹ�ڵ��±�
 */
void Dijkstra(Graph* graph, int startNode, int endNode);
