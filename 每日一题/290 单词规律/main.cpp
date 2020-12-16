/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-16 
 
 brief: https://leetcode-cn.com/problems/word-pattern/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> str2ch;
        map<char, string> ch2str;
        int n = s.length();
        int i = 0;
        for(auto ch:pattern){
            if(i>=n)
                return false;
            int j = i;
            while(j<n and s[j]!=' ') j++;
            const string &temp = s.substr(i, j-i);
            if(str2ch.count(temp)!=0 and ch!=str2ch[temp])
                return false;
            if(ch2str.count(ch)!=0 and temp!=ch2str[ch])
                return false;
            str2ch[temp] = ch;
            ch2str[ch] = temp;
            i = j+1;
        }
        return i>=n;
    }
};
int main(){
    
    return 0;
}