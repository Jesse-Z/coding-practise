# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/6
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        if matrix:
            top, bottom, left, right = 0, len(matrix)-1, 0, len(matrix[0])-1
            while 1:
                for i in range(left, right+1):
                    ans.append(matrix[top][i])
                top += 1
                if top > bottom:
                    break
                for i in range(top, bottom+1):
                    ans.append(matrix[i][right])
                right -= 1
                if right < left:
                    break
                for i in range(right, left-1, -1):
                    ans.append(matrix[bottom][i])
                bottom -= 1
                if bottom < top:
                    break
                for i in range(bottom, top-1, -1):
                    ans.append(matrix[i][left])
                left += 1
                if left > right:
                    break
        return ans
