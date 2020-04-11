/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-10 
 
 brief: n个商品，买三送一，求花钱最少的购买策略
*/
#include<bits/stdc++.h>
using namespace std;
long long ans = 0;

int main(){
    int n, temp;
    cin>>n;
    priority_queue<int, vector<int>> que;
    for(int i=0; i<n; ++i){
        cin>>temp;
        que.emplace(temp);
    }
    int cnt=1;
    for(int i =0;i<n; ++i){
        if((cnt%3)!=0){
            ans+=que.top();
        }
        que.pop();
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}