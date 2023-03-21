#include "lib.h"

void getint(int *a) {
    int n=0;
    do
    { n = scanf("%d", a);
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
    } while (n>0);
    return ptr;
}

Node * intz(char *str) {
    Node *root = malloc(sizeof(Node));
    root -> left = NULL;
    root -> right = NULL;
    root -> l_threaded = 0;
    root -> r_threaded = 0;
    root -> key = str;
    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root -> left);
        printf("%s \n", root -> key);
        inorder(root -> right);
    }
}

void free_tree(Node *root) {
    Node *cur = smallest_node(root);
    Node * tmp;
    while (cur != NULL) {
        if (cur -> r_threaded == 1) {
            tmp = cur -> right;
        }
        else {tmp = smallest_node(cur -> right);}
        free(cur -> key);
        //free (cur -> info);
        free(cur);
        cur = tmp;
    }
}

Node * insert_node(Node *root, char * key) {
    Node *parent = NULL;
    Node *tmp;
    while (root != NULL) {
        if (strcmp(root -> key, key) == 0) {
            printf("Key already exists\n");
            return 0;
        }
        else if (strcmp(root->key,key) > 0) {
            parent = root;
            if (root -> l_threaded == 1) {
                break;
            }
            root = root -> left;
        }
        else if (strcmp(root -> key, key) <0){
            parent = root;
            if (root -> r_threaded == 1) {
                break;
            }
            root = root -> right;
        }
    }
    if (strcmp(parent -> key, key) > 0) {
        tmp = intz(key);
        tmp -> right = parent;
        tmp -> left = parent -> left;
        if (tmp -> left != NULL) {tmp -> l_threaded = 1;}
        if (tmp -> right != NULL) {tmp -> r_threaded = 1;}
        parent -> left = tmp;
        parent -> l_threaded = 0;
        return 0;
    }
    else {
        tmp = intz(key);
        tmp -> left = parent;
        tmp -> right = parent -> right;
        if (tmp -> left != NULL) {tmp -> l_threaded = 1;}
        if (tmp -> right != NULL) {tmp -> r_threaded = 1;}
        parent -> right = tmp;
        parent -> r_threaded = 0;
        return 0;}
    
}

Node * prev_inorder(Node *root, char *key) {
    if (root == NULL) {
        printf("Tree is empty! \n");
        return 0;
    }
    Node *current = smallest_node(root);
    Node *parent;
    while(strcmp(current -> key, key) != 0) {
        parent = current;
        if (current -> r_threaded == 1) {
            current = current -> right;
        }
        else {
            current = smallest_node(current -> right);
        }
    }
    return parent;
}

Node *next_inorder(Node *root, char *key) {
    Node *current = prev_inorder(root,key);
    while (strcmp(current -> key, key) <= 0) {
        if (current -> r_threaded == 1) {
            current = current -> right;
        }
        else {
            current = smallest_node(current -> right);
        }
    }
    return current;
}

Node * delete_node(Node *root, char * key) {
    if (root == NULL) {
        printf("Empty tree! \n");
        return 0;
    }
    Node * current = smallest_node(root);
    Node *parent;
    while (strcmp(current -> key, key) != 0) {
        parent = current;
        if (strcmp(current -> key, key) > 0) {
        current = current -> left;
        }
        else if (strcmp(current -> key, key) < 0) {
            current = current -> right;
        }
    }
    
    printf("At point: %s \n", current -> key);
    //deletion of left node leaf
    if (current -> l_threaded == 1 && current -> r_threaded == 1 && strcmp(parent -> key, current -> key)>0) {
        parent -> l_threaded = 1;
        parent -> left = current -> left;
        free(current -> key);
        free(current);
        return 0;
    }

    //deletion of right node leaf
    if (current -> l_threaded == 1 && current -> r_threaded == 1 && strcmp(parent -> key, current -> key)<0) {
        parent -> r_threaded = 1;
        parent -> right = current -> right;
        free(current -> key);
        free(current);
        return 0;        
    }
    
    //deletion of node with 1 side-childs + 2 childs
    Node *prev = prev_inorder(root, key);
    Node *next = next_inorder(root, key);
    if ((current -> l_threaded + current ->r_threaded) == 1) {
        // 1 child from any sidez
        Node * child;
        if (current -> l_threaded == 1) {
            child = current -> right;
        }
        else {child = current -> left;}

        if (current == parent -> left) {
            parent -> left = child;
        }
        else {parent -> right = child;}
        if (current -> l_threaded == 1) {
            next -> left = prev;           
        }
        if (current -> r_threaded == 1) {
            prev -> right = next;   
        }
        free(current -> key);
        free(current);
        return 0;
    }

    // 2 childs
    if (current -> l_threaded == 0 && current -> r_threaded == 0) {
        Node * par_next = current;
        Node * next = current -> right;

        while (next -> left != NULL && next -> l_threaded == 0) {
            par_next = next;
            next = next -> left;
        }
        char *tmp = malloc(sizeof(char) * (strlen(next->key) +1));
        strcpy(tmp,next->key);
        delete_node(root, next -> key);
        free(current -> key);
        current -> key = tmp;
        
    }
}

void print_main_menu(int *choice) {
    printf("Print [1] to add element to binary tree \n");
    printf("Print [2] to delete element from binary tree \n");
    printf("Print [3] to search for element in binary tree \n");
    printf("Print [4] to Print binary tree \n");
    printf("Print [5] to Shut me down \n");
    printf("Make your choice : ");
    getint(choice);
    
    printf("\n");
}

Node * smallest_node(Node *root) {
    if (root == NULL) {
        return NULL;
    }

    while(root -> l_threaded == 0) {
        if (root -> left == NULL) {
            break;
        }
        root = root -> left; 
    }

    return root;
}

void threaded_print_inorder(Node * root) {
    if (root == NULL) {
        printf("Tree is empty !\n");
        return;
    }
    Node * current = smallest_node(root);
    while (current != NULL) {
        printf("%s\n ", current -> key);
        if (current -> r_threaded == 1) {
            current = current -> right;
        }
        else {
            current = smallest_node(current -> right);
        }
    }

}

Node * key_search(Node *root, char *key) {
    if (root == NULL) {
        printf("Tree is empty! \n");
        return NULL;
    }
    Node * current = smallest_node(root);
    while (strcmp(current->key,key) !=0) {
        if (current -> r_threaded == 1) {
            current = current -> right;
        }
        else {
            current = smallest_node(current -> right);
        }
    }
    return current;
}

void print_inorder(Node *root) {
    if (root == NULL)
        return;
    
    Node *smallest = smallest_node(root);
    printf("Smallest node : %s\n", smallest -> key);

    /* first recur on left child */
    print_inorder(root->left);
 
    /* then print the data of node */
    printf("%s ", root->key);

    /* now recur on right child */  
    print_inorder(root->right);

}