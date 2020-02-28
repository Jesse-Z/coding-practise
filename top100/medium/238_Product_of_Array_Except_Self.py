"""
Jesse@FDU-VTS-MIA
created by 2019/12/20
"""
from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [0 for _ in range(len(nums))]
        k = 1
        # 求当前位置的所有左边元素的乘积
        for i in range(len(nums)):
            res[i] = k
            k *= nums[i]
        k = 1
        # 所有右边元素的乘积
        for i in reversed(range(len(nums))):
            res[i] *= k
            k *= nums[i]
        return res
