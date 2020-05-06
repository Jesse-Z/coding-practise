/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-06 
 
 brief: 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

火车票有三种不同的销售方式：

一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday, d1, d7, d30, n = days.size(), index=0, cost;
        lastday = days[n-1];
        int dp[lastday+1];
        memset(dp, 0, sizeof dp);
        for(int today = 1; today<=lastday; ++today){
            if(today == days[index]){
                index++;
                cost = INT_MAX;
                d1 = today - 1;
                d7 = today - 7 > 0 ? today - 7 : 0;
                d30 = today - 30 > 0 ? today - 30 : 0;
                cost = min(dp[d1]+costs[0], cost);
                cost = min(dp[d7]+costs[1], cost);
                cost = min(dp[d30]+costs[2], cost);
                dp[today] = cost;
            }
            else{
                dp[today] = dp[today-1];
            }
        }
        return dp[lastday];
    }
};
int main(){
    
    return 0;
}