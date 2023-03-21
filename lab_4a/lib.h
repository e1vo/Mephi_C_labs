#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void getint(int *a);
char *getstr();
Node * intz();
void inorder(Node *root);
void free_tree(Node *root);
void print_main_menu(int *choice);
void add_node(Node *root);
Node * smallest_node(Node *root);
Node * delete_node(Node *root, char * key);
void print_inorder(Node *root);
Node * insert_node(Node *root, char *key);
void print_inorder(Node *root);
Node * key_search(Node *root, char *key);
void threaded_print_inorder(Node * root);