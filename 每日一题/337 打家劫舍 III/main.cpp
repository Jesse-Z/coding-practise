/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-05 
 
 brief: 
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}    
};

class Solution {
public:
    // 每个节点都有抢与不抢两种状态
    // 如果抢，则当前点的值等于左子树和右子树都不抢的结果，以及本节点的值之和。
    // 如果不抢，则当前点的值为左右子树（抢与不抢的最大值）之和
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans[0], ans[1]);
    }
    vector<int> dfs(TreeNode *curr){
        if(!curr)
            return {0,0};
        vector<int> ans = {0, 0};
        auto left = dfs(curr->left);
        auto right = dfs(curr->right);
        ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
        ans[1] = left[0] + right[0] + curr->val;
        return ans;
    }
};
int main(){
    
    return 0;
}