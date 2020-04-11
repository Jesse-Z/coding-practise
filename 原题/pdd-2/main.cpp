/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-10 
 
 brief: N个数，求能够被m整除的区间总数
 E.g: 1 2 3 4 5  和 2
 长度为1: 2, 4
 长度为2: None
 .....3: 123, 345
 .....4: 1234, 2345
 .....5: None

 https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned int n, m, cnt=0;
    cin>>n>>m;
    unsigned int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    unsigned int dp[n][2];
    memset(dp, 0, sizeof(dp));

    // 转1维，减少内存
    for(int step=1; step<=n; step++)
        for(int start=0; start<n-step+1; start++){
            dp[start][step%2] = (dp[start][(step-1)%2] + a[start+step-1] % m) % m;
            // cout<<start<<' '<<step<<' '<<dp[start][step]<<endl;
            if(dp[start][step%2]==0)
                cnt++;
        }
    cout<<cnt;
    return 0;
}