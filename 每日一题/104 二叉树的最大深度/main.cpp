/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-07-28 
 
 brief: 
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
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q. push(curr->right);
                sz-=1;
            }
            ans++;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}