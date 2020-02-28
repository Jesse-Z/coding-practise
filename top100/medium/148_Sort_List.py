"""
Jesse@FDU-VTS-MIA
created by 2019/12/17
"""
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        ans = self.mergeSort(head)
        return ans

    def mergeSort(self, head: ListNode):
        """归并排序
        用递归来进行cut,用快慢指针法来找到mid,
        """
        if not head or not head.next:
            return head                     # 当head.next为None时,说明只剩一个节点,cut结束
        slow, fast = head, head.next        # 奇数个节点找到中点，偶数个节点找到中心左边的节点
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        mid = slow.next                     # 保存中点
        slow.next = None                    # cut
        # 继续cut
        left, right = self.mergeSort(head), self.mergeSort(mid)
        # 开始merge
        curr = res = ListNode(0)
        while left and right:
            if left.val < right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next
            curr = curr.next
        curr.next = left if left else right
        return res.next
