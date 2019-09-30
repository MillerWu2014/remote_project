#include <math.h>
#include <stdio.h>

double sum_array(double in[]){
    double sum = 0;
    int i;
    for(i=0; !isnan(in[i]); i++){
        sum += in[i];
    }
    return sum;
}

#define sum(...) sum_array((double[]) {__VA_ARGS__, NAN})
#define array(type, name, length) type name[length] = {};

int main(int argc, char *args[]){
    double two_sum_two = sum(2, 2);
    printf("2+2 = %g\n", two_sum_two);
    printf("(2+2)*3 = %g\n", sum(two_sum_two, two_sum_two, two_sum_two));
    printf("sum(asst) = %g\n", sum(3.14159, two_sum_two, 3, 8, 98.4));
    array(char*, test, 10);

    int i=0;
    for (i=0; i<10; i++){
        printf("%c\n", test[i]);
    }
}


