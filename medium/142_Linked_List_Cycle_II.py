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
    def detectCycle(self, head: ListNode) -> ListNode:
        ans = self.doublePoint(head)
        return ans

    def hashSet(self, head):
        """哈希表
        用哈希表保存每个遍历过的节点,如果出现重复的,则有环
        """
        hash = set()
        node = head
        while node:
            if node in hash:
                return  node
            else:
                hash.add(node)
                node = node.next
        return None

    def doublePoint(self, head):
        """双指针法,快慢指针
        首先定义环特别大,设置快慢指针,fast和slow,
        当fast到达入口时,走了距离为n,则slow走的距离就是n/2
        当slow到达入口时,fast又走了n,离开入口n,设环剩下的大小为b
        则fast再走2b,slow再走b时,两者相遇,相遇点距离入口b.
        此时,相遇点再走距离n可以到达入口,等同于起点到入口的距离
        """
        if not head or not head.next:       # 如果是空节点,或者单个节点
            return None
        fast = slow = head
        meet = None                         # 初始化相遇点,如果遍历后还是None,则无环
        while fast and fast.next and slow:  # 注意长度为奇数的无环链表
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                meet = slow                 # 找到了相遇点
                break
        if not meet:                        # 无环
            return None
        ptr1 = head                         # 开始找入口,设置两个指针分别指向起点和相遇点
        ptr2 = meet
        while ptr1 != ptr2:                 # 因此相遇点此时距离入口的距离和起点是相同的,所以只要两个指针相同的速度相遇,就是入口
            ptr1 = ptr1.next
            ptr2 = ptr2.next
        return ptr1
