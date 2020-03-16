/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-16 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string compressString(string S) {
        int n = (int)S.length();
        if(!n)
            return S;
        string ans="";
        char curr = S[0];
        int cnt = 1;
        for(int i=1; i<n; ++i){
            if(S[i]==curr)
                cnt+=1;
            else{
                ans+= curr+to_string(cnt);
                curr = S[i];
                cnt = 1;
            }
        }
        ans += curr + to_string(cnt);
        return ans.length()>=S.length()? S : ans;
    }
};
int main(){
    
    return 0;
}