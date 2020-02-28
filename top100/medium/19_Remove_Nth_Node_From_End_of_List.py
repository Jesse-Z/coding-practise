"""
Jesse@FDU-VTS-MIA
created by 2019/11/27
"""
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        ans = self.double_points(head, n)
        return ans

    def double_points(self, head, n):
        p = q = head
        for i in range(n):
            p = p.next
        while p and p.next:
            p = p.next
            q = q.next
        # 此使p到达最后一个元素，q到达倒数第n+1个元素
        if p:
            q.next = q.next.next
            return head
        else:  # p为None，说明删除的是头
            return head.next
