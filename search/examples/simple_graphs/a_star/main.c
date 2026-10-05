#include <stdio.h>

#include "../../../a_star/a_star.h"
#include "../../../common/graph/graph.h"
#include "../../../common/result/search_result.h"

static double heuristic(int current_vertex, int goal_vertex)
{
    (void)goal_vertex;
    double values[] = {7.0, 6.0, 4.0, 3.0, 1.0, 0.0};
    return values[current_vertex];
}

int main(void)
{
    Graph *graph = graph_create(6, false);
    if (graph == NULL)
    {
        printf("Failed to create graph.\n");
        return 1;
    }

    graph_add_weighted_edge(graph, 0, 1, 2.0);
    graph_add_weighted_edge(graph, 0, 2, 4.0);
    graph_add_weighted_edge(graph, 1, 3, 5.0);
    graph_add_weighted_edge(graph, 2, 4, 2.0);
    graph_add_weighted_edge(graph, 3, 5, 3.0);
    graph_add_weighted_edge(graph, 4, 5, 1.0);

    printf("Graph:\n");
    graph_print(graph);
    printf("\n");

    SearchResult *result = a_star(graph, 0, 5, heuristic);
    if (result == NULL)
    {
        printf("A* failed.\n");
        graph_destroy(graph);
        return 1;
    }

    search_result_print(result);
    search_result_destroy(result);
    graph_destroy(graph);

    return 0;
}