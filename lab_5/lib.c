#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"
#include "structs.h"

void getint(int *a){
    int n=0;
    do
    { n = scanf("%u", a);
    if ( n<=0){
        printf("Input error. Try again:");
        scanf("%*[^\n]");
    }
    } while (n == 0 );
    scanf("%*c");
}

Graph * Create_Graph() {
    Graph * graph = (Graph*) malloc(sizeof(Graph));
    graph -> size = 0;
    graph -> vertex = (Alist*) malloc(sizeof(Alist));
    graph -> vertex -> head = NULL;
    return graph;
}


Graph * add_vertex_into_graph(Graph *graph) {
    int number = graph -> size;
    Vertex * vertex = create_new_vertex(number);
    graph -> list[graph -> size] = vertex;
    graph -> size +=1;
    graph -> vertex[number].head = NULL;
    return graph;
}

Vertex * create_new_vertex(int number) {
    Vertex * vertex = (Vertex*) malloc(sizeof(Vertex));
    //vertex -> x = x;
    //vertex -> y = y;
    vertex -> visited = 0;
    vertex -> number = number;
    vertex -> next = NULL;
    return vertex;
}

void create_edge(Graph * graph, int src, int dest) {   

    if(src > graph ->size || dest > graph -> size) {
        printf("does not exist!");
        return;
    }

    Vertex * tmp_vertex = create_new_vertex(src);
    tmp_vertex -> next = graph -> vertex[dest].head;
    graph -> vertex[dest].head = tmp_vertex;

    tmp_vertex = create_new_vertex(dest);
    tmp_vertex -> next = graph -> vertex[src].head;
    graph -> vertex[src].head = tmp_vertex;

}

void list_deletion(Graph *graph, Alist list, int number) {
    
}

void delete_from_list (Graph * graph, Alist * list, int number) {
    Vertex * tmp_v = list -> head;
    while(tmp_v != NULL){
    Vertex *tmp = graph -> vertex[tmp_v->number].head; 
    if(tmp -> number == number) {
        graph -> vertex[tmp_v->number].head = tmp -> next;
        tmp_v = tmp_v -> next;
        continue;
    }
    while(tmp != NULL) {
        if (tmp -> next -> number == number) {
            tmp -> next = tmp -> next -> next;
            break;
        }
        tmp = tmp -> next;
    }
    tmp_v = tmp_v -> next;
    }
    graph -> vertex[number].head = NULL;
}

void remove_edge(Graph * graph, int x, int y) {
    Vertex *tmp = graph ->vertex[x].head;
    if (tmp -> number == y) {
        graph -> vertex[x].head = tmp -> next;
    }
    else {while (tmp != NULL) {
        if (tmp -> next -> number == y) {
            tmp -> next = tmp -> next -> next;
            break;
        }
        tmp = tmp -> next;
    }}

    tmp = graph ->vertex[y].head;
    if (tmp -> number == x) {
        graph -> vertex[y].head = tmp -> next;
        return;
    }
    else{while (tmp != NULL) {
        if (tmp -> next -> number == x) {
            tmp -> next = tmp -> next -> next;
            break;
        }
        tmp = tmp -> next;
    }}
}

void graph_output(Graph * graph) {
    int size = graph -> size;
    Vertex * tmp;
    for (int i=0; i<size; i++) {
        tmp = graph -> vertex[i].head;
        printf("[vertex: %d]", i);
        while(tmp) {
            printf(" -> %d ", tmp -> number);
            tmp = tmp -> next;
        }        printf("\n");
    }
}

void free_graph(Graph * graph) {
    for(int i=0; i<graph -> size; i++) {
        free(graph -> vertex[i].head);
    }
    free(graph);
}



void init(Queue * q) {
    q -> first = 1;
    q -> last = 0;
    return ;
}


int Queue_empty(Queue *q) {
    if (q->last < q -> first) return 1;
    else return 0;
}

int Edge_empty(Edge *e) {
    if (e->last < e -> begin) return 1;
    else return 0;
}

void q_insert(Queue *q, int x) {
    if (q->last < 100) {
        q -> last +=1;
        q -> qu[q->last] = x;
    }
    else {
        printf("Error ! \n");
    }
    return;
}

int q_out(Queue *q) {
    if (Queue_empty(q)==1){
        printf("Empty! \n");
        return 0;
    }
    int x = q -> qu[q -> first];
    for (int i = q -> first; i < q -> last; i++) {
        q -> qu[i] = q -> qu[i+1];
    }
    q -> last --;
    return x;
}

int e_out(Edge *e) {
    if (Edge_empty(e)==1){
        printf("Empty! \n");
        return 0;
    }
    int x = e -> vertex[e -> begin];
    for (int i = e -> begin; i < e -> last; i++) {
        e -> vertex[i] = e -> vertex[i+1];
    }
    e -> last --;
    return x;
}

void e_init(Edge *e) {
    e -> begin = 1;
    e -> last = 0; 
}

void e_push(Edge *e, int x) {
    if (e -> last < 100) {
        e -> vertex[++]
    }
    else {
        printf("Error ! \n");
    }
    return;
}


void DFS(Graph * graph, int source, int dest) {
    Edge * e = (Edge*) malloc(sizeof(Edge));
    Queue * q = (Queue*) malloc(sizeof(Queue));
    init(q);
    e_init(e);
    q_insert(q,source);
    while(!Queue_empty(q)) {
        int vert = q_out(q);
        if(graph ->list[vert]->visited == 2) continue;
        graph -> list[vert] -> visited = 2;
        Vertex * tmp = graph -> vertex[vert].head;
        while(tmp != NULL) {
            if (tmp -> visited != 2) {
                q_insert(q,tmp -> number);
                tmp -> visited = 1;
                e_insert(e, vert);
                if(vert == dest) break;
            }
            tmp = tmp -> next;
        }
    }
    while (!Edge_empty(e)) {
        int t = e_out(e);
        if (t == dest)
    }
    
}




Graph * Test_graph(Graph *graph) {
    for(int i=0;i < 7; i++) {
        graph = add_vertex_into_graph(graph);
    }
    create_edge(graph,0,1);
    create_edge(graph,1,2);
    create_edge(graph,0,2);
    create_edge(graph,0,6);
    create_edge(graph,1,3);
    create_edge(graph,3,4);
    create_edge(graph,4,5);
    create_edge(graph,5,6);         
}

void CreateMenu(int *choice) {    
    printf("Print [1] to create new vertex!\n");
    printf("Print [2] to create edge between 2 existing vertexes!\n");
    printf("Print [3] to delete vertex ! \n");
    printf("Print [4] to remove edge !\n");
    printf("Print [5] for depth search ! \n");
    printf("Print [9] to output graph as list of adj !\n");
    printf("Print [0] to quit program ! \n");
    printf("-----------------------------------\n");
    printf("Your choice : ");
    getint(choice);
    printf("------------------------------------\n");
}