#include <stdio.h>
#include <stdlib.h>

#include "search_result.h"

SearchResult *search_result_create(SearchAlgorithm algorithm, int max_vertices)
{
    if (max_vertices <= 0)
    {
        return NULL;
    }

    SearchResult *result = malloc(sizeof(SearchResult));
    if (result == NULL)
    {
        return NULL;
    }

    result->order = malloc(max_vertices* sizeof(int));
    if (result->order == NULL)
    {
        free(result);
        return NULL;
    }

    result->path = malloc(max_vertices* sizeof(int));
    if (result->path == NULL)
    {
        free(result->order);
        free(result);

        return NULL;
    }

    result->algorithm = algorithm;
    result->order_count = 0;
    result->path_length = 0;
    result->found = false;

    switch (algorithm)
    {

    case SEARCH_BFS:
        result->data.bfs.depth = 0;
        break;

    case SEARCH_DFS:
        result->data.dfs.max_depth = 0;
        break;

    case SEARCH_UCS:
        result->data.ucs.cost = 0.0;
        break;

    case SEARCH_A_STAR:
        result->data.a_star.cost = 0.0;
        result->data.a_star.heuristic_cost = 0.0;
        break;
    }

    return result;
}

void search_result_destroy(SearchResult *result)
{
    if (result == NULL)
    {
        return;
    }

    free(result->order);
    free(result->path);
    free(result);
}

const char *search_algorithm_name(SearchAlgorithm algorithm)
{
    switch (algorithm)
    {

    case SEARCH_BFS:
        return "BFS";

    case SEARCH_DFS:
        return "DFS";

    case SEARCH_UCS:
        return "UCS";

    case SEARCH_A_STAR:
        return "A*";

    default:
        return "Unknown";
    }
}

void search_result_print(const SearchResult *result)
{
    if (result == NULL)
    {
        return;
    }

    printf("Algorithm: %s\n", search_algorithm_name(result->algorithm));
    printf("Found: %s\n", result->found ? "true" : "false");
    printf("Visit order: ");

    for (int i = 0; i < result->order_count; i++)
    {
        printf("%d ", result->order[i]);
    }

    printf("\n");

    printf("Path: ");
    for (int i = 0; i < result->path_length; i++)
    {
        printf("%d ", result->path[i]);
    }

    printf("\n");

    switch (result->algorithm)
    {

    case SEARCH_BFS:

        printf("Depth: %d\n", result->data.bfs.depth);
        break;

    case SEARCH_DFS:

        printf("Max depth: %d\n", result->data.dfs.max_depth);
        break;

    case SEARCH_UCS:

        printf("Cost: %.2f\n", result->data.ucs.cost);
        break;

    case SEARCH_A_STAR:

        printf("Cost: %.2f\n", result->data.a_star.cost);
        printf("Heuristic cost: %.2f\n", result->data.a_star.heuristic_cost);

        break;
    }
}