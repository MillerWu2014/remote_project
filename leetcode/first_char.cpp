/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *https://leetcode-cn.com/problems/single-number/comments/
**/
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==0){
            cout << "The vector is empty!" << endl;
            return 0;
        }
        map<int, int> num_count;
        int i;
        for(i=0; i<nums.size(); i++){
            int v = nums[i];
            int count = 0 ;
            if (num_count.find(v) != num_count.end()){
                count = num_count[v];
                count = count + 1;
                num_count[v] = count;
            } else {
                num_count[v] = 1;
            }
        }
        map<int, int>::iterator iter;
        for (iter=num_count.begin(); iter != num_count.end(); iter++){
            if (iter->second == 1){
                return iter->first;
            } 
        }
    }

    int singleNumber1(vector<int>& nums) {
        /*使用异或：
         *1.交换律：a ^ b ^ c <=> a ^ c ^ b
         *2.任何数于0异或为任何数 0 ^ n => n
         *3.相同的数异或为0: n ^ n => 0
         **/
        int len = nums.size();
        int result = 0;
        for(int i=0; i<len; i++){
            result ^= nums[i];
        } 
        return result;
 }
};

int main(void){
    vector<int> numbers(7);
    Solution s;
    numbers[0] = 4;
    numbers[1] = 1;
    numbers[2] = 1;
    numbers[3] = 2;
    numbers[4] = 2;
    numbers[5] = 3;
    numbers[6] = 3;
    cout << "The first value: " << numbers.at(5) << endl;
    
    int x = s.singleNumber1(numbers);
    cout << x << endl;
}
