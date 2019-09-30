/*给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 *找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 *https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/submissions/
*/
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i;
        for (i=0; i<nums.size(); i++){
            int index = abs(nums[i]) -1;
            nums[index] = -abs(nums[index]);
        }
        vector<int> res;
        for (i=0; i<nums.size(); i++){
            if (nums[i]>0){
                res.push_back(i+1);
            };
        }
        return res;
    }
};


int main(void){
    // [4,3,2,7,8,2,3,1]
    vector<int> x(8);
    x[0] = 4;
    x[1] = 3;
    x[2] = 2;
    x[3] = 7;
    x[4] = 8;
    x[5] = 2;
    x[6] = 3;
    x[7] = 1;
    Solution solution;
    vector<int> r;
    r = solution.findDisappearedNumbers(x);
    int n = 0;
    for (n=0; n<r.size(); n++){
        cout << r[n] << endl;
    }
}