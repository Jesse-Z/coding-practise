"""
Jesse@FDU-VTS-MIA
created by 2019/12/20
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.ans = None

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        a = self.recursion(root, p, q)
        return a

    def recursion(self, root, p, q):
        """递归
        遍历整个树，在回溯的时候传递一个布尔值，代表路径上是否存在p或q
        如果左节点，右节点或者当前节点其中任意两个为真，则代表找到了祖先节点"""
        def backTrace(node) -> bool:
            if not node:                        # 当前节点为空返回false
                return False
            left = backTrace(node.left)         # 递归遍历左子树
            right = backTrace(node.right)       # 递归遍历右子树
            mid = node in (p, q)            # 当前节点是否是p或q

            if left + right + mid >= 2:         # 如果存在两者为真，则找到了祖先
                self.ans = node

            return mid or left or right

        backTrace(root)
        return self.ans
