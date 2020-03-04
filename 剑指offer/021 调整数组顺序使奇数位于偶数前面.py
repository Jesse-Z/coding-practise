# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/4
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left, right = 0, n-1
        while left < right:
            while left < right and nums[left] & 1:
                left += 1
            while left < right and nums[right] & 1 == 0:
                right -= 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
        return nums
