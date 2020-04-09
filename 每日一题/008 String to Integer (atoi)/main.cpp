/**
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-04-05 
* 
* brief: 将字符串转换整数，存在英文，只转换以'+','-',数字开头的字符,跳过空格
* Note : 整数型溢出的处理
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        // 跳过开头空格
        while(i<str.size() and str[i]==' ')
            i++;
        int flag = 1;
        // 记录正负号，如果有的话
        if(str[i]=='-'){
            flag = -1;
            i++;
        }
        else if(str[i]=='+'){
            flag = 1;
            i++;
        }
        int ans = 0;
        // 提出连续整数,同时计算res结果，注意溢出
        while(i<str.size() and str[i]>='0' and str[i]<='9'){
            int r = str[i] - '0';
            // TIPS: 整数型溢出的处理，与INT_MAX/10来比较
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && r>7))
                return flag == 1 ? INT_MAX : INT_MIN;
            ans = ans*10 + r;
            i++;
        }
        return ans*flag;
    }
};
int main(){
    cout<<Solution().myAtoi("my satack 123");
    return 0;
}
