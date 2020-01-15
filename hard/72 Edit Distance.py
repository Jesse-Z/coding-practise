# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-01-15
#
from typing import List
from collections import defaultdict
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        ans = self.dynamicProgramming(word1, word2)
        print(ans)
        return ans

    def dynamicProgramming(self, word1: str, word2: str) -> int:
        """动态规划
        """
        dp = [[0 for _ in range(len(word2)+1)] for _ in range(len(word1)+1)]
        for i in range(1, len(word2)+1):
            dp[0][i] = i
        for j in range(1, len(word1)+1):
            dp[j][0] = j
        for i in range(1, len(word1)+1):
            for j in range(1, len(word2)+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
        return dp[-1][-1]