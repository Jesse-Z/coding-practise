# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-03-04 
# 
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        q = deque()
        fresh, ans = 0, 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while q:
            rootten = False
            n = len(q)
            for i in range(n):
                x = q.popleft()
                for d in dirs:
                    ni, nj = x[0] + d[0], x[1] + d[1]
                    if 0<=ni<rows and 0<=nj<cols and grid[ni][nj] == 1:
                        grid[ni][nj] = 2
                        q.append((ni, nj))
                        fresh -= 1
                        rootten = True
            if rootten:
                ans += 1
        return ans if not fresh else -1


solve = Solution()
print(solve.orangesRotting([[2,1,1],[1,1,0],[0,1,1]]))