#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib.h"

FILE *fd;
char fname[] = "file.c";
fd = fopen(fname, "r");
if (fd == NULL) {
    fprintf(stderr, "cant open file");
    return 1;
}


