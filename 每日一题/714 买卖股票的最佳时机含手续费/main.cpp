/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-17 
 
 brief: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // dp[1][i] = max(dp[0][i-1]-prices[i], dp[1][i-1])
    // dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i]-fee) 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for(int i=1; i<n; ++i){
            dp[1][i] = max(dp[0][i-1]-prices[i], dp[1][i-1]);
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]+prices[i]-fee);
        }
        return dp[0][n-1];
    }
};
int main(){
    
    return 0;
}