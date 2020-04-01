/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-07 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left<right){
            if(s[left] != s[right])
                return validSubString(s, left+1, right) || validSubString(s, left, right-1);
            ++left;
            --right;
        }
        return true;
    }
    bool validSubString(string s, int left, int right){
        while (left<right)
        {
            if(s[left]!=s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main(){
    Solution solve;
    string s = "abca";
    printf("%s, %d\n", s.c_str(), solve.validPalindrome(s));
    return 0;
}
