# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/28
#
from typing import List
from collections import defaultdict, Counter
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        ans = self.hashTabel(nums)
        return ans

    def hashTabel(self, nums: List[int]):
        h_t = defaultdict(int)
        ans = 0
        for i in nums:
            if i not in h_t.keys():
                h_t[i]+=1
            else:
                ans = i
                break
        return ans