"""
Jesse@FDU-VTS-MIA
created by 2019/11/13
"""

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0

        # sums 为node的父节点所有可能路径上和的集合，返回最长可延申到node结束的所有路径所能构成的和列表
        def dfs(node, sums):
            left = right = 0
            # 之前的所有和加当前节点构成的新和 + 从当前节点开始的新和
            temp = [num + node.val for num in sums] + [node.val]
            if node.left:
                left = dfs(node.left, temp)
            if node.right:
                right = dfs(node.right, temp)
            return temp.count(sum) + left + right
        return dfs(root, [])
