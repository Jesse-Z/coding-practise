# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/5
#
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        ans = False
        if A is not None and B is not None:
            if A.val == B.val:
                ans = self.helper(A, B)
            if not ans:
                ans = self.isSubStructure(A.left, B)
            if not ans:
                ans = self.isSubStructure(A.right, B)
        return ans

    def helper(self, A, B) -> bool:
        if B is None:
            return True
        if A is None or A.val != B.val:
            return False
        return self.helper(A.left, B.left) and self.helper(A.right, B.right)