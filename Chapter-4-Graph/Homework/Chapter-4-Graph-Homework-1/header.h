#pragma once


/* Homework.cpp */

/**
 * \brief 运行作业题目
 */
void TestHomework1();


/* Graph.cpp */

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
 * \brief 初始化图
 * \param matrix 图的邻接矩阵
 * \param nodeCount 图的节点数量
 * \return 返回图
 */
Graph* InitGraph(int matrix[10][10], int nodeCount);

/**
 * \brief Dijkstra算法寻找最短路径
 * \param graph 图
 * \param startNode 起始节点下标
 * \param endNode 终止节点下标
 */
void Dijkstra(Graph* graph, int startNode, int endNode);
