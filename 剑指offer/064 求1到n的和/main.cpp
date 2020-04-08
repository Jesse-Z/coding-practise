/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-08 
 
 brief: 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
*/
#include<bits/stdc++.h>
using namespace std;

// 使用构造函数
class Solution {
private:
    static unsigned int N;
    static unsigned int Sum;
public:
    Solution(){
        ++N;
        Sum+=N;
    }
    static void Reset(){
        N = 0; Sum = 0;
    }
    static unsigned int GetSum(){
        return Sum;
    }
};
// 类内只是声明，需要再定义
unsigned int Solution::N=0;
unsigned int Solution::Sum=0;

unsigned int Method1(unsigned int n){
    Solution::Reset();
    Solution *a = new Solution[n];
    delete []a;
    a = nullptr;
    return Solution::GetSum();
}
int main(){
    cout<<Method1(100);
    return 0;
}