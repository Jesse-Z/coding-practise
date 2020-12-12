/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-12 
 
 brief: https://leetcode-cn.com/problems/wiggle-subsequence/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // if nums[i] <= nums[i-1]  ---  up[i] =  up[i-1]
    // if nums[i] > nums[i-1]   ---  up[i] = down[i-1] + 1  or up[i-1]
    // 同理可得down

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        vector<int> up(n, 1), down(n, 1);
        for(int i=1; i<n; ++i){
            if(nums[i]==nums[i-1]){
                up[i] = up[i-1];
                down[i] = down[i-1];
            }else if(nums[i]<nums[i-1]){
                up[i] = up[i-1];
                down[i] = max(down[i-1], up[i-1]+1);
            }else{
                down[i] = down[i-1];
                up[i] = max(up[i-1], down[i-1]+1);
            }
        }
        return max(up[n-1], down[n-1]);
    }
};
int main(){
    
    return 0;
}