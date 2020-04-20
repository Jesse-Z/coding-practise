/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-20 
 
 brief: 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）
 使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
*/
#include<bits/stdc++.h>
using namespace std;

// 状态变量：分解n需要的最少平方数个数
// 状态：当前正整数n，选择：平方数大小j*j
// 转移方程：dp[i] = min(dp[i], dp[i-j*j]+1)，其中j是遍历1-sqrt(i)
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        for(int i=2; i<=n; ++i){
            // 最差情况为 每次+1
            dp[i] = i;
            for(int j=sqrt(i); j>0; --j)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        }
        return dp[n];
    }
};
int main(){
    cout<<Solution().numSquares(12);
    return 0;
}