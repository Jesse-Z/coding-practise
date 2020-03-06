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
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        p, q = head, head
        if not head:
            return head
        while k:
            if q is not None:
                q = q.next
                k -= 1
            else:
                return None
        while q:
            p, q = p.next, q.next
        return p
