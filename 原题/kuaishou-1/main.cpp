/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-12 
 
 brief: 统计合法的括号对数，以及落单的左右括号个数
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<char> stack;
    int pairn=0, leftn=0, rightn = 0;
    // 左括号则入栈，右括号则弹出
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            stack.emplace_back(s[i]);
            leftn++;
        }
        else if(s[i]==')'){
            // 栈不空，就弹出，配对数加一
            if(!stack.empty()){
                stack.pop_back();
                pairn++;
                leftn--;
            }
            // 栈空则右括号落单
            else{
                rightn++;
            }
        }
    }
    cout<<pairn<<' '<<leftn<<' '<<rightn<<endl;
    return 0;
}