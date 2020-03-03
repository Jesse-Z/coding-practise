# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/1
#
class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            res += 1
            n &= n - 1
        return res
