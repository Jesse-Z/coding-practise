/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-16 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        // i代表个位，十位，百位...
        int cnt = 0;
        for(long long i=1; i<=n ; i*=10){
            cnt += (n/(i*10))*i + min(max(n%(i*10)-i+1, 0LL), i);
        }
        return cnt;
    }
};
int main(){
    printf("%d", Solution().countDigitOne(12345));
    return 0;
}