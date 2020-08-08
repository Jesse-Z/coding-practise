/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-08 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int ti=0; ti<t; ++ti){
        int n, ai, bi;
        cin>>n;
        vector<int> a(n, 0), b(n-1, 0);
        for(int ni=0; ni<n; ++ni){
            cin>>ai;
            a[ni] = ai;
        }
        for(int ni=0; ni<n-1; ++ni){
            cin>>bi;
            b[ni] = bi;
        }
        vector<int> dp(n+1, 0);
        // dp[n] = min(dp[n-1]+a[i], dp[n-2]+b[i])
        dp[0] = 0;
        dp[1] = a[0];
        for(int i=2; i<=n; ++i){
            dp[i] = min(dp[i-1]+a[i-1], dp[i-2]+b[i-2]);
        }
        int hours = dp[n] / 3600;
        int mines = dp[n] / 60 % 60;
        int secon = dp[n] % 60;
        printf("%02d:%02d:%02d %s\n", hours>5?((8+hours)%13)+1:8+hours, mines, secon, (8+hours>12?"pm":"am"));
    }
    return 0;
}