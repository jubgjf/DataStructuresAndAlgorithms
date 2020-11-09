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
 * \brief Dijkstra算法寻找最短路径
 * \param graph 图
 * \param startNode 起始节点下标
 * \param endNode 终止节点下标
 */
void Dijkstra(Graph* graph, int startNode, int endNode);

/**
 * \brief Floyd算法寻找最短路径
 * \param graph 图
 * \param startNode 起始节点下标
 * \param endNode 终止节点下标
 */
void Floyd(Graph* graph, int startNode, int endNode);
