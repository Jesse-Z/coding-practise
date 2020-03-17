/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return doublePtrWizHash(s);
    }
    int doublePtrWizHash(string s){
        // 双指针，用哈希表记录每个字符的前一个索引，减少左指针移动次数
        unordered_map<char, int> prevIndex;
        int left=0, right=0, ans=0;
        while(right<s.size()){
            if(prevIndex.find(s[right])!=prevIndex.end())
                left = max(left, prevIndex[s[right]]+1);
            prevIndex[s[right++]] = right;
            ans = max(ans, right-left);
        }
        return ans;
    }
    int doublePtr(string s){
        // 双指针，测试样例有空格，将长度26的数组换位unordered_map
        unordered_map<char, int> char_cnt;
        int left=0, right=0;
        int ans=0;
        while(right<s.size()){
            if(!char_cnt[s[right]-'a']){
                char_cnt[s[right]-'a']++;
                ans = max(ans, right-left+1);
                right++;
            }
            else{
                while(char_cnt[s[right]-'a']){
                    char_cnt[s[left]-'a']--;
                    left++;
                }
            }
        }
        return ans;
    }
};
int main(){
    // cout<<Solution().lengthOfLongestSubstring("abcabcbb");
    unordered_map<char, int> m;

    return 0;
}