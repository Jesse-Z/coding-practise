# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/11
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed and not popped:
            return True
        if not pushed or not popped:
            return False
        stack = []
        p, q = 0, 0
        while q < len(popped):
            stack.append(pushed[q])
            q += 1
            while stack and stack[-1] == popped[p]:
                stack.pop()
                p += 1
        return p == len(popped)

Solution().validateStackSequences([1,2,3,4,5]
,[4,5,3,2,1])