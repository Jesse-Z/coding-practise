"""
Jesse@FDU-VTS-MIA
created by 2019/12/18
"""
from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        """动态规划
        dp[i][j]代表以第i行第j列的位置为右下角的正方形
        当matrix[i-1][j-1]为1时，其受左上、左、上三个位置制约构成正方形，且为三者中的最小值+1"""
        if not matrix:
            return 0
        dp = [[0 for _ in range(len(matrix[0]) + 1)] for _ in range(len(matrix) + 1)]
        max_r = 0
        for i in range(1, len(matrix) + 1):
            for j in range(1, len(matrix[0]) + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1
                    max_r = max(dp[i][j], max_r)
        return max_r * max_r
