/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-05-05 
 
 brief: 假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    bool dfs(TreeNode* curr, long lower, long upper){
        if(curr == nullptr){
            return true;
        }
        if(curr->val <= lower or curr->val >= upper)
            return false;
        return dfs(curr->left, lower, curr->val) and dfs(curr->right, curr->val, upper);
    }
};
int main(){
    
    return 0;
}