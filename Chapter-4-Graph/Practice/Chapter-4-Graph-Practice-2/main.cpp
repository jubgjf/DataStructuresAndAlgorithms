#include "header.h"

int main()
{
    Graph* graph = InitGraph();

    // bilibili�̳�����
    // 9
    // 0 4 0 0 0 0 0 8 0
    // 4 0 8 0 0 0 0 3 0
    // 0 8 0 7 0 4 0 0 2
    // 0 0 7 0 9 14 0 0 0
    // 0 0 0 9 0 10 0 0 0
    // 0 0 4 14 10 0 2 0 0
    // 0 0 0 0 0 2 0 6 6
    // 8 3 0 0 0 0 6 0 1
    // 0 0 2 0 0 0 6 1 0

    Dijkstra(graph, 0, 4);
    Floyd(graph, 0, 4);
}
