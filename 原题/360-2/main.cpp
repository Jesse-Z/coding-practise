/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-16 
 
 brief: 给定一个数a0，定义如下随机序列a1,a2,...an。

1、从闭区间[0,a0]中等概率随机选出一个整数k0，令a1=a0-k0。

2、得到随机数a1之后，再从闭区间[0,a1]中等概率随机选出一个整数k1，再令 a2=a1-k1。

3、一般地，得到随机数ai之后，再从闭区间[0,ai]中等概率随机选出一个整数ki，令ai+1=ai-ki。

问an=0的概率是多少?

*/
#include<bits/stdc++.h>
using namespace std;
long long n, a0;
// kuaisumi
typedef long long ll;
ll binaryPow(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b & 1){
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
// dfs求0的情况
void dfs(long long &cnt, long long depth, int prev){
    if(depth<0)
        return;
    // 一个数为0，后面都为0
    if(prev==0){
        cnt+=binaryPow(a0, depth, 999999999ll);
        cnt %= 999999999ll;
        return;
    }
    for(int k=0; k<=prev; ++k){
        dfs(cnt, depth-1, prev-k);
    }
}


// 可以求不是0的概率?
int main(){
    cin>>n>>a0;
    long long fenzi = 0;
    dfs(fenzi, n, a0);
    // cout<<fenzi<<' '<<pow(a0+1, n)<<endl;
    // cout<<(double)pow(3, 99)<<endl;
    cout<<setprecision(5) <<std::fixed<<fenzi/binaryPow((a0+1), n, 999999999ll)<<endl;
    return 0;
}

