/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-27 
 
 brief: https://leetcode-cn.com/problems/permutation-ii-lcci/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 有重复字符的全排列，在无重复字符代码的基础上先对字符串进行排序，
    // 这样重复字符必然相邻，然后在回溯过程中加一句判断条件去除重复排列
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        vector<string> ans;
        vector<bool> visited(S.length(), false);
        backTrace(ans, S, "", visited);
        return ans;
    }
    void backTrace(vector<string> &ans, string &S, string curr, vector<bool> &visited){
        if(curr.length() == S.length()){
            ans.emplace_back(curr);
            return;
        }
        for(int i=0; i<S.length(); ++i){
            if(!visited[i]){
                // 跳过重复字符
                if(i>0 and S[i]==S[i-1] and visited[i-1]) 
                    continue;
                curr.push_back(S[i]);
                visited[i] = true;
                backTrace(ans, S, curr, visited);
                curr.pop_back();
                visited[i] = false;
            } 
        }
    }
};
int main(){
    
    return 0;
}