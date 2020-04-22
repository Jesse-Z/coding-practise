"""
Jesse@FDU-VTS-MIA
created by 2019/11/19
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        """
        任意一条路径可以被写成两个箭头（左，右），每个箭头代表一条从某些点向下遍历到孩子节点的路径。
        假设我们知道对于每个节点最长箭头距离分别为L，R，那么最优路径经过 L + R + 1 个节点。
        """
        self.ans = 1  # 最少为单个root节点

        def dfs(node):
            if not node: return 0
            L = dfs(node.left)
            R = dfs(node.right)
            self.ans = max(L + R + 1, self.ans)
            return max(L, R) + 1

        dfs(root)
        return self.ans - 1
