/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-03 
 
 brief: https://leetcode-cn.com/problems/add-strings/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 结果存在longer中
    void helper(string &longer, string &shorter){
        int mod = 0, rect = 0, sum_ = 0;
        for(int i=0; i<shorter.size(); ++i){
            // 用上一轮的rect加到当前轮次中
            sum_ = (shorter[i] - '0') + (longer[i] - '0') + rect;
            mod = sum_ % 10;
            longer[i] = mod+'0';
            // 更新rect
            rect = sum_ / 10;
        }
        if(rect and longer.size()>shorter.size()){
            for(int i=shorter.size(); i<longer.size(); ++i){
                sum_ = longer[i] - '0' + rect;
                mod = sum_ % 10;
                longer[i] = mod + '0';
                rect = sum_/10;
            }
        }
        if(rect){
            longer += (rect+'0');
        }
    }

    string addStrings(string num1, string num2) {
        reverse(num2.begin(), num2.end());
        reverse(num1.begin(), num1.end());
        if(num2.size()>num1.size()){
            helper(num2, num1);
            reverse(num2.begin(), num2.end());
            return num2;
        }else{
            helper(num1, num2);
            reverse(num1.begin(), num1.end());
            return num1;
        }
    }
};
int main(){
    
    return 0;
}