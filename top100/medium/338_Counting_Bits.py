"""
Jesse@FDU-VTS-MIA
created by 2019/12/24
"""
from typing import List


class Solution:
    def countBits(self, num: int) -> List[int]:
        ans = self.brutal(num)
        return ans

    def brutal(self, num: int):
        """暴力求解
        x & x-1,可以将最小的非零位置零
        """
        ans = []
        for curr in range(num):
            count = 0
            while curr:
                curr &= curr - 1
                count += 1
            ans.append(count)
        return ans

    def dp(self, num: int):
        """动态规划
        一个数可以分解为最高有效位和其他位的和(已经计算过)
        """
        pass
