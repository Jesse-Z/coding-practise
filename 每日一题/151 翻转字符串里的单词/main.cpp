/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-10 
 
 brief: 给定一个字符串，逐个翻转字符串中的每个单词。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        // 翻转整个字符串
        reverseRange(s, s.begin(), s.end()-1);
        // 逐个反转word
        auto p = s.begin(), q = s.begin();
        // 跳过空格，找到第一个字母
        while(*p!='\0'){
            while(*q==' ' and *q!='\0') s.erase(q);
            p = q;
            while(*q!=' ' and *q!='\0') q++;
            reverseRange(s, p, q-1);
            if(*q!='\0')
                q++;
            p = q;
        }
        // 如果字符串非空，删掉最后一个单词后的空格
        if(!s.empty() and s[s.size()-1]==' ')
            s.erase(s.end()-1);
        return s;
    }
    void reverseRange(string &s, string::iterator start, string::iterator end){
        while(start<end){
            swap(*start, *end);
            start++; end--;
        }
    }
};
int main(){
    cout<<Solution().reverseWords(" ");
    return 0;
}