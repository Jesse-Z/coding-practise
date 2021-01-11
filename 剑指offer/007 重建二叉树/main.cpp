/**
 Jesse@FDU-VTS-MIA
 created @date: 2021-01-03 
 
 brief: https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
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
    vector<int> preorder;
    map<int, int> pre2in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i=0; i<inorder.size(); ++i){
            pre2in[inorder[i]] = i; 
        }
        return helper(0, 0, inorder.size()-1);
    }
    TreeNode* helper(int curr, int left, int right){
        if(left>right) return nullptr;
        TreeNode *root = new TreeNode(preorder[curr]);
        int index = pre2in[preorder[curr]];
        root->left = helper(curr+1, left, index-1);
        root->right = helper(curr+index-left+1, index+1, right);
        return root;
    }

};
int main(){
    
    return 0;
}