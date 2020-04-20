/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-20 
 
 brief: 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 求最大利润
*/
#include<bits/stdc++.h>
using namespace std;

// 状态矩阵：最大利润
// 状态：天数，股票持有状态；选择：出售、购入、冷冻
// dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
// dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof dp);
        dp[0][1] = INT_MIN;
        for(int i=1; i<=n; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i-1]);
            int dp_pre_0 = i>=2 ? dp[i-2][0]-prices[i-1] : -prices[i-1];
            dp[i][1] = max(dp[i-1][1], dp_pre_0);
        }
        return dp[n][0];
    }
};
int main(){
    vector<int> prices = {1,2,3,0,2};
    cout<<Solution().maxProfit(prices);
    return 0;
}