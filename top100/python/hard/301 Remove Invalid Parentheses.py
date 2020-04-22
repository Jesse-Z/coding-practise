# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/28
#
from typing import List
from collections import defaultdict, Counter


class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        ans = self.bfs(s)
        return ans

    @staticmethod
    def isValid(s: str):
        cnt = 0
        for i in s:
            if i == '(':
                cnt += 1
            if i == ')':
                cnt -= 1
            if cnt < 0:
                return False
        return cnt == 0

    def bfs(self, s: str):
        """广度优先，每次删除一个括号，如果合法，则是答案"""
        level = {s}
        while 1:
            valid = list(filter(self.isValid, level))
            if valid:
                return valid
            next_level = set()
            for item in level:
                for i in range(len(item)):
                    next_level.add(item[:i]+item[i+1:])
            level = next_level


solve = Solution()
solve.removeInvalidParentheses('()())()')