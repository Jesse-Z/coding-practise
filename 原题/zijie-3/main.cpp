/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: 抵用券，当商品金额大于等于券时才能用，求最少要付多少现金
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<int> quan;
    priority_queue<int> sp;
    for(int ni=0; ni<n; ni++){
        int temp;
        cin>>temp;
        quan.emplace(temp);
    }
    for(int mi=0; mi<m; mi++){
        int temp;
        cin>>temp;
        sp.emplace(temp);
    }
    long long ans = 0;
    while(!sp.empty()){
        // 去掉用不了的券
        while(sp.top()<quan.top() and !quan.empty())
            quan.pop();
        // 需要补上的钱
        while(sp.top()>=quan.top() and !sp.empty() and !quan.empty()){
            ans += sp.top() - quan.top();
            sp.pop();
        }
        if(quan.empty()){
            ans += sp.top();
            sp.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}