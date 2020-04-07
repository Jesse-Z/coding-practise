/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-30 
*
* brief: 0、1、2、3、4这5个数字组成一个圆圈，
* 从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
*/
#include<bits/stdc++.h>
using namespace std;

// 倒推，最终剩下一个人时的安全位置肯定为0，反推安全位置在人数为n时的编号
// 人数2：(0+m)%2
// 人数3：((0+m)%2 + m)%3 ……
class Solution {
public:
    int lastRemaining(int n, int m) {
        int result = 0;
        for (int i = 2; i <= n; ++i) {
            result = (result + m) % i;
        }
        return result;
    }
};

int main(){
    
    return 0;
}