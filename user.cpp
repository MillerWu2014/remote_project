#include <iostream>
#include "stock/stock10.h"

int main(){
    {
        using std::cout;
        Stock stock1 = Stock("NanoSmart", 12, 20.0);
        stock1.show();

        Stock stock2 = Stock("Google", 20, 28.7);
        stock2.show();

        cout << "\n";
        Stock tmp = stock1.topval(stock2);
        tmp.show();
    }
    return 0;
}