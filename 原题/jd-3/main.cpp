/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-06 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    // init params
    int n;
    char c;
    cin>>n;
    vector<char> p1, p2;
    for(int i=0; i<n; ++i){
        cin>>c;
        p1.emplace_back(c);
    }
    for(int i=0; i<n; ++i){
        cin>>c;
        p2.emplace_back(c);
    }
    
    // dp
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(p1[i-1] == p2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    float ratio = dp[n][n]/n;
    printf("%.2f %s\n", ratio, ratio<=0.5?"Yes":"No");
    return 0;
}