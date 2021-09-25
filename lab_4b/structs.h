#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    struct node * left;
    struct node * right;
    unsigned int key;
    char * info;
    int l_ch;
    int r_ch;
} node;

typedef struct tree {
    struct node *root;
    int size; 
    int height;
} tree;