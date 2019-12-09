"""
Jesse@FDU-VTS-MIA
created by 2019/12/9
"""
class Solution:
    def canJump(self, nums: [int]) -> bool:
        """贪心，从左向右遍历，每次求得可以跳到的最远距离"""
        furthest = 0
        for i in range(len(nums)):
            if i>furthest:
                return False
            furthest = max(furthest, i+nums[i])
        return True