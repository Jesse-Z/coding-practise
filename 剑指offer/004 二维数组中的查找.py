# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/28
#
# tips: same as https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
from typing import List
from collections import defaultdict, Counter

class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        ans = self.brutal(matrix, target)
        return ans

    def brutal(self, matrix, target):
        m, n = len(matrix), len(matrix[0])
        ans = False
        for i in range(m-1, -1, -1):
            if matrix[i][0] > target:
                continue
            for j in range(n):
                if matrix[i][j] == target:
                    ans = True
                    return ans
        return ans


solve = Solution()
solve.findNumberIn2DArray([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
,5)