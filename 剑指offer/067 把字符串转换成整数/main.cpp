/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-09 
 
 brief: 把字符串转换成整数,丢弃无用的开头空格字符
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        // 跳过空格
        while(i<str.size() and str[i]==' ') i++;
        // 记录正负
        int flag = 1;
        if(str[i] == '-') flag = -1;
        if(str[i] == '-' or str[i] == '+') i++;
        // 计算数字
        int ans = 0;
        while(i<str.size() and str[i]>='0' and str[i]<='9'){
            // 先检查是否溢出
            if(ans>INT_MAX/10 or (ans==INT_MAX/10 and (str[i]-'0')>7))
                return flag==1?INT_MAX:INT_MIN;
            cout<<str[i]<<' ';
            ans = ans*10 + (str[i] - '0');
            i++;
        }
        return ans*flag;
    }
};
int main(){
    cout<<Solution().strToInt("2147483646")<<endl;
    return 0;
}