/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-02 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> q(6, vector<char>(6));
    char c;
    for(int i=0; i<6; ++i){
        for(int j=0; j<6; ++j){
            cin>>c;
            q[i][j] = c;
        }
    }
    // 以i,j为右下角的矩形，可能性个数
    vector<int> dp(6, 1);
    if(q[0][0]=='#') dp[0] = 6;
    for(int j=1; j<6; ++j){
        if(q[0][j]=='#' and q[0][j-1]=='*')
            dp[j] = dp[j-1]*6;
        else if(q[0][j]=='#' and q[0][j-1]=='#')
            dp[j] = dp[j-1]*5;
        else if(q[0][j]=='*')
            dp[j] = dp[j-1];
    }
    //往右下走，上边和左边两种情况，相同或不同
    for(int i=1; i<6; ++i){ 
        for(int j=0; j<6; ++j){
            if(q[i][j]=='#' and j==0 and q[i-1][j]=='#'){
                dp[0] = dp[0]*5;
            }
            else if(q[i][j]=='#' and j==0 and q[i-1][j]=='*')
                dp[0] = dp[0]*6;
            else if(q[i][j]=='*' and j>0)
                dp[j] = max(dp[j-1], dp[j]);
            else if(q[i][j]=='#' and j>0 and q[i][j-1]=='#' and q[i-1][j]=='#')
                dp[j] = dp[j-1]*5 + dp[j]*4;
            else if(q[i][j]=='#' and j>0 and q[i][j-1]=='#')
                dp[j] = dp[j-1]*5;
            else if(q[i][j]=='#' and j>0 and q[i-1][j]=='#')
                dp[j] = dp[j]*5;
        }
    }
    cout<<dp[5]<<endl;
    return 0;
}