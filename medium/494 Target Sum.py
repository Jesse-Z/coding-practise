"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-26 
"""
from typing import List
from collections import defaultdict
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        ans = self.dp(nums, S)
        return ans

    def dp(self, nums: [int], S: int) -> int:
        """动态规划
        视作0-1背包问题,dp[i][j]代表[0,i]区间的数所能构成和为j的方案数
        """
        if S > 1000:
            return 0
        dp = [[0]*3001 for _ in range(len(nums))]
        dp[0][nums[0]+1000]   = 1
        dp[0][-nums[0]+1000] += 1
        for i in range(1, len(nums)):
            for j in range(-1000, 1001):
                dp[i][j+1000] = dp[i-1][j-nums[i]+1000] + dp[i-1][j+nums[i]+1000]

        return dp[len(nums)-1][S+1000]

    def dpWizOneDimension(self, nums:[int], S:int) -> int:
        """动态规划+空间优化

        """
        pass



solve = Solution()
solve.findTargetSumWays([1,1,1,1,1]
,3)