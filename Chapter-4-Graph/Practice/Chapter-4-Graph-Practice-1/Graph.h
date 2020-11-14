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
 * \brief �ӱ�������ѡ���Ȩֵ��С�ı�
 * \param edges ���б�
 * \return ����Ȩֵ��С�ı�
 */
struct EdgeInfo SelectMinWeightEdge(struct Edges* edges);

/**
 * \brief Prim�㷨������ͼ��С������
 * \param graph ����ͼ
 * \param startIndex ��ʼ������С�������Ľڵ�
 */
void Prim(Graph* graph, int startIndex);

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
 * \brief ��ʼ���洢�ߵ�����
 * \return ���ؿ�����
 */
Edges* InitEdges();

/**
 * \brief ��ͼ���ڽӾ����бߵ���Ϣ������Edges������
 * \param graph ͼ
 * \param edges ����ߵ�����
 */
void ConvertMatrixToEdges(Graph* graph, Edges* edges);

/**
 * \brief ���ݱߵ�Ȩֵ�����ߴ�С��������
 * \param edges �洢���б���Ϣ������
 */
void SortEdgesByWeight(Edges* edges);

/**
 * \brief ���ա�Ȩֵ - ��һ���˵� - �ڶ����˵㡱�����С������
 * \param minSpanningTreeEdges ��С����������
 */
void PrintMinSpanningTree(Edges* minSpanningTreeEdges);

/**
 * \brief Kruskal�㷨������ͼ��С������
 * \param graph ����ͼ
 */
void Kruskal(Graph* graph);
