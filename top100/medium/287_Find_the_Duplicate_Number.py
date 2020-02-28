"""
Jesse@FDU-VTS-MIA
created by 2019/12/20
"""
from typing import List
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """快慢指针
        这题要求空间复杂度为O(1)
        将数组的val视为指向下一节点的index, 因此存在相同的数意味着存在一个环,用快慢指针来进行检测"""
        fast = nums[0]
        slow = nums[0]
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:            # 找到了相遇点
                break
        ptr = nums[0]
        while ptr != slow:
            ptr = nums[ptr]
            slow = nums[slow]
        return ptr
