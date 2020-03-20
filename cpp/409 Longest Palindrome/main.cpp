/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-19 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> t;
        int ans=0, single=0;
        for(auto c:s){
            t[c]++;
        }
        for(map<char, int>::iterator i=t.begin(); i!=t.end(); ++i){
            int cnt = i->second;
            ans+=cnt&1?cnt-1:cnt;
            single+=cnt&1;
        }
        return single>0?ans+1:ans;
    }
};
int main(){
    return 0;
}