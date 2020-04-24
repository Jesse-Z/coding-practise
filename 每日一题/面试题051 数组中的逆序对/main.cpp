/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-24 
 
 brief: 在数组中的两个数字，如果前面一个数字大于后面的数字，
 则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> sorted(nums.size(), 0);
        int ans = 0;
        mergeSort(nums, sorted, 0, nums.size()-1, ans);
        return ans;
    }
    void mergeSort(vector<int> nums, vector<int> &sorted, int left, int right, int &ans){
        if(left>=right)
            return;
        int mid = (left+right)/2;
        mergeSort(nums, sorted, left, mid, ans);
        mergeSort(nums, sorted, mid+1, right, ans);
        // i前半段第一个，j后半段第一个
        int i = left, j = mid+1, sorted_index = left;
        while(i<=mid and j<=right){
            if(nums[i]>nums[j]){
                ans+=mid-i+1;
                sorted[sorted_index++] = nums[j++];
            }else{
                sorted[sorted_index++] = nums[i++];
            }
        }
        if(i<=mid)
            copy(nums.begin()+i, nums.begin()+mid+1, sorted.begin()+sorted_index);
        if(j<=right)
            copy(nums.begin()+j, nums.begin()+right+1, sorted.begin()+sorted_index);
        copy(sorted.begin()+left, sorted.begin()+right+1, nums.begin()+left);
    }
};
int main(){
    vector<int> nums={7,5,6,4};
    cout<<Solution().reversePairs(nums);
    return 0;
}