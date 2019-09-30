#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize){
    /*从排序的数组中删除重复项:给定 nums = [0,0,1,1,1,2,2,3,3,4],
     *函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
     *你不需要考虑数组中超出新长度后面的元素。
    **/
    int i, z, k = 1;
    if (numsSize==0){
        return k = 0;
    }
    z = nums[0];
    for (i=0; i<numsSize; i++){
        if (z != nums[i]){
            nums[k++] = nums[i];
            z = nums[i];
        }
    }
    return k;
}

int* plusOne(int* digits, int digitsSize, int* returnSize){
    /*leetcode: plus one:给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
     *最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
     *你可以假设除了整数 0 之外，这个整数不会以零开头。
     *输入: [4,3,2,1]
     *输出: [4,3,2,2]
    **/
    int i = digitsSize - 1;
    int t;
    int * re = malloc(digitsSize*sizeof(int));
    int * ree = malloc((digitsSize+1)*sizeof(int));

    do {
        t = digits[i] + 1;
        // printf("%d\n", t);
        if (t>9){
            t = 0;
            digits[i] = t;
        } else {
            digits[i] = t;
            break;
        }
        i--;
    } while (i>=0);

    if (digits[0] == 0){
        *returnSize = digitsSize + 1;
        int j;
        for (j=1; j<digitsSize+1; j++){
            ree[j] = 0;
        }
        ree[0] = 1;
        return ree;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
    
    return digits;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    /*给定两个数组，编写一个函数来计算它们的交集。输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
     *输出: [4,9]
    **/
    int i = 0, j = 0, k = 0;
    int *a = malloc(nums1Size*sizeof(int));
    if (nums1Size <= nums2Size){
        for (i=0; i<nums1Size; i++){
            for (j=0; j<nums2Size; j++){
                if (nums1[i] == nums2[j]){
                    a[k++] = nums1[i];
                    break;
                }
            }
        }
    } else {
        for (i=0; i<nums2Size; i++){
            for (j=0; j<nums1Size; j++){
                if (nums2[i] == nums1[j]){
                    a[k++] = nums2[i];
                    break;
                }
            }
        }
    }
    *returnSize = k;
    return a;
}

int maxProfit(int* prices, int priceSize) {
    int i, res = 0, n = priceSize;
    for (i = 0; i < n - 1; ++i) {
        if (prices[i] < prices[i + 1]) {
            res += prices[i + 1] - prices[i];
        }
    }
    return res;
}



void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int k =0;
    int j = 0;
    int * array = malloc((m + n)*sizeof(int));
    int i = 0;
    while(i<m && j<n){
        if (nums1[i] < nums2[j]){
            array[k++] = nums1[i++];
        } else {
            array[k++] = nums2[j++];
        }
    }
    // printf("the index of i: %d\n", k);
    if (i != m)
    {
        while(i < m){
            // printf("The index %d curret value: %d\n", k, nums1[i]);
            array[k++] = nums1[i++];
        }
    }
    if (j != n)
    {
        while(j < n){
            array[k++] = nums2[j++];
        }
    }
    i = 0; 
    for(k=0; k < (m+n); k++){
        nums1[i++] = array[k];
    }
    free(array);
}

int rob(int* nums, int numsSize){
    int i, sum = 0, half = 0;
    for (i=0; i < numsSize; i++){
        sum += nums[i];
        if (i % 2 == 0){
            half += nums[i];
        }
    }
    if (half < sum - half){
        return sum - half;
    } else {
        return half;
    }
}


int main(void){
    int x[8] = {1, 3, 3, 5, 6, 0, 0, 0};
    int y[3] = {2, 4, 5};
    int* z = merge(x, 8, 5, y, 3, 3);
    int i;
    for(i=0; i<8; i++){
        printf("%d\n", x[i]);
    }
}