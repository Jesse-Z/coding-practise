"""
Jesse@FDU-VTS-MIA
created by 2019/11/26
"""
class Solution:
    def maxArea(self, height: [int]) -> int:
        ans = self.double_point(height)
        return ans

    def double_point(self, height):
        p = 0
        q = len(height) - 1
        maxArea = 0
        while p < q:
            lower = min(height[p], height[q])
            area = lower * (q-p)
            maxArea = max(area, maxArea)
            if height[p] < height[q]:
                p += 1
            else:
                q -= 1
        return maxArea
