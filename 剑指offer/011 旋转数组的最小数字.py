# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def minArray(self, numbers: List[int]) -> int:
        """二分法"""
        n = len(numbers)
        left, right = 0, n-1
        while left < right:
            mid = (right + left) // 2
            if numbers[mid] > numbers[right]:
                left = mid + 1
            elif numbers[mid] == numbers[right]:
                right -= 1
            else:
                right = mid
        return numbers[left]
