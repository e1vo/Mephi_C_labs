#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    Graph *graph = Create_Graph();
    int choice = -1;
    while(choice != 0) {
        CreateMenu(&choice);
        switch (choice)
        {
        case 1:
            graph = add_vertex_into_graph(graph);
            break;
        
        case 2:
            printf("Between which vertexes I should put edge ? \n");
            int x1,x2;
            printf("First vertex : ");
            getint(&x1); 
            printf("Second vertex : ");
            getint(&x2);
            printf("-----------------------------------\n");
            create_edge(graph, x1, x2);
            break;

        case 3:
            printf("What vertex you want to delete ? \n");
            int number;
            getint(&number);
            delete_from_list(graph,&(graph ->vertex[number]), number);
            break;

        case 4:
            printf("Input first edge point :\n");
            int x,y;
            getint(&x);
            printf("input second edge poing :\n");
            getint(&y);
            remove_edge(graph,x,y);
            break;
        
        case 5:
            printf("Input source: \n");
            int dest,source;
            getint(&source);
            printf("Input destination: \n");
            getint(&dest);
            DFS(graph, source, dest);
            break;

        case 6:
            Test_graph(graph);
            break;

        case 9:
            graph_output(graph);
            printf("-----------------------------------\n");
            break;

        case 0:
            free_graph(graph);
            break;

        default:
            break;
        }
    }
return 0;
}