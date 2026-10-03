#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bfs.h"
#include "./common/graph/graph.h"
#include "./common/queue/queue.h"

Graph *bfs(Graph *graph, int start_vertex)
{
    if (graph == NULL)
    {
        return NULL;
    }

    if (
        start_vertex < 0 ||
        start_vertex >= graph->vertices_count)
    {
        return graph;
    }

    bool *visited = calloc(
        graph->vertices_count,
        sizeof(bool));

    if (visited == NULL)
    {
        return graph;
    }

    Queue *queue = queue_create();

    if (queue == NULL)
    {
        free(visited);
        return graph;
    }

    visited[start_vertex] = true;
    queue_enqueue(queue, start_vertex);

    printf("BFS: ");

    while (!queue_is_empty(queue))
    {

        int current_vertex = queue_dequeue(queue);

        printf("%d ", current_vertex);

        Edge *edge = graph->adj_list[current_vertex];

        while (edge != NULL)
        {

            int neighbor = edge->destination;

            if (!visited[neighbor])
            {

                visited[neighbor] = true;

                queue_enqueue(queue, neighbor);
            }

            edge = edge->next;
        }
    }

    printf("\n");

    queue_destroy(queue);
    free(visited);

    return graph;
}