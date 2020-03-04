# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/4
#
from typing import List
from collections import defaultdict, Counter, deque

class Solution:
    def __init__(self):
        self.index = 0

    def isNumber(self, s: str) -> bool:
        """
        一个有效数字应该为以下模式: A[.[B]][e|EC] 或 .[B][e|EC]
        其中A和C是包含'+' '-'的整数, B是纯数字
        """
        def scanInteger(s: str) -> bool:
            """
            用于扫描包含正负号的整数
            """
            if s[self.index] == '+' or s[self.index] == '-':
                self.index += 1
            return scanUnsignedInteger(s)

        def scanUnsignedInteger(s: str) -> bool:
            """
            扫描无符号整数
            """
            before = self.index
            while self.index < len(s) and s[self.index].isdigit():
                self.index += 1
            return self.index > before

        # 测试样例中有首尾存在空格的情况
        s = s.strip()
        if s == '':
            return False
        numeric = scanInteger(s)
        if self.index < len(s) and s[self.index] == '.':
            self.index += 1
            numeric = scanUnsignedInteger(s) or numeric if self.index < len(s) else numeric
        if self.index < len(s) and s[self.index] in ['e', 'E']:
            self.index += 1
            numeric = (numeric and scanInteger(s)) if self.index < len(s) else False
        return numeric and self.index == len(s)


solve = Solution()
print(solve.isNumber('-3 .'))