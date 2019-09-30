#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int> x;

int main(int argc, char const *argv[])
{
    int i = 0;
    for (i; i<10; ++i){
        x.push_back(i*i);
    }

    vector<int>::iterator p = x.begin();
    p = x.insert(p+2, 100);  // 向p+2的位置上插入值100, 返回p+2的位置并更新p
    x.insert(p, 3, 102);  // 在新p的位置上插入102的值
    for (i=0; i<x.size(); i++){
        cout << x.at(i) << endl;
    }
    
    int *p1 = x.data();
    cout << *(p1+8) << endl;

    int a[4] = {1, 2, 3 ,4};
 
    return 0;
}
