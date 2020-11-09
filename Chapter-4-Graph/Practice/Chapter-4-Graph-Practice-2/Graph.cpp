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

void Floyd(Graph* graph, int startNode, int endNode)
{
    int distance[MAX_NODE_COUNT][MAX_NODE_COUNT];
    int sequence[MAX_NODE_COUNT][MAX_NODE_COUNT];

    // ��ʼ������
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

    // ִ��ѭ����ÿ���ڵ�k�����·��
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

    // ������·������
    int currentNode = startNode;
    std::cout << startNode << " -> ";
    while (sequence[currentNode][endNode] != endNode)
    {
        std::cout << sequence[currentNode][endNode] << " -> ";
        currentNode = sequence[currentNode][endNode];
    }
    std::cout << endNode << std::endl;
}
