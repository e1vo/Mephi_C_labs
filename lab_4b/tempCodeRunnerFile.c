
#include <stdio.h>

int fun(int a, int * b) {
    scanf("%d", &a);
    *b = 5;
    return a;
}

int main()
{
    int a;
    int b;
    a = fun(a,&b);
    printf("%d and %d", a, b);

    return 0;
}