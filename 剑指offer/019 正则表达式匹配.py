# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/4
#
# 同leetcode第十题，https://leetcode-cn.com/problems/regular-expression-matching/
from typing import List
from collections import defaultdict, Counter, deque


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        ans = self.dp(s, p)
        return ans

    def dp(self, s: str, p: str) -> bool:
        """
        状态转移矩阵dp_array[i][j]含义：s前i位和p前j位是否匹配
        画出有限状态机更好进行判断。
        """
        dp_array = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        dp_array[0][0] = True
        for j in range(len(p)):
            if p[j] == '*' and dp_array[0][j - 1]:
                dp_array[0][j + 1] = True
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if s[i - 1] == p[j - 1] or p[j - 1] == '.':
                    dp_array[i][j] = dp_array[i - 1][j - 1]
                if p[j - 1] == '*':
                    if s[i - 1] == p[j - 2] or p[j - 2] == '.':
                        dp_array[i][j] = dp_array[i - 1][j - 2] or dp_array[i - 1][j] or dp_array[i][j - 2]
                    else:
                        dp_array[i][j] = dp_array[i][j - 2]
        return dp_array[len(s)][len(p)]

    def recursion(self, s: str, p: str) -> bool:
        if s == '' and p == '':
            return True
        if s != '' and p == '':
            return False
        # ----先判断通用符----
        if len(p) > 1 and p[1] == '*':
            if s != '' and (p[0] == s[0] or p[0] == '.'):
                return self.recursion(s[1:], p[2:]) or self.recursion(s[1:], p) or self.recursion(s, p[2:])
            else:
                return self.recursion(s, p[2:])
        # ----判断当前字符----
        if s != '' and (s[0] == p[0] or p[0] == '.'):
            return self.recursion(s[1:], p[1:])
        return False


solve = Solution()
print(solve.isMatch("mississippi"
                    , "mis*is*p*."))
