/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char firstUniqChar(string s) {
        if (s=="")
            return ' ';
        unordered_map<char, int> char_cnt;
        for(auto c:s)
            char_cnt[c]++;
        for(auto c:s)
            if(char_cnt[c]==1)
                return c;
        return ' ';
    }
};
int main(){
    
    return 0;
}