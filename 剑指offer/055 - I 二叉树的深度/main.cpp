/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-18 
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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
    int dfs(TreeNode *curr){
        if(!curr)
            return 0;
        int left = dfs(curr->left);
        int right = dfs(curr->right);
        return left>right?(left+1):(right+1);
    }
};
int main(){
    
    return 0;
}