"""
Jesse@FDU-VTS-MIA
created by 2019/12/13
"""
# Definition for a binary tree node.
from typing import List
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        """分治法，从pre确定当前的根节点root，再从in确定当前的左右节点个数"""
        def select_root(now_pre, now_in) -> TreeNode or None:
            if not now_pre:
                return None
            curr_root = TreeNode(now_pre[0])
            curr_root.left = select_root(now_pre[1:1+now_in.index(now_pre[0])], now_in[:now_in.index(now_pre[0])])
            curr_root.right = select_root(now_pre[1+now_in.index(now_pre[0]):], now_in[now_in.index(now_pre[0])+1:])
            return curr_root

        ans = select_root(preorder, inorder)
        return ans
