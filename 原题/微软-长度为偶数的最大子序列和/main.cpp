/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-21 
*/
#include<bits/stdc++.h>
using namespace std;

void subArraySum(vector<int> nums){
    // 状态：数组长度，子串奇偶；选择：选之前的或从头开始
    // dp表示，到第i个num为止的最大子串和，
    // 选：奇偶变换，最值更新，不选：从头开始；0奇1偶
    // dp[i][0] = max(dp[i-1][1]+nums[i], nums[i])
    // dp[i][1] = max(dp[i-1][0]+nums[i])
    int n = nums.size();
    int dp[n][2] = {{nums[0], INT_MIN}};  
    int ans = 0;
    for(int i=1; i<n; ++i){
        dp[i][0] = max(dp[i-1][1]+nums[i], nums[i]);
        dp[i][1] = dp[i-1][0]+nums[i];
        ans = max(dp[i][1], ans);
    }
    cout<<ans<<endl;
}

int main(){
    subArraySum(vector<int>{-2, 2, 2, 3, -6, 5, 2});
    return 0;
}