# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/28
#
from typing import List
from collections import defaultdict, Counter, deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        ans = self.recursion(preorder, inorder)
        return ans

    def recursion(self, now_pre: List[int], now_in: List[int]):
        if not now_pre:
            return None
        curr_root = TreeNode(now_pre[0])
        root_index = now_in.index(now_pre[0])
        curr_root.left = self.recursion(now_pre[1:1+root_index], now_in[:root_index])
        curr_root.right = self.recursion(now_pre[1+root_index:], now_in[root_index+1:])
        return curr_root
