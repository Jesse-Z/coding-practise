/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-16 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        if(num<10)
            return 1;
        string strs = "0";
        strs += to_string(num);
        int digits = (int)strs.length() - 1;
        int dp[digits+1] = {1, 1};
        // dp[1] =  '0'<strs[0]<='2' and strs[1] <= '5' ? 2 : 1;
        for(int i=2; i<=digits; ++i){
            if(strs[i-1]=='0' or strs[i-1]>='3' or (strs[i-1]=='2' and strs[i]>'5'))
                dp[i] = dp[i-1];
            else
                dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[digits];
    }
};
int main(){
    cout<<Solution().translateNum(122302);
    return 0;
}