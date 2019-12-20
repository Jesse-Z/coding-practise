"""
Jesse@FDU-VTS-MIA
created by 2019/12/20
"""
class Solution:
    def numSquares(self, n: int) -> int:
        ans = self.dp(n)
        return ans

    def dp(self, n: int):
        """动态规划
        """
        import math
        dp = [0 for _ in range(n+1)]
        for i in range(1, n+1):
            dp[i] = i
            for j in range(1, int(math.sqrt(i))+1):
                dp[i] = min(dp[i], dp[i-j**2]+1)
        return dp[n]
