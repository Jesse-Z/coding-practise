# -*- coding: utf-8 -*-
#
# Jesse@FDU-VTS-MIA
# created @date: 2020/2/29
#
from typing import List
from collections import defaultdict, Counter, deque


class Solution:
    def cuttingRope(self, n: int) -> int:
        return self.better_dp(n)

    def recursion(self, n: int) -> int:
        cache = [0 for _ in range(n + 1)]

        def helper(n, cache):
            if n == 2:
                return 1
            if cache[n] != 0:
                return cache[n]
            res = 1
            for i in range(1, n):
                res = max(res, max((n - i) * i, i * helper(n - i, cache)))
            cache[n] = res
            return res

        ans = helper(n, cache)
        return ans

    def dp(self, n: int) -> int:
        dp_array = [0 for _ in range(n + 1)]
        dp_array[2] = 1
        for i in range(n + 1):
            for j in range(2, i - 1):
                dp_array[i] = max(dp_array[i], max(j * (i - j), j * dp_array[i - j]))
        return dp_array[n]

    def better_dp(self, n: int) -> int:
        """任何一个属都可以分解为1，2，3的和，同时余数为0，1，2
        用三个数代表任何大于3的数"""
        dp_array = [0, 1, 1]
        for i in range(4, n + 1):
            dp_array[i % 3] = max(max(max(dp_array[(i - 1) % 3], i - 1), 2 * max(dp_array[(i - 2) % 3], i - 2)),
                                  3 * max(dp_array[(i - 3) % 3], i - 3))
        return dp_array[n % 3]


solve = Solution()
print(solve.cuttingRope(25))
