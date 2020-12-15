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
        while(i < strN.length() and strN[i-1]<=strN[i]){
            i++;
        }
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