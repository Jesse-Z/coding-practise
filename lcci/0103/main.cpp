/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-07-12 
 
 brief: URL化, 编写一种方法, 将字符串中的空格全部替换为%20。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int writePos = S.size()-1, readPos;
        for(int i=0; i<length; ++i){
            readPos = length - 1 - i;
            char c = S[readPos];
            if(c!=' '){
                S[writePos--] = c;
            }else{
                S[writePos--] = '0';
                S[writePos--] = '2';
                S[writePos--] = '%';
            }
        }
        if(writePos >= 0){
            S = S.substr(writePos + 1, S.size() - writePos - 1);
        }
        return S;
    }
};
int main(){
    
    return 0;
}