# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/6
#
# Definition for a binary tree node.
from typing import List
from collections import defaultdict, Counter, deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self.iteration(root)

    def recursion(self, root:TreeNode):
        def helper(a: TreeNode, b: TreeNode):
            if not a and not b:
                return True
            if not a or not b:
                return False
            if a.val != b.val:
                return False
            return helper(a.left, b.right) and helper(a.right, b.left)

        ans = True
        if root:
            # return ans
            ans = helper(root.left, root.right)
        return ans

    def iteration(self, root:TreeNode):
        if root:
            q = deque()
            q.append(root.left)
            q.append(root.right)
            while q:
                a = q.popleft()
                b = q.popleft()
                if not a and not b:
                    continue
                if (not a or not b) or a.val!=b.val:
                    return False
                q.append(a.left)
                q.append(b.right)
                q.append(a.right)
                q.append(b.left)
        return True
