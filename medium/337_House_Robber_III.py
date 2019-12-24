"""
Jesse@FDU-VTS-MIA
created by 2019/12/24
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        ans = self.dfs(root)
        return max(ans)

    def dfs(self, node: TreeNode):
        """
        每个节点都有抢与不抢两种状态
        如果抢，则当前点的值等于左子树和右子树都不抢的结果，以及本节点的值之和。
        如果不抢，则当前点的值为左右子树（抢与不抢的最大值）之和
        """
        if not node:
            return [0, 0]
        res = [0, 0]
        left = self.dfs(node.left)
        right = self.dfs(node.right)
        res[0] = max(left[0], left[1]) + max(right[0], right[1])
        res[1] = left[0] + right[0] + node.val
        return res
