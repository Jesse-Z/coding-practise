# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-01-17 
# 
from typing import List
from collections import defaultdict, Counter
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = self.brutal_1(nums)
        print(ans)
        return ans

    def brutal(self, nums: List[int]) -> int:
        """暴力
        遍历数组,以当前元素i作为一个连续序列的起点,不停判断i+1是否存在,并更新答案
        """
        n = len(nums)
        max_len = 0
        for i in range(n):
            now = nums[i]
            curr_len = 1
            while now + 1 in nums:
                curr_len += 1
                now += 1
            max_len = max(curr_len, max_len)
        return max_len

    def brutal_1(self, nums: List[int]) -> int:
        """暴力`改
        对于序列2-3-4-5,上述方法会分别判断2-3-4-5, 3-4-5, 4-5, 5,存在重复操作.
        其实我们只需要从2开始判断就可以, 同时用哈希表来减少判断次数.
        """
        max_len = 0
        nums_set = set(nums)
        for num in nums_set:
            if num - 1 not in nums_set:
                now = num
                curr_len = 1
                while now + 1 in nums_set:
                    curr_len += 1
                    now += 1
                max_len = max(max_len, curr_len)
        return max_len
             
solve = Solution()
solve.longestConsecutive([100, 4, 200, 1, 3, 2])