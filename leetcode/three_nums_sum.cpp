#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > out;
        int i = 0, j = 0, k = 0;
        for (i=0; i<nums.size(); i++){
            for (j=i+1; j<nums.size(); j++){
                for (k=j+1; k<nums.size(); k++){
                    if ((nums[i]+nums[j]+nums[k]) == 0){
                        out.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return out;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> a(6);
    int _a[6] = {-1, 0, 1, 2, -1, -4};
    int i = 0;
    for (i=0; i<6; i++){
        a[i] = _a[i];
    }

    Solution so;
    vector<vector<int> > z;
    z = so.threeSum(a);
    cout << "------------------------------" << endl;
    int m = 0;
    vector<vector<int> >::iterator iter;
    for (iter=z.begin(); iter!=z.end(); iter++){
        vector<int> d;
        d = *iter;
        int v = 0;
        vector<int>::iterator it;
        for(it=d.begin(); it != d.end(); it++){
            cout << *it << endl;
        }
        cout << "+++++++++++++++++" << endl;
    }
    return 0;
}
