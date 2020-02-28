# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/28
#
from typing import List
from collections import defaultdict, Counter

class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        print(self.dp(grid))
        pass

    def dp(self, grid: List[List[int]]):
        m, n = len(grid), len(grid[0])
        dp_a = [[0]*n for _ in range(m)]
        dp_a[0][0] = grid[0][0]
        for i in range(1, m):
            dp_a[i][0] = dp_a[i-1][0] + grid[i][0]
        for j in range(1, n):
            dp_a[0][j] = dp_a[0][j-1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                dp_a[i][j] = max(dp_a[i-1][j], dp_a[i][j-1]) + grid[i][j]
        return dp_a[m-1][n-1]

solve = Solution()
solve.maxValue([
  [1,3,1],
  [1,5,1],
  [4,2,1]
])