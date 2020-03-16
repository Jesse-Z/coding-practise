/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-16 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        while(n>=0){
            long long numbers = numOfDigits(digits);
            if(n<numbers*digits)
                return digitAtIndex(n, digits);
            n -= numbers*digits;
            digits++;
        }
        return -1;
    }
    int numOfDigits(int digits){
        // 返回m位数上，共多少个数
        if(digits==1)
            return 10;
        int num = pow(10, digits-1);
        return num*9;
    }
    int digitAtIndex(int index, int digits){
        // base为从10^(digits-1)开始的第index/digits个数，一位的话从0开始。
        // 需要找到base从左到右第index%digits位。
        int base = (digits == 1 ? 0: pow(10, (digits-1))) + index / digits;
        int indexRight = digits - index%digits;
        for(int i=1; i<indexRight; i++){
            base /= 10;
        }
        return base%10;
    }
};
int main(){
    // printf("%f", pow(10, 0));
    return 0;
}