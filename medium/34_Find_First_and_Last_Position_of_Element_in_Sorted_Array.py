"""
Jesse@FDU-VTS-MIA
created by 2019/11/28
"""


class Solution:
    def searchRange(self, nums: [int], target: int) -> [int]:
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        if not nums or left >= len(nums) or nums[left] != target:
            return [-1, -1]
        a = left
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            else:
                left = mid + 1
        b = left - 1
        return [a, b]


solve = Solution()
print(solve.searchRange([8, 8], 10))
