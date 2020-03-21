/** -*- coding: utf-8 -*-
*
* Jesse@FDU-VTS-MIA
* created @date: 2020-03-21 
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct queNode{
    TreeNode *T;
    int depth;
    int pos;
    queNode(TreeNode *x, int y, int z) : T(x), depth(y), pos(z){}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<queNode> que;
        queNode curr = queNode(root, 0, 0);
        // queNode *a = new queNode[100];
        int curr_depth, ans, left = 0;
        que.emplace_back(curr);
        while(!que.empty()){
            curr = que.front();
            que.pop_front();
            if(curr.T!=nullptr){
                que.emplace_back(queNode(curr.T->left, curr.depth+1, curr.pos*2));
                que.emplace_back(queNode(curr.T->right, curr.depth+1, curr.pos*2+1));
                if(curr_depth!=curr.depth){
                    curr_depth = curr.depth;
                    left = curr.pos;
                }
                ans = max(ans, curr.pos-left+1);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}