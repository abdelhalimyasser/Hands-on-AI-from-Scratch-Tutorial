#include <stdio.h>

#include "bfs.h"
#include "./common/graph/graph.h"

int main(void)
{
    Graph *graph = graph_create(6, false);

    if (graph == NULL)
    {
        return 1;
    }

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 2, 4);
    graph_add_edge(graph, 3, 5);
    graph_add_edge(graph, 4, 5);

    graph = bfs(graph, 0);

    printf("\nGraph after BFS:\n");
    graph_print(graph);

    graph_destroy(graph);

    return 0;
}