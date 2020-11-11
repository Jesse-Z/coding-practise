/**
 Jesse@FDU-VTS-MIA
 created @date: 2020-08-08 
 
 brief: https://leetcode-cn.com/problems/recover-binary-search-tree/
*/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inOrder(TreeNode *curr, vector<int> &nums){
        if(!curr)
            return;
        inOrder(curr->left, nums);
        nums.emplace_back(curr->val);
        inOrder(curr->right, nums);
    }
    void recover(TreeNode *curr, int cnt, int x, int y){
        if(!curr) return;
        if(curr->val==x or curr->val==y){
            curr->val = curr->val == x? y:x;
            cnt--;
        }
        if(cnt==0)
            return;
        recover(curr->left, cnt, x, y);
        recover(curr->right, cnt, x, y);
    }
    void recoverTree(TreeNode* root) {
        if(!root) return;
        vector<int> nums;
        inOrder(root, nums);

        int x=-1, y=-1, cnt=0;
        for(int i=0; i<nums.size()-1; ++i){
            if(nums[i]>nums[i+1]){
                y = nums[i+1];
                if(x==-1)
                    x = nums[i];
                else
                    break;
            }
        }
        recover(root, 2, x, y);
    }
};
int main(){
    
    return 0;
}