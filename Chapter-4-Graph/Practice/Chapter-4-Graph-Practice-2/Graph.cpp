#include <iostream>
#include "header.h"

Graph* InitGraph()
{
    Graph* graph = new Graph;

    std::cout << "Input node count: ";
    std::cin >> graph->nodeCount;

    std::cout << "Input graph matrix:('0' for INF)" << std::endl;
    for (int i = 0; i < graph->nodeCount; ++i)
    {
        for (int j = 0; j < graph->nodeCount; ++j)
        {
            std::cin >> graph->matrix[i][j];
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

void Floyd(Graph* graph, int startNode, int endNode)
{
    int distance[MAX_NODE_COUNT][MAX_NODE_COUNT];
    int sequence[MAX_NODE_COUNT][MAX_NODE_COUNT];

    // 初始化数组
    for (int i = 0; i < graph->nodeCount; ++i)
    {
        for (int j = 0; j < graph->nodeCount; ++j)
        {
            distance[i][j] = graph->matrix[i][j];
        }
    }
    for (int i = 0; i < graph->nodeCount; ++i)
    {
        for (int j = 0; j < graph->nodeCount; ++j)
        {
            if (i == j)
            {
                sequence[i][j] = INT_MAX / 2;
                continue;
            }
            sequence[i][j] = j;
        }
    }

    // 执行循环求每个节点k的最短路径
    for (int k = 0; k < graph->nodeCount; ++k)
    {
        for (int i = 0; i < graph->nodeCount; ++i)
        {
            for (int j = 0; j < graph->nodeCount; ++j)
            {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    sequence[i][j] = sequence[i][k];
                }
            }
        }
    }

    // 输出最短路径长度
    int currentNode = startNode;
    std::cout << startNode << " -> ";
    while (sequence[currentNode][endNode] != endNode)
    {
        std::cout << sequence[currentNode][endNode] << " -> ";
        currentNode = sequence[currentNode][endNode];
    }
    std::cout << endNode << std::endl;
}
