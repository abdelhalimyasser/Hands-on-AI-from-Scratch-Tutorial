#include <stdio.h>

#include "bfs.h"
#include "../graph/graph.h"


int main(void)
{
    Graph *graph = graph_create(6, false);

    if (graph == NULL) {
        printf("Failed to create graph.\n");
        return 1;
    }


    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);

    graph_add_edge(graph, 1, 3);

    graph_add_edge(graph, 2, 4);

    graph_add_edge(graph, 3, 5);
    graph_add_edge(graph, 4, 5);


    printf("BFS starting from vertex 0:\n");

    bfs(graph, 0);


    graph_destroy(graph);

    return 0;
}