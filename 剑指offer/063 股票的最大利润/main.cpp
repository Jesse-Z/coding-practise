/**
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-07 
* 
* brief: 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
*/
#include<bits/stdc++.h>
using namespace std;

// 动态规划，状态是天数，是否持有股票，选择卖或不卖，
// dp[i][1] = max(-prices[i], dp[i-1][1])
// dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)
            return 0;
        int dp[100000][2] = {0};
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for(int i=1; i<n; ++i){
            dp[i][1] = max(-prices[i], dp[i-1][1]);
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        }
        return dp[n-1][0];
    }
};
int main(){
    
    return 0;
}