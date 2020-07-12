/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-07-12 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 题目要求最佳路径下的最低初始点数
     * 最佳路径 = 当前路径和最大， 与最低初始点数相互影响，因此倒着走，避免影响
     * 动态规划 dp[i][j] 当前路径所需要的最低初始点数
     * 状态转移方程：dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - martix[i][j]
    */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = dp[n-1][m] = 1;

        for(int i = n-1; i>=0; --i){
            for(int j = m-1; j>=0; --j){
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j] , 1);
            }
        }
        return dp[0][0];
    }
};
int main(){
    
    return 0;
}