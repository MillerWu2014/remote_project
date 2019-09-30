#include <stdio.h>
#include <stdlib.h>

void get_even(int count, int out[]){
    int i=0;
    for (i=0; i<count; i++){
        out[i] = i * 2;
    }
    return ;
    error:
        printf("");
        free(out);
        exit(1);
}


int main(int argc, char const *argv[])
{
    int n = 10;
    int *p = malloc(n*sizeof(int));
    get_even(n, p);
    printf("%d, %d, %d", p[0], p[1], p[2]);
    free(p);
    return 0;
}
