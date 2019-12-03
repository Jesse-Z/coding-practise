"""
Jesse@FDU-VTS-MIA
created by 2019/12/3
"""
class Solution:
    def combinationSum(self, candidates: [int], target: int) -> [[int]]:
        ans = []

        def back_trace(start, now_sum, combs: [int]):
            if now_sum == target:
                ans.append(combs)
                return
            elif now_sum > target or start == len(candidates):
                return
            back_trace(start, now_sum+candidates[start], combs+[candidates[start]])
            back_trace(start+1, now_sum, combs)
        back_trace(0, 0, [])
        return ans


solve = Solution()
print(solve.combinationSum([2,3,6,7], 7))
