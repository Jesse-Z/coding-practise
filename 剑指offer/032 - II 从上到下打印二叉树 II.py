# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/11
#
from typing import List
from collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ans, level_ans = [], []
        flag = 1
        if root:
            q = deque()
            q.append(root)
            while q:
                level_ans.clear()
                level_num = len(q)
                for i in range(level_num):
                    curr = q.popleft()
                    level_ans.append(curr.val)
                    if curr.left:
                        q.append(curr.left)
                    if curr.right:
                        q.append(curr.right)
                if flag == 1:
                    ans.append(level_ans.copy())
                else:
                    ans.append(list(reversed(level_ans)).copy())
                flag *= -1
        return ans
