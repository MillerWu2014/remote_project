#include <iostream>
#include <stdio.h>


int add_one(int &x){
    return ++x;
}


int main() {
    int n = 10;
    int y = add_one(n);
    std::cout << "y:" << y << "\nx:" << n << std::endl;
    return 0;
}