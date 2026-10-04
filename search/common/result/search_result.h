#ifndef SEARCH_RESULT_H
#define SEARCH_RESULT_H

#include <stdbool.h>

typedef enum
{
    SEARCH_BFS,
    SEARCH_DFS,
    SEARCH_UCS,
    SEARCH_A_STAR
} SearchAlgorithm;

typedef struct
{
    int depth;
} BFSResultData;

typedef struct
{
    int max_depth;
} DFSResultData;

typedef struct
{
    double cost;
} UCSResultData;

typedef struct
{
    double cost;
    double heuristic_cost;
} AStarResultData;

typedef union
{
    BFSResultData bfs;
    DFSResultData dfs;
    UCSResultData ucs;
    AStarResultData a_star;
} SearchResultData;

typedef struct
{
    SearchAlgorithm algorithm;
    SearchResultData data;

    int *order;
    int order_count;

    int *path;
    int path_length;

    bool found;

} SearchResult;

SearchResult *search_result_create(SearchAlgorithm algorithm, int max_vertices);

void search_result_destroy(SearchResult *result);

void search_result_print(const SearchResult *result);

const char *search_algorithm_name(SearchAlgorithm algorithm);

#endif