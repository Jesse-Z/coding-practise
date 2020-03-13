/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-13 
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum, (vector<int>){});
        return path;
    }
    void dfs(TreeNode* curr, int target, vector<int> subPath){
        if(!curr)
            return;
        subPath.emplace_back(curr->val);
        target -= curr->val;
        if(!curr->left and !curr->right and !target)
            path.emplace_back(subPath);
        dfs(curr->left, target, subPath);
        dfs(curr->right, target, subPath);
    }
};
int main(){
    
    return 0;
}