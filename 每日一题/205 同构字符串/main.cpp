/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-27 
 
 brief: https://leetcode-cn.com/problems/isomorphic-strings/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int n = s.size();
        unordered_map<char, char> m1, m2;
        for(int i=0; i<n; ++i){
            if(m1.count(s[i]) and m1[s[i]]!=t[i] or m2.count(t[i]) and m2[t[i]]!=s[i])
                return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};
int main(){
    
    return 0;
}