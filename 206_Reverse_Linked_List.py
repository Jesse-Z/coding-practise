"""
Jesse@FDU-VTS-MIA
created by 2019/10/16
"""
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        return self.recursionMethod(head)

    # 迭代方法，
    @staticmethod
    def iterationMethod(head) -> ListNode:
        prev = None
        curr = head
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev

    # 递归方法
    def recursionMethod(self, head) -> [ListNode, None]:
        if head is None or head.next is None: return head
        p = self.recursionMethod(head.next)
        head.next.next = head
        head.next = None
        return p
