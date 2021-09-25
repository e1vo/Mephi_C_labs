#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getstr(){
    char* ptr = malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do{
        n = scanf("%80[^\n]", buf);
        if (n<0){
            free(ptr);
            ptr = NULL;
            continue;
        }

        if (n==0){
            scanf("%*c");
        }

        else {
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len+1);
            strcat(ptr, buf);
        }
    } while (n>0);
    return ptr;
}

void RemoveExtra_whitespaces(char* start_str, char* final){
    int n;
    int count = 0;
    char* finish_str;
    n = strlen(start_str);
    char prev;
    finish_str = malloc(n);
    prev = start_str[0];
    int index_write=0;
    for (int i = 0; i < n; i++)
    {
        if (start_str[i] != ' ' && start_str[i] != '\t'){
            finish_str[index_write] = start_str[i];
            index_write +=1;
            prev = start_str[i];
        }

        if (start_str[i] == ' ' || start_str[i] == '\t'){
            if (prev != ' ' && prev != '\t'){
                finish_str[index_write] = start_str[i];
                if (finish_str[index_write] == '\t'){
                    finish_str[index_write] = ' ';
                }
                index_write +=1;
                prev = start_str[i];

            }
        }
    }
    
    strcpy(final, finish_str);
    free(finish_str);

}

void TaskFunction(char* start_string){
    char* final;
    final = malloc(80);
    int n, count=0;
    n = strlen(start_string);
    int sw=0;
    if(n%2 == 1){sw = 1;}
    for(int i=0; i<(40-n/2); i++){
        final[i] = '*';
        printf("%c",final[i]);
    }

    for(int i=40-n/2; i<40+n/2;i++){
        if (i==40){printf("|");}
        final[i] = start_string[count];
        count +=1;
        printf("%c", final[i]);
    }


    for(int i=40+n/2; i<80;i++){
        final[i] = '*';
        if(sw==1){
        final[40+n/2] = start_string[n-1];
    }
        printf("%c",final[i]);
    }

    if(sw==1){
        final[40+n/2] = start_string[n-1];
    }
    
    strcpy(start_string, final);
    free(final);
}

int main(){
    char* string;
    char* final;
    int d,n;
    d = 0;
    n = 0;
    
    while ((string=getstr()) != NULL)
    {   
        final = malloc(80);
        n = strlen(string);
        RemoveExtra_whitespaces(string, final);
        TaskFunction(final);
        printf("\n");
        free(final);    
    }
    
    return 0;
}