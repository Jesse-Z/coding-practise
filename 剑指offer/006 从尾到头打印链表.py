# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/28
#
# Definition for singly-linked list.
from typing import List
from collections import defaultdict, Counter, deque

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if head is None:
            return []
        ans = self.usingStack(head)
        return ans

    def usingStack(self, head: ListNode):
        stack, ans = [], []
        while head:
            stack.append(head.val)
            head = head.next
        while stack:
            ans.append(stack.pop(-1))
        return ans