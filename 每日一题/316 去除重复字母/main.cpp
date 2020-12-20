/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-20 
 
 brief: https://leetcode-cn.com/problems/remove-duplicate-letters/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 单调栈 再加 入栈限制
    string removeDuplicateLetters(string s) {
        string buffer;
        vector<int> vis(26), num(26);
        for(char ch:s)
            num[ch-'a']++;
        for(char ch:s){
            if(!vis[ch-'a']){
                while(!buffer.empty() and buffer.back()>ch){
                    if(num[buffer.back()-'a']>0){
                        vis[buffer.back()-'a'] = 0;
                        buffer.pop_back();
                    }else{
                        break;
                    }
                }
                vis[ch-'a'] = 1;
                buffer.push_back(ch);
            }
            num[ch-'a']--;
        }
        return buffer;
    }
};
int main(){
    
    return 0;
}