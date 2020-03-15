/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-15 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans; 
    vector<string> permutation(string s) {
        helper(s, 0);
        return ans;
    }
    void helper(string &s, string::size_type pBegin){
        if(s[pBegin]=='\0')
            ans.emplace_back(s);
        else{
            for (auto pCh = pBegin; s[pCh] != '\0'; pCh++){
                if(chRepeat(s, pBegin, pCh))  // 如果有相同字符，跳过
                    continue;
                swap(s[pCh], s[pBegin]);
                helper(s, pBegin+1);
                swap(s[pCh], s[pBegin]);
            }
        }
    }
    bool chRepeat(string s, string::size_type pBegin, string::size_type pCh){
        for(auto i=pBegin; i<pCh ; ++i){
            if(s[i]==s[pCh])
                return true;
        }
        return false;
    }
};

int main(){
    system("chcp 65001");
    vector<string> ans = Solution().permutation(string("yes"));
    for(auto i:ans){
        cout<<i<<endl;
    }
    return 0;
}