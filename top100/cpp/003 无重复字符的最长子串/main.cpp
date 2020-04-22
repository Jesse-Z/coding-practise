/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-22 
 
 brief: 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*/
#include<bits/stdc++.h>
using namespace std;

// 滑动窗口，同时维护一个set
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int left = 0, right = 1, ans = 1;
        set<char> S={s[0]};
        while(right < s.size() and left < s.size()){
            if(S.find(s[right])==S.end()){
                S.insert(s[right++]);
                ans = max(right - left, ans);
            }
            else{
                S.erase(s[left++]);
            }            
        }
        return ans;
    }
};
int main(){
    cout<<Solution().lengthOfLongestSubstring("pwwkew");
    return 0;
}