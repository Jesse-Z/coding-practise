"""
Jesse@FDU-VTS-MIA
created by 2019/12/9
"""
class Solution:
    def sortColors(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0, curr, p2 = 0, 0, len(nums)-1
        while curr<=p2:                # 注意这个等于号，因为p2指向的是2的左边界，是开区间，需要再遍历一次
            if nums[curr]==0:
                nums[curr], nums[p0] = nums[p0], nums[curr]
                p0 += 1
                curr += 1
            elif nums[curr]==1:
                curr += 1
            elif nums[curr]==2:
                nums[curr], nums[p2] = nums[p2], nums[curr]
                p2 -= 1

solve = Solution()
solve.sortColors([2, 0, 1])