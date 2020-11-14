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
 * \brief Prim�㷨������ͼ��С������
 * \param graph ����ͼ
 */
void Prim(Graph* graph);

/**
 * \brief ͼ�бߵ���Ϣ
 */
struct EdgeInfo
{
    int weight;
    int node1Index;
    int node2Index;
};

/**
 * \brief ͼ�����бߵ���Ϣ
 */
struct Edges
{
    EdgeInfo edgeInfo[MAX_NODE_COUNT * MAX_NODE_COUNT];
    int lastIndex;
};

/**
 * \brief Kruskal�㷨������ͼ��С������
 * \param graph ����ͼ
 */
void Kruskal(Graph* graph);
