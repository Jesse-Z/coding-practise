"""
Jesse@FDU-VTS-MIA
created by 2019/10/9
"""
class Solution:
    def maxSubArray(self, nums: [int]) -> int:
        ans = nums[0]
        sum = 0
        for num in nums:
            if sum > 0:
                sum += num
            else:
                sum = num
            ans = max(sum, ans)
        return ans
