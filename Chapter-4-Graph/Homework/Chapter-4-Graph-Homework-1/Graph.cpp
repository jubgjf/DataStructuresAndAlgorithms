#include <iostream>
#include "header.h"

Graph* InitGraph(int (*matrix)[16], int nodeCount)
{
    Graph* graph = new Graph;

    graph->nodeCount = nodeCount;
    for (int i = 0; i < nodeCount; ++i)
    {
        for (int j = 0; j < nodeCount; ++j)
        {
            graph->matrix[i][j] = matrix[i][j];
            if (graph->matrix[i][j] == 0) { graph->matrix[i][j] = INT_MAX / 2; }
        }
    }

    return graph;
}

void Dijkstra(Graph* graph, int startNode, int endNode)
{
    bool visited[MAX_NODE_COUNT]; // 记录第i个节点是否访问过
    int distance[MAX_NODE_COUNT]; // 记录起始节点到第i个节点的最短距离
    int parent[MAX_NODE_COUNT]; // 记录最短路径中，第i个节点的上一个节点

    // 初始化数组
    std::fill_n(visited, MAX_NODE_COUNT, false);
    std::fill_n(distance, MAX_NODE_COUNT, INT_MAX / 2);
    std::fill_n(parent, MAX_NODE_COUNT, -1);

    // 修改起始节点数组信息
    visited[startNode] = true;
    distance[startNode] = 0;

    int currentNode = startNode;

    for (int k = 0; k < graph->nodeCount - 1; k++)
    {
        // 更新相邻节点信息
        for (int i = 0; i < graph->nodeCount; ++i)
        {
            if (graph->matrix[currentNode][i] != INT_MAX / 2 && !visited[i] && // 与当前节点邻接，且之前未遍历过
                graph->matrix[currentNode][i] + distance[currentNode] < distance[i]) // 并且路程更短
            {
                distance[i] = graph->matrix[currentNode][i] + distance[currentNode];
                parent[i] = currentNode;
            }
        }

        // 找到最短路径节点
        int minDistanceNode = -1;
        for (int i = 0; i < graph->nodeCount; ++i)
        {
            if (!visited[i])
            {
                if (minDistanceNode == -1 || distance[i] < distance[minDistanceNode])
                {
                    minDistanceNode = i;
                }
            }
        }

        // 标记节点为已遍历
        visited[minDistanceNode] = true;

        // 从当前节点出发进行下一次循环
        currentNode = minDistanceNode;
    }

    // 输出最短路径结果
    std::cout << "Shortest path:" << std::endl;
    std::cout << endNode << " <- ";
    for (int i = endNode; i != startNode; i = parent[i])
    {
        std::cout << parent[i] << " <- ";
    }
    std::cout << "\b\b\b\b    " << std::endl;
}
