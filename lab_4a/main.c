#include "lib.h"

int main() {
    Node *root = NULL;
    int menu_choice=0;

    do {
        print_main_menu(&menu_choice);
        switch (menu_choice)
        {
        case 1:
            printf("Input key, which you want to have in new Node : ");
            char *key = getstr();
            if (root == NULL) {
                root = intz(key);
                break;
            }
            insert_node(root, key);
            
            break;

        case 2:
            printf("Input deletion key: ");
            key = getstr();
            delete_node(root, key);
            free(key);
            break;

        case 3:
            printf("Input search key: ");
            key = getstr();
            Node *tmp = key_search(root, key);
            free(key);
            if (tmp == NULL) {
                printf("Not included ! \n");
                break;
            }
            printf("Found!\n");
            break;

        case 4:
            threaded_print_inorder(root);
            break;


        case 5:
            printf("\nYou want me dead.");
            free_tree(root);
            break;

        default:
            printf("Really strange. \n");
        }
    } while (menu_choice != 5);
    
   return 0;
}