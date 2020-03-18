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
    bool isBalanced(TreeNode* root){
        int depth =0;
        return getDepth(root, depth);
    }
    bool getDepth(TreeNode *curr, int &depth){
        if (!curr){
            depth = 0;
            return true;
        }
        int left, right;
        if(getDepth(curr->left, left) and getDepth(curr->right, right)){
            int diff = left - right;
            if(abs(diff)<=1){
                depth = 1 + (left>right?left:right);
                return true;
            }
        }
        return false;
    }
};
int main(){
    
    return 0;
}