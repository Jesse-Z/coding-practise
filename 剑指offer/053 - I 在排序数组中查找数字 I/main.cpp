/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-18 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        cout<< left_bound(nums, target) <<' '<< right_bound(nums, target);
        return 0;
        // return right_bound(nums, target) - left_bound(nums, target) + 1;
    }
    int left_bound(vector<int> &nums, int target){
        int left=0, right=nums.size();
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]==target)
                right=mid;
            else if(nums[mid]>target)
                right=mid;
        }
        return nums[left]==target?left:-1;
    }
    int right_bound(vector<int> &nums, int target){
        int left=0, right=nums.size();
        while(left<right){
            int mid=left + (right-left)/2;
            if(nums[mid]<target)
                left = mid+1;
            else if(nums[mid]==target)
                left = mid+1;
            else if(nums[mid]>target)
                right = mid;
        }
        return nums[left-1]==target?left-1:-1;  // 右开
    }
};
int main(){
    vector<int> a={5,7,7,8,8,10};
    Solution().search(a, 6);
    return 0;
}