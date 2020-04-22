"""
Jesse@FDU-VTS-MIA
created by 2019/10/16
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        return self.iterationMethod(root)

    # 迭代方法，广度遍历
    @staticmethod
    def iterationMethod(root) -> TreeNode:
        if not root: return root
        stack = [root]
        while stack:
            curr = stack.pop()
            temp = curr.left
            curr.left = curr.right
            curr.right = temp
            if curr.left:
                stack.append(curr.left)
            if curr.right:
                stack.append(curr.right)
        return root

    # 递归方法
    def recursionMethod(self, root) -> [TreeNode, None]:
        if root is None: return None
        right = self.recursionMethod(root.right)
        left = self.recursionMethod(root.left)
        root.left = right
        root.right = left
        return root
