# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/11
#
# Definition for a binary tree node.
from typing import List
from collections import deque
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        ans = []
        if root:
            q = deque()
            q.append(root)
            while q:
                level_num = len(q)
                for i in range(level_num):
                    curr = q.popleft()
                    ans.append(curr.val)
                    if curr.left:
                        q.append(curr.left)
                    if curr.right:
                        q.append(curr.right)
        return ans
