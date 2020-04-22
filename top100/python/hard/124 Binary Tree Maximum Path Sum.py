# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-01-17 
# 
from typing import List
from collections import defaultdict, Counter
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:    
        ans = self.recursion(root)
        print(ans)
        return ans

    def recursion(self, root: TreeNode) -> int:
        self.max_path = float('-inf')
        def max_now(node: TreeNode):
            if not node:
                return 0
            left_sum = max(max_now(node.left), 0)
            right_sum = max(max_now(node.right), 0)
            now_path = node.val + left_sum + right_sum
            # 以当前节点为根节点的情况
            self.max_path = max(now_path, self.max_path)
            # 不以当前节点为根节点
            return node.val + max(left_sum, right_sum)
        max_now(root)
        return self.max_path