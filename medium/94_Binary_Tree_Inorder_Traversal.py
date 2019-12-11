"""
Jesse@FDU-VTS-MIA
created by 2019/12/11
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> [int]:
        """中序遍历
        """
        ans = []

        def dfs(node):
            if node:
                if node.left:
                    dfs(node.left)
                ans.append(node.val)
                if node.right:
                    dfs(node.right)
        dfs(root)
        return ans
