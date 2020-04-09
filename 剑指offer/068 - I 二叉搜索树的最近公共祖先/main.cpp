/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-09 
 
 brief: 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
*/
#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
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
        // dfs(root, p, q);
        // return ans[0];
        return recursion(root, min(p->val, q->val), max(p->val, q->val));
    }
    // 没有利用二叉搜索树性质
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
    TreeNode* recursion(TreeNode* curr, int _min, int _max){
        if(curr->val >= _min and curr->val <= _max)
            return curr;
        if(curr->val > _max)
            return recursion(curr->left, _min, _max);
        if(curr->val < _min)
            return recursion(curr->right, _min, _max);
        return nullptr;
    }
};
int main(){
    
    return 0;
}