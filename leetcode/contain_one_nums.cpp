#include <iostream>

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0){
            return 0;
        }
        int remainder = n % 10;
        int n1 = n / 10;
        int part1 = remainder >= 1 ? n1: n1-1; // 得到21, 31, 41类似的个数.
        if (n1 > 1){
            // 判断
        }
    }
};