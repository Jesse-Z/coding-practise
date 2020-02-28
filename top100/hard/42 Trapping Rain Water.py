"""
Jesse@FDU-VTS-MIA
created @date: 2020-01-14 
"""
from typing import List
from collections import defaultdict
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = self.doublePoints(height)
        print(ans)
        return ans

    def doublePoints(self, height: List[int]) -> int:
        """双指针法
        想法核心在于每次只移动左右指针中较小的那一方.
        """
        if not height: return 0
        left, right, maxLeft, maxRight = 0, len(height) - 1, height[0], height[-1]
        ans = 0
        while left < right:
            if height[left] < height[right]:
                left += 1
                maxLeft = max(maxLeft, height[left])
                ans += maxLeft - height[left]
            else:
                right -= 1
                maxRight = max(maxRight, height[right])
                ans += maxRight - height[right]
        return ans

    def stack(self, height: List[int]) -> int:
        """辅助栈

        """
        pass