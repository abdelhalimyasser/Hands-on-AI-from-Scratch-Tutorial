#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

#include "a_star.h"

#include "../common/priority_queue/priority_queue.h"

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

    for (int left = 0, right = result->path_length - 1;
         left < right;
         left++, right--)
    {
        int temp = result->path[left];
        result->path[left] = result->path[right];
        result->path[right] = temp;
    }
}

SearchResult *a_star(const Graph *graph, int start_vertex, int goal_vertex, Heuristic heuristic)
{
    if (graph == NULL || heuristic == NULL)
    {
        return NULL;
    }

    if (start_vertex < 0 || start_vertex >= graph->vertices_count ||
        goal_vertex < 0 || goal_vertex >= graph->vertices_count)
    {
        return NULL;
    }

    SearchResult *result = search_result_create(SEARCH_A_STAR, graph->vertices_count);
    if (result == NULL)
    {
        return NULL;
    }

    double *g_cost = malloc(graph->vertices_count * sizeof(double));
    int *parent = malloc(graph->vertices_count * sizeof(int));
    bool *closed = calloc(graph->vertices_count, sizeof(bool));

    if (g_cost == NULL ||
        parent == NULL ||
        closed == NULL)
    {
        free(g_cost);
        free(parent);
        free(closed);

        search_result_destroy(result);

        return NULL;
    }

    for (int i = 0; i < graph->vertices_count; i++)
    {
        g_cost[i] = DBL_MAX;
        parent[i] = -1;
    }

    PriorityQueue *open = priority_queue_create(graph->vertices_count * graph->vertices_count);
    if (open == NULL)
    {
        free(g_cost);
        free(parent);
        free(closed);

        search_result_destroy(result);

        return NULL;
    }

    g_cost[start_vertex] = 0.0;

    double start_h = heuristic(start_vertex, goal_vertex);

    priority_queue_push(open, start_vertex, start_h);

    while (!priority_queue_is_empty(open))
    {
        int current_vertex;

        double current_priority;

        priority_queue_pop(open, &current_vertex, &current_priority);
        if (closed[current_vertex])
        {
            continue;
        }

        closed[current_vertex] = true;

        result->order[result->order_count++] = current_vertex;
        if (current_vertex == goal_vertex)
        {
            result->found = true;

            result->data.a_star.cost = g_cost[goal_vertex];
            result->data.a_star.heuristic_cost = heuristic(goal_vertex, goal_vertex);

            build_path(result, parent, start_vertex, goal_vertex);

            break;
        }

        Edge *edge = graph->adj_list[current_vertex];
        while (edge != NULL)
        {
            int neighbor = edge->destination;
            if (!closed[neighbor])
            {
                double tentative_g = g_cost[current_vertex] + edge->weight;

                if (tentative_g < g_cost[neighbor])
                {
                    g_cost[neighbor] = tentative_g;
                    parent[neighbor] = current_vertex;

                    double h = heuristic(neighbor, goal_vertex);
                    double f = tentative_g + h;

                    priority_queue_push(open, neighbor, f);
                }
            }

            edge = edge->next;
        }
    }

    priority_queue_destroy(open);
    free(g_cost);
    free(parent);
    free(closed);

    return result;
}