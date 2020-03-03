# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/3/3
#
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0: return 0
        if n < 0:
            x, n = 1 / x, -n
        return self.recursion(x, n)

    def fastPow(self, x, n):
        """
        快速幂方法
        """
        res = 1
        while n:
            if n & 1:
                res *= x
            x *= x
            n = n >> 1
        return res

    def recursion(self, x, n):
        # 递归版本的二分法
        # ----终止条件----
        if n == 0:
            return 1
        if n == 1:
            return x
        subpow = self.recursion(x, n >> 1)
        return subpow * subpow * x if n&1 else subpow * subpow