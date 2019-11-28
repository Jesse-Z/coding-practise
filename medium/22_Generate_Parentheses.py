"""
Jesse@FDU-VTS-MIA
created by 2019/11/28
"""
class Solution:
    def generateParenthesis(self, n: int) -> [str]:
        ans = []

        def back_trace(S, left, right):
            if len(S) == 2*n:
                ans.append(S)
                return
            if left < n:
                back_trace(S+'(', left+1, right)
            if right < left:
                back_trace(S+')', left, right+1)
        back_trace()
        return ans
