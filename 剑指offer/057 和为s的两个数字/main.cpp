/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-20 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 双指针
        int left=0, right=nums.size()-1;
        int ans = 0;
        while(left<right){
            ans = nums[left]+nums[right];
            if(ans<target)
                left++;
            else if(ans>target)
                right--;
            else if(ans==target)
                break;
        }
        return {nums[left], nums[right]};
    }
};
int main(){
    
    return 0;
}