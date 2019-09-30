#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a(m+n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n){
            if (nums1[i] < nums2[j]){
                a[k++] = nums1[i++];
            } else {
                a[k++] = nums2[j++];
            }
        }
        if (i != m){
            while (i < m){
                a[k++] = nums1[i++];
            }
        }
        if (j != n){
            while(j < n){
                a[k++] = nums2[j++];
            }
        }
        k = 0;
        for(i=0; i <= nums1.size(); i++){
            nums1[i] = a[k++];
        }
    }
};

int main(void){
    vector<int> x1 {1, 2, 3, 3, 4, 5, 0, 0, 0, 0, 0, 0};
    vector<int> x2 {3, 4, 5, 6, 7};

    Solution s;
    s.merge(x1, 6, x2, 5);
    int i = 0;
    for(i=0; i<x1.size(); i++){
        printf("%d");
    }
    return 0;
}