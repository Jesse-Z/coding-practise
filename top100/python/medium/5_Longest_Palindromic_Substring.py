"""
Jesse@FDU-VTS-MIA
created by 2019/11/26
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = self.expand_center(s)
        return ans

    def dp(self, s):
        """
        TLE
        """
        n = len(s)
        if not n: return ""
        P = [[False for j in range(n)] for i in range(n)]
        start = 0
        maxL = 1
        for i in range(n):
            P[i][i] = True
            if i < n - 1 and s[i] == s[i + 1]:
                P[i][i + 1] = True
                start = i
                maxL = 2
        for l in range(3, n + 1, 1):
            for i in range(n - l + 1):
                P[i][i + l - 1] = (P[i + 1][i + l - 2] and s[i] == s[i + l - 1])
                if P[i][i + l - 1] and l > maxL:
                    maxL = l
                    start = i
        return s[start:start + maxL]

    def expand_center(self, s):
        def expand_func(s, l, r):
            left = l
            right = r
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1
        n = len(s)
        if not n: return ""
        end = start = 0
        for i in range(n):
            len1 = expand_func(s, i, i)    # odd
            len2 = expand_func(s, i, i+1)  # even
            len_ = max(len1, len2)
            if len_ > end - start:
                start = i - (len_-1)//2
                end = i + len_//2
        return s[start: end+1]
