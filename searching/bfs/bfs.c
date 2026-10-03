#include <stdio.h>
#include <stdlib.h>

#include "bfs.h"
#include "queue/queue.h"

void bfs(const Graph *graph, int start_vertex)
{
    if (graph == NULL)
    {
        return;
    }

    if (
        start_vertex < 0 ||
        start_vertex >= graph->vertices_count)
    {
        return;
    }

    bool *visited = calloc(graph->vertices_count, sizeof(bool));

    if (visited == NULL)
    {
        return;
    }

    Queue *queue = queue_create();

    if (queue == NULL)
    {
        free(visited);
        return;
    }

    visited[start_vertex] = true;

    queue_enqueue(queue, start_vertex);

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
}