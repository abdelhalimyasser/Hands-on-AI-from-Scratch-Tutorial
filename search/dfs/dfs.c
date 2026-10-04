#include <stdlib.h>
#include <stdbool.h>

#include "dfs.h"

static bool dfs_visit(
    const Graph *graph,
    int vertex,
    int goal_vertex,
    int current_depth,
    bool *visited,
    int *parent,
    SearchResult *result)
{
    visited[vertex] = true;

    result->order[result->order_count++] = vertex;

    if (current_depth > result->data.dfs.max_depth)
    {
        result->data.dfs.max_depth = current_depth;
    }

    if (vertex == goal_vertex)
    {
        result->found = true;
        return true;
    }

    Edge *edge = graph->adj_list[vertex];
    while (edge != NULL)
    {
        int neighbor = edge->destination;

        if (!visited[neighbor])
        {
            parent[neighbor] = vertex;

            if (
                dfs_visit(
                    graph,
                    neighbor,
                    goal_vertex,
                    current_depth + 1,
                    visited,
                    parent,
                    result))
            {
                return true;
            }
        }

        edge = edge->next;
    }

    return false;
}

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

SearchResult *dfs(const Graph *graph, int start_vertex, int goal_vertex)
{
    if (graph == NULL)
    {
        return NULL;
    }

    if (
        start_vertex < 0 ||
        start_vertex >= graph->vertices_count ||
        goal_vertex < 0 ||
        goal_vertex >= graph->vertices_count)
    {
        return NULL;
    }

    SearchResult *result = search_result_create(SEARCH_DFS, graph->vertices_count);
    if (result == NULL)
    {
        return NULL;
    }

    bool *visited = calloc(graph->vertices_count, sizeof(bool));
    int *parent = malloc(graph->vertices_count * sizeof(int));

    if (
        visited == NULL ||
        parent == NULL)
    {
        free(visited);
        free(parent);

        search_result_destroy(result);

        return NULL;
    }

    for (int i = 0; i < graph->vertices_count; i++)
    {
        parent[i] = -1;
    }

    dfs_visit(
        graph,
        start_vertex,
        goal_vertex,
        0,
        visited,
        parent,
        result);

    if (result->found)
    {
        build_path(result, parent, start_vertex, goal_vertex);
    }

    free(visited);
    free(parent);

    return result;
}