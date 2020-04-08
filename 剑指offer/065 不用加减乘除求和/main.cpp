/**
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-08 
* 
* brief: 求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
*/
#include<bits/stdc++.h>
using namespace std;

// 只能用位运算，13 + 3 = 16， 01101 + 00011 = 10000
// 先不进位，1+1=0  0+0=0  1+0=1，异或运算，所以 01101+00011 = 01110
// 算进位，1+1才有进位,与运算并且左移一位, 01101+00011 = 00010
// 再求01110+00010=01100, 01110+00010= 00100
class Solution {
public:
    int add(int a, int b) {
        int sum = 0;
        unsigned int carry = 0;
        while(b){
            sum = a^b;
            // c++不支持负数进行左移，应该转换为unsigned int, 因为只需要记录进位所以不影响
            carry = (unsigned int)(a&b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
int main(){
    cout<<Solution().add(-1, 0);
    return 0;
}