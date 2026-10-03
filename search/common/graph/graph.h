#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct Edge
{
    struct Edge *next;
    double weight;
    int destination;
} Edge;

typedef struct
{
    Edge **adj_list;
    int vertices_count;
    bool directed;
} Graph;

/* Create / Destroy */
Graph *graph_create(int vertices_count, int directed);
void graph_destroy(Graph *graph);

/* Add edges */
void graph_add_edge(Graph *graph, int source, int destination);
void graph_add_weighted_edge(
    Graph *graph,
    int source,
    int destination,
    double weight);

/* Utilities */
void graph_print(const Graph *graph);
int graph_has_edge(
    const Graph *graph,
    int source,
    int destination);

#endif