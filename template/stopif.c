#include <stdio.h>
#include <stdlib.h>

/*
 * 该部分的代码再c99中支持
 */

char error_mode;
FILE *error_log;

#define Stopif(assertion, error_action, ...){\
    if (assertion){\
        fprintf(error_log? error_log: stderr, __VA_ARGS__);\
        fprintf(error_log? error_log: stderr, "\n");\
        if (error_mode = "s"){\
            abort;\
        } else {\
            error_action;\
        }\
    }\
}

#define forloop(i, loopmax, ...) for (int i=0; i<loopmax; i++)\
    {__VA_ARGS__}

int main(int argc, char *args[]){
    Stopif(x<0 || x>1, return -1, "x has value %g", "but it should be between 0 and 1.", x);

    int sum = 0;
    forloop(i, 
            10, 
            sum += i;
            printf("sum to %i: %i\n", i, sum);

    )
}