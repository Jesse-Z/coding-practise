# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/18
#
from typing import List
from collections import defaultdict, Counter, deque

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        queue = deque()
        queue.append(root)
        level, val_list = 0, []
        while queue:
            i = 0
            while i < 2**level:
                i += 1
                curr = queue.popleft()
                if curr is not None:
                    val_list.append(curr.val)
                    queue.append(curr.left)
                    queue.append(curr.right)
                if curr is None:
                    val_list.append(None)
        ans = '['
        for val in val_list:
            if val is not None:
                ans += str(val)
            if val is None:
                ans += 'null'
            ans += ','
        ans = ans[:-1]
        ans += ']'
        return ans

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        val_list = data[1:-1].split(',')
        if val_list[0] is 'null':
            return []
        children = []
        root = TreeNode(val_list[0])
        parents = [root]
        i = 1
        while i < len(val_list):
            if children:
                parents = children.copy()
                children = []
            for parent in parents:
                if i < len(val_list) and val_list[i] is not 'null':
                    parent.left = TreeNode(val_list[i])
                    children.append(parent.left)
                i += 1
                if i < len(val_list) and val_list[i] is not 'null':
                    parent.right = TreeNode(val_list[i])
                    children.append(parent.right)
                i += 1
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
