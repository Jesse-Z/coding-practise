/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-12-27 
 
 brief: https://leetcode-cn.com/problems/permutation-i-lcci/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 求全排列，回溯
    vector<string> permutation(string S) {
        vector<string> ans;
        vector<bool> visited(S.length(), false);
        backTrace(ans, "", S, visited);
        return ans;
    }
    
    void backTrace(vector<string> &ans, string curr, string &S, vector<bool> &visited){
        if(curr.length() == S.length()){
            ans.emplace_back(curr);
            return;
        }
        for(int i=0; i<S.length(); ++i){
            if(!visited[i]){
                visited[i] = true;
                curr.push_back(S[i]);
                backTrace(ans, curr, S, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
};
int main(){
    
    return 0;
}