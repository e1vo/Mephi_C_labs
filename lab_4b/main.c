#include <stdio.h>
#include "lib.h"

int main() {
    tree * GSTree;
    node * root = NULL;
    node *tmp = NULL;
    int key;
    int menu_choice = -1;
    printf("-----------------------------------\n");
    while(menu_choice != 9) {
        CreateMenu(&menu_choice);
        switch (menu_choice)
        {
        case 1:
            printf("Input key: ");
            getint(&key);
            if(root != NULL && search(root,key) != NULL) {
                printf("Already exists !\n");
                printf("-----------------------------------\n");
                break;
            }
            root = insert_node(root, key);
            printf("-----------------------------------\n");
            break;

        case 2:
            printf("Input key you want to delete: ");
            getint(&key);
            root = delete_node(root, key);
            break;

        case 3: 
            printf("Enter key you want to search:");
            getint(&key);
            tmp = search(root, key);
            
            if (tmp == NULL) {
                printf("Key is not included! \n");
            }
            else {printf("Found!\n");}
            printf("-----------------------------------\n");
        break;

        case 4:
            printf("Enter key you want to search:");
            getint(&key);
            tmp = search_the_biggest(root, key);
            printf("Key you was searching is : %d \n", tmp -> key);
            printf("-----------------------------------\n");
            break;
        
        case 5:
            file_read(root);

<<<<<<< HEAD
        case 6:
            D_timing();
            break;

=======
>>>>>>> e4f708d541828778d840a7981dbc7542dd0ecc34
        case 8:
            inorder(root);
            break;

        case 9:
            free_tree(root);
            break;
        
        default:
            printf("Heh \n");
            break;
        }
    }
    return 0;
}