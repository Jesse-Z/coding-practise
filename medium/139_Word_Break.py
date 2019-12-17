"""
Jesse@FDU-VTS-MIA
created by 2019/12/16
"""
from typing import List
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        """动态规划
        将s分解为两个部分s1和s2,其中s2是wordDict中的单词,只要s1也是wordDict单词组成的子串,则正确
        因此,将一个问题分解为了两个子问题,用动态规划求解.
        用dp数组保存s对应位置能否work break,使用2个下标指针i和j，
        其中i是当前字符串从头开始的子字符串(s')的长度,j是当前子字符串(s')的拆分位置,
        拆分为s'(0,j)和s'(j+1,i)
        """
        dp = [False for _ in range(len(s)+1)]
        dp[0] = True
        for i in range(1, len(s)+1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
        return dp[len(s)]
