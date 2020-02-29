# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
class Solution:
    def numWays(self, n: int) -> int:
        if n < 3:
            return n
        p, q = 1, 2
        for i in range(3, n+1):
            q = p + q
            p = q - p
        return int(q%1000000007)