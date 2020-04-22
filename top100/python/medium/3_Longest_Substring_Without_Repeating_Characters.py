"""
Jesse@FDU-VTS-MIA
created by 2019/11/26
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = self.slide_window(s)
        return ans

    def slide_window(self, s):
        hset = set()
        ans = i = j = 0
        n = len(s)
        while i < n and j < n:
            if s[j] not in hset:
                hset.add(s[j])
                j += 1
                ans = max(ans, j - i)
            else:
                hset.remove(s[i])
                i += 1
        return ans
