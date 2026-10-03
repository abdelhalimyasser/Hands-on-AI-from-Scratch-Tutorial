#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

static Edge *create_edge(int destination, double weight)
{
    Edge *edge = malloc(sizeof(Edge));

    if (edge == NULL)
    {
        return NULL;
    }

    edge->destination = destination;
    edge->weight = weight;
    edge->next = NULL;

    return edge;
}

Graph *graph_create(int vertices_count, int directed)
{
    if (vertices_count <= 0)
    {
        return NULL;
    }

    Graph *graph = malloc(sizeof(Graph));

    if (graph == NULL)
    {
        return NULL;
    }

    graph->vertices_count = vertices_count;
    graph->directed = directed;

    graph->adj_list = calloc(vertices_count, sizeof(Edge *));

    if (graph->adj_list == NULL)
    {
        free(graph);
        return NULL;
    }

    return graph;
}

void graph_add_weighted_edge(
    Graph *graph,
    int source,
    int destination,
    double weight)
{
    if (graph == NULL)
    {
        return;
    }

    if (
        source < 0 ||
        source >= graph->vertices_count ||
        destination < 0 ||
        destination >= graph->vertices_count)
    {
        return;
    }

    Edge *edge = create_edge(destination, weight);

    if (edge == NULL)
    {
        return;
    }

    edge->next = graph->adj_list[source];
    graph->adj_list[source] = edge;

    if (!graph->directed)
    {
        Edge *reverse_edge = create_edge(source, weight);

        if (reverse_edge == NULL)
        {
            return;
        }

        reverse_edge->next = graph->adj_list[destination];
        graph->adj_list[destination] = reverse_edge;
    }
}

void graph_add_edge(
    Graph *graph,
    int source,
    int destination)
{
    graph_add_weighted_edge(
        graph,
        source,
        destination,
        1.0);
}

int graph_has_edge(
    const Graph *graph,
    int source,
    int destination)
{
    if (graph == NULL)
    {
        return 0;
    }

    if (
        source < 0 ||
        source >= graph->vertices_count ||
        destination < 0 ||
        destination >= graph->vertices_count)
    {
        return 0;
    }

    Edge *current = graph->adj_list[source];

    while (current != NULL)
    {

        if (current->destination == destination)
        {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

void graph_print(const Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    for (int vertex = 0;
         vertex < graph->vertices_count;
         vertex++)
    {

        printf("%d: ", vertex);

        Edge *current = graph->adj_list[vertex];

        while (current != NULL)
        {

            printf(
                "-> %d(%.2f) ",
                current->destination,
                current->weight);

            current = current->next;
        }

        printf("\n");
    }
}

void graph_destroy(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    for (int vertex = 0;
         vertex < graph->vertices_count;
         vertex++)
    {

        Edge *current = graph->adj_list[vertex];

        while (current != NULL)
        {

            Edge *next = current->next;

            free(current);

            current = next;
        }
    }

    free(graph->adj_list);
    free(graph);
}