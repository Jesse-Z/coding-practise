"""
Jesse@FDU-VTS-MIA
created @date: 2019-12-25 
"""

class Solution:
    def decodeString(self, s: str) -> str:
        ans = self.wizStack(s)
        return ans

    def wizStack(self, s: str) -> str:
        """辅助栈
        由于存在嵌套括号的情况,引入一个辅助栈来记录
        1. [前的字符,用于后续的拼接操作
        2. [前的倍数,用于后续的乘法操作
        """
        stack = []
        res = ""
        curr_multi = 0
        for c in s:
            if c.isdigit():
                curr_multi = int(c) + curr_multi*10
            elif c.isalpha():
                res += c
            elif c == '[':
                stack.append([curr_multi, res])
                curr_multi = 0
                res = ''
            elif c == ']':
                multi, last_res = stack.pop()
                res = last_res + multi*res
        return res

    def recursion(self, s: str) -> str:
        """递归

        """
        # todo: 完成递归方法
        pass