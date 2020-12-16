/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-15 
 
 brief: https://leetcode-cn.com/problems/monotone-increasing-digits/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strN = to_string(N);
        int i = 1;
        // 找到一端非递减序列
        while(i < strN.length() and strN[i-1]<=strN[i]){
            i++;
        }
        // 只需要修改递减的一位，并将后面数位置为9，注意要对前面进行检查
        if(i<strN.length()){
            while(i>0 and strN[i-1]>strN[i]){
                strN[i-1] -= 1;
                i -= 1;
            }
            for(i+=1; i<strN.length(); ++i){
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};
int main(){
    
    return 0;
}