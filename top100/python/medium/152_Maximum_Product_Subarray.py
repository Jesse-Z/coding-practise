"""
Jesse@FDU-VTS-MIA
created by 2019/12/17
"""
from typing import List
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """动态规划
        维护两个值保存当前的最大值和最小值,
        由于存在负值, 乘法导致最大的变最小的, 最小的变最大的, 需要交换imin和imax
        """
        imax = imin = 1
        ans = float('-inf')
        for i in range(len(nums)):
            if nums[i] < 0:
                imax, imin = imin, imax
            imax = max(imax*nums[i], nums[i])
            imin = min(imin*nums[i], nums[i])
            ans = max(imax, ans)
        return ans
