/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-28 
 
 brief: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // buy[i][j] = max(buy[i-1][j], sell[i-1][j]-price[i])
    // sell[i][j] = max(sell[i-1][j], buy[i-1][j-1]+price[i])
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = min(k, n/2);
        vector<vector<int>> buy(n, vector<int>(k+1, 0)), sell(n, vector<int>(k+1, 0));
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for(int j=1; j<=k; ++j){
            buy[0][j] = sell[0][j] = INT_MIN/2;
        }
        for(int i=1; i<n; ++i){
            buy[i][0] = max(buy[i-1][0], sell[i-1][0]-prices[i]);
            for(int j=1; j<=k; ++j){
                buy[i][j] = max(buy[i-1][j], sell[i-1][j]-prices[i]);
                sell[i][j] = max(sell[i-1][j], buy[i-1][j-1]+prices[i]);
            }
        }
        return *max_element(sell[n-1].begin(), sell[n-1].end());
    }
};
int main(){
    
    return 0;
}