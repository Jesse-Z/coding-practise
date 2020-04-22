# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-01-16 
# 
from typing import List
from collections import defaultdict, Counter

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> (ListNode, List):
        step = 1
        total = len(lists)
        while step < total:
            for i in range(0, total-step, step*2):
                lists[i] = self.merge2Lists(lists[i], lists[i+step])
            step *= 2
        return lists[0] if total > 0 else lists

    def merge2Lists(self, L1: ListNode, L2: ListNode) -> ListNode:
        head = curr = ListNode(0)
        while L1 and L2:
            if L1.val <= L2.val:
                curr.next = L1
                L1 = L1.next
            else:
                curr.next = L2
                L2 = L2.next
            curr = curr.next
        if L1:
            curr.next = L1
        else:
            curr.next = L2
        return head.next
