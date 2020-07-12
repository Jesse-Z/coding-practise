/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-07-12 
 
 brief: 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> bits;
        for (char c : s) {
            bits.flip(c);
        }
        return bits.none() || bits.count() == 1;
    }
};
int main(){
    cout<<Solution().canPermutePalindrome("aab");
    return 0;
}