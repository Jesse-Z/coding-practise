/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-22 
*/
#include<bits/stdc++.h>
using namespace std;

// 给两个整数k,n  求将1~n分成k份后的最大乘积
// 例：n=18, k=4,   分为 4+4+5+5=18, 乘积最大
int main(){
    int n, k;
    cin>>n>>k;
    int base = n/k;
    int num_ones = n%k;
    // 原理：尽量将n分为离n/k最近的数时乘积最大，18能分出4个4，还余两个1，则得到4，4，5，5.
    int ans = (pow(base, k-num_ones) * pow(base+1, num_ones));
    cout<<ans;
    return 0;
}