"""
Jesse@FDU-VTS-MIA
created by 2019/12/20
"""
from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ans = self.dp(nums)
        return ans

    def dp(self, nums: [int]) -> int:
        """动态规划
        对于第i个数,其LIT是前i-1个数中最长的LIT长度加一,条件是nums[i] > nums[j]
        因此用localmax来记录局部最大值
        每次内部循环开始前将localmax置0, dp[i]最终等于localmax+1"""
        if not nums: return 0
        n = len(nums)
        large = 1
        dp = [0 for _ in range(n)]
        dp[0] = 1
        for i in range(n):
            localmax = 0
            for j in range(i+1):
                if nums[i] > nums[j]:
                    localmax = max(dp[j], localmax)
            dp[i] = localmax + 1
            large = max(dp[i], large)
        return large
