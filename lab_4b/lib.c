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

char *getstr(){
    char* ptr = (char *)calloc(1,1);
    char buf[129];
    int n =1, len = 0;
    *ptr = '\0';    
    do{
        n = scanf("%128[^\n]", buf);
        if (n<0){
            free(ptr);
            printf("The EOF");
            ptr = NULL;
            continue;
        }

        if (n==0){
            scanf("%*c");
        }

        else {
            len += strlen(buf);
            ptr = (char *)realloc(ptr, len+1);
            strcat(ptr, buf);
        }
    } 
    while (n>0);
    return ptr;
}

node * createNode(unsigned int key,int * sw) {
    node * tmp = malloc(sizeof(node));
    tmp -> key = key;
    *sw = 1;
    tmp -> left = NULL;
    tmp -> right = NULL;
    tmp -> r_ch = tmp -> l_ch = 0;
<<<<<<< HEAD
    //printf("Input info string:");
    //tmp -> info = getstr();
=======
    printf("Input info string:");
    tmp -> info = getstr();
>>>>>>> e4f708d541828778d840a7981dbc7542dd0ecc34

    return tmp;
}

node * search(node *root, unsigned int key) {
    if (root == NULL || root -> key == key) {
        return root;
    }
    if (root -> key < key) {
        return search(root -> right, key);
    }
    return search(root -> left, key);
}

node *insert_node(node *root, unsigned int key) {  
    int sw, balance;
    if (root == NULL) {
        int sw = 0;
        return createNode(key, &sw);
    }

    if (root -> key > key) {
        root -> left = insert_node(root -> left, key);
        if (sw > 0) {root -> l_ch += 1;}
        
    }
    else if (root -> key < key) {
        root -> right = insert_node(root -> right, key);
        if (sw > 0) {root -> r_ch += 1;}
    }

    if(sw > 0) {
    balance = root->l_ch - root -> r_ch;

    if (balance > N && key < root -> left -> key) {
        return right_rotate(root);
    }
    if (balance > N && key > root -> left -> key) {
        root -> left = left_rotate(root -> left);
        return right_rotate(root);
    }

    if (balance < -N && key > root -> right -> key) {
        return left_rotate(root);
    }
    if (balance < -N && key < root -> right -> key) {
        root -> right = right_rotate(root -> right);
        return left_rotate(root);
    }
    }
    return root;   
}

node * right_rotate(node *root) {
    node * tmp1 = root -> left;
    node * tmp2 = tmp1-> right;
    
    tmp1 -> right = root;
    root -> left = tmp2;

    root -> l_ch = tmp1 -> r_ch;
    root -> r_ch = root -> r_ch;
    tmp1 -> r_ch = root -> r_ch + tmp1 -> r_ch + 1;
    tmp1 -> l_ch = tmp1 -> l_ch;

    
    return tmp1;
}

node * left_rotate(node *root) {
    node *tmp1 = root -> right;
    node *tmp2 = tmp1 -> left;  

    tmp1 -> left = root;
    root -> right = tmp2;

    root -> l_ch = root -> l_ch;
    root -> r_ch = tmp1 -> l_ch;
    tmp1 -> r_ch = tmp1 -> r_ch;
    tmp1 -> l_ch = root -> l_ch + tmp1 -> l_ch + 1;
    
    return tmp1;
}

node *find_min_node(node *root) {
    node *current = root;
    while((current -> left) != NULL && current)
        current = current -> left;
    
    return current;
}

node* delete_node(node* root, unsigned int key)
{
   if (root == NULL) {
       return root;
   }

   if (key > root -> key) {
       root -> r_ch -=1;
       root -> right = delete_node(root->right, key);
   }

   else if( key < root -> key) {
       root -> l_ch -=1;
       root -> left = delete_node(root -> left, key);
   }

   else {
       //deleting 0/1 child 
       node *tmp;
       if(root -> left == NULL || root -> right == NULL){
       if (root -> left == NULL && root -> right == NULL) {
           tmp = root;
           free(tmp -> info);
            free(tmp);
            root = NULL;
       }
       else if(root -> left != NULL) {
           *root = *(root -> left);
           free(tmp -> info);
            free(tmp);    
       }
       else if (root -> right != NULL) {
           *root = *(root -> right);
           free(tmp -> info);
            free(tmp);
       }
       }
        else {
            tmp = find_min_node(root -> right);
            root -> key = tmp -> key;
            root -> r_ch -=1;
            root -> right = delete_node(root -> right, tmp -> key);
        }
   }

    if (root == NULL)
      return root;
  
    int balance = root->l_ch - root -> r_ch;

    if (balance > N && root -> left -> l_ch - root -> left -> r_ch >=0) {
        printf("Doing LR in %d", root -> key);
        root -> left = left_rotate(root -> left);
        inorder(root);
        return right_rotate(root);
    }
    if (balance > N && root -> left -> l_ch - root -> left -> r_ch < 0) {
        return right_rotate(root);
    }

    if (balance < -N && root -> right -> l_ch - root -> right -> r_ch > 0) {
        return left_rotate(root);
    }
    if (balance < -N && root -> right -> l_ch - root -> right -> r_ch <= 0) {
        root -> right = right_rotate(root -> right);
        return left_rotate(root);
    }
    return root;
}

node * search_the_biggest(node *root, unsigned int key) {
    while(root -> right != NULL && root -> key < key && root -> right -> key < key) {
        root = root -> right;
    }
    return root;
}

node * free_tree (node * root) {
    if (root == NULL) {
        return 0;
    }
    free_tree(root -> left);
    free_tree(root -> right);

    free(root -> info);
    free(root);
}

node * file_read(node *root) {
    FILE *input_file = fopen("file", "r");
    int key;
    while( fscanf(input_file, "%d", &key) == 1) {
        printf("Just scanned : %d\n", key);
    }
    
}

void inorder(node* root)
{
    if (root != NULL) {
        printf("Key: %u\n", root->key);
        //printf("Info: %s\n", root -> info);
        printf("Left children: %d\n", root -> l_ch);
        printf("Right children: %d\n", root -> r_ch);    
        printf("-----------------------------------\n");  
        inorder(root -> left);  
        inorder(root->right);
    }
}

int D_timing() {
    node *root = NULL;
    int n=10, key[10000],k,cnt = 1000000, i,m;
    clock_t first, last;
    srand(time(NULL));
    while (n-- > 0 ){
    for (int i=0; i< 10000; ++i) {
        key[i] = rand() * rand() % 1000000;
    }
    for (int i=0; i<cnt;) {
        k = rand() * rand() % 1000000;
        if(search(root,k) != NULL){
        root = insert_node(root,k);
        }
        ++i;
        }
    m=0;
    first = clock();
    for (int i=0; i<10000; ++i) {
        if(search(root, key[i]) != NULL){
            ++m;
        }
    }
    last = clock();
    printf("%d items was found\n", m);
    printf("test #%d, number of nodes = %d, time = %d\n", 10 - n, (10 -n)*cnt, last - first);
    }
    free_tree(root);
    return 1;
}

void CreateMenu(int *choice) {    
    printf("Print [1] to insert element into the tree.\n");
    printf("Print [2] to delete element from the tree.\n");
    printf("Print [3] to search for an element from the tree.\n");
    printf("Print [4] to find next value  element from the tree.\n");
    printf("Print [5] if you want to load tree from file ! \n");
    printf("Print [6] for timings ! \n");
    printf("Print [8] to print tree.\n");
    printf("Print [9] to quit.\n");
    printf("-----------------------------------\n");
    printf("Your choice : ");
    getint(choice);
    printf("------------------------------------\n");
}


