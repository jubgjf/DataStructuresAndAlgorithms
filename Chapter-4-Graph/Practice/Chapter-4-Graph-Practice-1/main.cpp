#include "Graph.h"

int main()
{
    Graph* graph = InitGraph();

    /* Prim */


    /* Kruskal */

    // 0 2 5 7 3 0
    // 2 0 8 0 0 0
    // 5 8 0 1 6 9
    // 7 0 1 0 -1 0
    // 3 0 6 -1 0 4
    // 0 0 9 0 4 0
    Kruskal(graph);
}
