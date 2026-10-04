#ifndef BFS_H
#define BFS_H

#include "../common/graph/graph.h"
#include "../common/result/search_result.h"

SearchResult *bfs(const Graph *graph, int start_vertex, int goal_vertex);

#endif