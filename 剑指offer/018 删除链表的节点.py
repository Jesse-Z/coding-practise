# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/4
#
from typing import List
from collections import defaultdict, Counter, deque

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        # ----判断头是不是空----
        if not head:
            return head

        # ----判断是不是要删除头----
        if head.val == val:
            head = head.next
            return head

        # ----正式开始----
        p, q = head, head.next
        while q:
            if q.val == val:
                p.next = q.next
                return head
            p = q
            q = q.next
        return head
