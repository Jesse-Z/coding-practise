/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-20 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> splitString(string s){
        int n = s.size();
        vector<string> words;
        string temp="";
        for(int i=0; i<n; ++i){
            if(s[i]==' ' and temp!=""){
                words.emplace_back(temp);
                temp="";
            }
            else if(s[i]!=' '){
                temp+=s[i];
            }
        }
        if(temp.size())
            words.emplace_back(temp);
        return words;
    }
    string reverseWords(string s) {
        vector<string> words = splitString(s);
        string ans ="";
        while(!words.empty()){
            ans+=words.back()+' ';
            words.pop_back();
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};
int main(){
    cout<<Solution().reverseWords("i     am students. ");
    return 0;
}