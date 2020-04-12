/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: https://leetcode-cn.com/circle/discuss/eXOcnD/view/SecVmv/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int ni=0; ni<n; ni++){
        cin>>a[ni];
    }
    int cnt=0;
    // 从右到左遍历
    for(int i=n-2; i>=0; i--){
        // 满足 跳过
        if(a[i+1]>=a[i])
            continue;
        // 分成多份才能满足
        int t = (a[i]-1)/a[i+1];
        cnt += t;
        a[i] /= (t+1);
    }
    cout<<cnt<<endl;
    return 0;
}