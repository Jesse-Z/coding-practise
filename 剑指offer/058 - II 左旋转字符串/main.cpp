/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-25 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(char *pBegin, char *pEnd){
        if(pBegin==nullptr or pEnd==nullptr)
            return;
        while(pBegin < pEnd){
            swap(*pBegin, *pEnd);
            pBegin++;
            pEnd--;
        }
    }
    string reverseLeftWords(string s, int n) {
        if(n>=s.length() or n==0)
            return s;
        char *pS = &s[0];
        char *pFirstE = &s[n-1];
        char *pSecondS = &s[n];
        char *pSecondE = &s[s.length()-1];
        reverseString(pS, pFirstE);
        reverseString(pSecondS, pSecondE);
        reverseString(pS, pSecondE);
        return s;
    }
};
int main(){
    return 0;
}