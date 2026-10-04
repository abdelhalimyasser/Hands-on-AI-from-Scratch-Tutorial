#include <stdlib.h>
#include <stdbool.h>

#include "bfs.h"
#include "../common/queue/queue.h"

static void build_path(SearchResult *result, const int *parent, int start_vertex, int goal_vertex)
{
    int current = goal_vertex;

    while (current != -1)
    {
        result->path[result->path_length++] = current;
        if (current == start_vertex)
        {
            break;
        }

        current = parent[current];
    }

    for (int left = 0, right = result->path_length - 1; left < right; left++, right--)
    {
        int temp = result->path[left];

        result->path[left] = result->path[right];
        result->path[right] = temp;
    }
}

SearchResult *bfs(const Graph *graph, int start_vertex, int goal_vertex)
{
    if (graph == NULL)
    {
        return NULL;
    }

    if (start_vertex < 0 || start_vertex >= graph->vertices_count || goal_vertex < 0 || goal_vertex >= graph->vertices_count)
    {
        return NULL;
    }

    SearchResult *result = search_result_create(SEARCH_BFS, graph->vertices_count);
    if (result == NULL)
    {
        return NULL;
    }

    bool *visited = calloc(graph->vertices_count, sizeof(bool));
    int *parent = malloc(graph->vertices_count * sizeof(int));
    int *depth = malloc(graph->vertices_count * sizeof(int));

    if (visited == NULL ||
        parent == NULL ||
        depth == NULL)
    {
        free(visited);
        free(parent);
        free(depth);

        search_result_destroy(result);

        return NULL;
    }

    for (int i = 0; i < graph->vertices_count; i++)
    {
        parent[i] = -1;
        depth[i] = -1;
    }

    Queue *queue = queue_create();
    if (queue == NULL)
    {
        free(visited);
        free(parent);
        free(depth);

        search_result_destroy(result);

        return NULL;
    }

    visited[start_vertex] = true;
    depth[start_vertex] = 0;

    queue_enqueue(queue, start_vertex);

    while (!queue_is_empty(queue))
    {
        int current_vertex = queue_dequeue(queue);

        result->order[result->order_count++] = current_vertex;

        if (current_vertex == goal_vertex)
        {
            result->found = true;
            result->data.bfs.depth = depth[current_vertex];

            build_path(result, parent, start_vertex, goal_vertex);

            break;
        }

        Edge *edge = graph->adj_list[current_vertex];
        while (edge != NULL)
        {
            int neighbor = edge->destination;
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current_vertex;
                depth[neighbor] = depth[current_vertex] + 1;

                queue_enqueue(queue, neighbor);
            }

            edge = edge->next;
        }
    }

    queue_destroy(queue);

    free(visited);
    free(parent);
    free(depth);

    return result;
}