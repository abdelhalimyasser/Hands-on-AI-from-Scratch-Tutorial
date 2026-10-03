#include <stdio.h>

#include "graph.h"

int main(void)
{
    Graph *graph = graph_create(6, false);

    if (graph == NULL)
    {
        printf("Failed to create graph.\n");
        return 1;
    }

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);

    graph_add_edge(graph, 1, 3);

    graph_add_edge(graph, 2, 4);

    graph_add_edge(graph, 3, 5);
    graph_add_edge(graph, 4, 5);

    printf("Graph:\n\n");

    graph_print(graph);

    printf("\nEdge tests:\n");

    printf(
        "0 -> 1: %s\n",
        graph_has_edge(graph, 0, 1)
            ? "exists"
            : "does not exist");

    printf(
        "1 -> 0: %s\n",
        graph_has_edge(graph, 1, 0)
            ? "exists"
            : "does not exist");

    printf(
        "0 -> 5: %s\n",
        graph_has_edge(graph, 0, 5)
            ? "exists"
            : "does not exist");

    graph_destroy(graph);

    return 0;
}