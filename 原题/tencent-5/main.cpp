/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-26 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binaryPow(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
int main(){
    ll x, depth[62];
    int k, q;
    cin>>q;
    for(int i=0; i<62; ++i){
        depth[i] = binaryPow(2, i) - 1ll;
        // cout<<depth[i]<<endl;
    }
    for(int qi=0; qi<q; ++qi){
        cin>>x>>k;
        // 找到当前层号
        int curr;
        for(int i=61; i>=0; --i)
            if(x - depth[i] > 0){
                curr = i + 1;
                break;
            }
        if(curr<=k){
            cout<<-1<<endl;
            continue;
        }
        while(curr != k){
            x /= 2ll;
            curr--;
        }
        cout<<x<<endl;
    }
    return 0;
}