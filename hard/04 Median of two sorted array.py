"""
Jesse@FDU-VTS-MIA
created @date: 2020-01-03 
"""
from typing import List
from collections import defaultdict
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        ans = self.binarySearchonX(nums1, nums2)
        return ans

    def binarySearchonX(self, nums1, nums2):
        """二分查找
        找到中位数,也就是找到一个分割位置,使得两个数组的左右子数组长度相同并且
        maxLeftX <= minRightY && maxLeftY <= minRightX,
        由于原数组是有序的,用二分查找来寻找这个分隔位置.注意一些边界情况例如子数组长度为0的情况.
        """
        if len(nums2) < len(nums1):
            return self.binarySearchonX(nums2, nums1)
        x = len(nums1)
        y = len(nums2)
        low = 0
        high = x
        while(low <= high):
            parititionX = (low+high) // 2
            parititionY = (x+y+1)//2 - parititionX

            maxLeftX = nums1[parititionX-1] if parititionX!=0 else float('-inf')
            minRightX = nums1[parititionX] if parititionX!=x else float('inf')
            maxLeftY = nums2[parititionY-1] if parititionY!=0 else float('-inf')
            minRightY = nums2[parititionY] if parititionY!=y else float('inf')

            if maxLeftX <= minRightY and maxLeftY<=minRightX:
                if (x+y) % 2 == 0:
                    return (max(maxLeftX, maxLeftY)+min(minRightX, minRightY)) / 2
                else:
                    return max(maxLeftX, maxLeftY)
            elif maxLeftX > minRightY:
                high = parititionX - 1
            else:
                low = parititionX + 1
