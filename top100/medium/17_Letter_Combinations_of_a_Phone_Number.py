"""
Jesse@FDU-VTS-MIA
created by 2019/11/27
"""
class Solution:
    def letterCombinations(self, digits: str) -> [str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        output = []
        def back_track(comb, next_dig):
            if len(next_dig) == 0:
                output.append(comb)
            else:
                for letter in phone[next_dig[0]]:
                    back_track(comb+letter, next_dig[1:])
        if digits:
            back_track("", digits)
        return output

solve = Solution()
solve.letterCombinations('234')
