/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-23 
 
 brief: 硬币。给定数量不限的硬币，
 币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coins[4] = {1, 5, 10, 25};
    int waysToChange(int n) {
        // map<pair<int, int>, int> memo;
        // return dfs(n, memo, 0);
        return dp(n);
    }
    /*index表示只使用index后的coins*/
    int dfs(int curr, map<pair<int, int>, int> &memo, int index){
        if(curr>0 and memo.find({curr, index})!=memo.end())
            return memo[{curr, index}];
        if(curr<0)
            return 0;
        if(curr==0)
            return 1;
        int ans = 0;
        for(int i=index; i<4; ++i){
            if(curr-coins[i]>=0)
                ans += dfs(curr-coins[i], memo, i);
        }
        memo[{curr, index}] = ans%1000000007;
        return ans%1000000007;
    }
    /*同dfs，限制当前使用过的硬币种类，同时升序使用，避免重复
      注意状态转移，当curr<coin时，不用当前币种，从上一状态转移
    */
    int dp(int n){
        vector<vector<int>> dp_array(4, vector<int>(n+1));
        // 只用一个币，只存在一种情况
        fill(dp_array[0].begin(), dp_array[0].end(), 1);
        for(int c=1; c<4; ++c){
            int coin = coins[c];
            int p_i_prev = 0;
            for(int curr=0; curr<=n; ++curr){
                if(curr-coin<0)
                    dp_array[c][curr] = dp_array[c-1][curr];
                else
                    dp_array[c][curr] = (dp_array[c-1][curr]+dp_array[c][curr-coin]) % 1000000007;
            }
        }
        return dp_array[3][n];
    }
};
int main(){
    cout<<Solution().dp(10);
    return 0;
}   