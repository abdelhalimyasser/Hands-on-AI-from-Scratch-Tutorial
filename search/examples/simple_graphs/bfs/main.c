#include <stdio.h>

#include "../../../bfs/bfs.h"
#include "../../../common/graph/graph.h"
#include "../../../common/result/search_result.h"

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

    printf("Graph:\n");
    graph_print(graph);
    printf("\n");

    SearchResult *result = bfs(graph, 0, 5);
    if (result == NULL)
    {
        printf("BFS failed.\n");
        graph_destroy(graph);
        return 1;
    }

    search_result_print(result);
    search_result_destroy(result);
    graph_destroy(graph);

    return 0;
}