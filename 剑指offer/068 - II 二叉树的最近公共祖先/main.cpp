/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-09 
 
 brief: 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
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
    vector<TreeNode *> ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans[0];
    }
    int dfs(TreeNode *curr, TreeNode *p, TreeNode *q){
        if(curr == nullptr)
            return 0;
        int val = 0;
        if(curr == p or curr == q)
            val++;
        int left = dfs(curr->left, p, q);
        int right = dfs(curr->right, p, q);
        val += left + right;
        if(val==2)
            ans.emplace_back(curr);
        return val;
    }
};
int main(){
    
    return 0;
}