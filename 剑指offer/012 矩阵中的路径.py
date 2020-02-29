# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        visited = [[False]*n for _ in range(m)]

        def dfs(visited, i, j, curr_w) -> bool:
            # ----长度相同，找到了----
            if curr_w == len(word):
                return True
            # ----越界还没找完，不对----
            if i >= len(visited) or j >= len(visited[0]) or i < 0 or j < 0 or board[i][j] != word[curr_w] or visited[i][j]:
                return False
            visited[i][j] = True
            res = dfs(visited, i-1, j, curr_w+1) or dfs(visited, i,j-1, curr_w+1) or dfs(visited, i+1,j, curr_w+1) or dfs(visited, i,j+1,curr_w+1)
            visited[i][j] = False
            return res
        # -----找到第一个字符后，开始dfs-----
        for i in range(m):
            for j in range(n):
                if dfs(visited, i, j, 0):
                    return True
        return False

solve = Solution()
solve.exist([["a","b"]]
,"ba")