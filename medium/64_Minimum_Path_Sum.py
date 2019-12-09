"""
Jesse@FDU-VTS-MIA
created by 2019/12/9
"""
class Solution:
    def minPathSum(self, grid: [[int]]) -> int:
        """动态规划，和62一样，当前路径等于当前节点加min(dp[i+1][j], dp[i][j+1])"""
        m, n = len(grid), len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in reversed(range(m)):
            for j in reversed(range(n)):
                if i == m-1 and j != n-1:
                    dp[i][j] = grid[i][j] + dp[i][j+1]
                elif j == n-1 and i != m-1:
                    dp[i][j] = grid[i][j] + dp[i+1][j]
                elif j != n-1 and i != m-1:
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1])
                else:
                    dp[i][j] = grid[i][j]
        return dp[0][0]
