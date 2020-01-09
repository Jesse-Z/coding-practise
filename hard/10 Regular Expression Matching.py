"""
Jesse@FDU-VTS-MIA
created @date: 2020-01-03 
"""
from typing import List
from collections import defaultdict
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        ans = self.dp(s, p)
        return ans

    def dp(self, s: str, p: str) -> bool:
        a = [[False] * (len(p)+1) for _ in range(len(s)+1)]
        a[0][0] = True
        # 首先做初始化，对于s长度为0时，只有b*种形式可以匹配
        for j in range(len(p)):
            if p[j] == '*' and a[0][j-1]:
                a[0][j+1] = True
        # 正式dp
        for i in range(len(s)):
            for j in range(len(p)):
                # 如果当前p字符和s字符相同，或为万能匹配符时
                if s[i] == p[j] or p[j] == '.':
                    a[i+1][j+1] = a[i][j]
                """
                如果p字符为星号时，进行判断
                p字符串有两种选择，例如p字符为 ###b*
                1. ###  , 删除b*, 此时依赖dp[i][j-2]
                2. ###b* , b重复n次, 此时依赖s[i-1]的字符是否能和p[j]的匹配
                """
                if p[j] == '*':
                    if a[i+1][j-1]:
                        a[i+1][j+1] = True
                    elif s[i] == p[j-1] or p[j-1] == '.':
                        a[i+1][j+1] = a[i][j+1]
                    else:
                        a[i+1][j+1] = False
        return a[len(s)][len(p)]


solve = Solution()
solve.dp("aa", "a*")
