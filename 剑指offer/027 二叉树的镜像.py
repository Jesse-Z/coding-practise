# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/5
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
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        self.iteration(root)
        return root

    def recursion(self, root: TreeNode):
        if not root:
            return
        root.left, root.right = root.right, root.left
        # if root.left:
        self.recursion(root.left)
        # if root.right:
        self.recursion(root.right)

    def iteration(self, root: TreeNode):
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            for _ in range(n):
                x = q.popleft()
                x.left, x.right = x.right, x.left
                if x.left:
                    q.append(x.left)
                if x.right:
                    q.append(x.right)
