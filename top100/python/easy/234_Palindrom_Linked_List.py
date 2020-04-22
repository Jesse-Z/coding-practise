"""
Jesse@FDU-VTS-MIA
created by 2019/11/13
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        fast = slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # 奇数长，fast指针在最后一个，slow在最中间，slow需要往后过一个
        # 偶数长，fast为空，slow指针中点过一个
        if fast:
            slow = slow.next
        pre = None
        cur = slow
        while cur:
            temp = cur.next
            cur.next = pre
            pre, cur = cur, temp
        while pre and head:
            if pre.val != head.val:
                return False
            pre = pre.next
            head = head.next
        return True