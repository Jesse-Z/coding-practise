# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/5
#
from typing import List
from collections import defaultdict, Counter, deque

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        ans = self.iteration(head)
        return ans

    def iteration(self, head: ListNode) -> ListNode:
        """
        迭代方法，定义指针pre, cur, next
        """
        pre, cur = None, head
        while cur:
            pNext = cur.next
            cur.next = pre
            cur = pNext
            pre = cur
        return pre

    def recursion(self, head: ListNode) -> ListNode:
        """
        递归方法,首先找到尾巴,然后递归修改
        """
        if not head or not head.next:
            return head
        tail = self.recursion(head.next)
        head.next.next = head
        head.next = None
        return tail
