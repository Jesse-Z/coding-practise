/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-15 
 
 brief: 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // dp保存当前位置上最近的0的距离
        vector<vector<int>> dp(m, (vector<int>(n, INT_MAX)));
        // 两次遍历，一次从左上到右下，一次反过来
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(matrix[i][j]==0)
                    dp[i][j]=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(j-1>=0)
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                if(i-1>=0)
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
        for(int i=m-1; i>=0; --i)
            for(int j=n-1; j>=0; --j){
                if(j+1<n)
                    dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                if(i+1<m)
                    dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
            }
        return dp;
    }
};
int main(){
    
    return 0;
}