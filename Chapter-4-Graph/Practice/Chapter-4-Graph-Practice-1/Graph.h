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
 * \brief 从边数组中选择出权值最小的边
 * \param edges 所有边
 * \return 返回权值最小的边
 */
struct EdgeInfo SelectMinWeightEdge(struct Edges* edges);

/**
 * \brief Prim算法求无向图最小生成树
 * \param graph 无向图
 * \param startIndex 开始计算最小生成树的节点
 */
void Prim(Graph* graph, int startIndex);

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
 * \brief 初始化存储边的数组
 * \return 返回空数组
 */
Edges* InitEdges();

/**
 * \brief 将图的邻接矩阵中边的信息储存在Edges数组中
 * \param graph 图
 * \param edges 储存边的数组
 */
void ConvertMatrixToEdges(Graph* graph, Edges* edges);

/**
 * \brief 根据边的权值，将边从小到大排序
 * \param edges 存储所有边信息的数组
 */
void SortEdgesByWeight(Edges* edges);

/**
 * \brief 按照“权值 - 第一个端点 - 第二个端点”输出最小生成树
 * \param minSpanningTreeEdges 最小生成树数组
 */
void PrintMinSpanningTree(Edges* minSpanningTreeEdges);

/**
 * \brief Kruskal算法求无向图最小生成树
 * \param graph 无向图
 */
void Kruskal(Graph* graph);
