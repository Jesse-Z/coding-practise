# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        p, q = 0, 1
        for i in range(2, n+1):
            q = p + q
            p = q - p

        q = q % 1000000007
        return int(q)


solve = Solution()
print(solve.fib(100))