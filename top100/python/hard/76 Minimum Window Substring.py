# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020-01-15 
# 
from typing import List
from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans = self.slideWindow(s, t)
        print(ans)
        return ans

    def slideWindow(self, s: str, t: str):
        left, right, matched= 0, 0, 0
        ans = [-1, 0, 0]  # initialize answer, [lenght, left, right]
        s_words_set, t_words_set = defaultdict(int), defaultdict(int)
        for c in t:
            t_words_set[c] += 1
        required = len(t_words_set.keys())  # NOTE：这里记录的是unique char数量
        while right < len(s):
            s_words_set[s[right]] += 1
            if s_words_set.get(s[right]) == t_words_set.get(s[right]):
                matched += 1
            while left <= right and matched == required:
                if ans[0] == -1 or right - left + 1 < ans[0]:
                    ans[0] = right - left + 1
                    ans[1], ans[2] = left, right
                s_words_set[s[left]] -= 1
                if s[left] in t_words_set.keys() and s_words_set.get(s[left]) < t_words_set.get(s[left]):
                    matched -= 1
                left += 1
            right += 1
        return s[ans[1]: ans[2]+1] if ans[0] != -1 else ""
