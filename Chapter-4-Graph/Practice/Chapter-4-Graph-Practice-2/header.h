#pragma once

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
 * \brief ���������ʼ��ͼ
 * \return ���������ͼ
 */
Graph* InitGraph();

/**
 * \brief Dijkstra�㷨Ѱ�����·��
 * \param graph ͼ
 * \param startNode ��ʼ�ڵ��±�
 * \param endNode ��ֹ�ڵ��±�
 */
void Dijkstra(Graph* graph, int startNode, int endNode);

/**
 * \brief Floyd�㷨Ѱ�����·��
 * \param graph ͼ
 * \param startNode ��ʼ�ڵ��±�
 * \param endNode ��ֹ�ڵ��±�
 */
void Floyd(Graph* graph, int startNode, int endNode);
