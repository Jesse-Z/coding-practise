/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-11 
 
 brief: 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==0) return 0.0;
        long long N = n;
        return n > 0 ? binaryPow(x, N) : 1 / binaryPow(x, -N);
    }
    double binaryPow(double x, long long n){
        double ans = 1.0;
        while(n>0){
            if(n&1){
                ans *= x;
            }
            x *= x;
            n>>=1;
        }
        return ans;
    }
};
int main(){
    cout<<Solution().myPow(2, -2)<<endl;
    return 0;
}