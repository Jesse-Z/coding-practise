# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
class Solution:
    @staticmethod
    def sum_digits(x):
        s = 0
        while x:
            s += x%10
            x = x // 10
        return s

    def movingCount(self, m: int, n: int, k: int) -> int:
        visited = set()
        def dfs(i, j):
            if not 0<=i<m or not 0<=j<n or (i, j) in visited:
                return 0
            if self.sum_digits(i)+self.sum_digits(j) > k:
                return 0
            visited.add((i, j))
            ans = 1 + dfs(i-1, j) + dfs(i+1, j) + dfs(i, j-1) + dfs(i, j+1)
            return ans
        return dfs(0, 0)
