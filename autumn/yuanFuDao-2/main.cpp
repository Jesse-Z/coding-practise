/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-01 
 
 brief: 发奖券
*/
#include<bits/stdc++.h>
using namespace std;

// 类似求最大子路径和？
int main(){
    // init params
    int n, a, b, ans=0;
    cin>>n;
    vector<int> prices(n, 0);
    vector<int> source(n, 0);
    for(int i=0; i<n; ++i){
        cin>>a>>b;
        prices[i] = a;
        // 记录奖券发放路径，第一个同学为-1
        source[i] = b == 0? -1 : b-2;
    }

    // 从后往前找？这样的话可以根据source往上溯源
    for(int i=n-1; i>=0; --i){
        int curr = i;
        int sum_ = 0;
        while(curr!=-1){
            sum_ += prices[curr];
            sum_ %= 1000000003;
            ans = max(sum_, ans);
            curr = source[curr];
        }
    }
    
    cout<<ans<<endl;
    return 0;
}