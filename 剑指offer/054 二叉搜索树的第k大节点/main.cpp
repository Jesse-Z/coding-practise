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
    int ans;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
    void dfs(TreeNode* curr, int &k){
        if(!curr)
            return;
        dfs(curr->right, k);
        k--;
        if(!k)
            ans=curr->val;
        if(k>0)
            dfs(curr->left, k);
    }
};
int main(){
    
    return 0;
}