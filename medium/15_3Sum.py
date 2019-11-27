"""
Jesse@FDU-VTS-MIA
created by 2019/11/27
"""
class Solution:
    def threeSum(self, nums: [int]) -> [[int]]:
        ans = self.sort_double_point(nums)
        return ans

    def sort_double_point(self, nums):
        nums.sort()
        res, k = [], 0
        for k in range(len(nums)-2):
            if nums[k] > 0: break                        # 1. nums[k]>0时，三个数都大于0
            if k > 0 and nums[k] == nums[k-1]: continue  # 2. nums[k-1] == nums[k]时已经处理过，跳过
            left = k+1
            right = len(nums) - 1
            while left < right:
                s = nums[k] + nums[left] + nums[right]
                if s < 0:
                    left += 1
                    while left < right and nums[left] == nums[left-1]: left += 1
                elif s > 0:
                    right -= 1
                    while left < right and nums[right] == nums[right+1]: right -= 1
                elif s == 0:
                    res.append([nums[k], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left-1]: left += 1
                    while left < right and nums[right] == nums[right+1]: right -= 1
        return res

solve = Solution()
solve.threeSum([-2,0,1,1,2])