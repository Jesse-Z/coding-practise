/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-10 
*/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // 构造函数
};

class Solution {
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
    }
    int helper(TreeNode* curr){
        if(!curr)
            return 0;
        int left_depth = helper(curr->left);
        int right_depth = helper(curr->right);
        diameter = max(diameter, left_depth+right_depth); // 更新最值
        return max(left_depth, right_depth) + 1;  // 返回的是左右子树深度的最值
    }
};

int main(){
    
    return 0;
}