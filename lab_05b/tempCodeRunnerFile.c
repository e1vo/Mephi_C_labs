
    int tmp_length;
    //printf("WTF:\n");
    //printf("%s\n", finish_str);
    tmp_length = strlen(finish_str);
    printf("%s\n", finish_str);
    finish_str = realloc(finish_str,tmp_length);
    printf("%s", finish_str);
    //printf("WTF:\n");
    //printf("%s\n", finish_str);
    char* final_str = malloc(tmp_length);
    int tmp_count =0;
    int j=0;
    for(int i=0; i<tmp_length; i++){
        j = i;
        if(finish_str[i] == '('){
            while (finish_str[j-1] != ')')
            {
                final_str[tmp_count] = finish_str[j];
                j +=1;
                tmp_count +=1;
            }

        

        }
        i = j;
    }

    

    n = strlen(final_str);
    final_str = realloc(final_str, n);
    strcpy(start_str, final_str);
    free(finish_str);
    free(final_str);

}

void AddElem(list **head, char *str){
    list *tmp = malloc(sizeof(list));
    tmp -> element = str;
    tmp -> ptr = *head;
    *head = tmp;
}

void PrintList(list *lst)
{
    list* tmp;
    tmp = lst;
    while(tmp!= NULL)
    {
        printf("%s\n", tmp -> element);
        tmp = tmp -> ptr;
    }
}

list* intz(char* s){
    list* tmp;
    tmp = malloc(sizeof(list));
    tmp -> element = s;
    tmp -> ptr = NULL;
    return(tmp);
}

list* GetLastElement(list *lst){
    if(lst == NULL){
        return NULL;
    }
    while(lst -> ptr){
        lst = lst -> ptr;
    }
    return lst;
}

void ListPushback(list* lst,char* str){
    list* last = GetLastElement(lst);
    list* tmp = malloc(sizeof(list));
    tmp -> element = str;
    tmp -> ptr = NULL;
    last -> ptr = tmp;
}

int main(){
    char* str;
    list *head = NULL;
    str = getstr();
    RemoveExtra_whitespaces(str);
    head = intz(str);
    int count = 0;
    while ((str=getstr()) != NULL)
    {
       RemoveExtra_whitespaces(str);
       ListPushback(head, str);

    }

    PrintList(head);
    
    
    return 0;
}