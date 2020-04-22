/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-04-22 
 
 brief: 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode *> que;
        vector<int> ans;
        que.emplace(root);
        while(!que.empty()){
            // 当前层次的节点个数
            int len = que.size();
            for(int i=0; i<len; ++i){
                TreeNode *curr = que.front(); que.pop();
                if(curr->left)
                    que.emplace(curr->left);
                if(curr->right)
                    que.emplace(curr->right);
                if(i==len-1)
                    ans.emplace_back(curr->val);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}