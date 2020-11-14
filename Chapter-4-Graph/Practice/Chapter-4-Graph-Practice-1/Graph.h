#pragma once

/**
 * \brief 图的最大节点数量
 */
#define MAX_NODE_COUNT 100

/**
 * \brief 图结构
 */
struct Graph
{
    int matrix[MAX_NODE_COUNT][MAX_NODE_COUNT];
    int nodeCount;
};

/**
 * \brief 根据输入初始化图
 * \return 返回输入的图
 */
Graph* InitGraph();

/**
 * \brief Prim算法求无向图最小生成树
 * \param graph 无向图
 */
void Prim(Graph* graph);

/**
 * \brief 图中边的信息
 */
struct EdgeInfo
{
    int weight;
    int node1Index;
    int node2Index;
};

/**
 * \brief 图的所有边的信息
 */
struct Edges
{
    EdgeInfo edgeInfo[MAX_NODE_COUNT * MAX_NODE_COUNT];
    int lastIndex;
};

/**
 * \brief Kruskal算法求无向图最小生成树
 * \param graph 无向图
 */
void Kruskal(Graph* graph);
