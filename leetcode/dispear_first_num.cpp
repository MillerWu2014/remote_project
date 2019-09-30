/*给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 *https://leetcode-cn.com/problems/first-missing-positive/
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()){
            return 1;
        }
        vector<int> temp(nums.size());
        temp = nums;
        int i;
        for (i=0; i<nums.size(); ++i){
            if (nums[i] > 0 && nums[i] <= nums.size()){
                temp[nums[i]-1] = nums[i];
            }
        }
        for (i=0; i<temp.size(); ++i){
            if(temp[i] != (i+1)){
                break;
            }
        }
        return i + 1;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> x(8);
    x[0] = -4;
    x[1] = 3;
    x[2] = 2;
    x[3] = 1;
    x[4] = 4;
    x[5] = 5;
    x[6] = 6;
    x[7] = 7;

    Solution solution;
    int y = solution.firstMissingPositive(x);
    cout << y << endl;
    return 0;
}
