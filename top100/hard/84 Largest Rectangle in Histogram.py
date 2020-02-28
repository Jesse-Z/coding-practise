# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-01-17 
# 
from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = self.usingStack(heights)
        print(ans)
        return ans

    def brutal(self, heights: List[int]) -> int:
        """暴力
        以i,j为区间,搜索其中最小高度,从而得到面积.
        时间复杂度为O(n^3)
        """
        n = len(heights)
        maxArea = 0
        for i in range(n):
            for j in range(i, n):
                minHeight = float('inf')
                for k in range(i, j + 1):
                    minHeight = min(minHeight, heights[k])
                maxArea = max(minHeight * (j - i + 1), maxArea)
        return maxArea

    def brutal_expand(self, heights: List[int]) -> int:
        """暴力`改
        以每根柱子为中心向两边拓展.
        时间复杂度为O(n^2).
        """
        n = len(heights)
        maxArea = 0
        for i in range(n):
            left, right = i - 1, i + 1
            while left >= 0 and heights[left] >= heights[i]:
                left -= 1
            while right <= n - 1 and heights[right] >= heights[i]:
                right += 1
            maxArea = max(heights[i] * (right - left - 1), maxArea)
        return maxArea

    def brutal_expand_2(self, heights: List[int]) -> int:
        """暴力`改2
        改1的本质在于寻找当前柱子左右两边高度大于它的开区间,可以提前保存.
        同时有传递性,heights[i-1] >= heights[i]时,左边界相同.
        时间复杂度为O(n).
        """
        if not heights:
            return 0
        n = len(heights)
        maxArea = 0
        left_bound, right_bound = [0] * n, [0] * n
        left_bound[0] = -1
        right_bound[-1] = n
        for i in range(1, n):
            temp = i - 1
            while temp >= 0 and heights[temp] >= heights[i]:
                temp = left_bound[temp]
            left_bound[i] = temp
        for i in range(n - 2, -1, -1):
            temp = i + 1
            while temp < n and heights[temp] >= heights[i]:
                temp = right_bound[temp]
            right_bound[i] = temp
        for i in range(n):
            maxArea = max(heights[i] * (right_bound[i] - left_bound[i] - 1), maxArea)
        return maxArea

    def usingStack(self, heights: List[int]) -> int:
        """辅助栈
        用一个辅助栈来保存[0, i]为止的单调递增序列.
        当遇到比栈顶索引高度小的点时,意味着遇到了(栈顶元素的)右边界.所有可能的左边界则保存在栈中.
        """
        stack = []
        heights = [0] + heights + [0]  # NOTE: 赋予第一个和最后一个元素左边界与右边界
        maxArea = 0
        for i in range(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                temp = stack.pop()
                maxArea = max(maxArea, (i - stack[-1] - 1) * heights[temp])
            stack.append(i)
        return maxArea


solve = Solution()
solve.largestRectangleArea([1, 2, 3, 4, 5, 6])
