#ifndef A_STAR_H
#define A_STAR_H

#include "../common/graph/graph.h"
#include "../common/result/search_result.h"

typedef double (*Heuristic)(int current_vertex, int goal_vertex);

SearchResult *a_star(const Graph *graph, int start_vertex, int goal_vertex, Heuristic heuristic);

#endif