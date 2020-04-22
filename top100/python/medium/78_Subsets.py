"""
Jesse@FDU-VTS-MIA
created by 2019/11/28
"""


class Solution:
    def subsets(self, nums: [int]) -> [[int]]:
        ans = []

        def back_trace(i, cads):
            ans.append(cads)
            for j in range(i, len(nums)):
                back_trace(j + 1, cads + [nums[j]])

        back_trace(0, [])
        print(ans)
        return ans


solve = Solution()
solve.subsets([1, 2, 3])
