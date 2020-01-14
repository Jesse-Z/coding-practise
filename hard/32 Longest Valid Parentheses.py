"""
Jesse@FDU-VTS-MIA
created @date: 2020-01-14 
"""
from typing import List
from collections import defaultdict
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans = self.usingStack(s)
        print(ans)

    def usingStack(self, s: str) ->int:
        """辅助栈
        栈中保存的是合法字符串的前一个无效字符,每当成功匹配一对，则弹出有效的字符位置。
        从而用无效字符来分隔了有效子串。
        """
        maxLen, stack = 0, [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if stack:
                    maxLen = max(maxLen, i - stack[-1])
                else:
                    stack.append(i)
        return maxLen

solve = Solution()
solve.longestValidParentheses(")((())()")