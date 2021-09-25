#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Vertex {
    struct Vertex * next;
    int x;
    int visited;
    int y;
    int number;
} Vertex;

typedef struct Alist {
    Vertex * head;
} Alist;

typedef struct Graph {
    int size;
    Vertex * list[100];
    Alist * vertex;
} Graph;

typedef struct Queue {
    int qu[100];
    int first;
    int last;
} Queue;

typedef struct edge {
    int vertex[100];
    int begin;
    int last;
} Edge;