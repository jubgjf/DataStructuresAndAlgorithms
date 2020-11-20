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
    bool visited[MAX_NODE_COUNT]; // ��¼��i���ڵ��Ƿ���ʹ�
    int distance[MAX_NODE_COUNT]; // ��¼��ʼ�ڵ㵽��i���ڵ����̾���
    int parent[MAX_NODE_COUNT]; // ��¼���·���У���i���ڵ����һ���ڵ�

    // ��ʼ������
    std::fill_n(visited, MAX_NODE_COUNT, false);
    std::fill_n(distance, MAX_NODE_COUNT, INT_MAX / 2);
    std::fill_n(parent, MAX_NODE_COUNT, -1);

    // �޸���ʼ�ڵ�������Ϣ
    visited[startNode] = true;
    distance[startNode] = 0;

    int currentNode = startNode;

    for (int k = 0; k < graph->nodeCount - 1; k++)
    {
        // �������ڽڵ���Ϣ
        for (int i = 0; i < graph->nodeCount; ++i)
        {
            if (graph->matrix[currentNode][i] != INT_MAX / 2 && !visited[i] && // �뵱ǰ�ڵ��ڽӣ���֮ǰδ������
                graph->matrix[currentNode][i] + distance[currentNode] < distance[i]) // ����·�̸���
            {
                distance[i] = graph->matrix[currentNode][i] + distance[currentNode];
                parent[i] = currentNode;
            }
        }

        // �ҵ����·���ڵ�
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

        // ��ǽڵ�Ϊ�ѱ���
        visited[minDistanceNode] = true;

        // �ӵ�ǰ�ڵ����������һ��ѭ��
        currentNode = minDistanceNode;
    }

    // ������·�����
    std::cout << "Shortest path:" << std::endl;
    std::cout << endNode << " <- ";
    for (int i = endNode; i != startNode; i = parent[i])
    {
        std::cout << parent[i] << " <- ";
    }
    std::cout << "\b\b\b\b    " << std::endl;
}
