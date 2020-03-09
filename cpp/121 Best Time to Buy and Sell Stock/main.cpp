/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-09 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return monotonicStack(prices);
    }
    int monotonicStack(vector<int>& prices){
        // 单调栈，每日的最大利润，由当天价格减去这天之前的最小值获得
        // 注意，在prices后面添加一个比所有元素都小的哨兵，确保最后所有栈内元素都能出栈
        prices.emplace_back(-1);
        int n = prices.size();
        vector<int> stack;
        int ans = 0;
        for(int i=0; i<n; ++i){
            while(!stack.empty() && stack.back()>prices[i]){
                ans = max(ans, stack.back()-stack.front());
                stack.pop_back();
            }
            stack.emplace_back(prices[i]);
        }
        return ans;
    }
    int dpMethod(vector<int>& prices){
        // 动态规划，每天有两个状态，1.天数，2.股票持有状态
        // dp[i][0] =  max(dp[i-1][0], dp[i-1][1]+price[i])  保持空手和卖出
        // dp[i][1] =  max(dp[i-1][1], -price[i])  保持持有和买入
        int n = prices.size();
        if(!n) return 0;
        int dp[n][2]={0};
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1; i<n; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n-1][0];
    }
};

int main(){
    vector<int> prices={1,2,3,4};
    printf("%d", Solution().maxProfit(prices));
    return 0;
}