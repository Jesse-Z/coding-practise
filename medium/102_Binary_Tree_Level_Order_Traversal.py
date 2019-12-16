"""
Jesse@FDU-VTS-MIA
created by 2019/12/12
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> [[int]]:
        ans = []
        if not root:
            return
        from collections import deque
        queue = deque([])
        queue.append(root)
        level_count = 0
        level = 0
        while queue:
            ans.append([])
            level_count = len(queue)
            for i in range(level_count):
                node = queue.popleft()
                ans[level].append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level += 1
        return ans