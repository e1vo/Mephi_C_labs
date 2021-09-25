#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct list
{
    char element;
    struct list *ptr;
} list;

list* inz(char* str)
{
    list *tmp;
    tmp = malloc(sizeof(list));
    tmp -> element = *str;
    tmp -> ptr = NULL;
    return(tmp);
}

list* get_last_list(list *lst)
{
    if (lst == NULL)
    {
        return NULL;
    }

    while (lst -> ptr){
        lst = lst -> ptr;
    }

    return lst;
}

list* add_element(list *lst, char a)
{
    list *tmp = malloc(sizeof(list));
    list *last = get_last_list(lst);
    tmp -> element = a;
    tmp -> ptr = NULL;
    (last -> ptr) = tmp;
}

list* freelist(list* root)
{
    list *tmp;
    while(root -> ptr != NULL)
    {
        tmp = root -> ptr;
        free(root);
        root = tmp;
    }

    free(root);
}

char *getstr(){
    char* ptr = malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';    
    do{
        n = scanf("%80[^\n]", buf);
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
            ptr = realloc(ptr, len+1);
            strcat(ptr, buf);
        }
    } while (n>0);
    return ptr;
}

list* delete_root(list* lst)
{
    list* tmp;
    tmp = lst -> ptr;
    free(lst);
    return(tmp);
}

list* fill(char *str)
{
    list *tmp = NULL;
    list *tmp1 = NULL;
    tmp = inz(str);
    str++;
    tmp1 = tmp;
    for(; *str != '\0'; ++str)
    {
        tmp = add_element(tmp, *str);
    }
    tmp = add_element(tmp, ' ');
    tmp = tmp1;
    return tmp;
}

void print_list(list *lst)
{
    list *tmp;
    list *tmp1;
    if (lst -> element != '(')
    {
        tmp1 = lst -> ptr;
        lst = tmp1;

    }
    tmp = lst;
    do {
        printf("%c", tmp -> element);
        tmp = tmp -> ptr;
    } while (tmp != NULL);
}

void remove_extra_spaces(list *root)
{
    list *tmp;
    while(root -> ptr != NULL){
        tmp = root -> ptr;
        if(root -> element == ' ' || root -> element == '\t'){
            root -> element = ' ';
            if (tmp -> element == ' ' || tmp -> element == '\t'){
                root -> ptr = tmp -> ptr;
                free(tmp);
                continue;
            }
        } 

        root = root -> ptr;   
    }
}

void words_in_brackets(list* root)
{
    list *tmp;
    list *tmp1;
    list *tmp2;
    tmp = root;
    int left_bracket = 0;
    while(tmp -> ptr != NULL)
    {
        if(tmp -> element == '(')
        {
            left_bracket = 1;
        }

        tmp1 = tmp -> ptr;
        if ((tmp1 -> element != '(' && !(left_bracket)))
        {
            tmp -> ptr = tmp1 -> ptr;
            free(tmp1);
            continue;
        }

        left_bracket = 1;

        if(tmp1 -> element == ')' || tmp1 -> element == '\n')
        {
            left_bracket = 0;
        }

        tmp = tmp -> ptr;
    }
}

int main()
{
    char* ch = 0;
    list* head = 0;
    printf("Enter string:");
    while((ch = getstr()) != NULL)
    {
        head = 0;
        head = fill(ch);
        printf("Task string:");
        remove_extra_spaces(head);
        words_in_brackets(head);
        print_list(head);
        free(ch);
        freelist(head);
        printf("\n");
        printf("Enter string:");
    }
    return 0;
}
