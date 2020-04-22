# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/14
#
from typing import List
from collections import defaultdict, Counter


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        """从第一行，往下分析，即多次84题解法"""
        ans = 0
        if matrix:
            dp = [0] * len(matrix[0])
            for i in range(len(matrix)):
                for j in range(len(matrix[0])):
                    dp[j] = dp[j] + 1 if matrix[i][j] == '1' else 0
                ans = max(ans, self.getMaxInLine(dp))
        return ans

    def getMaxInLine(self, height: List[int]) -> int:
        n = len(height)
        print(height)
        left_bound = [0]*n
        right_bound = [0]*n
        left_bound[0] = -1
        right_bound[-1] = n
        for i in range(1, n):
            temp = i-1
            while temp >= 0 and height[temp] >= height[i]:
                temp = left_bound[temp]
            left_bound[i] = temp
        for i in range(n-2, -1, -1):
            temp = i+1
            while temp < n and height[temp] >= height[i]:
                temp = right_bound[temp]
            right_bound[i] = temp
        maxArea = 0
        for i in range(n):
            maxArea = max(maxArea, height[i]*(right_bound[i]-left_bound[i]-1))
        return maxArea
