"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-25 
"""
from typing import List
from collections import defaultdict
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        pass

    def dp(self, nums: List[int]) -> bool:
        """动态规划
        0-1背包问题
        """
        if sum(nums) % 2:
            return False
        target = sum(nums) // 2
        n = len(nums)
        dp = [[False]*(target+1) for _ in range(n)]
        for j in range(target+1):
            if nums[0] == j:
                dp[0][j] = True
                break
        for i in range(1, n):
            for j in range(target+1):
                if j >= nums[i]:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i]]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[-1][-1]

    def dpWizOneDimension(self, nums: [int]) -> bool:
        """空间优化
        注意到dp[i][只依赖于dp[i-1],因此可以将dp矩阵压缩为一维向量,O(target)
        """
        # todo: 动态规划矩阵降维
        pass

solve = Solution()
solve.canPartition([1,5,11,5])