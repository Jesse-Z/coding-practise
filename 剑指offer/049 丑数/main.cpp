/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int res[n] = {1};
        int p2=0, p3=0, p5=0;
        for(int i=1; i<n; ++i){
            res[i] = min(res[p2]*2, min(res[p3]*3, res[p5]*5));
            if(res[i]==res[p2]*2) p2++;
            if(res[i]==res[p3]*3) p3++;
            if(res[i]==res[p5]*5) p5++;
        }
        return res[n-1];
    }
};
int main(){
    cout<<Solution().nthUglyNumber(10);
    return 0;
}