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

EdgeInfo SelectMinWeightEdge(Edges* edges)
{
    EdgeInfo minWeightEdge = edges->edgeInfo[0];
    for (int i = 0; i < edges->lastIndex + 1; ++i)
    {
        if (edges->edgeInfo[i].weight < minWeightEdge.weight)
        {
            minWeightEdge = edges->edgeInfo[i];
        }
    }

    return minWeightEdge;
}

void Prim(Graph* graph, int startIndex)
{
    bool visited[MAX_NODE_COUNT];
    std::fill_n(visited, MAX_NODE_COUNT, false);

    visited[startIndex] = true;

    Edges* minSpanningTreeEdges = InitEdges();

    while (minSpanningTreeEdges->lastIndex + 2 < graph->nodeCount)
    {
        // 找到所有以已选节点i为一个端点的边
        Edges* adjacentEdges = InitEdges();
        for (int i = 0; i < graph->nodeCount; i++)
        {
            if (visited[i])
            {
                // 找所有与节点i相邻的节点j
                for (int j = 0; j < graph->nodeCount; ++j)
                {
                    if (graph->matrix[i][j] != INT_MAX / 2 && !visited[j])
                    {
                        adjacentEdges->lastIndex++;
                        adjacentEdges->edgeInfo[adjacentEdges->lastIndex] =
                            {graph->matrix[i][j], i, j};
                    }
                }
            }
        }

        EdgeInfo minWeightEdge = SelectMinWeightEdge(adjacentEdges);

        minSpanningTreeEdges->lastIndex++;
        minSpanningTreeEdges->edgeInfo[minSpanningTreeEdges->lastIndex] = minWeightEdge;

        visited[minWeightEdge.node1Index] = true;
        visited[minWeightEdge.node2Index] = true;
    }

    PrintMinSpanningTree(minSpanningTreeEdges);
}

Edges* InitEdges()
{
    Edges* edges = new Edges;
    edges->lastIndex = -1;

    return edges;
}

void ConvertMatrixToEdges(Graph* graph, Edges* edges)
{
    for (int i = 0; i < graph->nodeCount; ++i)
    {
        for (int j = 0; j < graph->nodeCount; ++j)
        {
            if (graph->matrix[i][j] != INT_MAX / 2) // i和j之间有边
            {
                EdgeInfo edge = {graph->matrix[i][j], i, j};
                edges->lastIndex++;
                edges->edgeInfo[edges->lastIndex] = edge;
            }
        }
    }
}

void SortEdgesByWeight(Edges* edges)
{
    for (int i = 0; i < edges->lastIndex + 1; ++i)
    {
        for (int j = edges->lastIndex; j > i; --j)
        {
            if (edges->edgeInfo[j].weight < edges->edgeInfo[j - 1].weight)
            {
                EdgeInfo tempEdgeInfo = edges->edgeInfo[j];
                edges->edgeInfo[j] = edges->edgeInfo[j - 1];
                edges->edgeInfo[j - 1] = tempEdgeInfo;
            }
        }
    }
}

void PrintMinSpanningTree(Edges* minSpanningTreeEdges)
{
    for (int i = 0; i < minSpanningTreeEdges->lastIndex + 1; i++)
    {
        std::cout << "weight:\t" << minSpanningTreeEdges->edgeInfo[i].weight;
        std::cout << "\tnode1:\t" << minSpanningTreeEdges->edgeInfo[i].node1Index;
        std::cout << "\tnode2:\t" << minSpanningTreeEdges->edgeInfo[i].node2Index;
        std::cout << std::endl;
    }
}

void Kruskal(Graph* graph)
{
    // 对所有边排序
    Edges* allEdges = InitEdges();
    ConvertMatrixToEdges(graph, allEdges);
    SortEdgesByWeight(allEdges);

    // 使用并查集，将每个节点的都设置为根节点
    Pool* pool = InitUnionSetPool(0, 0);
    for (int i = 1; i < graph->nodeCount; ++i)
    {
        AddElement(pool, -1, i);
    }

    // 生成最小生成树
    Edges* minSpanningTreeEdges = InitEdges();
    for (int i = 0; i < allEdges->lastIndex + 1; ++i)
    {
        // 最小生成树：边数 + 1 = 顶点数，当边足够时直接跳出
        if (minSpanningTreeEdges->lastIndex + 2 >= graph->nodeCount) { break; }

        EdgeInfo currentEdge = allEdges->edgeInfo[i];
        if (FindRoot(pool, currentEdge.node1Index) != FindRoot(pool, currentEdge.node2Index))
        {
            UnionSets(pool, FindRoot(pool, currentEdge.node1Index),
                      FindRoot(pool, currentEdge.node2Index));

            minSpanningTreeEdges->lastIndex++;
            minSpanningTreeEdges->edgeInfo[minSpanningTreeEdges->lastIndex] = currentEdge;
        }
    }

    PrintMinSpanningTree(minSpanningTreeEdges);
}
