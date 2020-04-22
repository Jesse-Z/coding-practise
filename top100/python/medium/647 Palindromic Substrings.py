"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-30
"""
from typing import List
from collections import defaultdict
class Solution:
    def countSubstrings(self, s: str) -> int:
        """动态规划
        可以作为回文子串的中心共有2n-1个，n个字符+(n-1)个字符中间
        """
        n = len(s)
        ans = 0
        for center in range(2*n-1):
            left = center // 2
            right = left + center%2
            while left >= 0 and right < n and s[left] == s[right]:
                ans += 1
                left -= 1
                right += 1
        return ans
