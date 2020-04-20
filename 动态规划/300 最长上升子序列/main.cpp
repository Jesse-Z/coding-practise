/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-20 
 
 brief: 给定一个无序的整数数组，找到其中最长上升子序列的长度。s
*/
#include<bits/stdc++.h>
using namespace std;

// 状态矩阵：以第i个元素为结尾，最长上升子串的长度
// 状态：索引号，选择：和之前所有子串比较，求最大值
// dp[i] = max(dp[j]) + 1,  if num[i] > num[j]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int dp[nums.size()], ans = 1;
        // 最少为1
        fill(dp, dp+nums.size(), 1);
        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {0, 1, 2, 1, 1, 3, 2, 4};
    cout<<Solution().lengthOfLIS(nums);
    return 0;
}