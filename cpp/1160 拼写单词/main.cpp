/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt;
        for(auto c:chars)
            chars_cnt[c]++;
        int ans = 0;
        for(auto word: words){
            unordered_map<char, int> word_cnt;
            for(auto c:word)
                word_cnt[c]++;
            bool is_ans = true;
            for(auto c:word)
                if(word_cnt[c]>chars_cnt[c]){
                    is_ans = false;
                    break;
                }
            if(is_ans)
                ans+=(int)word.length();
        }
        return ans;
    }
};
int main(){
    
    return 0;
}