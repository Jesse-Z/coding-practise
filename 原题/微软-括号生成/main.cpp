/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-17 
* 给出 `n` 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
* e.g. n = 3,   
*    "((()))",
*    "(()())",
*    "(())()",
*    "()(())",
*    "()()()"
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // if(!n)
        //     return {""};
        // vector<string> ans;
        // dfs(n, n, "", ans);
        // return ans;
        return dp(n);
    }
    // 深度优先遍历
    void dfs(int left, int right, string curr, vector<string> &ans){
        if(left==0 and right==0){
            ans.emplace_back(curr);
            return;
        }
        if(left>right)
            return;
        if(left>0)
            dfs(left-1, right, curr+'(', ans);
        if(right>0)
            dfs(left, right-1, curr+')', ans);
    }
    // 动态规划，dp[i] = (dp[a]) + dp[b]，其中a+b=i-1，dp[i]代表用i对括号所能表示的所有情况
    vector<string> dp(int n){
        vector<vector<string>> dp_array(n+1);
        // 0对括号是空字符
        dp_array[0] = {""};
        for(int i=1; i<=n; ++i){
            for(int a=0; a<i; ++a){
                vector<string> left = dp_array[a];
                vector<string> right = dp_array[i-a-1];
                // 枚举左右字串的所有情况
                for(auto s1:left)
                    for(auto s2:right)
                        dp_array[i].emplace_back("("+s1+")"+s2);
            }
        }
        return dp_array[n];
    }
};
int main(){
    vector<string> ans = Solution().generateParenthesis(3);
    for(auto c:ans)
        cout<<c<<endl;
    return 0;
}