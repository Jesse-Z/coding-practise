/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-09 
 
 brief: 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 E.g: n = 3,       
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
    // 深度优先遍历，left始终大于等于right，left等于right时，只能添加左括号
    void dfs(int n, int left, int right, string s){
        if(left==n and right==n){
            ans.emplace_back(s);
            return;
        }
        if(left<right)
            return;
        if(left<n)
            dfs(n, left+1, right, s+"(");
        if(right<n)
            dfs(n, left, right+1, s+")");
    }
};
int main(){
    vector<string> a(Solution().generateParenthesis(3));
    for(auto c:a)
        cout<<c<<endl;
    return 0;
}