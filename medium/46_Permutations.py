"""
Jesse@FDU-VTS-MIA
created by 2019/12/3
"""
class Solution:
    def permute(self, nums: [int]) -> [[int]]:
        ans = []
        def back_trace(combs, cads):
            if not cads:
                ans.append(combs)
                return
            for i in range(len(cads)):
                back_trace(combs+[cads[i]], cads[:i]+cads[i+1:])
        back_trace([], nums)
        return ans

solve = Solution()
print(solve.permute([1,2,3]))