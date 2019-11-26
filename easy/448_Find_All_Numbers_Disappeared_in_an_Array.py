"""
Jesse@FDU-VTS-MIA
created by 2019/11/19
"""


class Solution:
    def findDisappearedNumbers(self, nums: [int]) -> [int]:
        res = []
        for i in range(len(nums)):
            while nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(len(nums)):
            if nums[i] != i + 1:
                res.append(i + 1)
        return res
