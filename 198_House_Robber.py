"""
Jesse@FDU-VTS-MIA
created by 2019/10/16
"""
class Solution:
    def rob(self, nums: [int]) -> int:
        return self.dp(nums)

    # DP，f(k) = Max(f(k-2)+A(k), f(k-1))
    @staticmethod
    def dp(nums) -> int:
        prev, curr = 0, 0
        for num in nums:
            temp = curr
            curr = max(prev + num, curr)
            prev = temp
        return curr
