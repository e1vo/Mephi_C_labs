#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void getint(int *a);
Graph * Create_Graph();
Vertex * create_new_vertex(int number);
void create_edge(Graph * graph, int src, int dest);
void graph_output(Graph * graph);
Graph * add_vertex_into_graph(Graph *graph);
Graph *delete_vertex(Graph * graph, int number);
void CreateMenu(int *choice);
void delete_from_list (Graph * graph, Alist * list, int number);
void remove_edge(Graph * graph, int x, int y);
void free_graph(Graph * graph);
void DFS(Graph * graph, int source, int dest);

Graph * Test_graph(Graph *graph);

