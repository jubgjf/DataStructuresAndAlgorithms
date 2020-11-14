#include "Graph.h"
#include <iostream>
#include "UnionSet.h"


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

void Prim(Graph* graph)
{
}

void Kruskal(Graph* graph)
{
    // 添加所有边的信息
    Edges* allEdges = new Edges;
    allEdges->lastIndex = -1;

    for (int i = 0; i < graph->nodeCount; ++i)
    {
        for (int j = 0; j < graph->nodeCount; ++j)
        {
            if (graph->matrix[i][j] != INT_MAX / 2) // i和j之间有边
            {
                EdgeInfo edge = {graph->matrix[i][j], i, j};
                allEdges->lastIndex++;
                allEdges->edgeInfo[allEdges->lastIndex] = edge;
            }
        }
    }

    // 对所有边按权值排序
    for (int i = 0; i < allEdges->lastIndex + 1; ++i)
    {
        for (int j = allEdges->lastIndex; j > i; --j)
        {
            if (allEdges->edgeInfo[j].weight < allEdges->edgeInfo[j - 1].weight)
            {
                EdgeInfo tempEdgeInfo = allEdges->edgeInfo[j];
                allEdges->edgeInfo[j] = allEdges->edgeInfo[j - 1];
                allEdges->edgeInfo[j - 1] = tempEdgeInfo;
            }
        }
    }

    // 使用并查集，将每个节点的都设置为根节点
    Pool* pool = InitUnionSetPool(0, 0);
    for (int i = 1; i < graph->nodeCount; ++i)
    {
        AddElement(pool, -1, i);
    }

    // 生成最小生成树
    Edges* minBinaryTreeEdges = new Edges;
    minBinaryTreeEdges->lastIndex = -1;
    for (int i = 0; i < allEdges->lastIndex + 1; ++i)
    {
        // 最小生成树：边数 + 1 = 顶点数，当边足够时直接跳出
        if (minBinaryTreeEdges->lastIndex + 2 >= graph->nodeCount) { break; }

        EdgeInfo currentEdge = allEdges->edgeInfo[i];
        if (FindRoot(pool, currentEdge.node1Index) != FindRoot(pool, currentEdge.node2Index))
        {
            // 合并集合，防止产生圈
            UnionSets(pool, FindRoot(pool, currentEdge.node1Index),
                      FindRoot(pool, currentEdge.node2Index));

            // 将当前的边添加到最小生成树
            minBinaryTreeEdges->lastIndex++;
            minBinaryTreeEdges->edgeInfo[minBinaryTreeEdges->lastIndex] = currentEdge;
        }
    }

    // 输出最小生成树
    for (int i = 0; i < minBinaryTreeEdges->lastIndex + 1; i++)
    {
        std::cout << "weight:\t" << minBinaryTreeEdges->edgeInfo[i].weight;
        std::cout << "\tnode1:\t" << minBinaryTreeEdges->edgeInfo[i].node1Index;
        std::cout << "\tnode2:\t" << minBinaryTreeEdges->edgeInfo[i].node2Index;
        std::cout << std::endl;
    }
}
