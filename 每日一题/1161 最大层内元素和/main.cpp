/**
 * Jesse@FDU-VTS-MIA
 * created @date: 2022-07-31
 * brief: https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/
 */
#include <bits/stdc++.h>

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
    int maxLevelSum(TreeNode* root) {
        // 按层遍历
        deque<TreeNode*> que;
        que.emplace_back(root);
        int ans = 0, layer = 1;
        int maxSum = INT_MIN;
        while(!que.empty()) {
            int layerNum = que.size();
            int layerSum = 0;
            for (int i = 0; i<layerNum; ++i) {
                TreeNode *curr = que.front();
                layerSum += curr->val;
                if (curr->left) que.emplace_back(curr->left);
                if (curr->right) que.emplace_back(curr->right);
                que.pop_front();
            }
            if (layerSum > maxSum) {
                maxSum = layerSum;
                ans = layer;
            }
            layer++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
