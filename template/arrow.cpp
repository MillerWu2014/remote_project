#include <stdio.h>

/*
 *模板函数的使用
 */
template <class NumberType> 
inline NumberType add(NumberType x, NumberType y){
    return x + y;
}

int main(int argc, char const *argv[])
{
    int x = add<int>(1, 2);
    printf("the add return %d!\n", x);
    return 0;
}
