#ifndef DFS_H
#define DFS_H

#include "../common/graph/graph.h"
#include "../common/result/search_result.h"

SearchResult *dfs(const Graph *graph, int start_vertex, int goal_vertex);

#endif