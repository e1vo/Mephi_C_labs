#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "structs.h"
#define N 1

void getint(int *a);
char *getstr();
node * createNode(unsigned int key, int * sw);
node *insert_node(node *root, unsigned int key);
int findDepth(node* root, int key);
void inorder(node* root);
void CreateMenu(int *choice);
int max(int a, int b);
node * right_rotate(node *root);
node * left_rotate(node *root);
node * search(node *root, unsigned int key);
node *find_min_node(node *root);
node *delete_node(node *root, unsigned int key);
node * search_the_biggest(node *root,unsigned int key);
node * free_tree(node * root);
node * file_read(node *root);
int D_timing();



