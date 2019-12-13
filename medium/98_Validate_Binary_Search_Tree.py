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
    def isValidBST(self, root: TreeNode) -> bool:
        """光是递归判断node.val >(<) node.left(right).val是不够的，
        反例：[10,5,15,null,null,6,20]，每个紫薯都是BST，但右子树中的6小于根节点10
        因此，还需要判断当前子树上界与下界的值。"""
        def recursion(node, lower=float('-inf'), upper=float('inf')) -> bool:
            if not node:
                return True
            l = r = True
            if node.val <= lower or node.val >= upper:
                return False
            if node.left:
                l = node.val > node.left.val and recursion(node.left, lower, node.val)
            if node.right:
                r = node.val < node.right.val and recursion(node.right, node.val, upper)
            return l and r
        ans = recursion(root)
        return ans
