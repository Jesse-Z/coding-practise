/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-03 
 
 brief: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 c++版本直接利用string的特性
 c版本先计算空格个数，创建新数组，从后向前填入字符
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        // 字符串为空
        if(s.empty() or s.length() == 0) return s;
        int blankCNT = 0, n = s.length();
        for(char c: s){
            if(c==' ') blankCNT++;
        }
        // 没有空格
        if(!blankCNT) return s;
        int n2 = n+2*blankCNT+1;
        char newStr[n2];
        newStr[n2-1] = '\0';
        int pNew = n2-2, pOld = n-1;
        while(pOld>=0){
            if(s[pOld]==' '){
                newStr[pNew--] = '0';
                newStr[pNew--] = '2';
                newStr[pNew--] = '%';
            }else{
                newStr[pNew--] = s[pOld];
            }
            pOld--;
        }
        string ans = newStr;
        return ans;
    }
};
int main(){
    
    return 0;
}